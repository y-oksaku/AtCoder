s = list(input())
t = list(input())

s.sort()
t.sort(reverse=True)

print('Yes' if s < t else 'No')
