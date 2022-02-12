#!/usr/bin/env python3

import multiprocessing
import subprocess


def runapp(idx) -> int:
    x = str(idx).zfill(4)
    cmd = "cargo run --release --bin tester ../main.py < in/" + \
        x + ".txt > out/" + x + ".txt"
    p = subprocess.Popen(
        cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    for line in p.stdout.readlines():
        line = line.decode()
        if line.startswith("Score = "):
            x = line.strip("Score = ").strip("\n")
            score = int(x)
            print(idx, score)
            return score


pool = multiprocessing.Pool()
ans = pool.map(runapp, range(0, 99))
print("AVG:", sum(ans)/len(ans))
