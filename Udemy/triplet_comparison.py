def compareTriplets(a, b):
    alice_points = 0
    bob_points = 0
    for i in range(3):
        if a[i] > b[i]:
            alice_points += 1
        elif a[i] < b[i]:
            bob_points += 1
    return (alice_points, bob_points)

# Input handling
a = list(map(int, input().split()))
b = list(map(int, input().split()))

# Output the result
result = compareTriplets(a, b)
print(result[0], result[1])
