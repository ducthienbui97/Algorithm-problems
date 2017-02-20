from collections import defaultdict

def canonical(s):
    '''
    Give a canonical representation of a tree given by a string s,
    assuming it starts from a particular root
    '''
    stack = [[]]
    for i in xrange(len(s)):
        if s[i] == '0':
            stack.append([])
        else:
            children = stack.pop()
            stack[-1].append(''.join(sorted(['0' + x + '1' for x in children])))
    return ''.join(sorted(['0' + x + '1' for x in stack[0]]))

n = int(raw_input())
unique = set()
for i in xrange(n):
    unique.add(canonical(raw_input()))
print len(unique)
