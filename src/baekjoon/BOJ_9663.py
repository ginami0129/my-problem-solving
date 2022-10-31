def dfs(nx):
    global ans
    # N개의 여왕을 모두 놓았다면 경우의수를 카운트한다.
    if nx == N:
        # print(queens)
        ans += 1
        return
    # 놓을 수 있는 모든 칸들을 탐색한다.
    for ny in range(N):
        # 수직 검사
        if flag[ny]:
            continue
        # 대각선 검사
        check = True
        for x, y in enumerate(queens[:nx]):
            # 기울기가 1 or -1 이어야 한다.
            if abs(ny - y) == nx - x:
                check = False
                break
        # 검사 를 모두 통과 하면 해당 칸을 방문한다.
        queens[nx] = ny
        if check == True:
            flag[ny] = True
            dfs(nx + 1)
            # 백트래킹
            flag[ny] = False


if __name__ == "__main__":
    N = int(input())
    # n X n 에서 n 개의 여왕을 놓으려면, 각 줄에 한개씩 놓아야한다.
    # 여왕의 위치 기록
    # queens[x] = y : x번째 줄 y번째 칸에 여왕이 놓아진다.
    queens = [0] * N
    # 방문한 칸 기록
    flag = [False] * N
    ans = 0
    dfs(0)
    print(ans)
