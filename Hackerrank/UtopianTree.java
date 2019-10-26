// https://www.hackerrank.com/challenges/utopian-tree/
public class UtopianTree {

  static int utopianTree(int n) {

    int height = 1;
    for (int i = 1; i <= n; i++) {

      if (i % 2 == 0) {
        height += 1;
      } else {
        height *= 2;
      }
    }
    return height;
  }

}