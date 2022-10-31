n, W = map(int, input().split())
coins, value = 0, 0


# total = coins * value + W

# price = [int(input()) for _ in range(n)]
# current = price[0]
# for i in range(1, n):
#     if coins == 0:
#         if current < price[i]:
#             value = current
#             coins = W // current
#             W -= coins * value

price = [0] * n
for i in range(n):
    price[i] = int(input())

coins = 0
for i in range(n - 1):
    if coins == 0:
        if price[i] < price[i + 1]:
            coins = W // price[i]
            W -= coins * price[i]
    else:
        if price[i] > price[i + 1]:
            W += price[i] * coins
            coins = 0

print(coins * price[n - 1] + W)
