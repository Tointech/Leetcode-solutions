import timeit
import array 
import numpy as np

# PART 1: Using Comprehension
def dont_1():
    list_object = []
    for i in range(100):
        list_object.append(i)
    return list_object
# 3.0778217649994986 s

def do_1():
    list_object = [i for i in range(100)]
# 2.3802124559997537 s

# PART 2: Dont concat string manually
def dont_2():
    obj_list = ["I", "went", "to", "school", "yesterday", "morning"]
    s = ""
    for el in obj_list:
        s = s + " " + el
    return s
# 0.6674990539995633 s

def do_2():
    obj_list = ["I", "went", "to", "school", "yesterday", "morning"]
    s = " ".join(obj_list)
    return s
# 0.21243107100053749 s

# PART 3: Should use Map function
def dont_3():
    obj_list = ["I", "went", "to", "school", "yesterday", "morning"]
    new_list = []
    for el in obj_list:
        new_list.append(el.upper())
    return new_list
# 0.7063563110004907 s

def up(x):
    return x.upper()

def do_3():
    obj_list = ["I", "went", "to", "school", "yesterday", "morning"]
    new_list = map(up, obj_list)
    return new_list
# 0.4229460389997257 s

# PART 4: Compare List and Set
def do_list():
    obj_list = ["I", "went", "to", "school", "yesterday", "morning"]
    return "I" in obj_list, "love" in obj_list # True False
# 0.2358549109994783 s

def do_set():
    obj_list = {"I", "went", "to", "school", "yesterday", "morning"}
    return "I" in obj_list, "love" in obj_list # True False
# 0.24559592100013106 s

# PART 5: Using Vector operation
n = 500
a = array.array("f")
for i in range(n):
    a.append(i)

b = array.array("f")
for i in range(n, 2*n):
    b.append(i)

# Sum = a1*b1 + a2*b2 + a3*b3 + ...
def dont_5():
    total = 0
    for i in range(len(a)):
        total = total + a[i]*b[i]
    return total 
# 64.51584353499857 s

def do_5():
    total = np.dot(a, b)
    return total
# 3.3095908909999707 s

# Calculate running time
t = timeit.Timer(setup="from __main__ import dont_5", stmt="dont_5()")
print("Dont =", t.timeit()) 

t = timeit.Timer(setup="from __main__ import do_5", stmt="do_5()")
print("Do =", t.timeit()) 


