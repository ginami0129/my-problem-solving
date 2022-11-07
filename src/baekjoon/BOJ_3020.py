import sys

input = sys.stdin.readline

n, h = map(int, input().split())
sum = [0] * (h + 2)
sum[1], sum[h + 1] = (n // 2), -(n // 2)
while n:
    height = int(input())
    if n % 2 == 0:
        sum[height + 1] -= 1
    else:
        sum[h - height + 1] += 1
    n -= 1
for i in range(1, h + 1):
    sum[i] += sum[i - 1]
min = 200000
count = 0
for i in range(1, h + 1):
    if min > sum[i]:
        min = sum[i]
        count = 1
    elif min == sum[i]:
        count += 1
print(min, count)
