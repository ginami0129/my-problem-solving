import sys

input = sys.stdin.readline
N = int(input())
# matrix[i] = i 번째 행렬의 정보 (row, column)
# d[i][j] : i 번째 부터 j 번째 행렬까지 곱하는데 필요한 곱셈 연산의 최솟값
# d[i][j] = min(d[i][k] + d[k+1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1]) (i<= k <j)
# 정답: matrix[0][N-1]
matrix = []
d = [[0] * N for i in range(N)]
# 행렬을 입력 받는다.
for i in range(N):
    r, c = list(map(int, input().split()))
    matrix.append((r, c))
# 곱셈 연산의 최솟값을 구한다.
for i in range(N - 1, -1, -1):
    for j in range(i + 1, N):
        d[i][j] = 2**32
        for k in range(i, j):
            d[i][j] = min(
                d[i][k] + d[k + 1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1],
                d[i][j],
            )
print(d[0][N - 1])
