import java.util.*;
import java.io.*;
import java.math.*;

/**
 * A Codingame Java puzzle where the program moves Thor around a map 
 **/
class Player {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int lightX = in.nextInt(); // the X position of the light of power
        int lightY = in.nextInt(); // the Y position of the light of power
        int initialTX = in.nextInt(); // Thor's starting X position
        int initialTY = in.nextInt(); // Thor's starting Y position

        // game loop
        while (true) {
            int remainingTurns = in.nextInt(); // The remaining amount of turns Thor can move. Do not remove this line.

            // Write an action using System.out.println()
            // To debug: System.err.println("Debug messages...");
            
            String directionX = "";
            String directionY = "";
            
            
                if (initialTX < lightX)
                {
                    directionX = "E";
                    initialTX = initialTX + 1;
                }       
            
                else if (initialTX > lightX)
                {
                    directionX = "W";
                    initialTX = initialTX - 1;
                }
            
    
            
                if (initialTY < lightY)
                {
                    directionY = "S";
                    initialTY = initialTY + 1;
                }
                else if (initialTY > lightY)
                {
                    directionY = "N";
                    initialTY = initialTY - 1;
                } 
            
            



            // A single line providing the move to be made: N NE E SE S SW W or NW
            System.out.println(directionY + directionX);
        }
    }
}
