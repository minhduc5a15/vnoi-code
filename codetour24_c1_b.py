a, b = map(int, input().split())

c = a // b + (b % a != 0)
print(c * (c + 1) // 2)