package types.definition;

import types.EntryField;
import types.EntryType;
import types.IEntryField;
import types.IEntryType;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by Aleksander on 25.11.2017.
 */
public interface IDefinition {
    Map<IEntryType, Map<IEntryField, FieldProperties>> getDefinition();
    public Map<String, EntryField> getFields();
    public Map<String, EntryType> getTypes();
    default <T1,T2> HashMap<T1, T2> build(Object... data){
        HashMap<T1, T2> result = new HashMap<>();

        if(data.length % 2 != 0)
            throw new IllegalArgumentException("Odd number of arguments");

        T1 key = null;
        Integer step = -1;

        for(Object value : data){
            step++;
            switch(step % 2){
                case 0:
                    key = (T1) value;
                    continue;
                case 1:
                    result.put(key, (T2) value);
                    break;
            }
        }

        return result;
    }

}
