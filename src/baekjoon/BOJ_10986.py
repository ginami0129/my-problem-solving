# 입력 예시
# A : 1 2 3 1 2
N, M = map(int, input().split(" "))
A = [0] + list(map(int, input().split(" ")))
count = [0] * M
count[0] = 1
# 누적합을 구해줌과 동시에 값들의 개수를 기록한다.
for i in range(1, N + 1):
    A[i] = (A[i] + A[i - 1]) % M
    count[A[i]] += 1
# 결과 예시
# A     : 0 1 0 0 1 0
# count : 4 2 0
# ans = 4C2 + 2C2 + 0C2
ans = 0
for cnt in count:
    ans += (cnt * (cnt - 1)) // 2
print(ans)
