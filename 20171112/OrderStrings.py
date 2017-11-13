n = int(input())
ls = []
for i in range(n):
    ls.append(input().split())
tmp = input().split()
k = int(tmp[0]) - 1

comp = [];
for i in range(n):
    if tmp[2] == 'numeric':
        comp.append([int(ls[i][k]),i])
    else:
        comp.append([ls[i][k],i])

for idx in sorted(comp, reverse = tmp[1] == 'true'):
    print(' '.join(ls[idx[1]]))
