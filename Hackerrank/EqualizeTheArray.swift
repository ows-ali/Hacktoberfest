//https://www.hackerrank.com/challenges/equality-in-a-array/problem

func equalizeArray(arr: [Int]) -> Int {

    var countedSet = NSCountedSet()
    
    for number in arr {
        countedSet.add(number)
    }
    
    var max = 0
    var mostRepeated = 0
    for number in countedSet {
        if countedSet.count(for: number) > max {
            max = countedSet.count(for: number)
            mostRepeated = number as! Int
        }
    }
    
    let finalArray = arr.filter { $0 == mostRepeated }
    
    return arr.count - finalArray.count
}
