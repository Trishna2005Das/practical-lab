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
# Parent class: Animal
class Animal:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def eat(self):
        print(f"{self.name} is eating.")

    def sleep(self):
        print(f"{self.name} is sleeping.")

# Child class: Dog
class Dog(Animal):
    def __init__(self, name, age, breed):
        super().__init__(name, age)
        self.breed = breed

    def bark(self):
        print(f"{self.name} the {self.breed} is barking.")

    def fetch(self):
        print(f"{self.name} the {self.breed} is fetching.")

# Child class: Cat
class Cat(Animal):
    def __init__(self, name, age, color):
        super().__init__(name, age)
        self.color = color

    def meow(self):
        print(f"{self.name} the {self.color} cat is meowing.")

    def scratch(self):
        print(f"{self.name} the {self.color} cat is scratching.")

# Child class: Panther
class Panther(Animal):
    def __init__(self, name, age, habitat):
        super().__init__(name, age)
        self.habitat = habitat

    def roar(self):
        print(f"{self.name} the panther is roaring in the {self.habitat}.")

    def climb(self):
        print(f"{self.name} the panther is climbing in the {self.habitat}.")

# Create instances of each child class
dog = Dog("Fido", 3, "Golden Retriever")
cat = Cat("Whiskers", 2, "Gray")
panther = Panther("Raja", 5, "Jungle")

# Test the methods
dog.eat()
dog.bark()
dog.fetch()

cat.sleep()
cat.meow()
cat.scratch()

panther.eat()
panther.roar()
panther.climb()

# #3)Wap of the parent class vehicle ehich contains multiple child class that is child 1(sports car),child 2 (heavy weight vehiicle),child 3(luxuries car)
# #which is derived from the parent class when the speed of each car(speed ranges from 50-150KM/HR and engine capacity ranges from 1000-5000 gigahertz with fuel capacity 50 litre to
# #1K litre).If a car exceeds speed limit pf 120 ,then it categorises sports ,under 120 but abive 90 is categorized luxurious and rest are under heavy weight.
# #When the speed increases the fuel capacity decreases and the engine power is as the speed.

class Vehicle:
    def __init__(self, speed, engine_capacity, fuel_capacity):
        self.speed = speed
        self.engine_capacity = engine_capacity
        self.fuel_capacity = fuel_capacity

    def categorize(self):
        if self.speed > 120:
            return "Sports"
        elif self.speed > 90:
            return "Luxury"
        else:
            return "Heavy Weight"

    def update_fuel_capacity(self):
        self.fuel_capacity -= (self.speed / 100) * 10

    def update_engine_power(self):
        self.engine_capacity += (self.speed / 100) * 100


class SportsCar(Vehicle):
    def __init__(self, speed, engine_capacity, fuel_capacity):
        super().__init__(speed, engine_capacity, fuel_capacity)


class HeavyWeightVehicle(Vehicle):
    def __init__(self, speed, engine_capacity, fuel_capacity):
        super().__init__(speed, engine_capacity, fuel_capacity)


class LuxuryCar(Vehicle):
    def __init__(self, speed, engine_capacity, fuel_capacity):
        super().__init__(speed, engine_capacity, fuel_capacity)



sports_car = SportsCar(140, 2000, 500)
print(sports_car.categorize()) 
sports_car.update_fuel_capacity()
print(sports_car.fuel_capacity) 
sports_car.update_engine_power()
print(sports_car.engine_capacity) 

luxury_car = LuxuryCar(100, 1500, 700)
print(luxury_car.categorize())  
luxury_car.update_fuel_capacity()
print(luxury_car.fuel_capacity)  
luxury_car.update_engine_power()
print(luxury_car.engine_capacity)  

heavy_weight_vehicle = HeavyWeightVehicle(60, 1000, 1000)
print(heavy_weight_vehicle.categorize()) 
heavy_weight_vehicle.update_fuel_capacity()
print(heavy_weight_vehicle.fuel_capacity)
heavy_weight_vehicle.update_engine_power()
print(heavy_weight_vehicle.engine_capacity)  

# #2)wap of inheritance of poarent class system which has child class chips,that contains variable budget amount systems which range from 100 dollar to 1500 dollar
# #Range 1 system is of the range:100-1500 dollar(which is defined as expensive system)
# #Range 2 is of the range 500-100 dollar(i.e of the perfect system)
# #Rest system of the are of the Range 3(which is of the )Take input from the user with system name,processor type.Store each system with its proper range system in 3 different list 


wap to implement runtime polymorhism
wap to define encapsulation
