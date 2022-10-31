N, S = map(int, input().split())
arr = list(map(int, input().split())) + [0]
left = 0
right = 0
sum = arr[0]
length = 1e5
while left <= right and right < N:
    if sum < S:
        right += 1
        sum += arr[right]
    elif sum >= S:
        length = min(length, right - left + 1)
        sum -= arr[left]
        left += 1
print([length, 0][length == 1e5])
