#!/usr/bin/env python3
from random import choice, randint
from functools import partial

test_cases = 10
sub_cases = 3

UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
LOWER = UPPER.lower()

def gen_seq(size):
    return choice(UPPER)*size

def gen_random_non_nested(size):
    if size == 0:
        return ""
    v = randint(1, size)
    return gen_seq(v) + gen_random_non_nested(size-v)

def gen_random_pure(size):
    return "".join(choice(UPPER) for i in range(size))

def gen_random_nested(max_size, size):
    if size == 0:
        return ""
    if size == 1:
        return choice(UPPER)

    s_r = randint(1, min(max_size,size//2))
    s_s = randint(1, size//s_r)

    return gen_random_nested(max_size,s_s)*s_r + gen_random_nested(max_size,size - s_s*s_r)

gen_funcs = [gen_random_pure, gen_random_non_nested, gen_random_non_nested, partial(gen_random_nested, 3), partial(gen_random_nested, 6)]

min_size = [ 3,  6,  8, 12,  13,
            17, 45, 65, 85, 100]
max_size = [ 3,  6,  8, 12,  13,
            19, 45, 75, 90, 100]

for t in range(test_cases):
    for c, gen_func in enumerate(gen_funcs):
        with open("swallow{}{}.in".format(t+1, LOWER[c]), "w") as fout:
            N = randint(min_size[t], max_size[t])
            fout.write(str(N))
            fout.write("\n")
            fout.write(gen_func(N))
            fout.write("\n")
