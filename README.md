 Custom Memory Allocator in C

A simple dynamic memory allocator simulation written in C, built without using malloc or free.
Implements a fixed-size array-based heap with first-fit allocation and manual deallocation.

 Features

- First-fit gap search via find_gap()
- Header-based block tracking (block size stored in leading cell)
- Automatic shrinking of heap top on tail-free (top pointer rollback)
- Interactive CLI: allocate blocks, free them by header index, inspect memory state

 How It Works

Each allocation stores the block size in a header cell, followed by OCCUPIED (4) sentinel values.


  Index:  [0]  [1]  [2]  [3]  [4]  [5]  [6]
  Value:   3    4    4    4    2    4    4
           ^header  ^data      ^header  ^data


Freeing a block zeros out the header + data cells.
If the freed block is at the end of the heap, top is rolled back.

 Usage

gcc memory_allocator.c -o mem && ./mem

Enter a positive number to allocate N bytes.
Enter -1 to free a block (you'll be prompted for the header index).
Enter 0 to exit.

 Known Limitations

- Fixed heap size (50 cells)
- No coalescing of adjacent free blocks
- Single-threaded only

 Concepts Demonstrated

Manual memory management · First-fit allocation · Header metadata · Heap compaction
