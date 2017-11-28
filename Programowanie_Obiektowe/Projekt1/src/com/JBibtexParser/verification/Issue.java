package com.JBibtexParser.verification;

import com.JBibtexParser.entry.IEntry;
import com.JBibtexParser.typemanager.IEntryField;

/**
 * Created by Aleksander on 27.11.2017.
 */
public class Issue {
    private String description;
    private IEntry entry;
    private IEntryField field;

    public Issue(String description, IEntry entry, IEntryField field) {
        this.description = description;
        this.entry = entry;
        this.field = field;
    }

    public IEntryField getField() {
        return field;
    }

    public void setField(IEntryField field) {
        this.field = field;
    }

    public IEntry getEntry() {
        return entry;
    }

    public void setEntry(IEntry entry) {
        this.entry = entry;
    }


    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }
}
