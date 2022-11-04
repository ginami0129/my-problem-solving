import sys

input = sys.stdin.readline
MAX = 123456
prime = [True] * (2 * MAX + 1)
prime[1] = False
number = 2
while number * number <= 2 * MAX:
    if prime[number] == True:
        for i in range(2 * number, 2 * MAX + 1, number):
            prime[i] = False
    number += 1
n = int(input())
while n:
    print(sum(prime[n + 1 : 2 * n + 1]))
    n = int(input())
