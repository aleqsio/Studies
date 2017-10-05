public class Main {

    public static void main(String[] args){
        Dog myDog = new Dog(15);
            myDog.bark();
           tryWalk(myDog);
        Husky myHusky = new Husky(10);
        myHusky.bark();
        myHusky.sneeze();
        tryWalk(myHusky);
        Husky cripledHusky = new Husky(10);
        cripledHusky.setLegs(false);
        cripledHusky.bark();
        cripledHusky.sneeze();
        tryWalk(cripledHusky);
        System.out.print(Husky.getCount() +":"+ Dog.getCount());
    }
    static void tryWalk(Dog d){
        try{
            d.walk();
        }catch (NoLegsException e){
            System.out.print("No legs!");
        }
    }
}
