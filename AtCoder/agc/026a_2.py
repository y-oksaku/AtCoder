N = int(input())
A = list(map(int, input().split()))

ans = 0
for i in range(N - 1):
    if A[i] != -1 and A[i] == A[i + 1]:
        A[i + 1] = -1
        ans += 1

print(ans)
