    from math import *
    from builtins import staticmethod
    from collections import Counter
    from collections import defaultdict
    from collections import namedtuple
    from collections import deque
    from queue import LifoQueue
    import heapq
    import functools
    import hashlib
    from datetime import datetime, timedelta
    import json
    import re
    from itertools import *
    import queue


    def solve(n, a):
        a.sort()
        prev_count, cnt, res_min = 0, 1, a[0]
        for i in range(1, n):
            if a[i] == res_min + 1 or a[i] == res_min:
                cnt += 1
            elif prev_count <= cnt:
                prev_count = cnt
                res_min = a[i]
                cnt = 1
        if prev_count == 0:
            return cnt
        return prev_count


    def main():
        n = int(input())
        a = list(map(int, input().split()))
        print(solve(n, a))


    if __name__ == '__main__':
        main()

    0|
    Add CommentPermalink

    yedinzon
    6 days ago

    C# Solution

    public static int pickingNumbers(List<int> a)
    {
        int maxSubArray = 0, maxTemp = 0;
        a.Sort();

        do
        {
            findMaxArray(a);            
            if(maxSubArray < maxTemp) maxSubArray = maxTemp;                
            a.RemoveAt(0);        
        }while(a.Count() > maxSubArray);        

        void findMaxArray(List<int> list)
        {      
            maxTemp = 0;            
            foreach(int num in list)
            {                
                if(num - list[0] > 1) break;                                    
                maxTemp++;
            }           
        }    

        return maxSubArray;       
    }
