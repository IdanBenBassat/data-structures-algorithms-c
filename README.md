# Interactive Data Structures & Algorithms Library in C

A comprehensive, interactive C library showcasing fundamental Data Structures and Sorting Algorithms. This project features robust memory management, custom pointer manipulations, and includes an interactive CLI menu to dynamically demonstrate and benchmark every module.

## Project Structure & Files
* **Core Application:** `main.c` (Includes the interactive test console)
* **Trees:** `avl_tree.c` / `avl_tree.h`, `bst.c` / `bst.h`
* **Hash Table:** `hash_table.c` / `hash_table.h`
* **Linear Structures:** `linked_list.c` / `linked_list.h`, `stack.c` / `stack.h`, `queue.c` / `queue.h`
* **Algorithms:** `sort.c` / `sort.h`

---

## Key Modules & Features

### 1. Interactive CLI Console (`main.c`)
* Features a dynamic terminal-based menu allowing users to select, run, and explore real-time demonstrations of every data structure and algorithm in the library.

### 2. Self-Balancing Trees (AVL) & BST
* **AVL Tree:** Implements a self-balancing Binary Search Tree using Left/Right rotations to guarantee $O(\log n)$ operations.
* **BST:** Standard implementation with recursive search, node deletion, and three traversal strategies (In-order, Pre-order, Post-order). Includes sideways graphical tree printing in the terminal.

### 3. Hash Table with Open Addressing
* Features array-based buckets utilizing linear probing for collision resolution.
* Uses state tracking (`EMPTY`, `FILLED`, `DELETED`) to maintain search integrity.

### 4. Linear Data Structures
* **Singly Linked List:** Supports dynamic memory node chaining, deletion, insertion at start/end/middle, and list reversal.
* **Queue:** Ring-buffer circular array queue with boundary checks.
* **Stack:** Static array stack implementing full overflow/underflow checks.

### 5. Algorithmic Benchmarking
* Compares performance across sorting algorithms: **Bubble Sort**, **Selection Sort**, **Quick Sort**, and **Merge Sort**.
* Built-in benchmarking functionality (`compareSortTimes`) tracks and displays execution times down to microseconds.

---

## Technical Concepts Practiced
* **Manual Memory Management:** Strict usage of `malloc` and `free` with dynamic pointer-to-pointer (`**Node`) manipulation.
* **Algorithm Complexity:** Implementation of divide-and-conquer strategies ($O(n \log n)$ complexity) and self-balancing tree structures.
* **C System Headers:** Utilizes standard libraries like `<time.h>` for execution metrics and `<stdbool.h>` for precise status checks.

---

## How to Build & Run

### Using GCC Compiler (Linux / Terminal)
1. Clone the repository:
   ```bash
   git clone [https://github.com/IdanBenBassat/data-structures-algorithms-c.git](https://github.com/IdanBenBassat/data-structures-algorithms-c.git)
