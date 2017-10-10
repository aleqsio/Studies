package test;

import main.Day;
import main.Term;
import org.junit.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Created by Aleksander on 09.10.2017.
 */
public class DeanerySystemTest {
    @Test
    public void nextDayShouldReturnTheCorrectValue(){
        assertEquals(Day.MON.nextDay(),Day.TUE);
        assertEquals(Day.TUE.nextDay(),Day.WED);
        assertEquals(Day.WED.nextDay(),Day.THU);
        assertEquals(Day.THU.nextDay(),Day.FRI);
        assertEquals(Day.FRI.nextDay(),Day.SAT);
        assertEquals(Day.SAT.nextDay(),Day.SUN);
        assertEquals(Day.SUN.nextDay(),Day.MON);
    }
    @Test
    public void prevDayShouldReturnTheCorrectValue(){
        assertEquals(Day.MON.prevDay(),Day.SUN);
        assertEquals(Day.TUE.prevDay(),Day.MON);
        assertEquals(Day.WED.prevDay(),Day.TUE);
        assertEquals(Day.THU.prevDay(),Day.WED);
        assertEquals(Day.FRI.prevDay(),Day.THU);
        assertEquals(Day.SAT.prevDay(),Day.FRI);
        assertEquals(Day.SUN.prevDay(),Day.SAT);
    }
    @Test
    public void toStringShouldReturnTheCorrectValue(){
        Term t1=new Term(12,30);
        assertEquals(t1.toString(),"12:30 [90]");
        Term t2=new Term(13,50);
        assertEquals(t2.toString(),"13:50 [90]");
    }
    @Test
    public void endTermShouldReturnTheCorrectValue(){
        Term t1=new Term(12,30);
        Term t2=new Term(13,50);
        Term t3=t1.endTerm(t2);
        assertEquals(t3.toString(),"12:30 [80]");
    }
    @Test(expected = IllegalArgumentException.class)
    public void endTermShouldThrowExceptionOnPrecedingEvent(){
        Term t1=new Term(12,30);
        Term t2=new Term(11,50);
        Term t3=t1.endTerm(t2);
    }
    @Test
    public void earlierThanShouldReturnTheCorrectValue(){
        Term t1=new Term(12,30);
        Term t2=new Term(13,50);
        assertEquals(t1.earlierThan(t2),true);
        assertEquals(t2.earlierThan(t1),false);
        Term t3=new Term(12,30);
        Term t4=new Term(12,30);
        assertEquals(t3.earlierThan(t4),false);
        Term t5=new Term(0,0);
        Term t6=new Term(0,1);
        assertEquals(t5.earlierThan(t6),true);
    }
    @Test
    public void laterThanShouldReturnTheCorrectValue(){
        Term t1=new Term(12,30);
        Term t2=new Term(13,50);
        assertEquals(t1.laterThan(t2),false);
        assertEquals(t2.laterThan(t1),true);
        Term t3=new Term(12,30);
        Term t4=new Term(12,30);
        assertEquals(t3.laterThan(t4),false);
        Term t5=new Term(0,0);
        Term t6=new Term(0,1);
        assertEquals(t5.laterThan(t6),false);
    }
}