package com.JBibtexParser.fieldparser;

import com.JBibtexParser.entry.entries.StringEntry;
import com.JBibtexParser.typemanager.EntryField;
import com.JBibtexParser.util.LeveledString;
import com.JBibtexParser.util.exceptions.ParseErrorException;

import java.util.List;

/**
 * Created by Aleksander on 27.11.2017.
 */
public interface IFieldParser {
    List<String> parseField(LeveledString fieldString, List<StringEntry> stringEntries, EntryField field) throws ParseErrorException;
}
