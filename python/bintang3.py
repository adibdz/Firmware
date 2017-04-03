a = 0
btn = ""

while a < 10:
    if a % 2 != 0:
        b = 1
        while b <= a:
            btn = btn + "*"
            b = b + 1
    a = a + 1
    btn = btn + "\n"

print btn
