/*Tower of Hanoi

Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. 
The objective of the puzzle is to move all disks from source rod to destination rod using 
third rod (say auxiliary). The rules are :
1) Only one disk can be moved at a time.
2) A disk can be moved only if it is on the top of a rod.
3) No disk can be placed on the top of a smaller disk.
Print the steps required to move n disks from source rod to destination rod.
Source Rod is named as 'a', auxiliary rod as 'b' and destination rod as 'c'.
Input Format :
Integer n
Output Format :
Steps in different lines (in one line print source and destination rod name separated by space)
Sample Input :
2
Sample Output :
a b
a c
b c
*/


public class solution {

	public static void towerOfHanoi(int disks, char source, char auxiliary, char destination) {
		// Write your code here
if (disks == 1) {
          System.out.println(source + " " + destination);
  //return disks;
       } else {
          towerOfHanoi (disks - 1,source ,destination , auxiliary);
           System.out.println(source + " " +destination );
          towerOfHanoi (disks - 1, auxiliary, source,destination );
       }
	}
}
