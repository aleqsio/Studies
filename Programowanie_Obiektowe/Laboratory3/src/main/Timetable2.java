package main;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by Aleksander on 31.10.2017.
 */
public class Timetable2 implements ITimetable {
    private final Break[] breaks;
    public Timetable2(Break[] breaks ){
        this.breaks=breaks;
    }
    public boolean skipBreaks;
    List<Lesson> lessons = new ArrayList<>();
    @Override
    public boolean canBeTransferredTo(Term term) {
        return lessons.stream().filter(x -> x.getTerm().getDay()==term.getDay()).filter(x->x.getTerm().getMinuteTime()==term.getMinuteTime()).count()==0;
    }
    @Override
    public Object get(Term term) {

        return lessons.stream().filter(x -> x.getTerm().getDay().equals(term.getDay())).filter(x->x.getTerm().getMinuteTime()==term.getMinuteTime()).findFirst().get();
    }
    @Override
    public boolean busy(Term term) {
        if(!skipBreaks)
        return lessons.stream().filter(x -> x.getTerm().getDay().equals(term.getDay())).filter(x->x.getTerm().getMinuteTime()==term.getMinuteTime()).count()>0;
        else
        return lessons.stream().filter(x -> x.getTerm().getDay().equals(term.getDay())).filter(x->x.getTerm().getMinuteTime()==term.getMinuteTime()).count()+
                Arrays.stream(breaks).filter(x->x.getTerm().getMinuteTime()==term.getMinuteTime()).count()
                >0;

    }

    @Override
    public void put(Lesson lesson) {
        if(canBeTransferredTo(lesson.getTerm())){
            lessons.add(lesson);
        }

    }

    @Override
    public void perform(Action[] actions) {

    }

    @Override
    public String toString() {
        String s=new String();
        Day firstDay = Day.MON;
        Day lastDay = Day.SUN;
        Term cterm;

        for (Day d:Day.values()) {
            s+=(d.toString()+"\n");
            Term firstTerm = new Term(8,0,d);
            Term lastTerm = new Term(20,0,d);

            for(cterm = firstTerm ; cterm.laterThan(lastTerm) ; cterm = cterm.endTerm()) {
                boolean handled = false;
                for (Break b : breaks) {
                    if (b.getTerm().equals(cterm)) {
                        s += "-break-\n";
                        handled = true;
                    }
                }
                if (!handled) {
                    s += (cterm.toString() + "\n");
                    if (busy(cterm))
                        s += (get(cterm).toString() + "\n");
                    else
                        s += ("\n");
                }
            }

        }
        return s;
    }
    @Override
    public String toShortString() {
        return null;
    }
}
