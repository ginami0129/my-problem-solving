import sys

input = sys.stdin.readline
t = int(input())
while t:
    n = int(input())
    contacts = [input().strip() for _ in range(n)]
    contacts.sort()
    hash, length = {}, {}
    ans = "YES"
    for contact in contacts:
        for l in length:
            if contact[:l] in hash:
                ans = "NO"
                break
        if ans == "NO":
            break
        else:
            hash[contact] = 1
            length[len(contact)] = 1
    print(ans)
    t -= 1
