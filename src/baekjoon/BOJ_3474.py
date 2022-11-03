import sys

input = sys.stdin.readline

t = int(input())
while t:
    number = int(input())
    target = 5
    ans = 0
    while number // target > 0:
        ans += number // target
        target *= 5
    print(ans)
    t -= 1
