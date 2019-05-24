import os
import shutil
import numpy as np
from sklearn.svm import LinearSVC
from sklearn import metrics
from sklearn.model_selection import train_test_split


os.system("echo  > ../scripts/out")

root = "../resources"
ac_dir = f"{root}/ac"
tle_dir = f"{root}/tle"

in_root = "/Users/songl/OneDrive/毕业设计/road"

in_files = os.listdir(in_root)

for i in range(len(in_files)):
    in_files[i] = f"{in_root}/{in_files[i]}"


X = []
y = []


def run(path, name, mode, func, result, input):
    global X, y
    command = f"./run {path} {name} {func} {result} {input} | grep 'number is'"
    r = os.popen(command)
    lines = r.readlines()
    if len(lines) != 3:
        return
    store = float(lines[0].split(" ")[-1])
    call = float(lines[1].split(" ")[-1])
    time = float(lines[2].split(" ")[-1])

    feature = np.array([store, call, time])

    r = 0
    if mode == "TLE":
        r = 1

    X.append(feature)
    y.append(r)


def classify(X, y):
    x_train, x_test, y_train, y_test = train_test_split(
        X, y, test_size=0.3, random_state=0)
    clf = LinearSVC(random_state=0, tol=1e-5)
    clf.fit(x_train, y_train)
    y_pred = clf.predict(x_test)
    print(clf.score(x_train, y_train))
    print(clf.score(x_test, y_test))
    print(metrics.recall_score(y_test, y_pred))

for file_input in in_files:
    X = []
    y = []
    ac_time = []
    tle_time = []
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
    input_name = file_input.split("/")[-1]
    np.save(f"X_{input_name}.npy",np.array(X))
    np.save(f"y_{input_name}.npy",np.array(y))
