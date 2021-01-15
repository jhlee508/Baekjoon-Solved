N, K = map(int, input().split())
minimum = 0
coin = []

for i in range(N):
    temp = int(input())
    coin.append(temp)


for i in range(N - 1, -1, -1):
    minimum += K//coin[i]
    K %= coin[i]

print(minimum)


