//https://www.hackerrank.com/challenges/permutation-equation

func permutationEquation(p: [Int]) -> [Int] {

    var array: [Int] = []
    for i in 1...p.count {
        let number = (p.firstIndex(of: i) ?? 0) + 1
        let pos = (p.firstIndex(of: number) ?? 0) + 1
        array.append(pos)
    }
    return array
}
