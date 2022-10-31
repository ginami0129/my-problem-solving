n = int(input())
w = list(map(int, input().split()))
w.sort()
left, right = 0, 2 * n - 1
ans = 100000 * 2
while left < right:
    ans = min(ans, w[left] + w[right])
    left += 1
    right -= 1
print(ans)
