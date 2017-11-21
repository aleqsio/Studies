package main;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by Aleksander on 24.10.2017.
 */
public class Timetable1 implements ITimetable {
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
        return lessons.stream().filter(x -> x.getTerm().getDay().equals(term.getDay())).filter(x->x.getTerm().getMinuteTime()==term.getMinuteTime()).count()>0;
    }

    @Override
    public void put(Lesson lesson) throws IllegalArgumentException {
        if (canBeTransferredTo(lesson.getTerm())) {
            lessons.add(lesson);
        } else {
            throw new IllegalArgumentException("Term " + lesson.getTerm() + " is occupied");
        }
    }
    @Override
    public String toString() {
        String s=new String();
        Day firstDay = Day.MON;
        Day lastDay = Day.SUN;
        Term term;

        for (Day d:Day.values()) {
            s+=(d.toString()+"\n");
            Term firstTerm = new Term(8,0,d);
            Term lastTerm = new Term(20,0,d);
            for(term = firstTerm ; term.laterThan(lastTerm) ; term = term.endTerm()){
                s+=(term.toString()+"\n");
                if(busy(term))
                    s+=(get(term).toString()+"\n");
                else
                    s+=("\n");
            }
        }
        return s;
    }
    public String toShortString(){
        return lessons.stream().map(x->x.toString()).collect(Collectors.joining (","));
    }
    @Override
    public void perform(Action[] actions) {
            int pos=0;
        for (Action a:actions
             ) {
            lessons.get(pos%actions.length).fromAction(a);
            pos++;
        }
    }


}
