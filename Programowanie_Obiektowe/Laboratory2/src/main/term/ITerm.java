package main.term;

/**
 * Created by Aleksander on 09.10.2017.
 */
public interface ITerm {
        public String toString();
        public boolean earlierThan(Term t);
        public boolean laterThan(Term t);
        public Term endTerm(Term endTerm) throws IllegalArgumentException;
        public Term endTerm();
        public boolean equals(Object obj);
}
