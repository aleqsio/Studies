package main;

/**
 * Created by Aleksander on 09.10.2017.
 */
public class Term implements ITerm{
    private int hour;
    private int minute;
    private int duration;

    public Day getDay() {
        return day;
    }

    public void setDay(Day day) {
        this.day = day;
    }

    private Day day;


    public Term(int hour, int minute, Day day){
        this.day = day;
        this.hour=hour;
        this.minute=minute;
        this.duration=90;
    }
    public Term(int hour, int minute){
        this.hour=hour;
        this.minute=minute;
        this.duration=90;
    }
    public Term(Term t){
        this.hour=t.hour;
        this.minute=t.minute;
        this.duration=t.duration;
        this.day=t.day;
    }
    public String toString(){
        return String.format("%d:%02d [%d]",hour, minute, duration);
    }

    public String toShortString(){
        return String.format("%d:%02d",hour, minute);
    }
    public boolean earlierThan(Term t){
        return this.getMinuteTime() < t.getMinuteTime();
    }
    public boolean laterThan(Term t){
        return this.getMinuteTime() > t.getMinuteTime();
    }
    public Term endTerm(Term endTerm) throws IllegalArgumentException{
        Term newTerm = new Term(this);
        int newDuration = (endTerm.getMinuteTime()-this.getMinuteTime());
                if(newDuration<0) {
                    throw new IllegalArgumentException("End time can not precede the event");
                }
        newTerm.duration=newDuration;
        return newTerm;
    }
    public Term endTerm(){
        Term newTerm = new Term(this);
        newTerm.setMinuteTime(this.getMinuteTime()+this.duration);
        return newTerm;
    }

    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null) return false;
        return this.getClass() == obj.getClass() && this.duration == ((Term) obj).duration && this.getMinuteTime() == ((Term) obj).getMinuteTime();
    }
    int getMinuteTime(){
        return this.hour*60+this.minute;
    }
    void setMinuteTime(int minuteTime){
        this.minute=minuteTime%60;
        this.hour=minuteTime/60;
    }

}
