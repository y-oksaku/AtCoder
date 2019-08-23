import sys
import heapq
from operator import itemgetter
from collections import deque, defaultdict
from bisect import bisect_left, bisect_right
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)
MOD = 10**9 + 7

def sol():
    N = int(input())

    for _ in range(N):
        A, B = map(int, input().split())
        if A == B:
            print(-1)
        else:
            print(abs(A - B))


sol()