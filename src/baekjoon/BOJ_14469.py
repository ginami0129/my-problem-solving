n = int(input())
cows = [list(map(int, input().split())) for _ in range(n)]
cows.sort()
ans = 0
for arrived, time in cows:
    if ans < arrived:
        ans = arrived + time
    else:
        ans += time
print(ans)
