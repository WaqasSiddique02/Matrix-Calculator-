#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to check if the matrix is a row matrix
bool isRowMatrix(int matrix[10][10], int rows, int cols) {
	return rows == 1;
}

// Function to check if the matrix is a column matrix
bool isColumnMatrix(int matrix[10][10], int rows, int cols) {
	return cols == 1;
}

// Function to check if the matrix is a null matrix
bool isNullMatrix(int matrix[10][10], int rows, int cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (matrix[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

// Function to check if the matrix is a square matrix
bool isSquareMatrix(int matrix[10][10], int rows, int cols) {
	return rows == cols;
}

// Function to check if the matrix is a diagonal matrix
bool isDiagonalMatrix(int matrix[10][10], int rows, int cols) {
	if (!isNullMatrix(matrix, rows, cols) && isSquareMatrix(matrix, rows, cols)) {
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (i != j && matrix[i][j] != 0) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

// Function to check if the matrix is an upper triangular matrix
bool isUpperTriangularMatrix(int matrix[10][10], int rows, int cols) {
	for (int i = 1; i < rows; ++i) {
		for (int j = 0; j < i; ++j) {
			if (matrix[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

// Function to check if the matrix is a lower triangular matrix
bool isLowerTriangularMatrix(int matrix[10][10], int rows, int cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = i + 1; j < cols; ++j) {
			if (matrix[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

// Function to check if the matrix is a symmetric matrix
bool isSymmetricMatrix(int matrix[10][10], int rows, int cols) {
	if (isSquareMatrix(matrix, rows, cols)) {
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < i; ++j) {
				if (matrix[i][j] != matrix[j][i]) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

// Function to check if the matrix is an antisymmetric matrix
bool isAntisymmetricMatrix(int matrix[10][10], int rows, int cols) {
	if (isSquareMatrix(matrix, rows, cols)) {
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < i; ++j) {
				if (matrix[i][j] != -matrix[j][i]) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

int main()
{
	char menu_opt;
	int rows1, cols1, rows2, cols2;
	char operate;
	int matrixA[10][10], matrixB[10][10], ans[10][10],dot[10];
	char choice;
	int determinent;

	
	do {
		cout << "          MENU " << endl;
		cout << "===================================================" << endl;
		cout << "Select one of the following options: " << endl;
		cout << "[A] Simple Funtions " << endl;
		cout << "[B] Advanced Funtions " << endl;
		cout << "[C] Check Type of Matrix " << endl;
		cout << "[D] History " << endl;
		cout << "[E] About " << endl;
		cout << "[F] Exit " << endl;

		cin >> menu_opt;

		ofstream matrixfile;  //file created
		

		if (menu_opt == 'A' || menu_opt == 'a')
		{   
			matrixfile.open("history.txt", ios::app); //file opened in append form here

			//input of sizes
			cout << "Enter the size of matrixes" << endl;
			cout << "Matrix 1  " << endl;
			cout << "Rows : ";
			cin >> rows1;
			cout << "columns : ";
			cin >> cols1;

			cout << endl << "Matrix 2  " << endl;
			cout << "Rows : ";
			cin >> rows2;
			cout << "columns : ";
			cin >> cols2;

			//matrix 1 input 
			cout << "Input matrix 1 :" << endl;
			for (int i = 0; i < rows1; i++)
			{
				for (int j = 0; j < cols1; j++)
				{
					cin >> matrixA[i][j];
				}
			}

			//matrix 2 input
			cout << "Enter matrix 2 : " << endl;
			for (int i = 0; i < rows2; i++)
			{
				for (int j = 0; j < cols2; j++)
				{
					cin >> matrixB[i][j];
				}
			}

			cout << endl << "Enter operator : " << endl;
			cout << "Addition [+]" << endl << "Subtraction [-]" << endl;
			cout << "Multiplication [*]" << endl << "Dot Product [D]" << endl;
			cin >> operate;

			switch (operate)
			{
			case '+':
				if (rows1 != rows2 && cols1 != cols2)
				{
					cout << "Sizes are different | Matrixes cannot be added " << endl;
				}
				else
				{
					//sum of matrix 1 and 2
					cout << "Matrix A + Matrix B = " << endl;
					for (int i = 0; i < rows1; i++)
					{
						for (int j = 0; j < cols1; j++)
						{
							ans[i][j] = matrixA[i][j] + matrixB[i][j];
							cout << ans[i][j] << " ";
							matrixfile << ans[i][j] << " ";
						}
						cout << endl;
						matrixfile << endl;
					}
				}
				break;

			case '-':
				if (rows1 != rows2 && cols1 != cols2)
				{
					cout << "Sizes are different | Matrixes cannot be subtracted " << endl;
				}
				else
				{
					//difference of matrix 1 and 2
					cout << "Matrix A - Matrix B = " << endl;
					for (int i = 0; i < rows1; i++)
					{
						for (int j = 0; j < cols1; j++)
						{
							ans[i][j] = matrixA[i][j] - matrixB[i][j];
							cout << ans[i][j] << " ";
							matrixfile << ans[i][j] << " "; 
						}
						cout << endl;
						matrixfile << endl;
					}
				}
				break;

			case '*':
				if (cols1 == rows2)
				{
					//product of matrix 1 and matrix 2 
					for (int i = 0; i < rows1; i++)
					{
						for (int j = 0; j < cols2; j++)
						{
							ans[i][j] = 0;
							for (int k = 0; k < rows2; k++)
							{
								ans[i][j] += matrixA[i][k] * matrixB[k][j];
							}
						}
					}

					for (int i = 0; i < rows1; i++)
					{
						for (int j = 0; j < cols2; j++)
						{
							cout << ans[i][j] << " ";
							matrixfile << ans[i][j] << " ";
						}
						cout << endl;
						matrixfile << endl;
					}
				}
				else
				{
					cout << "Matrixes cannot be multiplied | Size error " << endl;
				}
				break;

			case 'D':
			case 'd':
				if (rows1 == rows2 && cols1 == cols2)
				{
					//Dot product calculation 
					for (int i = 0; i < rows1; i++)
					{
						dot[i] = 0;
						for (int j = 0; j < cols1; j++)
						{
							dot[i] += matrixA[i][j] * matrixB[i][j];
						}
					}
					//dot product dispplaying 
					for (int i = 0; i < rows1; i++)
					{
						cout << dot[i] << " ";
						matrixfile << dot[i] << " ";
					}
					cout << endl;
					matrixfile << endl;
				}
				else
				{
					cout << "Dot product cannot be found for these matrices | Error | Matrices are not of the same size " << endl;
				}
				break;

			default:
				cout << "Error | Option not in the list " << endl;
			}
			matrixfile << endl;
			matrixfile.close();
			
		}
		//transpose inverse adoint etc 
		else if (menu_opt == 'B' || menu_opt == 'b')
		{
			matrixfile.open("history.txt", ios::app); //file opened in append form here

			cout << "Enter size of matrix : " << endl;
			cout << "Rows :";
			cin >> rows1;
			cout << "Columns";
			cin >> cols1;

			cout << "Enter elements of matrix : " << endl;
			for (int i = 0; i < rows1; i++)
			{
				for (int j = 0; j < cols1; j++)
				{
					cin >> matrixA[i][j];
				}
			}

			cout << "Select one of the following :" << endl;
			cout << "[T] Transpose" << endl << "[A] Adjoint" << endl;
			cout << "[D] Determinent" << endl << "[I] Inverse " << endl;
			cout << "[L] Linear Equations " << endl;
			cin >> operate;

			switch (operate)
			{
			case 'T':
			case't':
				//transpose
				cout << "Transpose of the matrix :" << endl;
				for (int i = 0; i < cols1; i++)
				{
					for (int j = 0; j < rows1; j++)
					{
						cout << matrixA[j][i] << " ";
						matrixfile << matrixA[j][i] << " ";

					}
					cout << endl;
					matrixfile << endl;
				}
				break;
			case 'D':
			case 'd':
				//determinent
				if (rows1==2 && cols1==2)
				{
					determinent = matrixA[0][0] * matrixA[1][1] - matrixA[0][1] * matrixA[1][0];
					cout << "det = " << determinent << endl;
					matrixfile << determinent << endl;
				}

				else if (rows1==3 && cols1==3)
				{
					determinent = matrixA[0][0] * (matrixA[1][1] * matrixA[2][2] - matrixA[2][1] * matrixA[1][2]) -matrixA[0][1] * (matrixA[1][0] * matrixA[2][2] - matrixA[2][0] * matrixA[1][2]) +matrixA[0][2] * (matrixA[1][0] * matrixA[2][1] - matrixA[2][0] * matrixA[1][1]);
					cout << "det = " << determinent << endl;
					matrixfile << determinent << endl;
				}

				else
				{
					cout << "Only 2x2 and 3x3 option available" << endl;
				}

				break;

			default:
				cout << "Error | Option Not found " << endl;
			}
			matrixfile << endl;
			matrixfile.close(); 
		}

		else if (menu_opt == 'C' || menu_opt == 'c')
		{
			matrixfile.open("history.txt", ios::app); //file opened in append form here

			int rows, cols;

			// matrix size 
			cout << "Enter size of the matrix " << endl;
			cout << "Rows : ";
			cin >> rows;
			cout << "Columns: ";
			cin >> cols;

			// matrix elements input 
			int matrix[10][10];
			cout << "Enter the elements of the matrix:" << endl;
			for (int i = 0; i < rows; ++i) {
				for (int j = 0; j < cols; ++j) {
					cin >> matrix[i][j];
				}
			}

			// Checking and displaying the type of matrix
			if (isRowMatrix(matrix, rows, cols)) {
				cout << "Row matrix." << endl;
				matrixfile<< "Row matrix." << endl;
			}
			else if (isColumnMatrix(matrix, rows, cols)) {
				cout << "Column matrix." << endl;
				matrixfile << "Column matrix." << endl;
			}
			else if (isNullMatrix(matrix, rows, cols)) {
				cout << "Null matrix." << endl;
				matrixfile << "Null matrix." << endl;
			}
			else if (isDiagonalMatrix(matrix, rows, cols)) {
				cout << "Diagonal matrix." << endl;
				matrixfile << "Diagonal matrix." << endl;
			}
			else if (isSquareMatrix(matrix, rows, cols)) {
				cout << "Sqaure matrix." << endl;
				matrixfile<< "Sqaure matrix." << endl;

			}
			else if (isUpperTriangularMatrix(matrix, rows, cols)) {
				cout << "Upper triangular matrix." << endl;
				matrixfile<< "Upper triangular matrix." << endl;
			}
			else if (isLowerTriangularMatrix(matrix, rows, cols)) { 
				cout << "Lower triangular matrix." << endl;
				matrixfile<< "Lower triangular matrix." << endl;
			}
			else if (isSymmetricMatrix(matrix, rows, cols)) { 
				cout << "Symmetric matrix." << endl;
				matrixfile<< "Symmetric matrix." << endl;
			}
			else if (isAntisymmetricMatrix(matrix, rows, cols)) {
				cout << "Antisymmetric matrix." << endl;
				matrixfile<< "Antisymmetric matrix." << endl;
			}
			else {
				cout << "The matrix does not fall into a specific category." << endl;
				matrixfile<< "The matrix does not fall into a specific category." << endl;
			}
			matrixfile.close();
		}

		else if (menu_opt == 'D' || menu_opt == 'd')
		{
			cout << "         HISTORY " << endl;
			cout << "===================================" << endl;

			//reading data from the file 
			string line;
			ifstream matrixfile;
			matrixfile.open("history.txt");
			while (getline(matrixfile, line))
			{
				cout << line << endl;
			}
			matrixfile.close();
		}

		else if (menu_opt == 'E' || menu_opt == 'e')
		{
			cout << "              ABOUT " << endl;
			cout << "===============================================" << endl;
			cout << "=>Program name: Matrix Calculator " << endl<<endl;
			cout << "=>Made by : M Waqas Siddique" << endl<<endl;
			cout << "This programs deals with problems regarding matrixes " << endl;
		}

		else if (menu_opt == 'F' || menu_opt == 'f')
		{
			cout << "Exiting the program..." << endl;
			return 0;
		}
		else
		{
			cout << "Option not in the list " << endl;
		}
		//again in to main menu 
		cout << "===================================================" << endl;
		cout << "Do you want to go to main menu (Y/any key)" << endl;
		cin >> choice;
	}
	while (choice == 'Y' || choice == 'y');
	return 0;
}
