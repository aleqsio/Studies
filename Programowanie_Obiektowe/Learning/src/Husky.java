/**
 * Created by Aleksander on 03.10.2017.
 */
public class Husky extends Dog {
    private static int count;
    Husky(int age){
        super(age);
        setCount(getCount() + 1);
    }

    public static int getCount() {
        return count;
    }

    public static void setCount(int count) {
        Husky.count = count;
    }

    public void bark()
    {
        System.out.print("Woof, i'm a husky\n");
    }
    public void sneeze() {
        System.out.print("Husky sneeze\n");
    }
}
