n = int(input())
ans = 0
while n:
    word = input()
    stack = []
    for char in word:
        stack.append(char)
        if len(stack) >= 2 and stack[-1] == stack[-2]:
            del stack[-2:]
    ans += [0, 1][len(stack) == 0]
    n -= 1
print(ans)
