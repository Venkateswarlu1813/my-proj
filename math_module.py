import math
def calculate_square_root(n):
    try:
        return math.sqrt(n)
    except ValueError:
        return "Cannot calculate square root of negative number"

def calculate_log(n):
    try:
        return math.log(n)
    except ValueError:
        return "Log undefined for non-positive numbers"