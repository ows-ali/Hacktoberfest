for t in range(int(input())):
    n,m = [int(i) for i in input().split()]
    v = [0 for i in range(n)]
    gr = [1 for i in range(n)]
    vd = dict()
    for i in range(m):
        ver,sec = [int(i) for i in input().split()]
        v[ver-1] += 1
        v[sec-1] += 1
        if ver in vd:
            vd[ver].append(sec)
        else:
            vd[ver] = [sec]
        if sec in vd:
            vd[sec].append(ver)
        else:
            vd[sec] = [ver]

    rem = -1
    for i in range(n):
        if v[i]%2 == 1:
            rem = i
            break
    if m%2 == 0:
        print(1)
    elif rem != -1:
        gr[rem] = 2
        print(2)
    else:
        print(3)
        for i,j in vd.items():
            if len(j) % 2 == 0:
                gr[i - 1] = 2
                gr[vd[i][0] - 1] = 3
                break


    print(*gr,sep=" ")

