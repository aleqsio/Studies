package com.JBibtexParser.entry;

import com.JBibtexParser.entry.entries.CommentEntry;
import com.JBibtexParser.entry.entries.PreambleEntry;
import com.JBibtexParser.entry.entries.PublicationEntry;
import com.JBibtexParser.entry.entries.StringEntry;
import types.EntryField;
import types.IEntryField;
import types.IEntryTypes;
import com.JBibtexParser.util.FieldOrTypeMissingException;
import com.JBibtexParser.util.LeveledString;
import com.JBibtexParser.util.ParseErrorException;
import javafx.util.Pair;
import types.Verification;
import types.definition.IDefinition;

import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class EntryFactory {
    private List<StringEntry> stringEntries;
    private List<CommentEntry> commmentEntries;
    private IEntryTypes entryTypes;
    private Verification verificationType;
    private IDefinition verificationDefinition;

    public EntryFactory(List<StringEntry> stringEntries, List<CommentEntry> commentEntries, IEntryTypes entryTypes, Verification verificationType, IDefinition verificationDefinition) {
        this.commmentEntries = commentEntries;
        this.stringEntries = stringEntries;
        this.entryTypes = entryTypes;
        this.verificationType=verificationType;
        this.verificationDefinition = verificationDefinition;
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
        if(!entryTypes.hasType(entryName.trim())) throw new FieldOrTypeMissingException("Some types are not defined: "+entryName);
        PublicationEntry publicationEntry = new PublicationEntry(entryTypes.getType(entryName.trim()));
        List<Pair<LeveledString, LeveledString>> pairs = leveledEntry.splitIntoKeyValuePairs();
        Pair<LeveledString, LeveledString> label = pairs.stream().filter(p -> p.getKey().getEntry().trim().equals("parser_entryname")).findFirst().get();
        publicationEntry.setEntryName(label.getValue().getEntry());
        pairs.remove(label);
        Object[] leveledStringStream = pairs.stream().map(p -> p.getKey()).filter(p -> !entryTypes.hasField(p.getEntry().trim())).toArray();
        if(leveledStringStream.length>0) throw new FieldOrTypeMissingException("Some fields are not defined: "+leveledStringStream[0].toString());
        Map<IEntryField, String> fields = pairs.stream().collect(Collectors.toMap(p -> entryTypes.getField(p.getKey().getEntry().trim()), p -> performSubstitutions(p.getValue()).getEntry().trim()));
        publicationEntry.setFields(fields);
        if(!entryTypes.isEntryCorrect(entryTypes.getType(entryName.trim()),fields,verificationDefinition,verificationType))
        {
            throw new ParseErrorException("Fields in this entry are not correct according to provided definition: "+ entryName);
        }
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