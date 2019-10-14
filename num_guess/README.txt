DESIGN:

This program is a number guessing game that repeatedly asks for number guesses. At the end, it asks if the user would
like to play again. To do this, two while loops are used. The outer loop uses a variable that is assigned a value of 1. 
At the end, if the user inputs 'y' for the play again prompt, it stays 1. Otherwise, it's set to 0 and the program ends.
The nested while loop repeatedly prompts for number guesses. Variables for things like whether the user has lost the game
and their guess, guess limit, and amount of guesses are used. The try count is incremented by 1 for every guess until the
limit is reached. Two variables for a closest low and closest high guess are used for keeping track of the closest value
to the correct one that the user guesses. Variables named high and low are used to update the range of possible answers
after each guess. When the game is over, the differences between the closest high/low variables and the correct answer
are calculated to determine the overall closest guess. This closest guess as well as the correct answer are printed back
to the user.

TESTS:

Input		Expected	Output

5		Go higher,	Go higher,
		range 6-50	range 6-50

45		Go lower,	Go lower,
		range 6-44	range 6-44

39		Correct! play	Correct! play
		again?		again?

Guesses: 1-7	Closest = 7	Closest = 7	// Required bugfixing for incorrect values
		Correct = 39	Correct = 39

Guesses: 49-43	Closest = 43	Closest = 43	// Required bugfixing for incorrect values
		Correct = 49	Correct = 49

Play again? 'y'	<Game restarts>	<Game restarts>

Play again? 'n' <Program ends>	<Program ends>


REFLECTION:
The main new thing I learned from this project was using getchar() to discard the newline character to ensure that my
loop was working correctly. Other than that, most of this project was more practice for me using control flow statements
like if and while. The main point of struggle for me was keeping track of the closest guess, and then making sure the the
correct closest guess was returned in all situations. But with a little thinking and debugging, I managed to get a working
solution to that problem. Overall it was a fun and engageing assignment.


