#include "CMatrix.h"
#include "Complex.h"
using InvalidInputExcepcion = std::domain_error;
using InvalidArgumentException = std::invalid_argument;

struct CMatrix {

Complex** matrix;
int size;
string id;

};

Matrix CreateMatrix(int sizeMatrix, const string& name){
    auto mat = new CMatrix();
    mat->size = sizeMatrix;
    mat->id = name;
    mat->matrix = new Complex *[sizeMatrix];
    for (int i = 0; i < sizeMatrix; ++i) {
        mat->matrix[i] = new Complex[sizeMatrix];
    }
    return mat;
}
void DestroyMatrix(Matrix mat){
    for (int i = 0; i < mat->size; ++i) {
        delete[] mat->matrix[i];
    }
    delete []mat->matrix;
    delete mat;
}
const string& GetNameMatrix(Matrix mat){
    return mat->id;
}

Matrix CopyMatrix(const string& name, Matrix mat){
    Matrix ma = CreateMatrix(mat->size,name);
    for (int i = 0; i < mat->size; ++i) {
        for (int j = 0; j < mat->size; ++j) {
            SetIndexMatrix(ma,i,j, GetIndexMatrix(mat,i,j));
        }
    }
    return ma;
}

void CopyMatrix(Matrix toCopy, Matrix mat){
    for (int i = 0; i < mat->size; ++i) {
        for (int j = 0; j < mat->size; ++j) {
            SetIndexMatrix(toCopy,i,j, GetIndexMatrix(mat,i,j));
        }
    }
}


void SetIndexMatrix(Matrix mat, int i, int j, const Complex& complex){
    mat->matrix[i][j] = complex;
}

Complex GetIndexMatrix(Matrix mat, int i, int j){
    return {mat->matrix[i][j]};
}

void MltMatrixByScalar(Matrix mat, const Complex& scalar){
    for (int i = 0; i < mat->size; ++i) {
        for (int j = 0; j < mat->size; ++j) {
            mat->matrix[i][j] *= scalar;
        }
    }
}
Matrix MLltTwoMatrix(Matrix a, Matrix b){
    Matrix res = CopyMatrix(a->id,a);
    MltMatrixByScalar(res,{0,0});
    for (int i = 0; i < res->size; i++) {
        for (int j = 0; j < res->size; j++) {
            for (int k = 0; k < res->size; k++) {
                res->matrix[i][j] += a->matrix[i][k] * b->matrix[k][j];
            }
        }
    }
    return res;
}
void OrderingMatrix(Matrix &mat, int order){
    if (order == 0){
        MltMatrixByScalar(mat,{0,0});
        for (int i = 0; i < mat->size; ++i) {
            SetIndexMatrix(mat,i,i,{1,0});
        }
    }
    else {
        string ID = mat->id;
        Matrix CopiedMatrix1 = CopyMatrix(mat->id, mat);
        for (int ord = 1; ord < order; ++ord) {//counting the mlt order
            mat = MLltTwoMatrix(mat, CopiedMatrix1);
        }
        mat->id = ID;
        DestroyMatrix(CopiedMatrix1);
    }
}

//create the intended matrix to calculate and determinant
Matrix& CreateSubMatrix(Matrix &subMatrix ,const Matrix& mat, int k){
    int subI = 0;
    int subJ = 0;
    for (int i = 0; i < mat->size; i++) {
        if (i == 0)continue;
        for (int j = 0; j < mat->size; j++) {
            if (j == k)continue;
            subMatrix->matrix[subI][subJ++] = GetIndexMatrix(mat,i,j);
        }
        subI++;
        subJ = 0;
    }
    return subMatrix;
}

Complex DeterminantMatrix(Matrix mat){
    Complex determinant = Complex(0,0);
    if (mat->size == 1){
        return GetIndexMatrix(mat,0,0);
    }
    else if (mat->size == 2){
        return (GetIndexMatrix(mat,0,0) * GetIndexMatrix(mat,1,1) - GetIndexMatrix(mat,1,0)* GetIndexMatrix(mat,0,1));}
    else{
        double sign = 1;
        for (int k = 0; k < mat->size; k++) {
            Matrix subMatrix = CreateMatrix(mat->size-1,mat->id);
            CreateSubMatrix(subMatrix,mat, k);
            determinant +=  (((GetIndexMatrix(mat,0,k) *= sign) * DeterminantMatrix(subMatrix)));
            sign = -sign;
            DestroyMatrix(subMatrix);
        }
    }

    return determinant;
}

void PrintMatrix(Matrix mat){
    ostringstream res ;
    res << mat->id << " = [\n";
    for (int i = 0; i < mat->size; ++i) {
        for (int j = 0; j < mat->size; ++j) {
            res << mat->matrix[i][j].toString();
            if (j == mat->size - 1){
                res << "\n";
            }
            else{
                res << " ";
            }
        }
    }
    res << "]";
    cout << res.str() << endl;
}
bool isLegalName(const string& name){
    if (((name.length() < 5) && (name.length() >= 0 ))){
        for (char c : name) {
            if (!islower(c))
                return false;
        }
        return true;
    }
    return false;
}

string chooseName(){
    string tmp;
    getline(cin,tmp);
    if (((tmp.length() < 5) && (tmp.length() >= 0 ))){
        for (char c : tmp) {
            if (!islower(c))
                throw InvalidInputExcepcion("");
        }
        return tmp;
    }
    throw InvalidInputExcepcion("");
}

int GetSize(Matrix matrix){
    return matrix->size;
}



