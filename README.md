# Custom Memory Allocator in C

A simple dynamic memory allocator simulation written in C, built without using `malloc` or `free`. Implements a fixed-size array-based heap with first-fit allocation and manual deallocation.

## Features

- First-fit gap search via `find_gap()`
- Header-based block tracking (block size stored in leading cell)
- Automatic shrinking of heap top on tail-free (`top` pointer rollback)
- Interactive CLI: allocate blocks, free them by header index, inspect memory state

## How It Works

Each allocation stores the block size in a header cell, followed by `OCCUPIED (4)` sentinel values.

```
Index:  [0]  [1]  [2]  [3]  [4]  [5]  [6]
Value:   3    4    4    4    2    4    4
         ^hdr  ^data        ^hdr  ^data
```

Freeing a block zeros out the header and data cells. If the freed block sits at the end of the heap, the `top` pointer is rolled back to reclaim that space.

## Usage

```bash
gcc memory_allocator.c -o mem && ./mem
```

| Input | Action |
|-------|--------|
| Positive integer | Allocate N cells on the heap |
| `-1` | Enter free mode (prompts for header index) |
| `0` | Exit the program |

After each operation the current state of the array is printed so you can follow along.

## Known Limitations

- Fixed heap size (50 cells)
- No coalescing of adjacent free blocks
- No bounds checking on the `OCCUPIED` sentinel value
- Single-threaded only

## Concepts Demonstrated

- Manual memory management
- First-fit allocation strategy
- Header metadata for block tracking
- Heap compaction via `top` pointer rollback
