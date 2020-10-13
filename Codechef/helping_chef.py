try:
    t=int(input(''))
    while t>0:
        n=int(input(''))
        if n<10:
         print('What an obedient servant you are!')
        else:
         print('-1')
        t=t-1
except Exception as e:
    pass
