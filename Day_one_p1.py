with open("input.txt") as f:
    lines = f.readlines()

arr = []
for i in lines:
    s = ""
    for j in range(len(i)):
        if i[j] in "1234567890":
            s += i[j]
            break
    for j in range(len(i) - 1, -1, -1):
        if i[j] in "1234567890":
            s += i[j]
            break
    arr.append(int(s))
print((sum(arr)))