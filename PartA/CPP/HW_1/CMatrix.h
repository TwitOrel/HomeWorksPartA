#ifndef EX01_CMATRIX_H
#define EX01_CMATRIX_H
#include "Complex.h"

typedef struct CMatrix* Matrix;

//creating Matrix
Matrix CreateMatrix(int size,const string& name);

//destroy Matrix
void DestroyMatrix(Matrix matrix);

//return id of matrix
const string& GetNameMatrix(Matrix matrix);

//Mlt the Matrix By Scalar
void MltMatrixByScalar(Matrix matrix,const Complex& scalar);

//mlt the Matrix order times
void OrderingMatrix(Matrix &matrix, int order);

//printing the Determinant of Matrix
Complex DeterminantMatrix(Matrix matrix);

//set the value in the matrix by the index
void SetIndexMatrix(Matrix matrix, int i, int j, const Complex& complex);

//return copy Complex
Complex GetIndexMatrix(Matrix matrix, int i, int j);

//printing the Matrix
void PrintMatrix(Matrix mat);

//get name from user
string chooseName();

//return size of matrix
int GetSize(Matrix matrix);

//copy from one to other matrix
void CopyMatrix(Matrix toCopy, Matrix mat);

//check if name is legal
bool isLegalName(const string& name);



//copy val matrix
Matrix CopyMatrix(const string& name,Matrix mat);

#endif //EX01_CMATRIX_H
