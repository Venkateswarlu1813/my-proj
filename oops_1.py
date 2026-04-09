class Animal:
    def __init__(self, name):
        self.name = name

    def sound(self):
        print("Animal makes a sound")

class Dog(Animal):
    def sound(self):
        print(self.name + " barks")

class Cat(Animal):
    def sound(self):
        print(self.name + " meows")

def animal_sound(animal):
    animal.sound()

a1 = Animal("Generic Animal")
d1 = Dog("Tommy")
c1 = Cat("Kitty")

a1.sound()
animal_sound(d1)
animal_sound(c1)