class Student:
    def __init__(self, name, marks):
        self.name = name
        self.marks = marks

    def display(self):
        return f"Name: {self.name}, Marks: {self.marks}"

    def is_pass(self):
        return self.marks >= 40
