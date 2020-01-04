class Difference:
    def __init__(self, a):
        self.__elements = a
        self.maximumDifference = -1

    def computeDifference(self):
        lowest = self.__elements[0]
        highest = self.__elements[0]
        for i in self.__elements:
            if i<lowest:
                lowest = i
            elif i>highest:
                highest = i

        self.maximumDifference = highest - lowest
    



# End of Difference class

_ = input()
a = [int(e) for e in input().split(' ')]

d = Difference(a)
d.computeDifference()

print(d.maximumDifference)
