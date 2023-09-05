#include "LinkedList.h"

/*********************************/
typedef struct node*  Node;
struct node{
    Matrix matrix;
    Node next;
};
struct LinkedList{
    Node head;
};
/*********************************/

LL LLCreate(){
    LL ll = new LinkedList();
    ll->head = nullptr;
    return ll;
}
void LLDestroy(LL ll){
    while (ll->head){
        LLRemove(ll);
    }
    delete ll;
}

void LLRemove(LL ll){
    if (!ll->head)return;
    Node node = ll->head;
    ll->head = ll->head->next;
    DestroyMatrix(node->matrix);
    delete node;
}
void LLAdd(LL ll, Matrix matrix){
    Node node1 = ll->head;
    while (node1){
        if (GetNameMatrix(node1->matrix) == GetNameMatrix(matrix)){
            Matrix del = node1->matrix;
            node1->matrix = matrix;
            DestroyMatrix(del);
            return;
        } else {
            node1 = node1->next;
        }
    }

    Node node = new struct node;
    node->matrix = matrix;
    node->next = ll->head;
    ll->head = node;
    /////cout<< "add complete"<< std::endl;
}

void LLRemoveById(LL ll,const string& id) {
    Node prevNode = ll->head;
    Node node = ll->head;
    while (node && GetNameMatrix(node->matrix) != id) {
        prevNode = node;
        node = node->next;
    }
    if (node) {
        if (GetNameMatrix(node->matrix )== GetNameMatrix(prevNode->matrix)){
            ll->head = nullptr;
        }
        prevNode->next = node->next;
        DestroyMatrix(node->matrix);
    }
}

bool isInLL(LL ll,const string& id){
    Node node = ll->head;
    if (!node)return false;
    if (GetNameMatrix(node->matrix) == id)return true;
    while (node){
        if (GetNameMatrix(node->matrix) == id)return true;
        node = node->next;
    }
    return false;
}

void LLMltByScalar(LL ll,const Complex& scalar,const string& id){
    Node node = ll->head;
    while (GetNameMatrix(node->matrix) != id){
        node = node->next;
    }
    MltMatrixByScalar(node->matrix,scalar);
}

void LLOrdering(LL ll,const string& name,const int& order){
    Node node = ll->head;
    while (GetNameMatrix(node->matrix) != name){
        node = node->next;
    }
    OrderingMatrix(node->matrix, order);
}

Complex LLDeterminantMatrix(LL ll,const string& name){
    Node node = ll->head;
    while (GetNameMatrix(node->matrix) != name){
        node = node->next;
    }
    return DeterminantMatrix(node->matrix);
}

int LLGetSizeMatrix(LL ll, const string& name){
    Node node = ll->head;
    while (GetNameMatrix(node->matrix) != name){
        node = node->next;
    }
    return GetSize(node->matrix);
}


void LLPrintMatrix(LL ll,const string& name){
    Node node = ll->head;
    while (GetNameMatrix(node->matrix) != name){
        node = node->next;
    }
    PrintMatrix(node->matrix);
}
void LLCopyMatrix(LL ll, const string& newName,const string& name){
    Node nodeName = ll->head;
    Node nodeNewName = ll->head;
    while (GetNameMatrix(nodeName->matrix) != name){
        nodeName = nodeName->next;
    }
    while (GetNameMatrix(nodeNewName->matrix) != newName){
        nodeNewName = nodeNewName->next;
    }
    CopyMatrix(nodeNewName->matrix,nodeName->matrix);

}




