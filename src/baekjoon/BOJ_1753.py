import heapq, sys

# 입력 속도 빠르게
input = sys.stdin.readline

# 그래프 정보 입력 받기
V, E = map(int, input().split())
graph = [[] for _ in range(V + 1)]
K = int(input())
for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append([v, w])

# distance[i]: K에서 i 까지의 거리의 최솟값
distance = [10 * 20000] * (V + 1)
# 시작값은 0 왜냐하면 이동을 안하는게 거리의 최솟값 달성
distance[K] = 0

# 우선순위 큐
queue = []
# 시작 노드 부터 탐색
heapq.heappush(queue, [distance[K], K])

# 큐에 남아 있는 노드가 없을 때 까지
while queue:
    # 최소 거리인 노드를 구함
    from_distance, from_node = heapq.heappop(queue)
    # 해당 노드를 거쳐 갈때 다른 노드들까지의 거리 구함
    for to_node, to_distance in graph[from_node]:
        # 알고 있는 거리보다 작으면 갱신
        if from_distance + to_distance < distance[to_node]:
            distance[to_node] = from_distance + to_distance
            # 다음 인접 거리 계산 위해 큐에 삽입
            heapq.heappush(queue, [distance[to_node], to_node])

# 결과 출력
for d in distance[1:]:
    print([d, "INF"][d == 10 * 20000])
