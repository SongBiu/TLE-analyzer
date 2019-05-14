import os
import shutil

os.system("echo  > ../scripts/out")

root = "../resources"
ac_dir = f"{root}/ac"
tle_dir = f"{root}/tle"

in_root = "/Users/songl/OneDrive/毕业设计/road"

in_files = os.listdir(in_root)

for i in range(len(in_files)):
    in_files[i] = f"{in_root}/{in_files[i]}"


ac_store_num = 0
ac_call_num = 0
ac_count = 0
tle_store_num = 0
tle_call_num = 0
tle_count = 0


def run(path, name, mode, func, result, input):
    global ac_store_num, ac_call_num, ac_count, tle_store_num, tle_call_num, tle_count
    command = f"./run {path} {name} {func} {result} {input} | grep 'number is'"
    print(command)
    r = os.popen(command)
    lines = r.readlines()
    if len(lines) != 2:
        return
    store_num = int(lines[0].split(" ")[-1])
    call_num = int(lines[1].split(" ")[-1])
    if mode == "TLE":
        tle_store_num += store_num
        tle_call_num += call_num
        tle_count += 1
    else:
        ac_store_num += store_num
        ac_call_num += call_num
        ac_count += 1


for file_input in in_files:
    ac_call_num = 0
    ac_store_num = 0
    ac_count = 0
    tle_call_num = 0
    tle_store_num = 0
    tle_count = 0
    cmd = f"echo {file_input} >> ../scripts/out"
    os.system(cmd)
    for file in os.listdir(ac_dir):
        path = f"{ac_dir}/{file}"
        with open(path) as f:
            line = f.readline()
            func = line.split(" ")[1].strip()
            result = line.split(" ")[2].strip()
            run(ac_dir, file.split('.')[0], "AC", func, result, file_input)
    for file in os.listdir(tle_dir):
        path = f"{tle_dir}/{file}"
        with open(path) as f:
            line = f.readline()
            func = line.split(" ")[1].strip()
            result = line.split(" ")[2].strip()
            run(tle_dir, file.split('.')[0], "TLE", func, result, file_input)
    cmd = f"echo tle_store:{tle_store_num / tle_count} tle_call:{tle_call_num / tle_count} mean:{tle_store_num / tle_call_num} ac_store:{ac_store_num / ac_count} ac_call:{ac_call_num / ac_count} mean:{ac_store_num / ac_call_num} >> ../scripts/out"
    os.system(cmd)
