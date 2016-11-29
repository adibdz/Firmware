a = 5
btn = ""

while a >= 1:
    b = a

    while b >= 1:
       btn = btn + "*" 
       b = b - 1

    btn = btn + "\n"
    a = a - 1

print btn
