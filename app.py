def check_even_odd(num):
    if num % 2 == 0:
        return "Even"
    else:
        return "Odd"

# test
number = 10
print(f"{number} is {check_even_odd(number)}")