package com.JBibtexParser.typemanager;

/**
 * Created by Aleksander on 25.11.2017.
 */
public class EntryField implements IEntryField {
    String name;

    public EntryField(String name) {
        this.name = name;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        EntryField that = (EntryField) o;

        return name != null ? name.equals(that.name) : that.name == null;
    }

    @Override
    public int hashCode() {
        return name != null ? name.hashCode() : 0;
    }
}
