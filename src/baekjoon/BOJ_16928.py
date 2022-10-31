from collections import deque

# arr[i] = j
# i 위치를 방문하면 연결된 j 위치를 방문해야한다.
arr = [i for i in range(0, 101)]
N, M = map(int, input().split())
N += M
# 연결된 위치를 기록한다.
while N:
    x, y = map(int, input().split())
    arr[x] = y
    N -= 1
# BFS로 완전탐색을 수행한다.
queue = deque()
queue.append(1)
ans = 0
# 방문 표시
# 0 위치는 없으므로 방문 할 수 없는 곳은 없다.
arr[1] = 0
while len(queue):
    size = len(queue)
    while size:
        # 현재 위치를 구한다.
        x = queue.popleft()
        if x == 100:
            print(ans)
            exit(0)
        # 이동할 수 있는 모든 경우에 대하여 탐색한다.
        for dx in [1, 2, 3, 4, 5, 6]:
            nx = x + dx
            if nx > 100:
                break
            # nx 위치와 연결된 ny 위치가 있는지 확인한다.
            if arr[nx] > 0:
                # 연결된 ny 위치를 방문한다.
                ny = arr[nx]
                queue.append(arr[ny])
                # nx, ny 두 위치 모두 방문했다.
                arr[ny] = arr[nx] = 0
        size -= 1
    # 몇번째 방문인지 횟수를 센다.
    ans += 1
