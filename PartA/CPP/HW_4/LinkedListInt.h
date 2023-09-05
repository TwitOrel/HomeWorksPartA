//
// Created by Orel on 25/05/2023.
//

#ifndef EX4_LINKEDLISTINT_H
#define EX4_LINKEDLISTINT_H

class LinkedListInt{
private:

    class Node{
    private:
        int val;
        Node *next;
        Node *prev;
    public:
        explicit Node(const int val):val(val),next(nullptr),prev(nullptr){}
        Node() = delete;
        ~Node(){
        }
        int& getElement(){
            return this->val;
        }
        void setNext(Node* node){
            this->next = node;
        }
        void setPrev(Node* node){
            this->prev = node;
        }
        Node* getNext(){
            return next;
        }
        Node* getPrev(){
            return prev;
        }

    };

    Node* head;
    Node* tail;
    void pop(){ // remove the first node
        if(size() == 0){
            return;
        }

        //  the size = 1
        if(this->head->getNext() == nullptr){
            this->head = this->tail = nullptr;

            //  the size > 1
        } else {
            head->getNext()->setPrev(nullptr);
            head = head->getNext();
        }
    }
public:
    LinkedListInt():head(nullptr),tail(nullptr){}
    ~LinkedListInt(){
        clear();
        this->head = this->tail = nullptr;
    }

    void insert(const int& val){
        Node* node = new Node(val);

        //  list is empty
        if(size() == 0){
            head = tail = node;
            return;
        } else if(val > head->getElement()){
            node->setNext(head);
            head->setPrev(node);
            head = node;
        } else if(val < tail->getElement()){
            node->setPrev(tail);
            tail->setNext(node);
            tail = node;
        } else{
            Node* tmp = head;
            while (tmp != nullptr){
                if (val >= tmp->getElement()){
                    node->setPrev(tmp->getPrev());
                    node->setNext(tmp);
                    tmp->getPrev()->setNext(node);
                    tmp->setPrev(node);
                    return;
                } else{
                    tmp = tmp->getNext();
                }
            }
        }
    }

    const int first(){
        return (this->head->getElement());
    }

    const int last(){
        return (this->tail->getElement());
    }

    //  relies on there being at least one
    int findForward(const int& val){
        Node* tmp = this->head;
        while (tmp != nullptr){
            if(tmp->getElement() == val){
                return tmp->getElement();
            } else{
                tmp = tmp->getNext();
            }
        }
        return -1;
    }

    //  relies on there being at least one
    int findBackward(const int val){
        Node* tmp = tail;
        while (tmp != nullptr){
            if(tmp->getElement() == val){
                return tmp->getElement();
            }
            else{
                tmp = tmp->getPrev();
            }
        }
        return -1;
    }

    //  relies on there being at least one
    void erase(const int val) {
        Node* tmp = head;
        while (tmp != nullptr) {
            Node* next = tmp->getNext();
            if (tmp->getElement() == val) {
                // he is first
                if (head == tmp) {
                    head = next;
                    if (head != nullptr) {
                        head->setPrev(nullptr);
                    } else {
                        tail = nullptr;
                    }
                }
                    // he is last
                else if (tail == tmp) {
                    tail = tmp->getPrev();
                    tail->setNext(nullptr);
                }
                    // he isn't the first or the last
                else {
                    tmp->getPrev()->setNext(tmp->getNext());
                    next->setPrev(tmp->getPrev());
                }
                delete tmp;
            }
            tmp = next;
        }
    }

    void clear() {   //recursive
        if(this->head == nullptr){
            return;
        } else{
            pop();
            clear();
        }
    }

    int size(){
        int res = 0;
        Node* tmp = this->head;
        while (tmp != nullptr){
            res++;
            tmp = tmp->getNext();
        }
        return res;
    }

    void print() {
        Node* current = this->head;
        while (current != nullptr) {
            std::cout << current->getElement() << " ";
            current = current->getNext();
        }
        std::cout << std::endl;
    }

    //void print(){}
};

#endif //EX4_LINKEDLISTINT_H
