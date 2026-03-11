*This project has been created as part of the 42 curriculum by esteiner.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum.  
The goal is to sort a stack of integers using a **limited set of stack operations** while producing **as few instructions as possible**.

The program receives a list of integers as command line arguments and outputs a sequence of operations that sorts them.

The program works with two stacks:

- **Stack A** – initially contains all numbers
- **Stack B** – initially empty

Only a restricted set of operations is allowed (swap, push, rotate, reverse rotate).  
The challenge of the project is not only to sort the numbers, but to do so **efficiently**.

This implementation uses a variation of the **Turk Algorithm**, where the algorithm calculates the optimal element to move based on the **lowest rotation cost**.

---

# Algorithm Overview

## Indexing

Before sorting begins, the program assigns an **index to each number** representing its final sorted position.

To do this, the input values are first copied and **pre-sorted using bubble sort**.  
The sorted order is then used to assign each element an index.

Example:

Input:
[-42, 3, 100, 7]

Sorted:
[-42, 3, 7, 100]

Indexes:
-42 → 0  
3 → 1  
7 → 2  
100 → 3  

Using indexes simplifies comparisons and makes the algorithm independent from the actual integer values.

---

## Data Structure

The stacks are implemented as a **circular doubly linked list**.

Each node stores:

- the number
- its index
- its current position in the stack
- the target position
- the cost of moving it
- pointers to the **next** and **previous** node

The circular structure makes rotations efficient in both directions.

---

## Sorting Strategy (Turk Algorithm)

The main sorting algorithm works as follows:

1. Push all elements except **three** from stack A to stack B.
2. While pushing elements to B, smaller numbers are pushed deeper in B to slightly pre-sort it.
3. Sort the remaining **three numbers in stack A** using hardcoded logic.
4. While stack B is not empty:
   - calculate the **target position in A** for every element in B
   - calculate the **total cost** required to move each element
   - select the element with the **lowest cost**
   - execute the required rotations and push it back to A
5. After B is empty, rotate A until the **smallest element is at the top**.

---

## Small Stack Optimizations

Special cases are handled separately.

### 2 Numbers

If the two numbers are not sorted:

sa

---

### 3 Numbers

There are only **5 possible permutations**, so they are handled with simple conditional checks using the allowed operations.

---

### 5 Numbers

1. Push two numbers to B.
2. Sort the remaining three numbers.
3. Insert the remaining elements from B back into A in the correct position.

---

# Instructions

## Compilation

Clone the repository and compile the program:

make

This will create:

./push_swap

---

## Running push_swap

Example:

./push_swap 3 2 1

Output example:

sa  
rra  

These instructions represent the operations needed to sort the stack.

---

## Bonus: checker

The bonus part includes a **checker program** that verifies whether a sequence of instructions correctly sorts the stack.

Compile it using:

make bonus

This creates:

./checker

The checker reads instructions from **standard input**, executes them, and then checks if:

- stack A is sorted
- stack B is empty

Example:

./push_swap 3 2 1 | ./checker 3 2 1

Output:

OK

If the instructions do not correctly sort the stack:

KO

The checker stops reading instructions when:

- an invalid instruction is encountered
- a newline or end-of-file is reached

---

## Testing

A helper target is included for quick testing with random numbers:

make check

This runs tests with random input sizes such as:

- 3 numbers
- 5 numbers
- 10 numbers
- 100 numbers
- 500 numbers

---

# Project Structure

push_swap/

operations/  
 pushing.c  
 swapping.c  
 rotating.c  
 reverse_rotating.c  

bonus/  
 checker.c  
 execute_instructions.c  
 operations/  

get_next_line/  

push_swap.c  
push_swap_help.c  
sorting.c  
sorting_3_and_5.c  
getting_the_index.c  
cost_calculate.c  
find_target_position.c  
execute_lowest_cost.c  

libft/

---

# Resources

Useful references related to this project:

Sorting Algorithms  
https://en.wikipedia.org/wiki/Sorting_algorithm  

Doubly Linked Lists  
https://www.geeksforgeeks.org/doubly-linked-list/  

Push_swap explanations and community guides  
Various push_swap tutorials and visualizers created by the 42 community.

---

# AI Usage

AI tools were used during development for:

- improving code readability
- clarifying algorithm concepts
- Helping with indentifing bugs
- understanding concepts

The algorithm design, data structures, and implementation were developed manually by the project author.
