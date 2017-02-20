#!/usr/bin/env python

raw_input()
s = raw_input().strip()

def fold(s):
    if len(s) == len(set(s)):
        return s

    ans = s
    for i in range(len(s)):
        for w in range(1, (len(s)-i)//2+1):
            t = "%s%s%s"%(fold(s[:i]), fold(s[i:i+w]), fold(s[i+w:]))
            if len(t) < len(ans):
                ans = t
            for repeats in range(2, (len(s)-i)//w+1):
                if s[i + w*(repeats-1):i + w*repeats] != s[i:i+w]:
                    break
                t = "%s%d(%s)%s"%(fold(s[:i]), repeats, fold(s[i:i+w]), fold(s[i+w*repeats:]))
                if len(t) < len(ans):
                    ans = t
    return ans


print(fold(s))
