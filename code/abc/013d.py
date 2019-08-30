import sys
import heapq
from operator import itemgetter
from collections import deque, defaultdict, Counter
from bisect import bisect_left, bisect_right
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)
MOD = 10**9 + 7
INF = float('inf')

class UnionFind :
    def __init__(self, size) :
        """
        Parameters
        ---
        size : int
            頂点数
        """
        self.parent = list(range(size))
        self.height = [0] * size
        self.size = [1] * size
        self.component = size

    def root(self, index) :
        """
        親のインデックスの取得

        Parameters
        ---
        index : int
            取得する頂点のインデックス

        Returns
        ---
        rootIndex : int
            指定した頂点の根のインデックス
        """
        if self.parent[index] == index :  # 根の場合
            return index
        rootIndex = self.root(self.parent[index])  # 葉の場合親の根を取得
        self.parent[index] = rootIndex  # 親の付け直し
        return rootIndex

    def union(self, index1, index2) :  # 結合
        """
        木の結合

        Parameters
        ---
        index1 : int
        index2 : int
            結合する頂点のインデックス
        """
        root1 = self.root(index1)
        root2 = self.root(index2)

        if root1 == root2 :  # 連結されている場合
            return

        self.component -= 1  # 連結成分を減らす

        if self.height[root1] < self.height[root2] :
            self.parent[root1] = root2  # root2に結合
            self.size[root2] += self.size[root1]
        else :
            self.parent[root2] = root1  # root1に結合
            self.size[root1] += self.size[root2]
            if self.height[root1] == self.height[root2] :
                self.height[root1] += 1
        return

    def isSameRoot(self, index1, index2) :
        """
        同じ木に属するかを判定する

        Parameters
        ---
        index1 : int
        index2 : int

        Returns
        ---
        boolean
        """
        return self.root(index1) == self.root(index2)

    def sizeOfSameRoot(self, index) :
        """
        指定した頂点の属する木の大きさを取得する
        """
        return self.size[self.root(index)]

    def getComponent(self) :
        """
        連結成分数を取得する
        """
        return self.component

def sol():
    N, _, D = map(int, input().split())
    A = list(map(int, input().split()))

    index = list(range(1, N + 1))
    for a in A:
        a -= 1
        index[a], index[a + 1] = index[a + 1], index[a]

    startToEnd = {s : e + 1 for e, s in enumerate(index)}

    tree = UnionFind(N + 1)
    for s in range(1, N + 1):
        tree.union(s, startToEnd[s])

    paths = {}
    startToPathIndex = {}
    for s in range(1, N + 1):
        root = tree.root(s)
        if root in paths:
            continue

        path = [root]
        startToPathIndex[root] = 0
        now = startToEnd[root]
        while now != root:
            path.append(now)
            startToPathIndex[now] = len(path) - 1
            now = startToEnd[now]
        paths[root] = path

    ans = []
    for start in range(1, N + 1):
        root = tree.root(start)
        roop = tree.sizeOfSameRoot(start)

        r = D % roop

        ans.append(paths[root][(startToPathIndex[start] + r) % roop])

    print(*ans, sep='\n')

sol()