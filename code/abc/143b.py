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
    D = list(map(int, input().split()))

    ans = 0
    for d1 in D:
        for d2 in D:
            ans += d1 * d2

    for d in D:
        ans -= d * d

    print(ans // 2)


sol()