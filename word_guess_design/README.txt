This program will be a two-player word guessing game, wherein one player will enter a word and the other will attempt
to guess said word based on hints given by the program. The design should go as follows:

1. Prompt player 1 to enter a word.
2. Store the word as an array.
3. Calculate and store the word’s length with a for loop.
4. Start a loop, while not all letters have been guessed.
5. Clear the screen and prompt player 2 to guess letters, giving them the length of the word.
6. Along with the previous step, print out blank line or underscore characters, one for each letter of the word.
7. When the user guesses, either tell them their guess is wrong if the letter isn’t present in the array or tell them it's 
   right if it is.
8. Check that all input from player 2 is valid (lowercase letters only).
9. Print out the correct letters, replacing the underscore characters at the positions that they appear in in the array.
10.Keep this process going until no underscore characters are present, meaning that player 2 has guessed all the letters.
11.Print a congratulations message and ask to play again. The whole program should be wrapped in a while loop to allow for 
   easy replayability. 
