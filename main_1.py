import math_module
import datetime_module
import os_module
import json_module
import exception_module

# Math
print(math_module.calculate_square_root(25))
print(math_module.calculate_log(10))

# DateTime
print(datetime_module.current_time())
print(datetime_module.format_date())

# OS
print(os_module.list_files())
print(os_module.create_folder("test_folder"))

# JSON
data = {"name": "Venky", "marks": 90}
print(json_module.write_json(data))
print(json_module.read_json())

# Exception Handling
print(exception_module.divide(10, 2))
print(exception_module.divide(10, 0))