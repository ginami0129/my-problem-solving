import sys

input = sys.stdin.readline
string = input().strip()
target = input().strip()
length = len(target)
stack = []
for char in string:
    stack.append(char)
    if char == target[-1] and "".join(stack[-length:]) == target:
        del stack[-len(target) :]
print(["".join(stack), "FRULA"][len(stack) == 0])
