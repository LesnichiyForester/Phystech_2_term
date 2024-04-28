a = 0
s = 0

for k in range(1, 1000):
    s += k * a ** (k - 1)
print(s)
