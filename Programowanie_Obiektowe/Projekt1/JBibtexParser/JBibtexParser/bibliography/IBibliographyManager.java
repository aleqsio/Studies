package JBibtexParser.bibliography;

import JBibtexParser.entry.entries.PublicationEntry;
import JBibtexParser.typemanager.IEntryTypesManager;

public interface IBibliographyManager{
    void add(PublicationEntry PublicationEntry);
    IBibliographyManager findFieldsOfValue(IEntryTypesManager.IEntryField field, String regex);
    IBibliographyManager filterByType(IEntryTypesManager.IEntryType type);
    Bibliography getBibliography();
    IBibliographyManager findEntriesContainingWords(String query);
}
