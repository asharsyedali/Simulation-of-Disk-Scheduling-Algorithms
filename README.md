# Simulation of Disk Scheduling Algorithms

---

## 🚀 Overview
This repository contains the implementation of four key disk scheduling algorithms:

- **First-Come-First-Serve (FCFS)**
- **Shortest Seek Time First (SSTF)**
- **SCAN (Elevator Algorithm)**
- **LOOK (Optimized SCAN Algorithm)**

The project simulates these algorithms to demonstrate their behavior in optimizing disk performance and minimizing head movement.

---

## 🌟 Features
- 🛠️ Modular implementation in C.
- 📥 Supports user and file-based input for disk requests and initial head position.
- 📊 Displays results in a structured table format for easy comparison.
- 📈 Includes analysis of total head movement for each algorithm.

---

## 🧮 Algorithms Implemented
1. **FCFS**: Processes requests in the order they arrive.
2. **SSTF**: Processes the closest request to the current head position.
3. **SCAN**: Moves the disk head in one direction and serves requests sequentially.
4. **LOOK**: Similar to SCAN but stops at the last request in the current direction.

---

## 💻 Usage

### Prerequisites
- 🖥️ GCC or any compatible C compiler.
- 🐧 Linux or Unix environment for running the simulation.

### 🔨 Compilation
Use the provided Makefile to compile the project:
```bash
make
```

### ▶️ Running the Program
Run the compiled program:
```bash
./disk_scheduling
```

Follow the prompts to:
1. Enter the number of requests and their sequence.
2. Specify the initial head position.
3. Choose an algorithm (FCFS, SSTF, SCAN, or LOOK).
4. Specify the scan direction for SCAN/LOOK algorithms (if applicable).

### 📥 Example Input
```plaintext
Enter number of requests: 8
Enter request sequence: 98 183 37 122 14 124 65 67
Enter initial head position: 53
Choose Disk Scheduling Algorithm:
1. FCFS
2. SSTF
3. SCAN
4. LOOK
Enter choice: 3
Enter direction (0 for left, 1 for right): 1
```

### 📤 Example Output
```plaintext
SCAN Order: 65 67 98 122 124 183 199 14
Algorithm: SCAN, Total Head Movement: 331
```

---

## 📂 Files Included
- **main.c**: The main program file implementing the algorithms.
- **Makefile**: Simplifies compilation and cleanup.
- **Report.pdf**: Detailed explanation of the project, including input examples, outputs, and analysis.

---

## 📊 Analysis
| Algorithm | Total Head Movement |
|-----------|---------------------|
| FCFS      | 640                 |
| SSTF      | 236                 |
| SCAN      | 331                 |
| LOOK      | 299                 |

---

## 🏁 Conclusion
This project highlights the differences between disk scheduling algorithms in terms of efficiency and fairness. While SSTF minimizes head movement, SCAN and LOOK provide systematic and fair scheduling.

---
