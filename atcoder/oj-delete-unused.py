#!/usr/bin/env python3
# oj-delete-unused.py: oj-prepareでコピーしたのに使ってないファイルを消す

import shutil
import pathlib
import os
import hashlib


def file_sha1(file_path, size=4096):
    m = hashlib.sha1()
    with open(file_path, 'rb') as f:
        for chunk in iter(lambda: f.read(size * m.block_size), b''):
            m.update(chunk)
    return m.hexdigest()


main_files = ["main.cpp", "main.go", "main.py", "src/main.rs"]
tmpl_path = "../misc/setup/tmpl"
aux = dict()
aux["src/main.rs"] = ["Cargo.toml", "rust-toolchain"]

rootDir = '.'

tmpl_files_hash = dict()
for n in main_files:
    f = pathlib.Path(tmpl_path, n).absolute().resolve()
    h = file_sha1(f)
    tmpl_files_hash[n] = h
# print(tmpl_files_hash)


delete_dir = []
delete_file = []
for dirName, subdirList, fileList in os.walk(rootDir):
    found = []
    unused = []
    for n in main_files:
        main_path = pathlib.Path(dirName, n).absolute().resolve()
        if main_path.is_file():
            found.append(n)
            # print(f"Found a quiz in {dirName}, ({n})")
            if tmpl_files_hash[n] == file_sha1(main_path):
                unused.append(n)
                # print(f"\tFound unused {n}")
    if len(found) == 0:
        continue
    # print(f"{dirName}, found {found}, unused {unused}")

    if len(found) == len(unused):
        delete_dir.append(pathlib.Path(dirName).absolute().resolve())
    else:
        for n in unused:
            delete_file.append(pathlib.Path(dirName, n).absolute().resolve())
            if n in aux:
                for nn in aux[n]:
                    delete_file.append(pathlib.Path(
                        dirName, nn).absolute().resolve())

print("===== delete dirs =====")
for n in delete_dir:
    n: pathlib.Path
    print(f"delete {n}")

print("===== delete files =====")
for n in delete_file:
    n: pathlib.Path
    print(f"delete {n}")

print("===== confirmation =====")
s = input('ok? type "yes": ')
if s != "yes":
    print("quit")
    exit(0)


for n in delete_dir:
    print(f"rm -rf {n}")
    shutil.rmtree(n)

for n in delete_file:
    print(f"rm {n}")
    os.remove(n)
