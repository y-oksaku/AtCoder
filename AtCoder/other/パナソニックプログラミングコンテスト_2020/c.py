a, b, c = map(int, input().split())

print('Yes' if c - a - b >= 0 and (c - a - b)**2 > 4 * a * b else 'No')
