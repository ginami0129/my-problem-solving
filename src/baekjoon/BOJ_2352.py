from bisect import bisect_left

N = int(input())
ports = list(map(int, input().split()))
lis = [0]
for port in ports:
    if lis[-1] < port:
        lis.append(port)
    else:
        i = bisect_left(lis, port)
        lis[i] = port
print(len(lis) - 1)
