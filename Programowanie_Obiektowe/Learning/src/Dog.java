/**
 * Created by Aleksander on 03.10.2017.
 */
public class Dog implements Animal {
    private boolean legs=true;
    private int age;
    private static int count;
    Dog(int age){
        setAge(age);
        setCount(getCount() + 1);
    }

    public static int getCount() {
        return count;
    }

    public static void setCount(int count) {
        Dog.count = count;
    }

    public void bark()
    {
        System.out.print("Woof\n");
    }
    public void walk() throws NoLegsException
    {
        if(!isLegs()){
            throw new NoLegsException();
        }
        System.out.print("Tup tup\n");
    }

    public boolean isLegs() {
        return legs;
    }

    public void setLegs(boolean legs) {
        this.legs = legs;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
