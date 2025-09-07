# Push Swap – 42 School Project  
### Algorithmic challenge to sort a stack in ascending order


---


## Project Guidelines
The goal is to sort a list of integers in **stack A** in ascending order using only one other stack (**stack B**) and a set of predefined operations. Purpose of the project was to implement an efficient algorithm that minimizes the number of moves.


---


## Program Behavior
The program accepts a list of integers via command-line arguments and outputs the sequence of operations required to sort them.
It uses a custom implementation of the **Turk algorithm**, which:
- Calculates the cheapest node to move from stack A to stack B, building stack B in descending order.
- Then applies the same logic to move elements back to stack A in ascending order.

### Moves

| Move | Description |
|------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | Perform `sa` and `sb` simultaneously |
| `pa` | Push the top element of stack B to stack A |
| `pb` | Push the top element of stack A to stack B |
| `ra` | Rotate stack A upwards |
| `rb` | Rotate stack B upwards |
| `rr` | Perform `ra` and `rb` simultaneously |
| `rra`| Reverse rotate stack A |
| `rrb`| Reverse rotate stack B |
| `rrr`| Perform `rra` and `rrb` simultaneously |

---

## Build instructions

- Only valid integers are accepted.
- Already sorted input produces no output.
- Invalid input results in `"Error\n"` as per project specifications.

To compile and run the program:

```zsh
make
./push_swap <ARGS>

