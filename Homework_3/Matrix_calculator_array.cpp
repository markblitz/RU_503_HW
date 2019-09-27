// Name: Yiming Bi
// This is the matrix calculator for Hw 3

#include<iostream>

using namespace std;
void print_matrix(float matrix[][10], int row_number, int column_number);
int main() {

	// variables and initialization
	int user_choise = 0;

	// ask input from user in the huge loop and realize each function
	while (true) {
		cout << "Menu \n"
			<< "Choice 1: Addition\nChoice 2: Subtraction\nChoice 3: Multiplication\n"
			<< "Choice 4: Transpose\nChoice 5: Determinant\nChoice 6: Inverse\nChoice 7: Quit\n"
			<< "Enter your choice: \n";
		cin >> user_choise;

		switch (user_choise) {
		case 1:
			cout << "1\n"; 
			{
				int matrix_a_size_row = 0;
				int matrix_a_size_column = 0;
				cout << "Please enter the number of row: ";
				cin >> matrix_a_size_row;
				cout << "Please enter the number of column: ";
				cin >> matrix_a_size_column;
				float matrix_a[10][10];
				cout << "Please enter the values of elements: \n";
				for (int i = 0; i < matrix_a_size_row; i++) {
					for (int j = 0; j < matrix_a_size_column; j++) {
						cin >> matrix_a[i][j];
					}
				}
				cout << "Your input is:\n";
				print_matrix(matrix_a, matrix_a_size_row, matrix_a_size_column);

				int matrix_b_size_row = 0;
				int matrix_b_size_column = 0;
				while (true) {
					cout << "Please enter the number of row: ";
					cin >> matrix_b_size_row;
					cout << "Please enter the number of column: ";
					cin >> matrix_b_size_column;
					if ((matrix_b_size_row != matrix_a_size_row) || (matrix_a_size_column != matrix_b_size_column)) {
						cout << "Dimensions of both matrices do not match!\n";
						continue;
					}
					break;
				}
				float matrix_b[10][10];
				cout << "Please enter the values of elements: \n";
				for (int i = 0; i < matrix_b_size_row; i++) {
					for (int j = 0; j < matrix_b_size_column; j++) {
						cin >> matrix_b[i][j];
					}
				}
				cout << "Your input is:\n";
				print_matrix(matrix_b, matrix_b_size_row, matrix_b_size_column);

				float matrix_c[10][10];
				for (int i = 0; i < matrix_a_size_row; i++) {
					for (int j = 0; j < matrix_a_size_column; j++) {
						matrix_c[i][j] = matrix_a[i][j] + matrix_b[i][j];
					}
				}
				cout << "The result is:\n";
				print_matrix(matrix_c, matrix_a_size_row, matrix_a_size_column);

			}
			continue;
		case 2:
			cout << "2\n";
			continue;
		case 3:
			cout << "3\n";
			continue;
		case 4:
			cout << "4\n";
			continue;
		case 5:
			cout << "5\n";
			continue;
		case 6:
			cout << "6\n";
			continue;
		case 7:
			cout << "7\n";
			break;
		default:
			cout << "Invalid input, please try again!\n";
			continue;
		}
		break;

	}

	return 0;
}

void print_matrix(float matrix[][10], int row_number, int column_number)
{
	for (int i = 0; i < row_number; i++) {
		for (int j = 0; j < column_number; j++) {
			cout << matrix[i][j] << " ";;
		}
		cout << endl;
	}
}
