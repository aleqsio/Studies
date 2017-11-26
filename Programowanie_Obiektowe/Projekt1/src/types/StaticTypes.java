package types;

import types.definition.BibtexDefinition;
import types.definition.IDefinition;

import javax.management.openmbean.InvalidKeyException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by Aleksander on 25.11.2017.
 */
public class StaticTypes implements IEntryTypes {
    private Map<String,EntryType> types = new HashMap<>();
    private Map<String,EntryField> fields = new HashMap<>();
    private IDefinition definition;
    public StaticTypes(IDefinition definition) {
        this.definition=definition;
        types=definition.getTypes();
        fields=definition.getFields();
    }

    @Override
    public EntryType getType(String name) {
       return types.get(name.toLowerCase());
    }

    @Override
    public boolean hasType(String name) {
        return types.containsKey(name.toLowerCase());
    }

    @Override
    public List<EntryType> getAllTypes() {
        return new ArrayList<EntryType>(types.values());
    }

    @Override
    public EntryField getField(String name) {
        if(!fields.containsKey(name.toLowerCase())) throw new InvalidKeyException();
        return fields.get(name.toLowerCase());
    }

    @Override
    public boolean hasField(String name) {
        return fields.containsKey(name.toLowerCase());
    }
}
