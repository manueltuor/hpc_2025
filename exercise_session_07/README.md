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

### Exercise 2

a. What data type is M (integer, pointer to integer, ...)?

M is type int**, so a pointer to a pointer to an integer

b. What are M, *M, **M?

	•	M: the pointer to the first element of the array of pointers (M[0]).
	•	*M: same as M[0], a pointer to the first integer of the first row.
	•	**M: same as M[0][0], the first integer of the first row.

c. What is M[1][3], *(M[0]+1), *(*(M+1)+3)?

	•	M[1][3]: the 4th element of the second row = 8
	•	*(M[0]+1): the second element of the first row = 1
	•	*(*(M+1)+3): 4th element of second row = 8

d. Are the M[0] and M[1] arrays stored next to each other in the memory? In other words, is it true that *(M[0]+5)==M[1][0]?

	•	No, M[0] and M[1] are two separate allocations, so memory may not be contiguous.
	•	*(M[0]+5): undefined behavior. You cannot assume it equals M[1][0].

