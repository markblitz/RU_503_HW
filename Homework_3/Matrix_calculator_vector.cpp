// Name: Yiming Bi
// This is the matrix calculator for Hw 3

#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

// some build-in functions
int Get_Matrix_Size_Row();
int Get_Matrix_Size_Column();
void Get_Matrix_Value(vector< vector<float> > &matrix);
void Print_Matrix(vector< vector<float> > matrix);
void Matrix_Addition(vector<vector<float>> input_matrix_a, vector<vector<float>> input_matrix_b, vector<vector<float>> &output_matrix);
void Matrix_Subtraction(vector<vector<float>> input_matrix_a, vector<vector<float>> input_matrix_b, vector<vector<float>> &output_matrix);
void Matrix_Multiplication(vector<vector<float>> input_matrix_a, vector<vector<float>> input_matrix_b, vector<vector<float>> &output_matrix);
void Matrix_Transpose(vector<vector<float>> input_matrix_a, vector<vector<float>>& output_matrix);
float Matrix_Determinate(vector<vector<float>> input_matrix_a);
void Matrix_Inverse(vector<vector<float>> input_matrix_a, vector<vector<float>>& output_matrix);

int main() {

	// variables and initialization
	int user_choise = 0;
	int matrix_a_size_row, matrix_a_size_column;
	int matrix_b_size_row, matrix_b_size_column;

	// ask input from user in the huge loop and realize each function
	while (true) {
		cout << "Menu \n"
			<< "Choice 1: Addition\nChoice 2: Subtraction\nChoice 3: Multiplication\n"
			<< "Choice 4: Transpose\nChoice 5: Determinant\nChoice 6: Inverse\nChoice 7: Quit\n"
			<< "Enter your choice: \n";
		cin >> user_choise;

		switch (user_choise) {

		case 1:
		{	// in vector case, I first get size of 2-D vectors and check if the size fits requirment then initialize the 2-D vector
			// when call functions, size information of 2-D vectors do not need to be transferred into functions
			matrix_a_size_row = Get_Matrix_Size_Row();
			matrix_a_size_column = Get_Matrix_Size_Column();

			vector< vector<float> > input_matrix_a(matrix_a_size_row, vector<float>(matrix_a_size_column, 0));

			Get_Matrix_Value(input_matrix_a);
			cout << "Your input is:\n";
			Print_Matrix(input_matrix_a);

			// do some size check here for matrix 2
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

			vector< vector<float> > input_matrix_b(matrix_b_size_row, vector<float>(matrix_b_size_column, 0));
			
			Get_Matrix_Value(input_matrix_b);
			cout << "Your input is:\n";
			Print_Matrix(input_matrix_b);

			vector< vector<float> > output_matrix(matrix_b_size_row, vector<float>(matrix_b_size_column, 0));

			Matrix_Addition(input_matrix_a, input_matrix_b, output_matrix);
			cout << "The result is:\n";
			Print_Matrix(output_matrix);
		}
		continue;

		case 2:
		{
			matrix_a_size_row = Get_Matrix_Size_Row();
			matrix_a_size_column = Get_Matrix_Size_Column();

			vector< vector<float> > input_matrix_a(matrix_a_size_row, vector<float>(matrix_a_size_column, 0));

			Get_Matrix_Value(input_matrix_a);
			cout << "Your input is:\n";
			Print_Matrix(input_matrix_a);

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

			vector< vector<float> > input_matrix_b(matrix_b_size_row, vector<float>(matrix_b_size_column, 0));

			Get_Matrix_Value(input_matrix_b);
			cout << "Your input is:\n";
			Print_Matrix(input_matrix_b);

			vector< vector<float> > output_matrix(matrix_b_size_row, vector<float>(matrix_b_size_column, 0));

			Matrix_Subtraction(input_matrix_a, input_matrix_b, output_matrix);
			cout << "The result is:\n";
			Print_Matrix(output_matrix);
		}
		continue;

		case 3:
		{
			matrix_a_size_row = Get_Matrix_Size_Row();
			matrix_a_size_column = Get_Matrix_Size_Column();

			vector< vector<float> > input_matrix_a(matrix_a_size_row, vector<float>(matrix_a_size_column, 0));

			Get_Matrix_Value(input_matrix_a);
			cout << "Your input is:\n";
			Print_Matrix(input_matrix_a);

			while (true) {
				matrix_b_size_row = Get_Matrix_Size_Row();
				if (matrix_b_size_row != matrix_a_size_column) {
					cout << "Dimensions of both matrices do not match!\n";
					continue;
				}
				matrix_b_size_column = Get_Matrix_Size_Column();
				break;
			}

			vector< vector<float> > input_matrix_b(matrix_b_size_row, vector<float>(matrix_b_size_column, 0));

			Get_Matrix_Value(input_matrix_b);
			cout << "Your input is:\n";
			Print_Matrix(input_matrix_b);

			vector< vector<float> > output_matrix(matrix_a_size_row, vector<float>(matrix_b_size_column, 0));

			Matrix_Multiplication(input_matrix_a, input_matrix_b, output_matrix);
			cout << "The result is:\n";
			Print_Matrix(output_matrix);
		}
		continue;

		case 4:
		{
			matrix_a_size_row = Get_Matrix_Size_Row();
			matrix_a_size_column = Get_Matrix_Size_Column();

			vector< vector<float> > input_matrix_a(matrix_a_size_row, vector<float>(matrix_a_size_column, 0));

			Get_Matrix_Value(input_matrix_a);

			cout << "Your input is:\n";
			Print_Matrix(input_matrix_a);

			vector< vector<float> > output_matrix(matrix_a_size_column, vector<float>(matrix_a_size_row, 0));

			Matrix_Transpose(input_matrix_a, output_matrix);
			cout << "The result is:\n";
			Print_Matrix(output_matrix);
		}
		continue;

		case 5:
		{
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

			vector< vector<float> > input_matrix_a(matrix_a_size_row, vector<float>(matrix_a_size_column, 0));

			Get_Matrix_Value(input_matrix_a);

			cout << "Your input is:\n";
			Print_Matrix(input_matrix_a);

			float determinate_result;
			determinate_result = Matrix_Determinate(input_matrix_a);
			cout << "The result is:\n" << determinate_result << endl;
		}
		continue;

		case 6:
		{
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

			vector< vector<float> > input_matrix_a(matrix_a_size_row, vector<float>(matrix_a_size_column, 0));

			Get_Matrix_Value(input_matrix_a);

			cout << "Your input is:\n";
			Print_Matrix(input_matrix_a);

			float determinate = Matrix_Determinate(input_matrix_a);
			if (determinate == 0) {
				cout << "This matrix may not be invertable!\n";
				continue;
			}

			vector< vector<float> > output_matrix(matrix_a_size_row, vector<float>(matrix_a_size_column, 0));

			Matrix_Inverse(input_matrix_a, output_matrix);
			cout << "The result is:\n";
			Print_Matrix(output_matrix);

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

void Get_Matrix_Value(vector<vector<float>> &matrix)
{
	cout << "Please enter the values of elements: \n";
	for (unsigned int i = 0; i < matrix.size(); i++) {
		for (unsigned int j = 0; j < matrix[0].size(); j++) {
			cin >> matrix[i][j];
		}
	}
}

void Print_Matrix(vector<vector<float>> matrix)
{
	for (unsigned int i = 0; i < matrix.size(); i++) {
		for (unsigned int j = 0; j < matrix[0].size(); j++) {
			cout <<setw(10) << matrix[i][j];
		}
		cout << endl;
	}
}

void Matrix_Addition(vector<vector<float>> input_matrix_a, vector<vector<float>> input_matrix_b, vector<vector<float>> &output_matrix)
{
	for (unsigned int i = 0; i < input_matrix_a.size(); i++) {
		for (unsigned int j = 0; j < input_matrix_a[0].size(); j++) {
			output_matrix[i][j] = input_matrix_a[i][j] + input_matrix_b[i][j];
		}
	}
}

void Matrix_Subtraction(vector<vector<float>> input_matrix_a, vector<vector<float>> input_matrix_b, vector<vector<float>> &output_matrix)
{
	for (unsigned int i = 0; i < input_matrix_a.size(); i++) {
		for (unsigned int j = 0; j < input_matrix_a[0].size(); j++) {
			output_matrix[i][j] = input_matrix_a[i][j] - input_matrix_b[i][j];
		}
	}
}

void Matrix_Multiplication(vector<vector<float>> input_matrix_a, vector<vector<float>> input_matrix_b, vector<vector<float>>& output_matrix)
{
	for (unsigned int i = 0; i < input_matrix_a.size(); i++) {
		for (unsigned int j = 0; j < input_matrix_b[0].size(); j++) {
			for (unsigned int k = 0; k < input_matrix_a[0].size(); k++) {
				output_matrix[i][j] += input_matrix_a[i][k] * input_matrix_b[k][j];
			}
		}
	}
}

void Matrix_Transpose(vector<vector<float>> input_matrix_a, vector<vector<float>>& output_matrix)
{
	for (unsigned int i = 0; i < input_matrix_a[0].size(); i++) {
		for (unsigned int j = 0; j < input_matrix_a.size(); j++) {
			output_matrix[i][j] = input_matrix_a[j][i];
		}
	}
}

float Matrix_Determinate(vector<vector<float>> input_matrix_a)
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

void Matrix_Inverse(vector<vector<float>> input_matrix_a, vector<vector<float>>& output_matrix)
{
	float determinate = Matrix_Determinate(input_matrix_a);

	float cofactor_matrix[3][3] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	cofactor_matrix[0][0] = input_matrix_a[1][1] * input_matrix_a[2][2] - input_matrix_a[1][2] * input_matrix_a[2][1];
	cofactor_matrix[0][1] = input_matrix_a[1][2] * input_matrix_a[2][0] - input_matrix_a[1][0] * input_matrix_a[2][2];
	cofactor_matrix[0][2] = input_matrix_a[1][0] * input_matrix_a[2][1] - input_matrix_a[1][1] * input_matrix_a[2][0];
	cofactor_matrix[1][0] = input_matrix_a[2][1] * input_matrix_a[0][2] - input_matrix_a[2][2] * input_matrix_a[0][1];
	cofactor_matrix[1][1] = input_matrix_a[2][2] * input_matrix_a[0][0] - input_matrix_a[2][0] * input_matrix_a[0][2];
	cofactor_matrix[1][2] = input_matrix_a[2][0] * input_matrix_a[0][1] - input_matrix_a[2][1] * input_matrix_a[0][0];
	cofactor_matrix[2][0] = input_matrix_a[0][1] * input_matrix_a[1][2] - input_matrix_a[0][2] * input_matrix_a[1][1];
	cofactor_matrix[2][1] = input_matrix_a[0][2] * input_matrix_a[1][0] - input_matrix_a[0][0] * input_matrix_a[1][2];
	cofactor_matrix[2][2] = input_matrix_a[0][0] * input_matrix_a[1][1] - input_matrix_a[0][1] * input_matrix_a[1][0];

	vector< vector<float> > adjoint_matrix(input_matrix_a.size(), vector<float>(input_matrix_a[0].size(), 0));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			adjoint_matrix[i][j] = cofactor_matrix[j][i];
			output_matrix[i][j] = adjoint_matrix[i][j] / determinate;
		}
	}
}
