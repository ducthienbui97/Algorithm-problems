#!/usr/bin/env python

import sys
sys.setrecursionlimit(10000)

raw_input()
s = raw_input().strip()

def find_best(s1, s2):
    return s1 if len(s1) < len(s2) else s2

cache = {}

def fold(s):
    if s in cache:
        return cache[s]

    if len(s) == 1:
        cache[s] = (s, {s:1})
        return cache[s]

    ans = s
    ansr = {s: 1}

    for i in range(1, len(s)):
        p1, p2 = s[:i], s[i:]
        p1a, p1ar = fold(p1)
        p2a, p2ar = fold(p2)

        ans = find_best(ans, p1a + p2a)

        if p1 == p2:
            ansr[p1] = 2

        if p1 in p2ar:
            ansr[p1] = p2ar[p1]+1

        if p1 in ansr:
            ans = find_best(ans, "%d(%s)"%(ansr[p1], p1a))

    cache[s] = (ans, ansr)
    return cache[s]

print(fold(s)[0])
