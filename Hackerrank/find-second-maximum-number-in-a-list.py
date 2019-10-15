#Given the participants' score sheet for your University Sports Day, you are required to find the runner-up score. You are given n scores. Store them in a list and find the score of the runner-up. 
#Use Python2
if __name__ == '__main__':
    n = int(raw_input())
    arr = map(int, raw_input().split())
    for i in (sorted(arr)[::-1]):
        if i < (sorted(arr)[-1]):
            print i
            break