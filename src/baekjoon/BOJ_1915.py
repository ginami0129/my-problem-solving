# d[i][j] : (i, j) 를 오른쪽 아래 꼭짓점으로 하는 정사각형의 변의 길이의 최댓값
# (i, j) 가 오른쪽 아래 꼭짓점이 가능하다면 아래가 성립한다.
# d[i][j] = min(d[i-1][j], d[i][j-1], d[i-1][j-1]) + 1
n, m = map(int, input().split(" "))
d = [[0] * (m + 1)]
ans = 0
for i in range(1, n + 1):
    # 배열 입력 받는다.
    d.append(list(map(int, [0] + list(input()))))
    # 위 점화식을 사용해서 가장 큰 정사각형의 한변의 길이를 구한다.
    for j in range(1, m + 1):
        # (i, j)가 꼭짓점이 가능한지 확인한다.
        if d[i][j] == 1:
            d[i][j] += min(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1])
            ans = max(d[i][j], ans)
# 가장 큰 정사각형의 넓이를 출력한다.
print(ans * ans)
