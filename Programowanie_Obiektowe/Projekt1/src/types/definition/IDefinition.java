package types.definition;

import types.EntryField;
import types.EntryType;
import types.IEntryField;
import types.IEntryType;

import java.util.Map;

/**
 * Created by Aleksander on 25.11.2017.
 */
public interface IDefinition {
    Map<IEntryType, Map<IEntryField, FieldProperties>> getDefinition();
    public Map<String, EntryField> getFields();
    public Map<String, EntryType> getTypes();
}
