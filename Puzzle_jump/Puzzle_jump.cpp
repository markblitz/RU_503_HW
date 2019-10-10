// Name: Yiming Bi
// This is the program for hw5 puzzle jump

#include<iostream>
#include <iterator>

using namespace std;

bool Solve_Puzzle(int puzzle[], int starting_index);

bool Solve_Puzzle(int puzzle[], int starting_index)
{
	int next_starting_point = 0;
	int step = puzzle[starting_index];
	int array_length = 0;

	/* Since I am asked to take two parameters for this function, an array and an integer,
	   this loop is used to get the length of array,
	   do this meaningless job in every call... SAD */

	while (true) {							
		if (puzzle[array_length] == 0) {	
			break;							
		}
		array_length++;
	}

	if (puzzle[starting_index] == 0) {
	//	cout << "touch end!\n";
		return true;
	}
	if (puzzle[starting_index] == -1) {
	//	cout << "touch before!\n";
		return false;
	}

	if ((starting_index - step) >= 0) {
	//	cout << "start at " << starting_index << " with value " << puzzle[starting_index] << endl;
	//	cout << "move left " << step << endl;
		next_starting_point = starting_index - step;
		puzzle[starting_index] = -1;
		if (Solve_Puzzle(puzzle, next_starting_point)) {
			return true;
		}
	}

	if ((starting_index + step) <= array_length) {
	//	cout << "start at " << starting_index << " with value " << puzzle[starting_index] << endl;
	//	cout << "move right " << step << endl;
		next_starting_point = starting_index + step;
		puzzle[starting_index] = -1;
		if (Solve_Puzzle(puzzle, next_starting_point)) {
			return true;
		}
	}

	return false;
}

int main() {

	int puzzle[5] = { 3, 2, 1, 3, 0 };
	bool if_solvable = Solve_Puzzle(puzzle, 1);

	if (if_solvable) {
		cout << "This puzzle is solvable!\n";
	}
	else {
		cout << "This puzzle may not be solvable!\n";
	}

	return 0;
}