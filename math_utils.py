def add(a, b):
    return a + b

def subtract(a, b):
    return a - b

def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n - 1)

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(n/2) + 1):
        if n % i == 0:
            return False
    return True