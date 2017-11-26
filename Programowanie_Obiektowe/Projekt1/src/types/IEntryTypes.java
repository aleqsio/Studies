package types;

import com.JBibtexParser.util.ParseErrorException;
import types.definition.FieldProperties;
import types.definition.IDefinition;

import java.util.List;
import java.util.Map;

/**
 * Created by Aleksander on 25.11.2017.
 */
public interface IEntryTypes {
    EntryType getType(String name);

    boolean hasType(String name);

    List<EntryType> getAllTypes();

    EntryField getField(String name);

    boolean hasField(String name);

    default boolean isEntryCorrect(IEntryType entryType, Map<IEntryField, String> fields, IDefinition definition, Verification verificationMode) throws ParseErrorException {
        boolean verificationAllowed = true;
        boolean verificationRequired = true;
        if (verificationMode == Verification.VERIFY_ONLY_ALLOWED || verificationMode == Verification.FULL_VERIFY) {
            for (IEntryField field : fields.keySet()) {
                if(!definition.getDefinition().containsKey(entryType)) throw new ParseErrorException("This entry has no key in the provided definition: " + entryType.getName()+":"+field.getName());
                FieldProperties property = definition.getDefinition().get(entryType).get(field);
                if (property == FieldProperties.NONE) verificationAllowed = false;
            }
        }
        if (verificationMode == Verification.VERIFY_ONLY_REQUIRED || verificationMode == Verification.FULL_VERIFY) {
            for (IEntryField field : definition.getDefinition().get(entryType).keySet()) {
                if (!fields.containsKey(field) && definition.getDefinition().get(entryType).get(field) == FieldProperties.NONE)
                    verificationRequired = false;
            }
        }
        switch (verificationMode) {
            case NO_VERIFICTION:
                return true;
            case FULL_VERIFY:
                return verificationAllowed && verificationRequired;
            case VERIFY_ONLY_ALLOWED:
                return verificationAllowed;
            case VERIFY_ONLY_REQUIRED:
                return verificationRequired;
        }
return false;
    }
}

