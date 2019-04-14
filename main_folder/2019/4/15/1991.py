class FourCal:
     def setdata(self, first, second):
         self.first = first
         self.second = second
     def sum(self):
         result = self.first + self.second
         return result
     def mul(self):
         result = self.first * self.second
         return result
     def sub(self):
         result = self.first - self.second
         return result
     def div(self):
         result = self.first / self.second
         return result
class q(FourCal):
    pass
a=q()
b=q()
a.setdata(4,2)
b.setdata(3,7)
print(a.sum())
print(b.sum())
print(a.div())
print(b.div())
