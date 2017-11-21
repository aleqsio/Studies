package main;

/**
 * Created by Aleksander on 31.10.2017.
 */
public class Break {
    private Term term;
    public Break(Term term){
        this.term=term;
    }

    @Override
    public String toString() {
        return "Przerwa";
    }
    public Term getTerm(){
        return term;
    }
}
