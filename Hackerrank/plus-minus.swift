// https://www.hackerrank.com/challenges/plus-minus/problem

import Foundation

// Complete the plusMinus function below.
func plusMinus(arr: [Int]) -> Void {

    let precisionOrder = 6
    let length = Double(arr.count)

    var positiveCount = 0.0
    var negativeCount = 0.0
    var zeroCount = 0.0

    for i in arr {
        if i == 0 {
            zeroCount += 1
        }
        else if i > 0 {
            positiveCount += 1
        }
        else {
            negativeCount += 1
        }
    }

    let positiveFrac = makePrecise(for: positiveCount, with: precisionOrder) / length
    let negativeFrac = makePrecise(for: negativeCount, with: precisionOrder) / length
    let zeroFrac = makePrecise(for: zeroCount, with: precisionOrder) / length

    print(positiveFrac)
    print(negativeFrac)
    print(zeroFrac)
}


func makePrecise(for num: Double, with order: Int) -> Double {
    
    var precisionOrder = Double(truncating: NSDecimalNumber(decimal: pow(10, order)))
    let precisedNum = round((num * precisionOrder)) / precisionOrder

    return precisedNum
}


guard let n = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

guard let arrTemp = readLine() else { fatalError("Bad input") }
let arr: [Int] = arrTemp.split(separator: " ").map {
    if let arrItem = Int($0.trimmingCharacters(in: .whitespacesAndNewlines)) {
        return arrItem
    } else { fatalError("Bad input") }
}

guard arr.count == n else { fatalError("Bad input") }

plusMinus(arr: arr)
