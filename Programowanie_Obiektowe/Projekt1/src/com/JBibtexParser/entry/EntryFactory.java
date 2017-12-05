package com.JBibtexParser.entry;

import com.JBibtexParser.entry.entries.CommentEntry;
import com.JBibtexParser.entry.entries.PreambleEntry;
import com.JBibtexParser.entry.entries.PublicationEntry;
import com.JBibtexParser.entry.entries.StringEntry;
import com.JBibtexParser.typemanager.IEntryTypesManager;
import com.JBibtexParser.util.exceptions.FieldOrTypeMissingException;
import com.JBibtexParser.util.LeveledString;
import com.JBibtexParser.util.exceptions.ParseErrorException;
import com.JBibtexParser.fieldparser.IFieldParser;
import javafx.util.Pair;

import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class EntryFactory {
    private List<StringEntry> stringEntries;
    private IEntryTypesManager entryTypes;
    private IFieldParser fieldParser;

    public EntryFactory(List<StringEntry> stringEntries, List<CommentEntry> commentEntries, IEntryTypesManager entryTypes, IFieldParser fieldParser) {
        this.stringEntries = stringEntries;
        this.entryTypes = entryTypes;
        this.fieldParser = fieldParser;
    }

    private CommentEntry createCommentEntry(String block) {
        if (block.trim().length() == 0 || block.trim().equals(",")) return null;
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
        if (pairs.size() < 1) throw new ParseErrorException("Missing string substitution in block " + leveledEntry);
        if(pairs.get(0).getKey().getEntry().equals("JBibtexParser_entry_id_specifier") || pairs.get(0).getKey().length()==0 || pairs.get(0).getValue().length() ==0) throw new ParseErrorException("Malformed string substitution");
        StringEntry stringEntry = new StringEntry(pairs.get(0).getKey().getEntry(), pairs.get(0).getValue().getEntry());
        return stringEntry;
    }


    private PublicationEntry createPublicationEntry(LeveledString leveledEntry, String entryName) throws ParseErrorException {
        if (!entryTypes.hasType(entryName.trim()))
            throw new FieldOrTypeMissingException("Some types are not defined: " + entryName);
        PublicationEntry publicationEntry = new PublicationEntry(entryTypes.getType(entryName.trim().toLowerCase()));
        List<Pair<LeveledString, LeveledString>> pairs = leveledEntry.splitIntoKeyValuePairs();
        Pair<LeveledString, LeveledString> label = pairs.stream().filter(p -> p.getKey().getEntry().trim().equals("JBibtexParser_entry_id_specifier")).findFirst().get();
        publicationEntry.setEntryName(label.getValue().getEntry().toLowerCase());
        pairs.remove(label);
        Object[] leveledStringStream = pairs.stream().map(Pair::getKey).filter(p -> !entryTypes.hasField(p.getEntry().trim())).toArray();

        if (leveledStringStream.length > 0)
            throw new FieldOrTypeMissingException("Some fields are not defined: " + leveledStringStream[0].toString());
        try {
            Map<IEntryTypesManager.IEntryField, List<String>> fields = pairs.stream().collect(Collectors.toMap(
                    p -> entryTypes.getField(p.getKey().getEntry().trim().toLowerCase()), //key
                    p -> {
                        try {
                            return fieldParser.parseField(p.getValue(), stringEntries,entryTypes.getField(p.getKey().getEntry().trim().toLowerCase()));
                        } catch (ParseErrorException e) {
                            throw new NullPointerException(e.getMessage());
                        }
                    }, //value
                    (firstKey, secondKey) -> firstKey)); //merge
            publicationEntry.setFields(fields);
        } catch (NullPointerException e) {
            throw new ParseErrorException(e.getMessage());
        }

        return publicationEntry;
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
        List<LeveledString> substringsOfLevel = leveledEntry.getSubstringsOfLevel(0, (x, y) -> y - x);
        if(substringsOfLevel.size()==0) throw new ParseErrorException("Entry has no fields");
        String entryName = substringsOfLevel.get(0).getEntry().replace("@", "").replace("{", "").toLowerCase();
        if (entryName.equals("string")) {
            return createStringEntry(leveledEntry);
        }
        return createPublicationEntry(leveledEntry, entryName);
    }


}