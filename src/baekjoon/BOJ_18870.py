import sys

input = sys.stdin.readline
n = int(input())
x = list(map(int, input().split()))
hash = {}
for index, value in enumerate(sorted(set(x))):
    hash[value] = index
for i in range(n):
    x[i] = hash[x[i]]
print(*x)
