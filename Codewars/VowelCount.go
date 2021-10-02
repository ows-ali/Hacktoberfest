//Problem URL: https://www.codewars.com/kata/54ff3102c1bad923760001f3/train/go
//Difficulty: 7 Kata

package kata

func GetCount(str string) (count int) {
  // Enter solution here
  count = 0;
  for _, letter := range str {
    if string(letter)=="a" || string(letter)=="e" || string(letter)=="i" || string(letter)=="u" || string(letter)=="o" {
      count++;
    }
  }
  return count
}
