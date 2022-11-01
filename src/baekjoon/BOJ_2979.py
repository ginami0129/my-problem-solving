cost = list(map(int, input().split()))
n = 3
count = [0] * 101
while n:
    start, end = map(int, input().split())
    for i in range(start, end):
        count[i] += 1
    n -= 1
ans = 0
for i in range(101):
    ans += cost[count[i] - 1] * count[i]
print(ans)
