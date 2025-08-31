# Push Swap - 42 school project
# Algorithm based challenge to sort a stack in ascending order

## Project guidelines
The goal was to sort a list of integers in stack A in ascending order using only one helper stack, stack B, and a limited set of predefined moves. The purpose of the project was to select and implement an efficient algorithm.

## Behavior
The program sorts stack A in ascending order. Stack content is provided via command-line arguments.<br>
It uses my implementation of the Turk algorithm to perform the sorting.
Program accepts only integer values as input, sorts them, and **outputs moves to achieve the sorted state**.

*Program calculates the cheapest node to move from stack A to stack B, building stack B in descending order.<br>
It applies the same logic again: finds the cheapest order to move content back to stack A, this time in ascending order.*

### Moves
>sa: Swap the first 2 elements at the top of stack a.<br>
>sb: Swap the first 2 elements at the top of stack b.<br>
>ss: sa and sb at the same time.<br>
>
>pa: Take the first element at the top of b and put it at the top of a.<br>
>pb: Take the first element at the top of a and put it at the top of b.<br>
>
>ra: Shift up all elements of stack a by 1.
The first element becomes the last one.<br>
>rb: Shift up all elements of stack b by 1.
The first element becomes the last one.<br>
>rr : ra and rb at the same time.
>
>rra: Shift down all elements of stack a by 1.
The last element becomes the first one.<br>
>rrb: Shift down all elements of stack b by 1.
The last element becomes the first one.<br>
>rrr : rra and rrb at the same time.

## Usage
To compile and run the program, and count the number of moves:
>make<br>
>./push_swap $ARGS | wc -l
>
*where ARGS=given integer values*
  
Already sorted stack displays nothing<br>
Invalid input results in "Error\n", as specified in the project requirements.<br>

## Results
The project was tested in peer evaluations based on sorting efficiency, achieving results aligned with the expected performance of the Turk sorting algorithm.

 sorts 100 elements on ~650 moves<br> 
 sorts 500 elements on ~6300 moves<br>
*medians based on peer testing conducted at Hive Helsinki*
