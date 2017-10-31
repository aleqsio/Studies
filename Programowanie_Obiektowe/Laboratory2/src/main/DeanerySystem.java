package main;

import main.term.Term;

public class DeanerySystem {
    public static void main(String[] args) {
        Term term1 = new Term(9,45);
        System.out.println(term1);
        Term term2 = new Term(10,15);
        System.out.println(term2);
        System.out.println(term1.endTerm(term2)); //'duration' zwróconego obiektu powinna mieć wartość 30
    }
}
