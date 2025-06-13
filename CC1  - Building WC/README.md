# **C WC Tool Clone**

This project is an implementation of a command-line tool similar to the Unix `wc` (word count) utility, written in C. It's based on [Coding Challenge #1](https://codingchallenges.fyi/challenges/challenge-wc) by John Crickett.

The goal is to build `ccwc` (Coding Challenge Word Count) step-by-step, adding new features at each stage.

---

## **✅ Requirements**

- [ ] **Step 1: Count Bytes (`-c`)**

  - Implement the `-c` option to count the number of bytes in a file.
  - Example: `ccwc -c test.txt` should output `342190 test.txt`.

- [ ] **Step 2: Count Lines (`-l`)**

  - Implement the `-l` option to count the number of lines in a file.
  - Example: `ccwc -l test.txt` should output `7145 test.txt`.

- [ ] **Step 3: Count Words (`-w`)**

  - Implement the `-w` option to count the number of words in a file.
  - Example: `ccwc -w test.txt` should output `58164 test.txt`.

- [ ] **Step 4: Count Characters (`-m`)**

  - Implement the `-m` option to count the number of characters, accounting for multi-byte characters.
  - Example: `ccwc -m test.txt` should output `339292 test.txt`.

- [x] **Step 5: Default Option**

  - If no options are provided, the tool should output the line, word, and byte counts.
  - Example: `ccwc test.txt` should output `7145   58164  342190 test.txt`.

- [ ] **Step 6: Handle Standard Input (stdin)**
  - The tool should be able to process data piped from standard input if no filename is given.
  - Example: `cat test.txt | ccwc -l` should output `7145`.

---

## **🚀 How to Use**

1.  **Compile the Program**:
    Use a C compiler like GCC to create the executable.

    ```bash
    gcc -o ccwc ccwc.c
    ```

2.  **Run with an Option**:
    Execute the program with one of the options and a file path.

    ```bash
    ./ccwc -c test.txt
    ```

3.  **Run with Standard Input**:
    Pipe data into the program.
    ```bash
    cat test.txt | ./ccwc -l
    ```

## References

- [C Standard Library documentation for file I/O functions.](https://en.cppreference.com/w/c/io)
- [POSIX `getopt` documentation for parsing command-line options.](https://pubs.opengroup.org/onlinepubs/009696799/functions/getopt.html)
