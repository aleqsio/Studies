package main;

import org.junit.Test;

import static junit.framework.TestCase.assertEquals;

/**
 * Created by Aleksander on 31.10.2017.
 */
public class TimetableTest {
    @Test
     public void Timetable1PerformsReschedulesCorrectly()
    {
        ITimetable timetable = new Timetable1();
        String[] desc={"d-","t+"};
        Action [] actions = new ActionsParser().parse(desc);

        Lesson l1 = new Lesson(timetable,new Term(8,0,Day.TUE),"Angielski","Nowak",1);
        Lesson l2 = new Lesson(timetable,new Term(9,30,Day.MON),"JTP","Kowalski",3);
        timetable.put(l1);
        timetable.put(l2);
        timetable.perform(actions);
        assertEquals("Timetable1","Angielski (Poniedziałek 8:00-9:30),JTP (Poniedziałek 11:00-12:30)",timetable.toShortString());
    }
    @Test
    public void Timetable2PerformsReschedulesCorrectly()
    {
        ITimetable timetable = new Timetable3();
        String[] desc={"d-","t+"};
        Action [] actions = new ActionsParser().parse(desc);
        Lesson l1 = new Lesson(timetable,new Term(8,0,Day.TUE),"Angielski","Nowak",1);
        Lesson l2 = new Lesson(timetable,new Term(9,30,Day.MON),"JTP","Kowalski",3);
        timetable.put(l1);
        timetable.put(l2);
        System.out.print(timetable.toShortString());
        timetable.perform(actions);
        assertEquals("Timetable2","Angielski (Poniedziałek 8:00-9:30),JTP (Poniedziałek 11:00-12:30)",timetable.toShortString());
    }
}
