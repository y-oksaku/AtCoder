import sys
from heapq import heappop, heappush
from operator import itemgetter
from collections import deque, defaultdict, Counter
from bisect import bisect_left, bisect_right
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)
MOD = 10**9 + 7
INF = float('inf')

def sol():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    ans = 0
    for i in range(N):
        ans += B[A[i] - 1]
        if i > 0 and A[i - 1] + 1 == A[i]:
            ans += C[A[i - 1] - 1]

    print(ans)


sol()