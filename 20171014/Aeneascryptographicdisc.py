import math
d = float(input())
degree = dict()
for i in range(26):
    c, d = input().split()
    degree[c] = float(d)
ans = d
s = ''.join(c for c in input() if c.isalpha()).upper()
def cal(x,y):
    dis = min(math.fabs(x - y), 360 - math.fabs(x - y))
    return d*math.sqrt(2. - 2.*math.cos(dis*math.pi/180))

for i in range(1,len(s)):
    ans += cal(degree[s[i-1]],degree[s[i]])
print(math.ceil(ans))