from collections import deque

# 입력 받기
N, M = map(int, input().split())
maze = [[int(i) for i in input()] for _ in range(N)]

queue = deque()
# 방문 표시
maze[0][0] = 0
queue.append((0, 0))
# 상하좌우 이동
dx, dy = [1, -1, 0, 0], [0, 0, -1, 1]
# BFS 수행
ans = 1
while len(queue):
    # 이동 칸수 구분
    size = len(queue)
    while size:
        # 현재 위치
        x, y = queue.popleft()
        # 도착지인지 확인
        if x == N - 1 and y == M - 1:
            print(ans)
            exit(0)
        # 다음 위치 방문
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            # 유효한 위치인지 확인
            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue
            # 방문 한적이 있는지 확인
            if maze[nx][ny] == 1:
                maze[nx][ny] = 0
                queue.append((nx, ny))
        size -= 1
    # 이동 칸수 증가
    ans += 1
