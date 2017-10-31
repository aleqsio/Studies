package main;

public class DeanerySystem {
    public static void main(String[] args) {
     /*   Term term1 = new Term(9,45);
        System.out.println(term1);
        Term term2 = new Term(10,15);
        System.out.println(term2);
        System.out.println(term1.endTerm(term2)); //'duration' zwróconego obiektu powinna mieć wartość 30
     */
        String[] desc={"d-","t+"};
        Action [] actions = new ActionsParser().parse(desc);
        ITimetable timetable = new Timetable1();
        Lesson l1 = new Lesson(timetable,new Term(8,0,Day.TUE),"Angielski","Nowak",1);
        Lesson l2 = new Lesson(timetable,new Term(9,30,Day.MON),"JTP","Kowalski",3);
        timetable.put(l1);
        timetable.put(l2);
        System.out.println(timetable.toString());

        timetable.perform(actions);
        System.out.println(timetable.toString());

    }
}
