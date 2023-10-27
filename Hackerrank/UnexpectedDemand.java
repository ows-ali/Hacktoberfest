package ProblemSolvingBasic;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/*A widget manufacturer is facing unexpectedly high demand for its new product.
They would like to satisfy as many customers as possible. Given a number of widgets
 available and a list of customer orders, what is the maximum number of orders the
 manufacturer can fulfill in full?*/

public class UnexpectedDemand {
    public static void main(String[] args) {
        System.out.println("Unexpected Demand!");

        List<Integer> orders = Arrays.asList(5, 2, 4);

        Collections.sort(orders);

        int widgets = 3;
        int counter = 0;

        for (Integer order : orders) {
            if (order <= widgets) {
                widgets -= order;
                counter++;
            } else {
                break;
            }
        }

        System.out.println("Successful Filled Orders   --->   " + counter);
    }
}