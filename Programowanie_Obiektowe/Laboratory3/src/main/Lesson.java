package main;

/**
 * Created by Aleksander on 17.10.2017.
 */
public class Lesson {
    public Term getTerm() {
        return term;
    }

    public void setTerm(Term term) {
        this.term = term;
    }

    private Term term;
    private String name;
    private String teacherName;
    private int year;
    private boolean full_time=true;
    private ITimetable timetable;

    public Lesson(Term term, String name, String teacherName, int year) {
        this.term = term;
        this.name = name;
        this.teacherName = teacherName;
        this.year = year;
    }
    public Lesson(ITimetable timetable, Term term, String name, String teacherName, int year)
    {
        this.timetable=timetable;
        this.term=term;
        this.name=name;
        this.teacherName=teacherName;
        this.year=year;
    }
    @Override
    public String toString() {
        return String.format("%s (%s %s-%s)", name, term.getDay().toString(), term.toShortString(), term.endTerm().toShortString());
    }

    public boolean earlierDay() {
        Term newTerm = new Term(term);
        newTerm.setDay(newTerm.getDay().prevDay());
        if (timetable.canBeTransferredTo(newTerm)) {
            this.term = newTerm;
            return true;
        } else {
            return false;
        }
    }

    public boolean laterDay() {
        Term newTerm = new Term(term);
        newTerm.setDay(newTerm.getDay().nextDay());
        if (timetable.canBeTransferredTo(newTerm)) {
            this.term = newTerm;
            return true;
        } else {
            return false;
        }
    }

    public boolean earlierTime() {
        Term newTerm = new Term(term);
        newTerm.setMinuteTime(term.getMinuteTime() - 90);
        if (timetable.canBeTransferredTo(newTerm)) {
            this.term = newTerm;
            return true;
        } else {
            return false;
        }
    }

    public boolean laterTime() {
        Term newTerm = new Term(term);
        newTerm.setMinuteTime(term.getMinuteTime() + 90);
        if (timetable.canBeTransferredTo(newTerm)) {
            this.term = newTerm;
            return true;
        } else {
            return false;
        }
    }
    public void fromActions(Action[] actions){
        for (Action a:actions
             ) {
           fromAction(a);
            }
        }

    private boolean isCorrect(Term t) {
        if (((t.getMinuteTime()-8*60) % 90) != 0) return false;

        if (full_time) {
            if (t.getDay().ordinal() < 4) {
                if (t.getMinuteTime() < 8 * 60) return false;
                if (t.endTerm().getMinuteTime() > 20 * 60) return false;
            }
            if (t.getDay().ordinal() == 4) {
                if (t.getMinuteTime() < 8 * 60) return false;
                if (t.endTerm().getMinuteTime() > 17 * 60) return false;
            }
            if (t.getDay().ordinal() > 4) return false;
        } else {
            if (t.getDay().ordinal() > 4) {
                if (t.getMinuteTime() < 8 * 60) return false;
                if (t.endTerm().getMinuteTime() > 20 * 60) return false;
            }
            if (t.getDay().ordinal() == 4) {
                if (t.getMinuteTime() < 17 * 60) return false;
                if (t.endTerm().getMinuteTime() > 20 * 60) return false;
            }
        }

        return true;
    }

    public void fromAction(Action a) {
        switch (a){
            case DAY_EARLIER:earlierDay();
                break;
            case DAY_LATER:laterDay();
                break;
            case TIME_LATER:laterTime();
                break;
            case TIME_EARLIER:earlierTime();
        }
    }
}
