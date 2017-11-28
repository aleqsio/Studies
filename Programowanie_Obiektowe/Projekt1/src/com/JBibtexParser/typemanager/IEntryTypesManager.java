package com.JBibtexParser.typemanager;

import java.util.List;

/**
 * Created by Aleksander on 25.11.2017.
 */
public interface IEntryTypesManager {
    EntryType getType(String name);

    boolean hasType(String name);

    List<EntryType> getAllTypes();

    EntryField getField(String name);

    boolean hasField(String name);

    public interface IEntryField {
        String getName();
        boolean equals(Object other);
        int hashCode();
    }
    
}

