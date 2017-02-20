import random
import math

random.seed(int(1e9+7))

inputFile = "MRobot.inp"


def generate(T, N, folder):
    iWriter = open(folder + "/" + inputFile, "w")
    iWriter.write('%i\n' % T)
    for i in range(T):
        iWriter.write('%i %i\n' % (random.randint(N/2, N), random.randint(N/2, N)))
    iWriter.close()

Ns = [10, 20, 30, 40, 50, 100, 1000, 2000, 3000, 5000,
      10000, 20000, 50000, 70000, 80000, 100000, 200000, 500000, 700000, 1000000]

for i in range(20):
    foler = str(i)
    if len(foler) < 2:
        foler = "0" + foler
    foler = "Test" + foler
    print foler

    T, N = ((i+1)*50, min(1000000, Ns[i]))
    print T, N
    generate(T, N, foler)
