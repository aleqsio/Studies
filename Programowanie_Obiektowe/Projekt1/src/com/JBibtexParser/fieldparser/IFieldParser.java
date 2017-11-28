package com.JBibtexParser.fieldparser;

import com.JBibtexParser.util.LeveledString;

import java.util.List;

/**
 * Created by Aleksander on 27.11.2017.
 */
public interface IFieldParser {
    List<String> parseField(LeveledString fieldString);
}
