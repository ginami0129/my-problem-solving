from collections import deque

N = int(input())
area = [list(map(int, input().split())) for _ in range(N)]


# 아기 상어의 위치 찾기
cnt = 0
x, y = 0, 0
for i in range(N):
    for j in range(N):
        if area[i][j] == 9:
            x, y = i, j
            area[x][y] = 0
            break

dx = [1, 0, 0, -1]
dy = [0, -1, 1, 0]
size, eat = 2, 0
ans = 0
while True:
    queue = deque()
    # 현재 위치 (x, y)에서 먹을 수 있는 가장 가까운 물고기를 탐색
    queue.append((x, y, 0))
    visited = [[False] * N for _ in range(N)]
    # 가장 가까운 물고기까지 가는데 걸리는 시간
    min_time = 1e9
    # 가장 가까운 물고기의 정보(위치, 가는게 걸리는 시간) 저장
    fish = []
    while queue:
        x, y, time = queue.popleft()
        # 가장 가까운 물고기가 아니면 더이상 탐색 안함
        if time > min_time:
            break
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if nx < 0 or ny < 0 or nx >= N or ny >= N:
                continue
            if area[nx][ny] > size or visited[nx][ny]:
                continue
            # 먹을 수 있는 물고기 인지 확인한다.
            if area[nx][ny] > 0 and area[nx][ny] < size:
                fish.append((nx, ny, time + 1))
                min_time = time
            visited[nx][ny] = True
            queue.append((nx, ny, time + 1))
    # 먹을 수 있는 물고기가 존재한다면
    if len(fish) > 0:
        # 조건에 맞게 위, 왼 순으로 방문한다.
        fish.sort()
        x, y, time = fish[0]
        area[x][y] = 0
        ans += time
        # 크기 증가, 먹은 물고기 횟수 증가한다.
        eat, size = [(eat + 1, size), (0, size + 1)][eat + 1 == size]
    else:
        break
print(ans)
