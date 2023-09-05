#ifndef EX01_LINKEDLIST_H
#define EX01_LINKEDLIST_H
#include "CMatrix.h"

typedef struct LinkedList* LL;

//Return an empty LinkedList
LL LLCreate();

//Destroy a list
void LLDestroy(LL ll);

//first check if we got matrix with the same id as this.matrix
//if yes: change only the node.matrix
//else: adding this matrix to the list
void LLAdd(LL ll,Matrix matrix);

//Remove the first    function for DestroyLL
void LLRemove(LL ll);


//remove the matrix with that id
void LLRemoveById(LL ll, const string& id);

//mlt the id matrix with this scalar
void LLMltByScalar(LL ll,const Complex& scalar,const string& id);

//mlt the matrix order times
void LLOrdering(LL ll,const string& name,const int& order);

//return the determinant of this matrix
Complex LLDeterminantMatrix(LL ll,const string& name);

//calling PrintMatrix
void LLPrintMatrix(LL ll,const string& name);

//return size of matrix
int LLGetSizeMatrix(LL ll, const string& name);

//copy the values matrix from nameMatrix to newNameMatrix
void LLCopyMatrix(LL ll ,const string& newName,const string& name);




//check if we have matrix with that id
bool isInLL(LL ll,const string& id);
#endif //EX01_LINKEDLIST_H
