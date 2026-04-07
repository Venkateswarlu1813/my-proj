# main.py

import math_utils
import string_utils
import file_utils
from oop_utils import Student

#Math
print(math_utils.add(5, 3))
print(math_utils.factorial(5))
print(math_utils.is_prime(7))

#String
print(string_utils.reverse_string("hello"))
print(string_utils.is_palindrome("madam"))
print(string_utils.count_vowels("venkatesh"))

#File
file_utils.write_file("test.txt", "Hello Python")
print(file_utils.read_file("test.txt"))

#OOP 
s1 = Student("Venky", 85)
print(s1.display())
print(s1.is_pass())