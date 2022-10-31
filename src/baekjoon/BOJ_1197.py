import heapq, sys

input = sys.stdin.readline

def prim(start):
    # cost[i] : i번 노드와 연결된 간선의 최소 가중치
    cost = [INF] * V
    visited = [False] * V
    # 시작 지점 설정
    cost[start] = 0
    queue = []
    heapq.heappush(queue, [cost[start], start])
    while queue:
        # 가중치가 최소인 노드 부터 MST에 포함
        current = heapq.heappop(queue)[1]
        visited[current] = True
        # 가중치 최소인 다음 노드 찾기
        for next, weight in graph[current]:
            # 방문 한적 없고 가중치가 작다면 MST 후보에 포함
            if visited[next] == False and cost[next] > weight:
                cost[next] = weight
                heapq.heappush(queue, [cost[next], next])
    return cost

if __name__ == "__main__":
    # 그래프 정보 입력
    V, E = map(int, input().split())
    graph = [[] * V for _ in range(V)]
    for _ in range(E):
        A, B, C = map(int, input().split())
        graph[A - 1].append([B - 1, C])
        graph[B - 1].append([A - 1, C])
    # 간선의 가중치의 최댓값
    INF = 1000000
    # MST 구하기
    cost = prim(0)
    # MST 최소 가중치 출력
    print(sum(cost))
