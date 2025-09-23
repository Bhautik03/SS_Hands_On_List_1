# System Software Practicals  

This repository contains the *System Software Lab Exercises (File and Process Management)* from the course *CS 513 / EC 506*.  

## 📂 Contents  
The practicals are implemented in *C* using *system calls* and *shell scripting* where required.  

### 🔹 File Management Practicals  
1. Create different types of files (soft link, hard link, FIFO).  
2. Program to execute in an infinite loop at background and explore /proc.  
3. Create a file and print the file descriptor (using creat).  
4. Open an existing file in read-write mode (with O_EXCL).  
5. Create 5 new files in infinite loop and check /proc/pid/fd.  
6. Read from STDIN and display on STDOUT (using only read/write).  
7. Copy contents of one file into another (like cp file1 file2).  
8. Read file line by line and display until EOF.  
9. Print file information: inode, hard links, uid, gid, size, block size, number of blocks, timestamps.  
10. Write 10 bytes → move pointer with lseek → write again 10 bytes.  
11. Duplicate file descriptors using dup, dup2, fcntl.  
12. Find out opening mode of a file (fcntl).  
13. Wait for STDIN for 10 seconds using select.  
14. Identify file type (input from command line).  
15. Display environment variables (environ).  
16. Mandatory file locking (read/write).  
17. Online ticket reservation system (file locking).  
18. Record locking to avoid race conditions.  

### 🔹 Process Management Practicals  
19. Time taken to execute getpid system call.  
20. Find and modify process priority using nice.  
21. Use fork to print parent and child process IDs.  
22. Open a file, call fork, and write using both parent and child.  
23. Create a zombie process.  
24. Create an orphan process.  
25. Parent process waits for a specific child using waitpid.  
26. Execute another program using exec family.  
27. Execute ls -Rl using execl, execlp, execle, execv, execvp.  
28. Get maximum and minimum real-time priority.  
29. Get and modify scheduling policy (SCHED_FIFO, SCHED_RR).  
30. Run a script at a specific time using a daemon process.  

---

## ⚙ How to Compile & Run
```bash
# Compile
gcc program.c -o program.out

# Run
./program.out
