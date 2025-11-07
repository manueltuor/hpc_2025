## Sheet 7

### Exercise 1

a. What C/C++ type is p?
int[10]: array of 10 integers
b. What is the type of *p?
int: pointer to the first element
c. What is the type of &p?
(*)[10]: pointer to an array of 10 integers
d. What is the value of *p?
10, value of the first array element
e. What is the value of p[0]?
10, value of the first array element
f. What is the value of p[3]?
40, value of the fourth array element
g. What is the value of *(p+5)?
60, value of the 6th array element
h. What is the value of *p+5?
value of the first array element + 5 = 15
i. In some languages (e.g. Python), p[-1] = 42 sets the last (10th) element to 42. What does p[-1] = 42 mean in C/C++?
It accesses memory before the first array element, which might overwrite some other variable or cause a crash.
j. Let: int *q = p-1; What is the value of q[0]. Careful!
Again we do not know since p-1 references unknown memory before the array.
k. What is the value of *(q+10)?
100, points to the 10th element
l. What is the value of *(q+11)?
one element past the array, again references unknwon memory
