Github: https://github.com/somatis-samuel-9006/CS133C-Samuel-Somtis

Design:

This program is a turn based game of battleship. It has some basic info about player data that is stored as ints and pointers to char arrays within
nested structs. Malloc is used to create space for these names. It uses user IO to first ask players for their real and user names. It initializes the
display as 2 8x8 game boards, that are 2D arrays filled with the '_' character. The define macro is used when building these arrays. The program
prompts each player for 3 spots on their board to choose by asking for row and column numbers. If the input is less than 0 or more than 7, or
not a int at all, an invalid message is printed and the user is prompted to try again. As the game is played, the two game board displays are
updated after each guess, with either an X or an O in the case of a hit, or a '*' is the case of a miss. Once a player gets 3 hits, the game ends
and a game summary is written out to a text file. This summary includes my name, which is stored as an array of strings, the player names,
stored in an array of pointers, the name of the player that won, and the factorial of that players guesses which is calculated using a recursive
function.

Testing:

Input		Expected			Output

Proper ints	Everything works		Everything works
<0 or >7		Invalid, try again		Invalid, try again
non-ints		Invalid, try again		Invalid, try again

Reflection:

This program turned out to be a lot harder than I thought, mainly becuase I didn't give myself enough time to get it done in a calm and steady
manner. There were some pretty new concepts I had to use, such as structs and malloc. Learning how these worked was one of the hardest
parts of the project. The other hardest part was input validation for non-int values. I faced a variety of issues and bugs from this and I had to
learn about clearing the buffer and a variety of different functions. Some of the easier parts of the project was doing the recursive function and
the file I/O. Overall this project was stressful but it was a good learning experience.