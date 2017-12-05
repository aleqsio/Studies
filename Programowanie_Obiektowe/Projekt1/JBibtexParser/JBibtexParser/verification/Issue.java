package JBibtexParser.verification;

import JBibtexParser.entry.IEntry;
import JBibtexParser.typemanager.IEntryTypesManager;

/**
 * Created by Aleksander on 27.11.2017.
 */
public class Issue {
    private String description;
    private IEntry entry;
    private IEntryTypesManager.IEntryField field;

    public Issue(String description, IEntry entry, IEntryTypesManager.IEntryField field) {
        this.description = description;
        this.entry = entry;
        this.field = field;
    }

    public IEntryTypesManager.IEntryField getField() {
        return field;
    }

    public void setField(IEntryTypesManager.IEntryField field) {
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
