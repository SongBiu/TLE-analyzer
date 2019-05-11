import os, shutil

os.system("echo  > ../scripts/out")

root = "../resources/data"

in_root = "/Users/songl/OneDrive/毕业设计/road"

in_files = os.listdir(in_root)

for i in range(len(in_files)):
    in_files[i] = f"{in_root}/{in_files[i]}"


dirs = os.listdir(root)


def run(path, name, mode, func, result):
    global in_files
    mean = 0
    n = len(in_files)
    command = f"echo {path} {mode}: >> ../scripts/out"
    for in_file in in_files:
        os.system(command)
        print(command)
        command = f"./run {path} {name} {func} {result} < {in_file} | grep 'result is'"
        r = os.popen(command)
        line = r.readline()
        if line == '':
            n -= 1
            continue
        cnt = int(line.strip().split(' ')[-1])
        if cnt == -1:
            n -= 1
        else:
            mean += cnt
    if mean != 0:
        mean /= 1.0 * len(in_files)
    os.system(f"echo {mean} >> ../scripts/out")
        

for file in dirs:
    if not os.path.isdir(f"{root}/{file}"):
        continue
    path = f"{root}/{file}"
    for code in os.listdir(f"{root}/{file}"):
        with open(f"{path}/{code}") as f:
            line = f.readline()
            func = line.split(" ")[1].strip()
            result = line.split(" ")[2].strip()
        if code.split("_")[1] == "TLE.cpp":
            run(path, code.split('.')[0], "TLE", func, result)
        else:
            run(path, code.split('.')[0], "AC", func, result)
