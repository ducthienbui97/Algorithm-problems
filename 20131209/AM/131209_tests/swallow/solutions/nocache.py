#!/usr/bin/env python

input()
s = input().strip()

def find_best(s1, s2):
    return s1 if len(s1) < len(s2) else s2

cache = {}

def find_ans(s):
    if len(s) == 1:
        cache[s] = (s, {s:1})
        return s, {s:1}

    ans = s
    ansrepeat = {s:1}
    for i in range(1, len(s)):
        p1, p2 = s[:i], s[i:]

        p1a, p1ar = find_ans(p1)
        p2a, p2ar = find_ans(p2)

        ans = find_best(ans, p1a + p2a)

        if p1 == p2:
            ansrepeat[p1] = 2

        if p1 in p2ar:
            ansrepeat[p1] = p2ar[p1]+1

        if p1 in ansrepeat:
            ans = find_best(ans, "%d(%s)"%(ansrepeat[p1], p1a))

    cache[s] = (ans, ansrepeat)
    return cache[s]

print(find_ans(s)[0])
