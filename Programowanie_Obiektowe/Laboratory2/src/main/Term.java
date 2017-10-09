package main;

/**
 * Created by Aleksander on 09.10.2017.
 */
public class Term {
    public int hour;
    public int minute;
    public int duration;

    public Term(int hour, int minute){
        this.hour=hour;
        this.minute=minute;
        this.duration=90;
    }
    public Term(Term t){
        this.hour=t.hour;
        this.minute=t.minute;
        this.duration=t.duration;
    }
    public String toString(){
        return String.format("%d:%2d [%d]",hour, minute, duration);
    }
    public boolean earlierThan(Term t){
        return this.getMinuteTime() < t.getMinuteTime();
    }
    public boolean laterThan(Term t){
        return this.getMinuteTime() > t.getMinuteTime();
    }
    public Term endTerm(Term endTerm){
        Term newTerm = new Term(this);
        newTerm.duration=(endTerm.getMinuteTime()-this.getMinuteTime());
        return newTerm;
    }
    public Term endTerm(){
        Term newTerm = new Term(this);
        newTerm.setMinuteTime(this.getMinuteTime()+this.duration);
        return newTerm;
    }
    public boolean equals(Object obj){
        if (this == obj) return true;
        if (obj == null) return false;
        if (this.getClass() != obj.getClass()) return false;
        return this.duration==((Term)obj).duration && this.getMinuteTime()==((Term)obj).getMinuteTime();
    }
    private int getMinuteTime(){
        return this.hour*60+this.minute;
    }
    private void setMinuteTime(int minuteTime){
        this.minute=minuteTime%60;
        this.hour=minuteTime/60;
    }
}
