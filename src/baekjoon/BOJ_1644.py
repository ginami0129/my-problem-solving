N = int(input()) + 1
target = N - 1
# 1 예외 처리
if target == 1:
    print(0)
    exit(0)
# 에라토스테네스의 체로 소수 구하기
isPrime = [True] * N
i = 1
while i * i < N:
    i += 1
    if isPrime[i] == False:
        continue
    for j in range(2 * i, N, i):
        isPrime[j] = False
# 구한 소수들의 누적합구하기
sum = [0]
for i in range(2, N):
    if isPrime[i]:
        sum.append(sum[-1] + i)
start, end = 0, 1
ans = 0
# 투 포인터로 연속된 소수의 합 중 가능한 경우 구하기
while end < len(sum) and start < end:
    psum = sum[end] - sum[start]
    if psum == target:
        ans += 1
    if psum <= target:
        end += 1
    else:
        start += 1
print(ans)
