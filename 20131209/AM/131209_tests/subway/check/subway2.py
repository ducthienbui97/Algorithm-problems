from collections import defaultdict

def canonical(s):
    '''
    Return canonical representation of tree given by string s,
    assuming it starts from a particular root
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
            parts.append('0' + canonical(s[current_start:i]) + '1')
            current_start = i+2
    return ''.join(sorted(parts))

n = int(raw_input())
unique = set()
for i in xrange(n):
    unique.add(canonical(raw_input()))
print len(unique)
