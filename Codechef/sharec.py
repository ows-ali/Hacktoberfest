tc=int(input())
for i in range(tc):
    n=int(input())
    lst=[]
    for sr in range(n):
        st=str(input())
        lst.append(st)  
        #function;
    def common(arr): 
        resut = set(arr[0])  
        for S in arr[1:]: 
            resut.intersection_update(S) 
  
        return list(resut)    
    arr = lst
    opt = common(arr) 
    if len(opt) > 0: 
        
        print(len(opt)) 
    else: 
        print("0")
