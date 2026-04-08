from abc import ABC, abstractmethod

class Vehicle(ABC):
    @abstractmethod
    def start(self):
        pass

class Car(Vehicle):
    def __init__(self, brand, speed):
        self.__brand = brand
        self.__speed = speed
    def get_brand(self):
        return self.__brand
    def get_speed(self):
        return self.__speed
    def set_speed(self, speed):
        self.__speed = speed
    def start(self):
        print(self.__brand + " car is starting...")
    def display(self):
        print("Brand:", self.__brand)
        print("Speed:", self.__speed)

c1 = Car("Tesla", 120)
c1.start()
c1.display()
c1.set_speed(150)
print("Updated Speed:", c1.get_speed())