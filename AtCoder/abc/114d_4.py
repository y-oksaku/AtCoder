from collections import Counter, defaultdict

N = int(input())

# 素数のリスト
def createPrimeList(N, isTable=True):
    isPrime = [True] * N
    isPrime[0] = False
    isPrime[1] = False
    for i in range(2, N):
        if not isPrime[i]:
            continue
        for p in range(i * 2, N, i):
            isPrime[p] = False
    return isPrime if isTable else [i for i in range(2, N) if isPrime[i]]

# 素因数分解(複数回)
isPrime = createPrimeList(10**5, False)
def primeFactorization(N):
    primes = Counter()
    for p in isPrime:
        while N % p == 0:
            N //= p
            primes[p] += 1
    return primes

primes = Counter()
for i in range(1, N + 1):
    primes += primeFactorization(i)

cnt = defaultdict(int)
for c in primes.values():
    c += 1
    for d in (3, 5, 15, 25, 75):
        if c >= d:
            cnt[d] += 1

ans = 0
ans += cnt[5] * (cnt[5] - 1) * (cnt[3] - 2) // 2
ans += cnt[25] * (cnt[3] - 1)
ans += cnt[15] * (cnt[5] - 1)
ans += cnt[75]
print(ans)
