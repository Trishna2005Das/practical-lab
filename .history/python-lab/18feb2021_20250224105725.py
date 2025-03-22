#write a program to show the details of the student entities using class and object
#wap to show the details about an employee that is working in an mnc-id name age yoe ctc 
#wap to show the details about a faculty of a uni emp id age sub yoe 

# import math
# #wap to find gcd and lcm of two given numbers
# a=int(input("enter number"))
# b=int(input("enter number"))
# print(math.gcd(a,b))
# print(math.lcm(a,b))
#marks of 5 students using class 
class marks:
    def get(self):
        self.lst=[]
        for i in range(5):
            self.lst.append(int(input("enter number")))
    def average(self)-> int :
        return sum(self.lst)
obj= marks()
obj.get()
print(obj.lst)
print(obj.average())

class student:
    def about(self):
        self.name=int(input("enter number"))
        self.rollno=int(input("enter number"))
        self.marks=int(input("enter number"))
obj=student()

#wap to show the deatils about an employee that is working in an mnc-id name age yoe ctc 

class emp:
    def about(self):
        self.id=int(input("enter number"))
        self.name=input("enter name")
        self.age=int(input("enter number"))
        self.yoe=int(input("enter number"))
        self.ctc=int(input("enter number"))
obj=emp()
obj.about()
print(obj.id)
print(obj.name)
print(obj.age)
print(obj.yoe)
print(obj.ctc)

class uni:
    def about(self):
        self.id=int(input("enter number"))
        self.name=input("enter name")
        self.age=int(input("enter number"))
        self.yoe=int(input("enter number"))
        self.sub=int(input("enter number"))
obj=uni()
obj.about()
print(obj.id)
print(obj.name)
print(obj.age)
print(obj.yoe)
print(obj.sub)

#wap to shopping cart include methods for adding and removing items and calculating the total price 

class shopping:
    def __init__(self):
        self.lst=[]
    def add(self,item):
        self.lst.append(item)
    def remove(self,item):
        self.lst.remove(item)
obj=shopping()


#wap class representing circle and include methods to calculate its area
class circle:
    def getdata(self,r):
        self.r=r
    def area(self):
        return 3.14*self.r*self.r
obj=circle()
obj.getdata(5)

#wap to implement the concept of inheritence with th below problem statement
#implement inehritance with disney hotstar substription that contains entities like usename password no of devices no if screens screenshare.the child class contains some specicfic entities like live match broadcasting ,premeire show ,,exclusive release time of first day of the web series. when one user is watching the live match broadcasting with one devices then the live match wont run in any other devices. if two devices the premeire show at the same time they cannot do it with same isp. first day and first show of the web series is exclusive to the first owner of the ott subscription which must be cast on his devices with one screen no screenshare is possible on 

#    implement digital hostel subsbription  
# when one devices is watching then no other device log in .if tryin gthen all the devices log out