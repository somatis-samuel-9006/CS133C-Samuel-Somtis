DESIGN:

- Use a function to initialize the gameboard display by looping through the array, making each character = '_'.
- Use similar functions to update the display. Set the element at the position passed to the function to be = either x or o, reprint array.
- In wincheck function, use for loops and if statements to determine if patterns of equality that yield a tick tack toe win have been achieved.
If so, return 1 and have the game end and print a victory message.. Otherwise, if all turns have been taken return 2 or if turns are left return 0.
- Call initializing function at the start of main.
- Use a while loop to continually ask for x and o positions in the array until the counter reaches 9. After each guess, incriment the counter, call
wincheck to see if turns are still left, if so print a message saying so, and check if the counter = 9. If so, break out of the loop.
-When the loop ends, call wincheck to determine if a victory or tie has occured and print the appropriate message.

TESTING:

Input		Expected			Output

Horizontal	"You win"			"You win"
victory

Vertical		"You win"			"You win"
victory

Diagonal		"You win"			"You win"
victories

No victory	"Tie"			"Tie"
pattern

REFLECTION:

Going in, I didn't have much experience with 2D arrays in C. The most I'd had was making a simple list of names. This project was very good
practice for making them via loops and working with them in loops, function calls, etc. The hardest part was determining the proper logic
for determining a victory in the wincheck function that wouldn't cause other parts of the program to break. It took some discussion and code
re-organizing but I now have a better working understanding of it.