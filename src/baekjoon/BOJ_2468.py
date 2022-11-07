import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline
dx, dy = [0, 0, -1, 1], [1, -1, 0, 0]


def dfs(x, y):
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if nx < 0 or ny < 0 or nx >= n or ny >= n:
            continue
        if visited[nx][ny] == False and area[nx][ny] > height:
            visited[nx][ny] = True
            dfs(nx, ny)


if __name__ == "__main__":
    n = int(input())

    area = [list(map(int, input().strip().split())) for _ in range(n)]
    ans = 1
    for height in range(1, 101):
        cnt = 0
        visited = [[False] * n for _ in range(n)]
        for x in range(0, n):
            for y in range(0, n):
                if visited[x][y] == False and area[x][y] > height:
                    visited[x][y] = True
                    dfs(x, y)
                    cnt += 1
        ans = max(ans, cnt)
    print(ans)
