package main;

import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;
import java.util.stream.Collectors;

/**
 * Created by Aleksander on 24.10.2017.
 */
public class Timetable3 implements ITimetable {
    Map<Term,Lesson> lessons=new TreeMap<>();


    @Override
    public boolean canBeTransferredTo(Term term) {
        return !lessons.containsKey(term);
    }
    @Override
    public Object get(Term term) {
        return lessons.get(term);
    }
    @Override
    public boolean busy(Term term) {
        return lessons.containsKey(term);
    }

    @Override
    public void put(Lesson lesson) throws IllegalArgumentException {
        if(canBeTransferredTo(lesson.getTerm())){
         lessons.put(lesson.getTerm(),lesson);
        }else{
            throw new IllegalArgumentException("this term:" + lesson.getTerm()+" is already busy");
        }
    }

    @Override
    public String toString() {
        String s=new String();
        Day firstDay = Day.MON;
        Day lastDay = Day.SUN;
        Term term;

        for (Day d:Day.values()) {
            s+=(d.toString()+"\n");
            Term firstTerm = new Term(8,0,d);
            Term lastTerm = new Term(20,0,d);
            for(term = firstTerm ; term.laterThan(lastTerm) ; term = term.endTerm()){
                s+=(term.toString()+"\n");
                if(busy(term))
                    s+=(get(term).toString()+"\n");
                else
                    s+=("\n");
            }
        }
        return s;
    }
    public String toShortString(){
        return lessons.values().stream().sorted((x,y)->x.getTerm().laterThanInAWeek(y.getTerm())).map(x->x.toString()).collect(Collectors.joining (","));
    }
    @Override
    public void perform(Action[] actions) {
            int pos=0;
        Lesson[] lessons2 = lessons.values().stream().sorted((x,y)->x.getTerm().laterThanInAWeek(y.getTerm())).toArray(Lesson[]::new);

        for (Action a:actions
             ) {
                    lessons2[pos%actions.length].fromAction(a);
            pos++;
        }
    }


}
