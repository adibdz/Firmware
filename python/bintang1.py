a = 1
btn = ""

while a <= 5:
    b = a

    while b > 0:
       btn = btn + "*" 
       b = b - 1

    btn = btn + "\n"
    a = a + 1

print btn
