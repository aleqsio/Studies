package types;

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
}
