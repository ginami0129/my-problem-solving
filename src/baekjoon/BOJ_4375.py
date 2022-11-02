import sys

for n in sys.stdin.readlines():
    n = int(n)
    temp = 1
    ans = 1
    while temp % n > 0:
        temp = 10 * (temp % n) + 1
        ans += 1

    print(ans)
