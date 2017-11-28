package com.JBibtexParser.typemanager;

import com.JBibtexParser.typemanager.definitions.IDefinition;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class StaticTypesManager implements IEntryTypesManager {
    private Map<String, EntryType> types = new HashMap<>();
    private Map<String, EntryField> fields = new HashMap<>();
    private IDefinition definition;

    public StaticTypesManager(IDefinition definition) {
        this.definition = definition;
        types = definition.getTypes().stream().collect(Collectors.toMap(p -> p.getName(), p -> p));
        fields = definition.getFields().stream().collect(Collectors.toMap(p -> p.getName(), p -> p));
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
        return new ArrayList<>(types.values());
    }

    @Override
    public EntryField getField(String name) {
        return fields.get(name.toLowerCase());
    }

    @Override
    public boolean hasField(String name) {
        return fields.containsKey(name.toLowerCase());
    }
}
