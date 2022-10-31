n = int(input())
# '*' 기준으로 분리한다
left, right = input().split("*")
while n:
    file = input()
    # 곂쳐지면 안된다.
    if len(left) + len(right) <= len(file):
        # 앞 부분에 동일한 문자열이 있는지 확인
        result = ["DA", "NE"][file[: len(left)] != left]
        # 뒷 부분에 동일한 문자열이 있는지 확인
        if file[-len(right) :] != right:
            result = "NE"
        # 결과 출력
        print(result)
    else:
        # 곂쳐지면 검사할 필요 없음
        print("NE")
    n -= 1
