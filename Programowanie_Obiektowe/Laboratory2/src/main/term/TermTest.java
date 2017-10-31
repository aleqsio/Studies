package main.term;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Aleksander on 10.10.2017.
 */
public class TermTest {
@Test
   public void setMinuteValueShouldGiveCorrectValue()
{
    Term t =new Term(0,0);
    t.setMinuteTime(200);
    assertEquals(t.hour,3);
    assertEquals(t.minute,20);
}
    @Test
    public void getMinuteValueShouldGiveCorrectValue()
    {
        Term t =new Term(3,20);
        assertEquals(t.getMinuteTime(),200);
    }
}