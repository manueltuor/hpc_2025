# Exercise Sheet 4

## Exercise 1

- $HOME: drwx------ 2 mtuor uzh8 4096 Okt 10 10:10 /users/mtuor => meaning the owner can read, write and execute, others can not access your home folder though, and you can not access others home folders
- $SCRATCH: drwxr-x---+ 2 mtuor uzh8 4096 Sep 18 11:23 /capstor/scratch/cscs/mtuor => meaning the owner has full access, the group can read and execute, others have no access, so I could access other students scratch directory
- Default permissions for new files:
    - $HOME: -rw-r--r-- 1 mtuor uzh8 0 Okt 16 22:45 /users/mtuor/testfile.txt => owner can read and write, group can read, others can read
    - $SCRATCH: -rw-r-----+ 1 mtuor uzh8 0 Okt 16 22:44 /capstor/scratch/cscs/mtuor/testfile.txt => owner can read and write, group can read
- Permissions for /users/meberlei: drwx------ 2 meberlei uzh8 4096 Okt 16 17:35 /users/meberlei => only the owner can access it. Even if I knew that /users/meberlei/exam solutions.txt exists I could not open it since I have no execute permission on the parent directory and no read permission on the file.
- Command so only owner has full access: chmod 700 dir
- Create group file:
    - [eiger][mtuor@eiger-ln004 ~]$ touch $SCRATCH/groupfile.txt
    - [eiger][mtuor@eiger-ln004 ~]$ chmod 660 $SCRATCH/groupfile.txt
    - [eiger][mtuor@eiger-ln004 ~]$ ls -l $SCRATCH/groupfile.txt
    - -rw-rw----+ 1 mtuor uzh8 0 Okt 16 22:54 /capstor/scratch/cscs/mtuor/groupfile.txt
- Create locked file:
    - [eiger][mtuor@eiger-ln004 ~]$ touch $SCRATCH/lockedfile.txt
    - [eiger][mtuor@eiger-ln004 ~]$ chmod 000 $SCRATCH/lockedfile.txt
    - [eiger][mtuor@eiger-ln004 ~]$ ls -l $SCRATCH/lockedfile.txt
    - —————+ 1 mtuor uzh8 0 Okt 16 22:56 /capstor/scratch/cscs/mtuor/lockedfile.txt
    - To regain access to the file I can run: chmod 600 $SCRATCH/lockedfile.txt

## Exercise 2

1. End with 00: 00$
2. Start and end with 1: ^1[01]*1$
3. Contain the pattern 110: 110
4. Contain at least three times a 1: 1.*1.*1
5. Contain at least three consecutive 1s: 111

## Exercise 3

- The factor command returns the prime factorization of an input, so 20 returns 2, 2, 5 and 31 returns 31.
- Time results:
  [eiger][mtuor@eiger-ln004 exercise_session_04]$ ./isprime.sh 4230283
    4230283 is prime Execution time: 0.004035 seconds
    [eiger][mtuor@eiger-ln004 exercise_session_04]$ ./isprime.sh 4572862171001
    4572862171001 is prime
    Execution time: 0.003996 seconds


