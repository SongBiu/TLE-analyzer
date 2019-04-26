import os
resource_dir = "../resources"

files = os.listdir(resource_dir)

def read_std_out():
    with open('../scripts/stdout') as f:
        return f.readlines()

correct = 0

for file in files:
    cmd = f"./run {file[:-4]} < ../scripts/in > ../scripts/out"
    print(cmd)
    os.system(cmd)
    with open('../scripts/out') as f:
        out = f.readlines()
    stdout = read_std_out()
    if len(stdout) != len(out):
        continue
    error = False
    for i in range(len(out)):
        out_line = out[i].strip()
        stdout_line = stdout[i].strip()
        if out_line != stdout_line:
            error =True
            break
    if not error:
        correct += 1

print(1- correct * 1.0 / len(files))
