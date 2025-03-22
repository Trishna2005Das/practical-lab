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


# Example usage:
sports_car = SportsCar(140, 2000, 500)
print(sports_car.categorize()) 
sports_car.update_fuel_capacity()
print(sports_car.fuel_capacity) 
sports_car.update_engine_power()
print(sports_car.engine_capacity)  # Output: 2200

luxury_car = LuxuryCar(100, 1500, 700)
print(luxury_car.categorize())  # Output: Luxury
luxury_car.update_fuel_capacity()
print(luxury_car.fuel_capacity)  # Output: 670
luxury_car.update_engine_power()
print(luxury_car.engine_capacity)  # Output: 1600

heavy_weight_vehicle = HeavyWeightVehicle(60, 1000, 1000)
print(heavy_weight_vehicle.categorize())  # Output: Heavy Weight
heavy_weight_vehicle.update_fuel_capacity()
print(heavy_weight_vehicle.fuel_capacity)  # Output: 940
heavy_weight_vehicle.update_engine_power()
print(heavy_weight_vehicle.engine_capacity)  # Output: 1100