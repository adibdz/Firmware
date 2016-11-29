a = 0
d = 30
btn = ""

while a < d:
    if a % 2 != 0:
        b = 1
        f = True
        while b <= a:
            c = (d - a) / 2
            e = 0
            if f == True:
                while e < c:
                    btn = btn + " "
                    e = e + 1
                f = False
            btn = btn + "*"
            b = b + 1
        btn = btn + "\n"
    a = a + 1

print btn
