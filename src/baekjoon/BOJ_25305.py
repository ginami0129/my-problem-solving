import sys
input = sys.stdin.readline
N, k = map(int, input().split())
grades = list(map(int, input().split()))
MAX = 10001
count = [0] * MAX
for grade in grades:
    count[grade] += 1
ans = 0
sorted_grades = []
for i in range(MAX):
    sorted_grades += [i] * count[i]
print(sorted_grades[-k])
