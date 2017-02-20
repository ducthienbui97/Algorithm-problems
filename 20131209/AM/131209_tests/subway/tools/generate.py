from sys import argv
from random import randint, shuffle
from collections import defaultdict

b = int(argv[1])
n = int(argv[2])
v = int(argv[3])

u = randint(int((3./4.)*n), n)

def generate(n):
    edges = defaultdict(list)

    for i in xrange(1, n):
        r = randint(0,i-1)
        edges[r].append(i)
        edges[i].append(r)

    return edges

def traverse(edges, i, previous = -1):
    s = ''
    e = edges[i]
    shuffle(e)
    for x in e:
        if x != previous:
            s += '0' + traverse(edges, x, i) + '1'
    return s

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

unique = set()
unique_list = []
for i in xrange(u):
    while True:
        s = canonical(v, generate(v))
        if s not in unique:
            r = randint(0, v-1)
            unique.add(s)
            unique_list.append((s, r))
            break

print n
r = range(u) + [randint(0, u-1) for i in xrange(n-u)]
shuffle(r)
for i in xrange(n):
    if b == 1: # random root
        print traverse(graph(unique_list[r[i]][0])[1], randint(0, v-1))
    else: # specific root
        print traverse(graph(unique_list[r[i]][0])[1], unique_list[r[i]][1])
