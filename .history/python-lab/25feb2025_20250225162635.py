# 1)wap to implement inheritance of the parent class animal which has 3 child class dog,cat and panther.Each child class must have a specific unique characters
# #2)wap of inheritance of poarent class system which has child class chips,that contains variable budget amount systems which range from 100 dollar to 1500 dollar
# #Range 1 system is of the range:100-1500 dollar(which is defined as expensive system)
# #Range 2 is of the range 500-100 dollar(i.e of the perfect system)
# #Rest system of the are of the Range 3(which is of the )Take input from the user with system name,processor type.Store each system with its proper range system in 3 different list 
# #3)Wap of the parent class vehicle ehich contains multiple child class that is child 1(sports car),child 2 (heavy weight vehiicle),child 3(luxuries car)
# #which is derived from the parent class when the speed of each car(speed ranges from 50-150KM/HR and engine capacity ranges from 1000-5000 gigahertz with fuel capacity 50 litre to
# #1K litre).If a car exceeds speed limit pf 120 ,then it categorises sports ,under 120 but abive 90 is categorized luxurious and rest are under heavy weight.
# #When the speed increases the fuel capacity decreases and the engine power is as the speed.

# 1)wap to implement inheritance of the parent class animal which has 3 child class dog,cat and panther.Each child class must have a specific unique characters
class animal:
    def __init__(self):
        self.name=""
        self.color=""
        self.species=""
class dog(animal):
    def __init__(self):
        super().__init__(self)
        self.breed=""
class cat(animal):
    def __init__(self):
        super.__init__(self)
        self.breed=""
class panther(animal):
    def __init__(self):
        
        super().__init__(self)
        self.breed=""
        
obj1=dog("vodaphone dog","brown","","")
obj2=cat("aster")
obj3=panther()

# #3)Wap of the parent class vehicle ehich contains multiple child class that is child 1(sports car),child 2 (heavy weight vehiicle),child 3(luxuries car)
# #which is derived from the parent class when the speed of each car(speed ranges from 50-150KM/HR and engine capacity ranges from 1000-5000 gigahertz with fuel capacity 50 litre to
# #1K litre).If a car exceeds speed limit pf 120 ,then it categorises sports ,under 120 but abive 90 is categorized luxurious and rest are under heavy weight.
# #When the speed increases the fuel capacity decreases and the engine power is as the speed.

class vehicle:
    def __init__(self):
        self.speed=""
        self.fuel=""
        self.engine_power=""
class sports_car:
    super().__init(self)
    if(self.speed>=50 and self.speed()<=150):
        if(self.fuel>50 and self.fuel<=1000):
            if(self.engine_power<1000 and self.engine_power>=5000):
                print("sports car")

class sports_car:
    super().__init__(self)
    if(self.speed>=120):
        if(self.fuel>50 and self.fuel<=1000):
            if(self.engine_power<1000 and self.engine_power>=5000):
                print("sports car")
class heavyvehicle:
    super().__init__()
        