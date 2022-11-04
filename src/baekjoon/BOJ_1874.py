import sys

input = sys.stdin.read
n, *nums = map(int, input().split())
stack = []
command = ""
i = 1
for num in nums:
    while i <= num:
        stack.append(i)
        command += "+\n"
        i += 1
    if stack[-1] == num:
        del stack[-1]
        command += "-\n"
    else:
        command = "NO"
        break

print(command)
