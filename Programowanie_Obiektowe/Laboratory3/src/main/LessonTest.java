package main;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Aleksander on 17.10.2017.
 */
public class LessonTest {
    @Test
    public void toStringTest() throws Exception {
        Lesson lesson = new Lesson(new Term(9,35,Day.TUE),"Programowanie w języku Ruby","Stanisław Polak",2);
        assertEquals(lesson.toString(),"Programowanie w języku Ruby (Wtorek 9:35-11:05)");

    }

}