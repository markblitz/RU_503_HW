// Name: Yiming Bi
// This is the matrix calculator for Hw 3

#include<iostream>
#include<iomanip>

using namespace std;

// some build-in functions
int Get_Matrix_Size_Row();
int Get_Matrix_Size_Column();
void Get_Matrix_Value(float matrix[10][10], int row_number, int column_number);
void Matrix_Addition(float input_matrix_a[10][10], float input_matrix_b[10][10], 
	float output_matrix[10][10], int row_number, int column_number);
void Matrix_Subtraction(float input_matrix_a[10][10], float input_matrix_b[10][10],
	float output_matrix[10][10], int row_number, int column_number);
void Matrix_Multiplication(float input_matrix_a[10][10], float input_matrix_b[10][10],
	float output_matrix[10][10], int row_number, int column_number, int middle_size);
void Matrix_Transpose(float input_matrix_a[10][10], float output_matrix[10][10], int row_number, int column_number);
float Matrix_Determinate(float input_matrix_a[10][10]);
void Matrix_Inverse(float input_matrix_a[10][10], float output_matrix[10][10]);
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
			{	// in this array case, because of the properties of array, size of each matrix needs to be sent into functions
				int matrix_a_size_row, matrix_a_size_column;
				matrix_a_size_row = Get_Matrix_Size_Row();
				matrix_a_size_column = Get_Matrix_Size_Column();

				Get_Matrix_Value(input_matrix_a, matrix_a_size_row, matrix_a_size_column);

				cout << "Your input is:\n";
				Print_Matrix(input_matrix_a, matrix_a_size_row, matrix_a_size_column);

				// do some size check here for matrix 2
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

				Get_Matrix_Value(input_matrix_b, matrix_b_size_row, matrix_b_size_column);

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

				Get_Matrix_Value(input_matrix_a, matrix_a_size_row, matrix_a_size_column);

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

				Get_Matrix_Value(input_matrix_b, matrix_b_size_row, matrix_b_size_column);

				cout << "Your input is:\n";
				Print_Matrix(input_matrix_b, matrix_b_size_row, matrix_b_size_column);

				Matrix_Subtraction(input_matrix_a, input_matrix_b, output_matrix, matrix_a_size_row, matrix_a_size_column);
				cout << "The result is:\n";
				Print_Matrix(output_matrix, matrix_a_size_row, matrix_a_size_column);
			}
			continue;

		case 3:
			{
				int matrix_a_size_row, matrix_a_size_column;
				matrix_a_size_row = Get_Matrix_Size_Row();
				matrix_a_size_column = Get_Matrix_Size_Column();

				Get_Matrix_Value(input_matrix_a, matrix_a_size_row, matrix_a_size_column);

				cout << "Your input is:\n";
				Print_Matrix(input_matrix_a, matrix_a_size_row, matrix_a_size_column);

				int matrix_b_size_row, matrix_b_size_column;
				while (true) {
					matrix_b_size_row = Get_Matrix_Size_Row();
					if (matrix_b_size_row != matrix_a_size_column) {
						cout << "Dimensions of both matrices do not match!\n";
						continue;
					}
					matrix_b_size_column = Get_Matrix_Size_Column();
					break;
				}

				Get_Matrix_Value(input_matrix_b, matrix_b_size_row, matrix_b_size_column);

				cout << "Your input is:\n";
				Print_Matrix(input_matrix_b, matrix_b_size_row, matrix_b_size_column);

				Matrix_Multiplication(input_matrix_a, input_matrix_b, output_matrix, matrix_a_size_row, matrix_b_size_column, matrix_a_size_column);
				cout << "The result is:\n";
				Print_Matrix(output_matrix, matrix_a_size_row, matrix_b_size_column);
			}
			continue;

		case 4:
			{
				int matrix_a_size_row, matrix_a_size_column;
				matrix_a_size_row = Get_Matrix_Size_Row();
				matrix_a_size_column = Get_Matrix_Size_Column();

				Get_Matrix_Value(input_matrix_a, matrix_a_size_row, matrix_a_size_column);

				cout << "Your input is:\n";
				Print_Matrix(input_matrix_a, matrix_a_size_row, matrix_a_size_column);

				Matrix_Transpose(input_matrix_a, output_matrix, matrix_a_size_column, matrix_a_size_row);
				cout << "The result is:\n";
				Print_Matrix(output_matrix, matrix_a_size_column, matrix_a_size_row);
			}
			continue;

		case 5:
			{
				int matrix_a_size_row, matrix_a_size_column;
				while (true) {
					matrix_a_size_row = Get_Matrix_Size_Row();
					if (matrix_a_size_row != 3) {
						cout << "Matrix size not supported\n";
						continue;
					}
					matrix_a_size_column = Get_Matrix_Size_Column();
					if (matrix_a_size_column != 3) {
						cout << "Matrix size not supported\n";
						continue;
					}
					break;
				}

				Get_Matrix_Value(input_matrix_a, matrix_a_size_row, matrix_a_size_column);

				cout << "Your input is:\n";
				Print_Matrix(input_matrix_a, matrix_a_size_row, matrix_a_size_column);

				float determinate_result;
				determinate_result = Matrix_Determinate(input_matrix_a);
				cout << "The result is:\n" << determinate_result << endl;
			}
			continue;

		case 6:
			{
				int matrix_a_size_row, matrix_a_size_column;
				while (true) {
					matrix_a_size_row = Get_Matrix_Size_Row();
					if (matrix_a_size_row != 3) {
						cout << "Matrix size not supported\n";
						continue;
					}
					matrix_a_size_column = Get_Matrix_Size_Column();
					if (matrix_a_size_column != 3) {
						cout << "Matrix size not supported\n";
						continue;
					}
					break;
				}

				Get_Matrix_Value(input_matrix_a, matrix_a_size_row, matrix_a_size_column);

				cout << "Your input is:\n";
				Print_Matrix(input_matrix_a, matrix_a_size_row, matrix_a_size_column);

				float determinate = Matrix_Determinate(input_matrix_a);
				if (determinate == 0) {
					cout << "This matrix may not be invertable!\n";
					continue;
				}

				Matrix_Inverse(input_matrix_a, output_matrix);
				cout << "The result is:\n";
				Print_Matrix(output_matrix, matrix_a_size_column, matrix_a_size_row);

			}
			continue;

		case 7:
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
			matrix[i][j] = 0;
			cin >> matrix[i][j];
		}
	}
}

void Matrix_Addition(float input_matrix_a[10][10], float input_matrix_b[10][10], float output_matrix[10][10], int row_number, int column_number)
{
	for (int i = 0; i < row_number; i++) {
		for (int j = 0; j < column_number; j++) {
			output_matrix[i][j] = 0;
			output_matrix[i][j] = input_matrix_a[i][j] + input_matrix_b[i][j];
		}
	}
}

void Matrix_Subtraction(float input_matrix_a[10][10], float input_matrix_b[10][10], float output_matrix[10][10], int row_number, int column_number)
{
	for (int i = 0; i < row_number; i++) {
		for (int j = 0; j < column_number; j++) {
			output_matrix[i][j] = 0;
			output_matrix[i][j] = input_matrix_a[i][j] - input_matrix_b[i][j];
		}
	}
}

void Matrix_Multiplication(float input_matrix_a[10][10], float input_matrix_b[10][10], float output_matrix[10][10], int row_number, int column_number, int middle_size)
{
	for (int i = 0; i < row_number; i++) {
		for (int j = 0; j < column_number; j++) {
			output_matrix[i][j] = 0;
			for (int k = 0; k < middle_size; k++) {
				output_matrix[i][j] += input_matrix_a[i][k] * input_matrix_b[k][j];
			}
		}
	}
}

void Matrix_Transpose(float input_matrix_a[10][10], float output_matrix[10][10], int row_number, int column_number)
{
	for (int i = 0; i < row_number; i++) {
		for (int j = 0; j < column_number; j++) {
			output_matrix[i][j] = 0;
			output_matrix[i][j] = input_matrix_a[j][i];
		}
	}
}

float Matrix_Determinate(float input_matrix_a[10][10])
{
	float determinate = 0;
	determinate = input_matrix_a[0][0] * input_matrix_a[1][1] * input_matrix_a[2][2] +
		input_matrix_a[0][1] * input_matrix_a[1][2] * input_matrix_a[2][0] +
		input_matrix_a[0][2] * input_matrix_a[1][0] * input_matrix_a[2][1] -
		input_matrix_a[0][2] * input_matrix_a[1][1] * input_matrix_a[2][0] -
		input_matrix_a[1][2] * input_matrix_a[2][1] * input_matrix_a[0][0] -
		input_matrix_a[2][2] * input_matrix_a[0][1] * input_matrix_a[1][0];
	return determinate;
}

void Matrix_Inverse(float input_matrix_a[10][10], float output_matrix[10][10])
{	// this inverse algorithm is not the best
	// since I am only asked to do 3 by 3 matrix, this would be easier
	float determinate = Matrix_Determinate(input_matrix_a);

	float cofactor_matrix[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	cofactor_matrix[0][0] = input_matrix_a[1][1] * input_matrix_a[2][2] - input_matrix_a[1][2] * input_matrix_a[2][1];
	cofactor_matrix[0][1] = input_matrix_a[1][2] * input_matrix_a[2][0] - input_matrix_a[1][0] * input_matrix_a[2][2];
	cofactor_matrix[0][2] = input_matrix_a[1][0] * input_matrix_a[2][1] - input_matrix_a[1][1] * input_matrix_a[2][0];
	cofactor_matrix[1][0] = input_matrix_a[2][1] * input_matrix_a[0][2] - input_matrix_a[2][2] * input_matrix_a[0][1];
	cofactor_matrix[1][1] = input_matrix_a[2][2] * input_matrix_a[0][0] - input_matrix_a[2][0] * input_matrix_a[0][2];
	cofactor_matrix[1][2] = input_matrix_a[2][0] * input_matrix_a[0][1] - input_matrix_a[2][1] * input_matrix_a[0][0];
	cofactor_matrix[2][0] = input_matrix_a[0][1] * input_matrix_a[1][2] - input_matrix_a[0][2] * input_matrix_a[1][1];
	cofactor_matrix[2][1] = input_matrix_a[0][2] * input_matrix_a[1][0] - input_matrix_a[0][0] * input_matrix_a[1][2];
	cofactor_matrix[2][2] = input_matrix_a[0][0] * input_matrix_a[1][1] - input_matrix_a[0][1] * input_matrix_a[1][0];

	float adjoint_matrix[3][3] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			adjoint_matrix[i][j] = cofactor_matrix[j][i];
			output_matrix[i][j] = adjoint_matrix[i][j] / determinate;
		}
	}
}

void Print_Matrix(float matrix[10][10], int row_number, int column_number)
{
	for (int i = 0; i < row_number; i++) {
		for (int j = 0; j < column_number; j++) {
			cout <<setw(10) << matrix[i][j];
		}
		cout << endl;
	}
}
