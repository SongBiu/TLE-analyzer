import os
resource_dir = "../resources"

files = os.listdir(resource_dir)

def read_std_out():
    with open('../scripts/stdout') as f:
        return f.readlines()

correct = 0

all = 0

for file in files:
    if file[-8:] != "_TLE.cpp":
        print(file[-8:])
        continue
    cmd = f"./run {file[:-4]} < ../scripts/in > ../scripts/out"
    print(cmd)
    path = f"{resource_dir}/{file}"
    os.system(cmd)
    with open('../scripts/out') as f:
        out = f.readlines()
    stdout = read_std_out()

    if len(stdout) != len(out):
        cmd = f"echo {file} >> ../scripts/files"
        all += 1
        os.system(cmd)
        continue
    error = False
    for i in range(len(out)):
        out_line = out[i].strip()
        stdout_line = stdout[i].strip()
        if out_line != stdout_line:
            cmd = f"echo {file} >> ../scripts/files"
            all += 1
            os.system(cmd)
            error =True
            break
    if not error:
        all += 1
        correct += 1

print(correct, all)
print(correct * 1.0 / all)
