package com.JBibtexParser.entry;

import com.JBibtexParser.entry.defaultTypes.EntryFieldEnum;
import com.JBibtexParser.entry.defaultTypes.EntryTypeEnum;
import com.JBibtexParser.entry.entries.CommentEntry;
import com.JBibtexParser.entry.entries.PreambleEntry;
import com.JBibtexParser.entry.entries.PublicationEntry;
import com.JBibtexParser.entry.entries.StringEntry;
import com.JBibtexParser.util.LeveledString;
import com.JBibtexParser.util.ParseErrorException;
import javafx.util.Pair;

import java.util.List;
import java.util.stream.Collectors;

public class EntryFactory {
    private List<StringEntry> stringEntries;
    private List<CommentEntry> commmentEntries;

    public EntryFactory(List<StringEntry> stringEntries, List<CommentEntry> commmentEntries) {
        this.commmentEntries = commmentEntries;
        this.stringEntries = stringEntries;
    }

    private CommentEntry createCommentEntry(String block) {
        CommentEntry commentEntry = new CommentEntry();
        commentEntry.setCommentText(block);
        return commentEntry;
    }
    private PreambleEntry createPreambleEntry(String block) {
        PreambleEntry preambleEntry = new PreambleEntry();
        preambleEntry.setPreambleText(block);
        return preambleEntry;
    }

    private StringEntry createStringEntry(LeveledString leveledEntry) throws ParseErrorException {
        List<Pair<LeveledString, LeveledString>> pairs = leveledEntry.splitIntoKeyValuePairs();
        if(pairs.size()<1) throw new ParseErrorException("Missing string substitution in block "+leveledEntry);
       StringEntry stringEntry = new StringEntry(pairs.get(0).getKey().getEntry(), pairs.get(0).getValue().getEntry());
        return stringEntry;
    }


    private PublicationEntry createPublicationEntry(LeveledString leveledEntry, String entryName) throws ParseErrorException {
        PublicationEntry publicationEntry = new PublicationEntry(EntryTypeEnum.valueOf(entryName.toUpperCase()));
        List<Pair<LeveledString, LeveledString>> pairs = leveledEntry.splitIntoKeyValuePairs();
        publicationEntry.setFields(pairs.stream().collect(Collectors.toMap(p -> EntryFieldEnum.valueOf(p.getKey().getEntry().trim().toUpperCase()), p -> performSubstitutions(p.getValue()).getEntry().trim())));
        return publicationEntry;
    }

    private LeveledString performSubstitutions(LeveledString leveledString) {
        for (StringEntry stringEntry : stringEntries){
            leveledString=leveledString.substituteOnLevel(0, stringEntry.getSourceText(), stringEntry.getReplacementText());
        }
        System.out.print(leveledString.toStringWithLevels());
        return leveledString;
    }

    public IEntry getEntry(String block) throws ParseErrorException {
        block = block.trim();
        block = block.replace("\n", "").replace("\r", "");
        String lowercaseBlock = block.toLowerCase();
        if (lowercaseBlock.startsWith("@comment{") || !lowercaseBlock.startsWith("@")) {
            return createCommentEntry(block);
        }
        if (lowercaseBlock.startsWith("@preamble{")) {
            return createPreambleEntry(block);
        }
        LeveledString leveledEntry = new LeveledString(block);
        String entryName = leveledEntry.getSubstringsOfLevel(0, (x, y) -> y - x).get(0).getEntry().replace("@", "").replace("{", "").toLowerCase();
        if (entryName.equals("string")) {
            return createStringEntry(leveledEntry);
        }
        return createPublicationEntry(leveledEntry, entryName);
    }


}