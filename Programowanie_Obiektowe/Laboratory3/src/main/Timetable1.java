package main;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

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
    public boolean busy(Term term) {
        return lessons.stream().filter(x -> x.getTerm().getDay()==term.getDay()).filter(x->x.getTerm().getMinuteTime()==term.getMinuteTime()).count()>0;
    }

    @Override
    public boolean put(Lesson lesson) {
        if(canBeTransferredTo(lesson.getTerm())){
            lessons.add(lesson);
            return true;
        }
        return false;
    }

    @Override
    public String toString() {
        return lessons.stream().map(x->x.toString()).collect(Collectors.joining (","));
    }

    @Override
    public void perform(Action[] actions) {
            int pos=0;
        for (Action a:actions
             ) {
            lessons.get(pos).fromAction(a);
        }
    }

    @Override
    public Object get(Term term) {
        return lessons.stream().filter(x -> x.getTerm().getDay()==term.getDay()).filter(x->x.getTerm().getMinuteTime()!=term.getMinuteTime()).findFirst();
    }
}
