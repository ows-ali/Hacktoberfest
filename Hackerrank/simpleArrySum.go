// Go program to sum array of integers
package main

import (
	"bufio"
	"fmt"
	"os"
	"encoding/json"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Please enter an array of numbers EG: [11, 14, 16] ")
	fmt.Println("---------------------")
	nums, err := reader.ReadString('\n')
	if err != nil {
		fmt.Printf("Error: %+v", err)
		return
	}
	var intNum []int
	err = json.Unmarshal([]byte(nums), &intNum)
	if err != nil {
		fmt.Printf("Please enter the array of numbers Eg: [10, 12, 34]Error: %+v", err)
		return
	}
	fmt.Printf("The sum of numbers is %d", sumNumber(intNum))

}
func sumNumber(nums []int) int {
	sum := 0
	for _, num := range nums {
		sum += num
	}
	return sum
}
