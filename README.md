# Memory Allocation using segmentation simulation
## Requirements 
- C++ 
- Qt creator 
## Description
Segmentation is a memory management technique in which each job is divided into several segments of different sizes, one for each module that contains pieces that perform related functions. Each segment is actually a different logical address space of the program.  When a process is to be executed, its corresponding segmentation are loaded into non-contiguous memory though every segment is loaded into a contiguous block of available memory.  Segmentation memory management works very similar to paging but here segments are of variable-length where as in paging pages are of fixed size.  A program segment contains the program's main function, utility functions, data structures, and so on. The operating system maintains a segment map table for every process and a list of free memory blocks along with segment numbers, their size and corresponding memory locations in main memory. For each segment, the table stores the starting address of the segment and the length of the segment. A reference to a memory location includes a value that identifies a segment and an offset.  
![](segment_map_table.jpg)
The project simulates memory allocation using segmentation with First-fit ,best-fit and worst-fit algorihtms .
### First-Fit Memory Allocation
In this method, the job segment claims the first available memory with space more than or equal to it’s size. The operating system doesn’t search for appropriate hole/partition but just allocate the job to the nearest memory hole/partition available with sufficient size.
### Best-Fit Memory Allocation 
In this method, the operating system first searches the whole of the memory according to the size of the given job segment and allocates it to the closest-fitting free hole/partition in the memory, making it able to use memory efficiently. 
### Worst_Fit Memory Allocation
In this allocation technique the process traverse the whole memory and always search for largest hole/partition, and then the process is placed in that hole/partition.It is a slow process because it has to traverse the entire memory to search largest bole. 
## Input 
User enter memory size and the number of hole/partition in the memory then specify the starting address and the size of each hole/partition . After that a dialog opens , the user can add a process but he / she has to specify number of segments of this process, the name and size  of each segment and the used algorithm (first , best ,worst).
Also User call deallocate processes .
## Output 
vertical chart represent Memory Alloction accorrding to the used algorithm.   
## Test 
