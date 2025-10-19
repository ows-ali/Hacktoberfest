import java.io.*;
import java.util.*;

class Singleton {
    public static Singleton instance = null;
    public String str;

    private Singleton() {}

    public static Singleton getSingleInstance() {
        if (instance == null) {
            instance = new Singleton();
        }
        return instance;
    }
}

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();

        Singleton s = Singleton.getSingleInstance();
        s.str = input;

        System.out.println("Hello I am a singleton! Let me say " + s.str + " to you");
    }
}