from bisect import bisect_left

# 수열을 입력받는다.
N = int(input())
A = list(map(int, input().split()))
# LIS : longest increasing subsequence
# lis[i] : 길이가 i 인 IS의 마지막 원소의 최솟값
# ans : lis 배열의 크기 -1
lis = [0]
for number in A:
    if lis[-1] < number:
        lis.append(number)
    else:
        i = bisect_left(lis, number)
        lis[i] = number
print(len(lis) - 1)

# 예시
# A : 2 4 1 3 5 6
# A  lis
# 2  2
# 4  2 4
# 1  1 4
# 3  1 3
# 5  1 3 5
# 6  1 3 5 6
