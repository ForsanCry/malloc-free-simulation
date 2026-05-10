# C Custom Memory Manager (First-Fit Algorithm)

This project is a low-level memory management simulator developed in C. It manages a fixed-size array acting as a virtual RAM, implementing custom versions of `malloc` and `free` logic.

## 🚀 Features

- **First-Fit Allocation:** Scans memory for the first available block that fits the requested size, ensuring fast allocation.
- **Implicit Coalescing:** Automatically merges adjacent free blocks by zeroing out headers, creating larger contiguous free spaces.
- **Boundary Retraction:** Features a "Sweeper" logic that shrinks the `top` pointer when the last allocated block is freed, returning memory to the system.
- **Modular Design:** Highly organized architecture with dedicated functions: `find_gap`, `my_alloc`, and `my_free`.
- **Safety Checks:** Includes boundary checks for index ranges and "Out of Memory" (OOM) error handling.

## 🛠️ Technical Overview

The manager operates on a 1D integer array. Each allocated block consists of a **Header** (storing the block size) followed by the actual **Data cells**.

- `int my_alloc(int size)`: Allocates space and returns the starting index (handle).
- `void my_free(int index)`: Releases the block at the given handle and clears the space for future use.

## 📦 Usage

To compile and run the project locally:

```bash
gcc main.c -o memory_manager
./memory_manager
