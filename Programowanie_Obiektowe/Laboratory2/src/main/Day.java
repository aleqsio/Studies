package main;

/**
 * Created by Aleksander on 09.10.2017.
 */
public enum Day {
    MON,TUE,WED,THU,FRI,SAT,SUN;
    public String toString(){
    String[] days = {"Poniedziałek","Wtorek","Sroda","Czwartek","Piatek","Sobota","Niedziela"};
    return days[this.ordinal()];
    }
    public Day nextDay(){
        return Day.values()[(this.ordinal()+1)%7];
    }
    public Day prevDay(){  return Day.values()[(this.ordinal()+6)%7]; }
}
