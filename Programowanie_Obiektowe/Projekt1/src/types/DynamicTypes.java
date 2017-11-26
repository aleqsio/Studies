package types;

import types.definition.FieldProperties;
import types.definition.IDefinition;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by Aleksander on 25.11.2017.
 */
public class DynamicTypes implements IEntryTypes {
    Map<String, EntryType> types = new HashMap<>();
    Map<String, EntryField> fields = new HashMap<>();

    @Override
    public EntryType getType(String name) {
        if (!types.containsKey(name.toLowerCase())) types.put(name.toLowerCase(), new EntryType(name));
        return types.get(name.toLowerCase());
    }

    @Override
    public boolean hasType(String name) {
        return true;
    }

    @Override
    public List<EntryType> getAllTypes() {
        return new ArrayList<>(types.values());
    }

    @Override
    public EntryField getField(String name) {
        if (!fields.containsKey(name.toLowerCase())) fields.put(name.toLowerCase(), new EntryField(name));
        return fields.get(name.toLowerCase());
    }

    @Override
    public boolean hasField(String name) {
        return true;
    }


}
