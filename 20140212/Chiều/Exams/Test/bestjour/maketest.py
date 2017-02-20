import random
import math

random.seed(int(1e9+7))

inputFile = "bestjour.inp"
outputFile = "bestjour.out"


def generate(N, M, folder):
    iWriter = open(folder + "/" + inputFile, "w")
    oWriter = open(folder + "/" + outputFile, "w")
    iWriter.write('%i\n' % N)
    for i in range(N):
        for j in range(N):
            if i == j:
                iWriter.write('0 ')
            else:
                if i % 3 != 0 or j % 3 != 0:
                    iWriter.write('%i ' % random.randint(M/2, M))
                else:
                    iWriter.write('%i ' % random.randint(M/3, M/2))
        iWriter.write('\n')
    iWriter.close()
    oWriter.close()

for i in range(20):
    foler = str(i)
    if len(foler) < 2:
        foler = "0" + foler
    foler = "Test" + foler
    print foler

    N, M = ((i+1)*25, min(200, (i+1)*25))
    print N, M
    generate(N, M, foler)
