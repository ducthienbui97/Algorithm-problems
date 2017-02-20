#!/usr/bin/env python

raw_input()
s = raw_input().strip()

DP = {}
DPrepeats = {}

def find_best(s1, s2):
    return s1 if len(s1) < len(s2) else s2

for w in range(1, len(s)+1):
    for i in range(0, len(s)-w+1):
        t = s[i:i+w]

        if t in DP:
            continue

        if t not in DPrepeats:
            DPrepeats[t] = {}
            DPrepeats[t][t] = 1

        ans = t
        for j in range(1, w):
            p1, p2 = t[:j], t[j:]
            ans = find_best(ans, DP[p1] + DP[p2])

            if p1 == p2:
                DPrepeats[t][p1] = 2

            if p1 in DPrepeats[p2]:
                DPrepeats[t][p1] = DPrepeats[p2][p1]+1

            if p1 in DPrepeats[t]:
                ans = find_best(ans, "%d(%s)"%(DPrepeats[t][p1], DP[p1]))

        DP[t] = ans

print(DP[t])
