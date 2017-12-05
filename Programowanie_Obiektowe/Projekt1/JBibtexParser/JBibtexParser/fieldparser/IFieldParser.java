package JBibtexParser.fieldparser;

import JBibtexParser.entry.entries.StringEntry;
import JBibtexParser.typemanager.EntryField;
import JBibtexParser.util.LeveledString;
import JBibtexParser.util.exceptions.ParseErrorException;

import java.util.List;

/**
 * A simple parser of a single field's contents - used for string substitutions - can also be used for adding custom behaviour based on provided {@link LeveledString} and {@link EntryField}
 */
public interface IFieldParser {
    /**
     * final transformation a single field's value before being added to a {@link JBibtexParser.bibliography.IBibliographyManager}
     * @param fieldString - field's contents
     * @param stringEntries - a list of string entries used for substitutions
     * @param field - field type from either {@link JBibtexParser.typemanager.definitions.BibtexDefinition} or a custom definition implementing {@link JBibtexParser.typemanager.definitions.IDefinition} provided to the parser
     * @return A list of subfields - for example single authors can be divided into separate strings
     * @throws ParseErrorException
     */
    List<String> parseField(LeveledString fieldString, List<StringEntry> stringEntries, EntryField field) throws ParseErrorException;
}
