# Problem Link: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

# Complete the climbingLeaderboard function below.
def climbingLeaderboard(scores, alice):

    def binsrch(scores,num):
        """
        A binary search function that searches for a particular score in the scores
        array, and returns a tuple containing the possible location of the scores
        in the list and a boolean to show if the score existed in the list.

        Parameters
        -------------------------------
        scores: list[int]
            list of scores
        num: int
            integer to be searched in the scores list

        Returns
        --------------------------------
        (pos,isFound): (int,bool)
            a tuple containing the (possilbe) position of num in the scores array
            and a boolean to indicate if the score was found in the array.

        """
        start = 0
        end = len(scores)-1

        while start<=end:
            mid = start + int((end-start)/2)

            if scores[mid]>num:
                start = mid+1
            elif scores[mid]<num:
                end = mid-1
            elif scores[mid]==num:
                return (mid,True)

        if start<len(scores) and num<scores[start]:
            return (start+1,False)
        else:
            return (start-1,False)

    # Create position and found array to indicate, position of alices score in the
    # scores array, and a boolean array to indicate if they were already present in
    # the scores array or not.
    position = []
    found = []
    for score in alice:
        pos,isFound = binsrch(scores,score)
        position.append(pos)
        found.append(isFound)

    # Creating a rank array for scores, which indicates the rank for each entry
    # in the scores array
    rank = 1
    rank_arr = [0]*len(scores)
    rank_arr[0] = 1

    for i in range(1,len(scores)):
        if scores[i]==scores[i-1]:
            rank_arr[i]=rank_arr[i-1]
        else:
            rank+=1
            rank_arr[i] = rank

            
    res = []
    for i,pos in enumerate(position):
        if pos==-1:
            res.append(1)
        elif found[i]:
            res.append(rank_arr[pos])
        else:
            res.append(rank_arr[pos]+1)

    return(res)



if __name__ == '__main__':

    scores = list(map(int, input().rstrip().split()))

    alice = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(scores, alice)

    # Sample Input :
    # 100 100 50 40 40 20 10
    # 5 25 50 120
    # Sample Output:
    # [6,4,2,1]
    print(result)
