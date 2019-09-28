// Name: Yiming Bi
// This is the matrix calculator for Hw 3

#include<iostream>

using namespace std;

int Get_Matrix_Size_Row();
int Get_Matrix_Size_Column();
void Get_Matrix_Value(float matrix[10][10], int row_number, int column_number);
void Matrix_Addition(float input_matrix_a[10][10], float input_matrix_b[10][10], 
					 float output_matrix[10][10], int row_number, int column_number);
void Matrix_Subtraction(float input_matrix_a[10][10], float input_matrix_b[10][10],
						float output_matrix[10][10], int row_number, int column_number);
void Print_Matrix(float matrix[10][10], int row_number, int column_number);

int main() {

	// variables and initialization
	int user_choise = 0;
	float input_matrix_a[10][10];
	float input_matrix_b[10][10];
	float output_matrix[10][10];
	// ask input from user in the huge loop and realize each function
	while (true) {
		cout << "Menu \n"
			<< "Choice 1: Addition\nChoice 2: Subtraction\nChoice 3: Multiplication\n"
			<< "Choice 4: Transpose\nChoice 5: Determinant\nChoice 6: Inverse\nChoice 7: Quit\n"
			<< "Enter your choice: \n";
		cin >> user_choise;

		switch (user_choise) {
		case 1:
			{
				int matrix_a_size_row, matrix_a_size_column;
				matrix_a_size_row = Get_Matrix_Size_Row();
				matrix_a_size_column = Get_Matrix_Size_Column();

				Get_Matrix_Value(input_matrix_a, matrix_a_size_column, matrix_a_size_column);

				cout << "Your input is:\n";
				Print_Matrix(input_matrix_a, matrix_a_size_row, matrix_a_size_column);

				int matrix_b_size_row, matrix_b_size_column;
				while (true) {
					matrix_b_size_row = Get_Matrix_Size_Row();
					if (matrix_b_size_row != matrix_a_size_row) {
						cout << "Dimensions of both matrices do not match!\n";
						continue;
					}
					matrix_b_size_column = Get_Matrix_Size_Column();
					if (matrix_b_size_column != matrix_a_size_column) {
						cout << "Dimensions of both matrices do not match!\n";
						continue;
					}
					break;
				}

				Get_Matrix_Value(input_matrix_b, matrix_b_size_column, matrix_b_size_column);

				cout << "Your input is:\n";
				Print_Matrix(input_matrix_b, matrix_b_size_row, matrix_b_size_column);

				Matrix_Addition(input_matrix_a, input_matrix_b, output_matrix, matrix_a_size_row, matrix_a_size_column);
				cout << "The result is:\n";
				Print_Matrix(output_matrix, matrix_a_size_row, matrix_a_size_column);
			}
			continue;
		case 2:
			{
				int matrix_a_size_row, matrix_a_size_column;
				matrix_a_size_row = Get_Matrix_Size_Row();
				matrix_a_size_column = Get_Matrix_Size_Column();

				Get_Matrix_Value(input_matrix_a, matrix_a_size_column, matrix_a_size_column);

				cout << "Your input is:\n";
				Print_Matrix(input_matrix_a, matrix_a_size_row, matrix_a_size_column);

				int matrix_b_size_row, matrix_b_size_column;
				while (true) {
					matrix_b_size_row = Get_Matrix_Size_Row();
					if (matrix_b_size_row != matrix_a_size_row) {
						cout << "Dimensions of both matrices do not match!\n";
						continue;
					}
					matrix_b_size_column = Get_Matrix_Size_Column();
					if (matrix_b_size_column != matrix_a_size_column) {
						cout << "Dimensions of both matrices do not match!\n";
						continue;
					}
					break;
				}

				Get_Matrix_Value(input_matrix_b, matrix_b_size_column, matrix_b_size_column);

				cout << "Your input is:\n";
				Print_Matrix(input_matrix_b, matrix_b_size_row, matrix_b_size_column);

				Matrix_Subtraction(input_matrix_a, input_matrix_b, output_matrix, matrix_a_size_row, matrix_a_size_column);
				cout << "The result is:\n";
				Print_Matrix(output_matrix, matrix_a_size_row, matrix_a_size_column);
			}
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

int Get_Matrix_Size_Row()
{
	int matrix_size_row = 0;
	while (true) {
		cout << "Please enter the number of row: ";
		cin >> matrix_size_row;
		if ((matrix_size_row > 0) && (matrix_size_row < 11)) {
			break;
		}
		cout << "Your input is either too big or small!\n";
	}
	return matrix_size_row;
}

int Get_Matrix_Size_Column()
{
	int matrix_size_column = 0;
	while (true) {
		cout << "Please enter the number of column: ";
		cin >> matrix_size_column;
		if ((matrix_size_column > 0) && (matrix_size_column < 11)) {
			break;
		}
		cout << "Your input is either too big or small!\n";
	}
	return matrix_size_column;
}

void Get_Matrix_Value(float matrix[10][10], int row_number, int column_number)
{
	cout << "Please enter the values of elements: \n";
	for (int i = 0; i < row_number; i++) {
		for (int j = 0; j < column_number; j++) {
			cin >> matrix[i][j];
		}
	}
}

void Matrix_Addition(float input_matrix_a[10][10], float input_matrix_b[10][10], float output_matrix[10][10], int row_number, int column_number)
{
	for (int i = 0; i < row_number; i++) {
		for (int j = 0; j < column_number; j++) {
			output_matrix[i][j] = input_matrix_a[i][j] + input_matrix_b[i][j];
		}
	}
}

void Matrix_Subtraction(float input_matrix_a[10][10], float input_matrix_b[10][10], float output_matrix[10][10], int row_number, int column_number)
{
	for (int i = 0; i < row_number; i++) {
		for (int j = 0; j < column_number; j++) {
			output_matrix[i][j] = input_matrix_a[i][j] - input_matrix_b[i][j];
		}
	}
}

void Print_Matrix(float matrix[10][10], int row_number, int column_number)
{
	for (int i = 0; i < row_number; i++) {
		for (int j = 0; j < column_number; j++) {
			cout << matrix[i][j] << " ";;
		}
		cout << endl;
	}
}
