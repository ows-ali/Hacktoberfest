class Difference:
    def __init__(self, a):
        self.__elements = a
    
    def computeDifference(self):
        self.dv=[]
        self.__elements=sorted(self.__elements)
        self.maximumDifference=abs(self.__elements[len(self.__elements)-1]-self.__elements[0])
    
        

# End of Difference class

_ = input()
a = [int(e) for e in input().split(' ')]

d = Difference(a)
d.computeDifference()

print(d.maximumDifference)