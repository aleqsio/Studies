package main;

import java.util.ArrayList;

/**
 * Created by Aleksander on 17.10.2017.
 */
public class ActionsParser {
    public static Action[] parse(String[] descriptions){
        ArrayList<Action> actions = new ArrayList<>();
        for (String desc:descriptions
             ) {
            switch  (desc){
                case "d-":
                    actions.add(Action.DAY_EARLIER);
                    break;
                case "d+":
                    actions.add(Action.DAY_LATER);
                    break;
                case "t-":
                    actions.add(Action.TIME_EARLIER);
                    break;
                case "t+":
                    actions.add(Action.TIME_LATER);
                    break;
                default:
                    break;
            }
        }
        return actions.toArray(new Action[actions.size()]);
    }
}
