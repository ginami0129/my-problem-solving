import sys

input = sys.stdin.readline
# 표, 구간 입력 받기
N, M = map(int, input().split())
table = [[0] * (N + 1)] + [[0] + list(map(int, input().split(" "))) for _ in range(N)]
# 행방향 누적합
for i in range(1, N + 1):
    for j in range(1, N + 1):
        table[i][j] += table[i][j - 1]
# 열방향 누적합
for i in range(1, N + 1):
    for j in range(1, N + 1):
        table[j][i] += table[j - 1][i]
# table[i][j] : (1, 1) 부터 (i+1, j+1) 까지의 합

for _ in range(M):
    # 구하고자 하는 구간 입력받기
    x1, y1, x2, y2 = map(int, input().split(" "))
    print(
        # (x1, y1)부터 (x2, y2) 까지의 합 출력
        table[x2][y2]
        - (table[x1 - 1][y2] + table[x2][y1 - 1])
        + table[x1 - 1][y1 - 1]
    )
