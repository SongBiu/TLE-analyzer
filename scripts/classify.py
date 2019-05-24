from sklearn.svm import SVC
from sklearn import metrics
from sklearn.model_selection import train_test_split
import os
from sklearn.ensemble import AdaBoostClassifier
from sklearn.ensemble import RandomForestClassifier
import numpy as np

ins = ["ROADS.in1.in", "ROADS.in2.in", "ROADS.in3.in", "ROADS.in4.in",
       "ROADS.in5.in", "ROADS.inA.in", "ROADS.in7.in", "ROADS.in8.in", "ROADS.in9.in"]

for name in ins:
    print(name)
    x_name = f"X_{name}.npy"
    y_name = f"y_{name}.npy"
    X = np.load(x_name)
    y = np.load(y_name)

    x_train, x_test, y_train, y_test = train_test_split(
        X, y, test_size=0.3, random_state=0)

    clf = SVC(random_state=0, tol=1e-5)
    clf.fit(x_train, y_train)
    y_pred = clf.predict(x_test)
    y_train_pred = clf.predict(x_train)
    print("svm train ac:", clf.score(x_train, y_train))
    print("svm train recall", metrics.recall_score(y_train, y_train_pred))
    print("svm test ac:", clf.score(x_test, y_test))
    print("svm test recall:", metrics.recall_score(y_test, y_pred))

    clf = AdaBoostClassifier(n_estimators=100, random_state=0)
    clf.fit(x_train, y_train)
    y_pred = clf.predict(x_test)
    y_train_pred = clf.predict(x_train)
    print("boost train ac:", clf.score(x_train, y_train))
    print("boost train recall", metrics.recall_score(y_train, y_train_pred))
    print("boost test ac:", clf.score(x_test, y_test))
    print("boost test recall:", metrics.recall_score(y_test, y_pred))

    clf = RandomForestClassifier(n_estimators=100, max_depth=2, random_state=0)
    clf.fit(x_train, y_train)
    y_pred = clf.predict(x_test)
    y_train_pred = clf.predict(x_train)
    print("forest train ac:", clf.score(x_train, y_train))
    print("forest train recall", metrics.recall_score(y_train, y_train_pred))
    print("forest test ac:", clf.score(x_test, y_test))
    print("forest test recall:", metrics.recall_score(y_test, y_pred))
