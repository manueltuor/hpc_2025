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

### Exercise 3

a. Which variable (x or y) tells you which row it is, and which tells you the column?

y determines the row and x the column

b. How many total elements are in the table?

14 * 6 = 84

c. Are the elements (1, 3) and (1, 4) adjacent in memory, or is it rather (1, 3) and (2, 3)?

(1,3) has linear index 17, (1,4) has linear index 18, so they are adjacent, (2,3) has linear index 31, so it is not adjacent to (1,3)

d. Is one of these choices “better”? Why or why not?

The row-major layout is better if you need to access elements in row sequence so accessing (1,3) and then (1,4) is better for cache performance than (1,3) and then (2,3).

e. From now on assume “row-major” order, meaning that elements in each row are adjacent to each other. The “stride” tells you the distance between elements in the given direction. What is the stride for the x dimension?

Elements in the same row are contiguous so the stride is equal to 1.

f. What is the stride of the y dimension?

To go from one row to the next you need 14 steps, like the number of columns, so the stride is 14.

g. Remember again that elements are stored adjacent in memory. Assume that rows are stored adjacent to each other. This means that if you have a table of integers (int *A) then the element (0, 0) is at A[0], element (0, 1) is at A[1] and so on. Where is element (0, 10)?

(0, 10) is at A[10]

h. Where is element (3, 0)?

(3, 0) is at A[42], (3 * 14 + 0)

i. Where is element (7, 4)?

out of bounds, since the array only has 6 rows
