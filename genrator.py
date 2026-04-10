def count_up(max):
    for i in range(1, max + 1):
        yield i

for num in count_up(5):
    print(num)