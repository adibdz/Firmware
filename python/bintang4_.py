angka1 = 1
string = ""
b = 0 
while angka1 <= 5: 
  angka2 = angka1
  n = angka1 + b
  while angka2 <= 4:
    string = string + " "
    angka2 = angka2 + 1
  while n > 0: 
    string = string + "*"
    n = n - 1
  string = string + "\n"
  angka1 = angka1 + 1
  b = b + 1

print string
