# Function for Hackerrank Arrays: Left Rotation
def rotateLeft(d, arr):
    arr = arr[d:]+arr[:d]
    return arr
    
