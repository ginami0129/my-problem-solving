while True:
    # 입력에서 직사각형의 수를 분리한다.
    height = list(map(int, input().split())) + [0]
    N = height.pop(0)
    # 종료 조건 확인
    if N == 0:
        break
    # 오름차순을 만족하는 막대의 인덱스를 저장한다.
    stack = []
    ans = 0
    for i in range(N + 1):
        # 오름차순을 만족하지 않다면 만족할 때까지 pop 하면서 직사각형의 최대 넓이를 구한다.
        while len(stack) > 0 and height[stack[-1]] > height[i]:
            check = stack.pop(-1)
            width = i - stack[-1] - 1 if len(stack) > 0 else i
            ans = max(ans, height[check] * width)
        stack.append(i)
    print(ans)

# 7 2 1 4 5 1 3 3
# N      :  7
# height :  2 1 4 5 1 3 3
