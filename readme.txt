Justin Shen
CSC173
Project 5
jshen37@u.rochester.edu
Collaborators: Chris Chen (schen133@u.rochester.edu), Jeffrey li(jli167@u.rochester.edu)

Build/Running instruction:
	1. cd to the location of the file
	2. gcc -o pro5 -std=c99 -Wall -Werror ./*.c
	3. Run pro5.exe

Notes on code:
	1. There are 3 functions (circuit1, circuit2, circuit3) in the main.c which create the 3 required circuits. 
	2. To implement NOR and NAND gate, i simply negate(!) the argument in the OR and AND gate.
	3. All possible combinations inputs of required circuits are tested in the function "testall()" .
	4. I kept the "circuit_dump" function that contain in the code bundle.
	
Extra Credit:
	We only implement the first part of extra credit. 
	The code can found in the main.c file starting from the comment "//extra credit part1 (one-bit adder)//".
	The functions "b2i", "test3In2Out", and "onebitadder" belong to the extra credit.
	The "testall()" also tests all the possible combinations of the one bit adder.
	
