package com.JBibtexParser.util;

import javafx.util.Pair;

import java.util.*;
import java.util.function.IntBinaryOperator;

/**
 * Created by Aleksander on 24.11.2017.
 */
public class LeveledString {
   private String entry;
   private int[] levels;

    public LeveledString(String entry) throws ParseErrorException {
        setEntry(entry);
    }
    public LeveledString(String entry,int[] levels) {
        this.entry=entry;
        this.levels=levels;
    }

    public String getEntry() {
        return entry;
    }

    public void setEntry(String entry) throws ParseErrorException {
        this.entry = entry;
      parseLevels(entry);
    }
    private void parseLevels(String entry) throws ParseErrorException {
        levels = new int[entry.length()];
        Stack<Character> previousbrackets = new Stack<>();
        boolean insideQuotes = false;
        int pos = 0;
        for (char c : entry.toCharArray()) {
            levels[pos] = previousbrackets.size();
            if (c == '{' || c == '(') {
                previousbrackets.push(c);
            }
            if (c == '}' || c == ')') {
                if (c != rotateBracket(previousbrackets.pop())) {
                    throw new ParseErrorException("Mismatched brackets");
                }
            }
            if(c=='"')
            {
                insideQuotes=!insideQuotes;
                if(insideQuotes) {
                    previousbrackets.push(c);
                }else{
                    if (c != previousbrackets.pop()) {
                        throw new ParseErrorException("Mismatched quotes");
                    }
                }
            }
            levels[pos] = Math.min(previousbrackets.size(),levels[pos]);
            pos++;
        }
    }

    private char rotateBracket(char bracket){
        if(bracket=='{') return '}';
        if(bracket=='}') return '{';
        if(bracket=='(') return ')';
        if(bracket==')') return '(';
        return bracket;
    }
    public LeveledString substituteOnLevel(int level,String find,String replace) {
        String newEntry = entry;
        Integer[] positions = findAllOccurences(entry,find).stream().filter(p->levels[p]==level).toArray(Integer[]::new);
        for(Integer position:positions) {
            newEntry = newEntry.substring(0,position)+replace+newEntry.substring(position+find.length(),newEntry.length());
        }
        try {
            return new LeveledString(newEntry);
        } catch (ParseErrorException e) {
            return new LeveledString(newEntry,new int[newEntry.length()]);
        }

    }
    private List<Integer> findAllOccurences(String string,String pattern)
    {
        int lastIndex = 0;
        List<Integer> result = new ArrayList<Integer>();
        while(lastIndex != -1) {
            lastIndex = string.indexOf(pattern,lastIndex);
            if(lastIndex != -1){
                result.add(lastIndex);
                lastIndex += 1;
            }
        }
        return result;
    }
    public List<LeveledString> getSubstringsOfLevel(int level,IntBinaryOperator operator)
    {
        List<LeveledString> strings = new ArrayList<>();
        StringBuilder sb =new StringBuilder();
        List<Integer> lb = new LinkedList<>();

        for(int i=0;i<entry.length();i++){
            if(operator.applyAsInt(levels[i],level)>=0){
                sb.append(entry.charAt(i));
                lb.add(levels[i]-level);
            }else if(sb.length()>0) {
                LeveledString string = new LeveledString(sb.toString(),lb.stream().mapToInt(k->k).toArray());
                strings.add(string);
                sb =new StringBuilder();
                lb.clear();
            }
        }
        return strings;
    }
    public String toString(){
        return entry;
    }
    public String toStringWithLevels(){
        return entry+"\n"+ String.join("",Arrays.stream(levels).mapToObj(x -> String.valueOf(x)).toArray(String[]::new))+"\n";
    }
    private String removeCharAt(String s, int pos) {
        return s.substring(0,pos) + s.substring(pos+1);
    }
    public   List<LeveledString> splitOnLevel(char separator,int level){

        List<LeveledString> strings = new ArrayList<>();
        StringBuilder sb =new StringBuilder();
        List<Integer> lb = new LinkedList<>();

        for(int i=0;i<entry.length();i++){
            if(entry.charAt(i)!=separator){
                sb.append(entry.charAt(i));
                lb.add(levels[i]-level);
            }else if(levels[i]<=level){
                LeveledString string = new LeveledString(sb.toString(),lb.stream().mapToInt(k->k).toArray());
                strings.add(string);
                sb =new StringBuilder();
                lb.clear();
            }
        }
            LeveledString string = new LeveledString(sb.toString(), lb.stream().mapToInt(k -> k).toArray());
            strings.add(string);
        return strings;
    }
    public int[] getLevels() {
        return levels;
    }
    public List<Pair<LeveledString, LeveledString>> splitIntoKeyValuePairs() throws ParseErrorException {
        List<Pair<LeveledString, LeveledString>> pairs = new LinkedList<>();

        for (LeveledString leveledString : getSubstringsOfLevel(1,(x,y)->x-y).get(0).splitOnLevel(',', 0)) {
            List<LeveledString> keyValue = leveledString.splitOnLevel('=', 0);
            if (keyValue.size() ==1 && leveledString.getEntry().trim().length()>0)
                pairs.add(new Pair<LeveledString, LeveledString>(new LeveledString("parser_entryname"), keyValue.get(0)));
            else if(keyValue.size() ==2)
                pairs.add(new Pair<LeveledString, LeveledString>(keyValue.get(0), keyValue.get(1)));
        }
        return pairs;
    }
}
