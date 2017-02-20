from collections import defaultdict

def graph(s):
    '''
    Return the graph corresponding to a string.
    Returns (v, e), the number of vertices and the dictionary of edges
    '''
    e = defaultdict(list)
    v = 1
    stack = [(0, [])]
    for i in xrange(len(s)):
        if s[i] == '0':
            stack.append((v, []))
            v += 1
        else:
            parent, children = stack.pop()
            e[parent] = children
            for c in children:
                e[c].append(parent)
            stack[-1][1].append(parent)
    e[0] = stack[0][1]
    for c in stack[0][1]:
        e[c].append(0)
    return v, e

def repr(i, e, parent):
    '''
    Returns a representation of a tree starting from vertex i,
    and not including the parent
    '''
    return ''.join(sorted(['0' + repr(j, e, i) + '1' for j in e[i] if j != parent]))

def canonical(v, e):
    '''
    Return a canonical representation of a tree
    '''
    h = v*[-1]
    q = [x for x in xrange(v) if len(e[x]) == 1]
    for x in q:
        h[x] = 0
    i = 1
    while q:
        q1 = []
        for x in q:
            for y in e[x]:
                if h[y] < 0:
                    h[y] = i
                    q1.append(y)
        q = q1
        i += 1
    max_h = max(h)
    return min([repr(i, e, -1) for i in xrange(v) if h[i] == max_h])

n = int(raw_input())
unique = set()
for i in xrange(n):
    unique.add(canonical(*graph(raw_input())))
print len(unique)
