import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class CrosswordPuzzle {
    
    private static class Tuple {
        String[] crossWord;
        boolean solved;
        Tuple(char[][] lol, boolean lol1) {
            crossWord = new String[lol.length];
            for(int i = 0; i < lol.length; i++) {
                String str = "";
                for(int j = 0; j < lol[i].length; j++) str += lol[i][j];
                crossWord[i] = str;
            }
            solved = lol1;
        }
    }
    
    // Complete the crosswordPuzzle function below.
    static String[] crosswordPuzzle(String[] crossword, String words) {
        char[][] grid = new char[crossword.length][crossword[0].length()];
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length; j++) {
                grid[i][j] = crossword[i].charAt(j);
            }
        }
        
        Tuple result = solvePuzzle(grid, words.split(";"));
        
        System.out.println(result.solved? "Solved" : "Not solved");
        
        return result.solved? result.crossWord : crossword;

    }
    
    static Tuple solvePuzzle(char[][] grid, String[] words) {
        if(words.length == 0) {
            Tuple result = new Tuple(grid, true);
            return result;
        }
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length; j++) {
                char[][] tempGrid = new char[grid.length][grid[0].length];
                if(wordCanBePlacedHorizontally(grid, i, j, words[0])) {
                    copyGrid(grid, tempGrid);
                    printArray(words);
                    placeWordHorizontally(grid, i, j, words[0]);
                    printGrid(grid);
                    System.out.println("Going in");
                    Tuple result = solvePuzzle(grid, eliminateAt(words, 0));
                    if(result.solved) return result;
                    copyGrid(tempGrid, grid);
                }
                if(wordCanBePlacedVertically(grid, i, j, words[0])) {
                    copyGrid(grid, tempGrid);
                    printArray(words);
                    placeWordVertically(grid, i, j, words[0]);
                    printGrid(grid);
                    System.out.println("Going in");
                    Tuple result = solvePuzzle(grid, eliminateAt(words, 0));
                    if(result.solved) return result;
                    copyGrid(tempGrid, grid);
                }
            }
        }
        System.out.println("Going back");
        return new Tuple(grid, false);
    }
    
    static void printGrid(char[][] grid) {
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length; j++){
                System.out.print(grid[i][j]);
            }
            System.out.println();
        }
    }
    
    static boolean wordCanBePlacedHorizontally(char[][] grid, int rowIndex, int colIndex, String word) {
        int i;
        for(i = 0; i < word.length() && ((colIndex + i) < grid[0].length); i++)     
            if(grid[rowIndex][colIndex + i] != '-' && grid[rowIndex][colIndex+i] != word.charAt(i)) return false;
        return i == word.length();
    }
    
    static boolean wordCanBePlacedVertically(char[][] grid, int rowIndex, int colIndex, String word) {
        int i;
        for(i = 0; i < word.length() && ((rowIndex + i) < grid.length); i++) if(grid[rowIndex  + i][colIndex] != '-' && grid[rowIndex + i][colIndex] != word.charAt(i)) return false;
        return i == word.length();
    }
    
    static void placeWordHorizontally(char[][] grid, int rowIndex, int colIndex, String word) {
        for(int i = 0; i < word.length(); i++) grid[rowIndex][colIndex + i] = word.charAt(i);
    }
    
    static void placeWordVertically(char[][] grid, int rowIndex, int colIndex, String word) {
        for(int i = 0; i < word.length(); i++) grid[rowIndex  + i][colIndex] = word.charAt(i);
    }
    
    static String[] eliminateAt(String[] words, int j) {
        String[] arr = new String[words.length-1];
        int c = 0;
        for(int i = 0; i < words.length; i++) {
            if(i != j) arr[c++] = words[i];
        }
        return arr;
    }
    
    static void printArray(String[] arr) {
        for(int i = 0; i < arr.length; i++) System.out.print(arr[i] + " ");
        System.out.println();
    }
    
    static void copyGrid(char[][] grid, char[][] tempGrid) {
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length; j++) {
                tempGrid[i][j] = grid[i][j];
            }
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] crossword = new String[10];

        for (int i = 0; i < 10; i++) {
            String crosswordItem = scanner.nextLine();
            crossword[i] = crosswordItem;
        }

        String words = scanner.nextLine();

        String[] result = crosswordPuzzle(crossword, words);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(result[i]);

            if (i != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
