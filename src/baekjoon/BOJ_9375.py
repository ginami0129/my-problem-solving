t = int(input())
while t:
    wears = int(input())
    hash = {}
    for _ in range(wears):
        _, kind = input().split()
        hash[kind] = hash[kind] + 1 if kind in hash else 1
    ans = 1
    for kind in hash:
        ans *= hash[kind] + 1
    print(ans - 1)
    t -= 1
