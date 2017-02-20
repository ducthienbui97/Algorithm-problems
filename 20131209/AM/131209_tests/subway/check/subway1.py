from collections import defaultdict

def parts(s):
    '''
    Given string of 0s and 1s, return the strings corresponding to the subtrees
    '''
    zeros = 0
    ones = 0
    current_start = 1
    parts = []
    for i in xrange(len(s)):
        if s[i] == '0':
            zeros += 1
        else:
            ones += 1
        if zeros == ones:
            parts.append(s[current_start:i])
            current_start = i+2
    return parts

def compare(x, y):
    '''
    Return true if two strings correspond to the same tree starting from the same root
    '''
    a = parts(x)
    b = parts(y)
    if len(a) != len(b):
        return False
    for x in a:
        for j in xrange(len(b)):
            if compare(x, b[j]):
                b.pop(j)
                break
        else:
            return False
    else:
        return True

n = int(raw_input())
unique = []
for i in xrange(n):
    s = raw_input()
    for x in unique:
        if compare(s, x):
            break
    else:
        unique.append(s)
print len(unique)
