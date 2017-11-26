package types;

/**
 * Created by Aleksander on 25.11.2017.
 */
public interface IEntryType {
    String getName();
    boolean equals(Object other);
    int hashCode();
}
