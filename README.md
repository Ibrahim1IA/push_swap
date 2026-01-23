*This project has been created as part of the 42 curriculum by iissoufo.*

## Description

Push_swap is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations. The goal is to implement an efficient sorting algorithm that uses the fewest possible operations to sort the stack in ascending order.

The project consists of two programs:
- `push_swap`: Takes a list of integers as arguments and outputs a series of operations to sort the stack.
- `checker` (bonus): Takes the same arguments and reads operations from standard input to verify if the sorting is correct.

The allowed operations are:
- `sa` (swap a): Swap the first two elements of stack a
- `sb` (swap b): Swap the first two elements of stack b
- `ss`: sa and sb at the same time
- `pa` (push a): Take the first element of stack b and put it on top of stack a
- `pb` (push b): Take the first element of stack a and put it on top of stack b
- `ra` (rotate a): Shift all elements of stack a up by one
- `rb` (rotate b): Shift all elements of stack b up by one
- `rr`: ra and rb at the same time
- `rra` (reverse rotate a): Shift all elements of stack a down by one
- `rrb` (reverse rotate b): Shift all elements of stack b down by one
- `rrr`: rra and rrb at the same time

## Instructions

### Compilation

To compile the project, use the provided Makefile:

```bash
make
```

This will create the `push_swap` executable.

For the bonus checker:

```bash
make bonus
```

This will create the `checker` executable.

### Execution

Run the program with a list of integers:

```bash
./push_swap 3 1 4 1 5 9 2 6
```

The program will output a series of operations to sort the stack.

To check if the operations sort correctly, pipe the output to the checker:

```bash
./push_swap 3 1 4 1 5 9 2 6 | ./checker 3 1 4 1 5 9 2 6
```

The checker will output "OK" if sorted correctly, "KO" otherwise.

### Cleaning

To clean object files:

```bash
make clean
```

To clean everything:

```bash
make fclean
```

To recompile:

```bash
make re
```

## Resources

- [Push_swap project explanation](https://youtu.be/wRvipSG4Mmk?si=iS4BkF850GzdPS-O) - by Thuggonaut 
- [Sorting Algorithms and project concept explanation](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap) - gitbook
- [Sorting algorithms Used](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) - Overview of sorting algorithms