def outer_function(msg):
    def inner_function():
        print(msg)   # remembers msg
    return inner_function
closure_func = outer_function("Hello Closure")
closure_func()