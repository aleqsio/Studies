package com.JBibtexParser.fieldparser;

import com.JBibtexParser.util.LeveledString;

import java.util.LinkedList;
import java.util.List;

/**
 * Created by Aleksander on 27.11.2017.
 */
public class SimpleFieldParser implements IFieldParser{
    @Override
    public List<String> parseField(LeveledString fieldString) {
        fieldString=fieldString.trim();
        if(fieldString.length()==0) return new LinkedList<>();
        List<String> subfields = new LinkedList<>();
        subfields.add(fieldString.toString());
        return subfields;
    }
}
