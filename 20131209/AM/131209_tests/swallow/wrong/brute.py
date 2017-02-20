#!/usr/bin/env python

def fold(s):
    if len(s) == 1:
    #if len(s) == len(set(s)):
        return s

    ans = s
    for i in range(1, len(s)-1):
        p1 = s[:i]
        p2 = s[i:]
        p1a = fold(p1)
        p2a = fold(p2)

        t = p1a + p2a
        if len(t) < len(ans):
            ans = t

        if len(p2) % len(p1) == 0:
            idx = 0
            repeating = True

            while idx != len(p2):
                if p2[idx:idx+len(p1)] != p1:
                    repeating = False
                    break
                idx += len(p1)

            if repeating:
                t = "%d(%s)"%(len(p2)//len(p1)+1, p1a)
                if len(t) < len(ans):
                    ans = t

    return ans

raw_input()
s = raw_input().strip()
print(fold(s))
