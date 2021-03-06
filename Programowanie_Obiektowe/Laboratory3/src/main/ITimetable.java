package main;

/**
 * Created by Aleksander on 24.10.2017.
 */
public interface ITimetable {


    /*************************************/
    /**
     * Informs whether a lesson can be transferred to the given term
     * @param term
     *         The term checked for the transferability
     * @return True if the lesson can be transferred to this term
     */
    boolean canBeTransferredTo(Term term);

    /*************************************/
    /**
     * Returns true if the given term is busy
     *
     * @param term
     *         Checked term
     * @return True if the term is busy
     */
    boolean busy(Term term);

    /*************************************/
    /**
     * Add the given lesson to the timetable
     *
     *
     * @param lesson
    The added  lesson@return True if the lesson was added
     */
    void put(Lesson lesson) throws IllegalArgumentException;

    /*************************************/
    /**
     * Transfer the lessons included in the timetable as described in the list of actions
     */
    void perform(Action [] actions);

    /*************************************/
    /**
     * Get object (lesson) indicated by the given term
     * @param term
     *          The term of the lesson
     * @return Object or null if the term is free
     */
    Object get(Term term);
    String toShortString();
}
