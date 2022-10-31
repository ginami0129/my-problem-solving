import sys

input = sys.stdin.readline

n = int(input())
m = int(input())
INF = 100000 * 100
cost = [[INF] * n for _ in range(n)]
# 그래프 입력 받는다. 
for _ in range(m):
    a, b, c = map(int, input().split())
    cost[a - 1][b - 1] = min(cost[a - 1][b - 1], c)
# 플로이드 워셜(Floyd-Warshall)알고리즘
# cost[i][j] : i 도시에서 j 도시를 가는데 필요한 최소 비용
# i 에서 j 도시를 갈때 거칠 수 있는 모든 도시 k 에 대해 모두 구해준다.
# cost[i][j] : min(cost[i][k] + cost[k][j]) ( 1<= k <=n )
for k in range(n):
    for i in range(n):
        for j in range(n):
            # 시작도시와 도착도시가 같은 경우 없음
            if i == j:
                cost[i][j] = 0
            else:
            # 거칠수 있는 모든 도시에 대하여 최솟 값을 구한다.
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j])
# 결과 출력
for i in range(n):
    for j in range(n):
        print([cost[i][j], 0][cost[i][j] == INF], end=" ")
    print()
