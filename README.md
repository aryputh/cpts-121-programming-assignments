## cpts 121 programming assignments
All of my programming assignments for my CptS 121 course. Basic description of each PA is available in this file.

### Table of Contents
> [Programming Assignment 1 - Solving Equations](https://github.com/frozenpixel-games/cpts-121-programming-assignments/tree/main?tab=readme-ov-file#programming-assignment-1---solving-equations)<br>
> [Programming Assignment 2 - Solving Equations using Scanning](https://github.com/frozenpixel-games/cpts-121-programming-assignments/tree/main?tab=readme-ov-file#programming-assignment-2---solving-equations-using-scanning)<br>
> [Programming Assignment 3 - GPA Operations](https://github.com/frozenpixel-games/cpts-121-programming-assignments/tree/main?tab=readme-ov-file#programming-assignment-3---gpa-operations)<br>
> [Programming Assignment 4 - Craps](https://github.com/frozenpixel-games/cpts-121-programming-assignments/tree/main?tab=readme-ov-file#programming-assignment-4---craps)<br>
> [Programming Assignment 5 - Yahtzee](https://github.com/frozenpixel-games/cpts-121-programming-assignments/tree/main?tab=readme-ov-file#programming-assignment-5---yahtzee)<br>
> [Programming Assignment 6 - Battleship](https://github.com/frozenpixel-games/cpts-121-programming-assignments/tree/main?tab=readme-ov-file#programming-assignment-6---battleship)<br>
> [Programming Assignment 7 - 5-Card Poker](https://github.com/frozenpixel-games/cpts-121-programming-assignments/tree/main?tab=readme-ov-file#programming-assignment-7---5-card-poker)

### Programming Assignment 1 - Solving Equations
Create a program that evaluates equations. Checking for faulty numbers aren't required.

**Equations**
1. Newton’s Second Law of Motion
    - force = mass * acceleration
3. Volume of a cylinder
    - volume_cylinder = PI * radius² * height
5. Character encoding
    - encoded_character = (plaintext_character - 'a') + 'A
8. Gravity
    - force = G * mass1 * mass2 / distance²
10. Resistive divider
    - vout = r2 / (r1 + r2) * vin
12. Distance between two points
    - distance = √((x1 - x2)² + (y1 - y2)²)
14. General equation
    - y = (73 / 12) - x * z + a / (a % 2)

### Programming Assignment 2 - Solving Equations using Scanning
Alter PA 1 to be modular and use scanning (scanf) for inputs. Do not check for faulty inputs.

### Programming Assignment 3 - GPA Operations
Write a program that processes numbers, corresponding to student records read from a file. You must define the following functions and process them accordingly.

**Required Functions**
1. Read a double from a file.
    - double read_double (FILE *infile)
2. Read an int from a file.
    - int read_integer (FILE *infile)
3. Find the sum of the numbers.
    - double calculate_sum (double number1, double number2, double number3, double number4, double number5)
4. Find the average.
    - double calculate_mean (double sum, int number)
5. Find the deviation.
    - double calculate_deviation (double number, double mean)
6. Find the variance.
    - double calculate_variance (double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
7. Find the standard deviation.
    - double calculate_standard_deviation (double variance)
8. Find the maximum number.
    - double find_max (double number1, double number2, double number3, double number4, double number5)
9. Find the minimum number.
    - double find_min (double number1, double number2, double number3, double number4, double number5)
10. Print a double to the output file.
    - void print_double (FILE *outfile, double number)

**Required Processes**
1. Find sum of GPAs.
2. Find sum of class standings.
3. Find sum of ages.
4. Find average GPA, writing to output file.
5. Find average class standing, writing to output file.
6. Find average age, writing to output file.
7. Find deviation of GPAs.
8. Find variance of GPAs.
9. Find standard deviation of GPAs, writing to output file.
10. Determine minimum GPA, writing to output file.
11. Determine maximum GPA, writing to output file.
12. Close the input and output files.

**Expected Input File Format**
Student ID (int)<br>
GPA (double)<br>
Class Standing (int)<br>
Age (double)

**Expected Input File Format**
GPA Mean (double)<br>
Class Standing Mean (double)<br>
Age Mean (double)<br>
GPA Standard Deviation (double)<br>
GPA Minimum (double)<br>
GPA Maximum (double)

### Programming Assignment 4 - Craps
Write a program that plays a game of Craps, with wagering implemented. Required functions are listed below.

**Required Functions**
1. Prints out the game rules.
    - void print_game_rules (void)
2. Prompts and gets a bank balance amount.
    - double get_bank_balance (void)
3. Prompts and gets a wager amount.
    - double get_wager_amount (void)
4. Checks wager amount to ensure you can spend it.
    - int check_wager_amount (double wager, double balance)
5. Rolls a die and returns the result.
    - int roll_die (void)
6. FInds the sum of the die faces.
    - int calculate_sum_dice (int die1_value, int die2_value)
7. Determines the result of the first roll. If sum is 7 or 11, the player wins. If sum is 2, 3, or 12, the player loses. Any other sum becomes the point.
    - int is_win_loss_or_point (int sum_dice)
8. Determines the result of any successive roll after the first roll. If the sum of the roll is the point_value, player wins. If the sum of the roll is a 7, player loses.
    - int is_point_loss_or_neither (int sum_dice, int point_value)
9. Add or subtract amount to/from bank balance.
    -  double adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract)
10. Random messages to add for fun.
    - void chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
11. Others?

### Programming Assignment 5 - Yahtzee
Develop and implement an interactive two-player Yahtzee game. Required processes are listed below.

**Required Processes**
1. Print a game menu.
2. Get menu choice and either print rules, start game, or quit.
3. Ask player to hit any key to continue.
4. Roll 5 die and display them.
5. Allow player to reroll die up to 3 times.
6. Save the combination, as it cannot be changed anymore.
7. Calculate points and validate the selections (which section on score card) the player chose to assign points to is valid and hasn't been used yet.
8. Alternate players and repeat steps for 14 rounds.
9. If the total score in the upper section (score card) is greater than or equal to 63 for a player, add 35 points to the score.
10. Print scores for both players and display the winner.
11. Return to step 1.

### Programming Assignment 6 - Battleship
Write a program that simulates the game of Battleship. Both players' fleets consist of 5 ships that are hidden from the enemy. For each move made by Player1 and Player2, the results should be echoed to a file called "battleship.log". At the end of the game, Player1's and Player2's statistics should be written to "battleship.log". Must use structs to store log information. See optional functions, required processes, and expected output below.

**Required Processes**
1. Print a game menu.
2. Prints menu, starts game, or quits accordingly.
3. Open logging file.
4. Intializing Player1's and Player2's boards.
5. Ask for manual or automatic placement for ships.
6. Manually or automatically place ships for Player1.
7. Automatically place ships for Player2 (CPU).
8. Randomly select who goes first.
9. Displaying game boards accurately, including hiding (but not changing) the enemy's board.
10. Ask for coordinates, validate them and check for hits/misses.
11. Determin if a ship is sunk.
12. Alternate players.
13. Keep going until there is a winner.
14. Close logging file.

**Expected Input File Format**
Position (int int)<br>
Hit or Miss (char)<br>
Which Ship Sunk (char)

Number of Hits (int)<br>
Number of Misses (int)<br>
Number of Shots (int)<br>
Hit to Miss Ratio (double)<br>
Won or Lost (int)

### Programming Assignment 7 - 5-Card Poker
Coming soon.
