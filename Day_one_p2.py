mappings = {
    "1" : 1,
    "2" : 2,
    "3" : 3,
    "4" : 4,
    "5" : 5,
    "6" : 6,
    "7" : 7,
    "8" : 8,
    "9" : 9,
    "one" : 1,
    "two" : 2,
    "three" : 3,
    "four" : 4,
    "five" : 5,
    "six" : 6,
    "seven" : 7,
    "eight" : 8,
    "nine" : 9,
}

with open("input.txt") as f:
    lines = f.readlines()

tot = 0
for _ in lines:
    arr = []
    for i in mappings:
        if i in _:
            res = [[j, mappings[i]] for j in range(len(_)) if _.startswith(i, j)]
            arr.extend(res)
            print(res)
    arr.sort()   
    ans = int(str(arr[0][1]) + str(arr[-1][1]))   
    tot += ans
print(tot)