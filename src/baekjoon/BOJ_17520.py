n = int(input())
n = (n + 1) // 2
MAX = 16769023
ans = 1
for i in range(n):
    ans = (ans * 2) % MAX
print(ans)
