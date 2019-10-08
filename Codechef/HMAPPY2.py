def gcd(a,b): 
    if (b == 0): 
         return a 
    return gcd(b, a%b) 

def probSolver(N, A, B, K):
    lcm = (A*B)/gcd(A, B)
    arr = [x for x in range(N) if x%(lcm) != 0]
    count = 0
    for itr in arr:
        if itr%A == 0:
            count+=1
        if itr%B == 0:
            count+=1
    
    if count >= K:
        return "win"
    else:
        return "lose"


if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        line = input().split(" ")
        N = int(line[0])
        A = int(line[1])
        B = int(line[2])
        K = int(line[3])

        result = probSolver(N, A, B, K)

        print(result)