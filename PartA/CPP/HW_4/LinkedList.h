////
//// Created by Orel on 16/05/2023.
////
//
#ifndef EX4_LINKEDLIST_H
#define EX4_LINKEDLIST_H
///* for this class need:
// *  T must contain operator >
// *  T must contain operator ==
// *  T must contain operator <
// *  T must contain operator >=
// *  T must contain copy ctor
// *  T copy()
// *
// */
using namespace std;

template <class T>
class LinkedList {
private:
    class Node {
    private:
        T* val;
        Node* next;
        Node* prev;
    public:
        explicit Node(const T& val) : val(val.copy()), next(nullptr), prev(nullptr) {
            //cout << "ctor Node " << endl;
        }
        ~Node(){
            delete val;
        }
        Node(const Node& node):val(node.val->copy()),next(nullptr), prev(nullptr){}

        Node& operator =(const Node& node){
            if (this == &node) return *this;
            delete val;
            val = node.val->copy();
            return *this;
        }

        const T& getElement() const {
            return *val;
        }

        T& getElement() {
            return *val;
        }

        void setNext(Node* node) {
            next = node;
        }

        void setPrev(Node* node) {
            prev = node;
        }

        Node* getNext() const {
            return next;
        }

        Node* getPrev() const {
            return prev;
        }
    };

    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    LinkedList(const LinkedList<T>& other) : head(nullptr), tail(nullptr) {
        Node* current = other.head;
        while (current != nullptr) {
            insert(current->getElement());
            current = current->getNext();
        }
    }

    LinkedList& operator=(const LinkedList<T>& other) {
        if (this == &other) {
            return *this;
        }

        clear();

        Node* current = other.head;
        while (current != nullptr) {
            insert(current->getElement());
            current = current->getNext();
        }

        return *this;
    }
    LinkedList(LinkedList<T>&& other) noexcept : head(other.head), tail(other.tail) {
        other.head = nullptr;
        other.tail = nullptr;
    }

    LinkedList& operator=(LinkedList<T>&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        clear();
        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;

        return *this;
    }

    ~LinkedList() {
        clear();
    }

    void insert(const T& val) {
        //cout << &val << endl;
        Node* node = new Node(val);

        if (head == nullptr) {
            head = tail = node;
        }
        else if (node->getElement() < head->getElement()) {
            node->setNext(head);
            head->setPrev(node);
            head = node;
        }
        else if (node->getElement() >= tail->getElement()) {
            tail->setNext(node);
            node->setPrev(tail);
            tail = node;
        }
        else {
            Node* current = head->getNext();
            while (node->getElement() >= current->getElement()) {
                current = current->getNext();
            }

            node->setNext(current);
            node->setPrev(current->getPrev());
            current->getPrev()->setNext(node);
            current->setPrev(node);
        }
    }

    const T* first() const {
        return &head->getElement();
    }

    const T* last() const {
        return &tail->getElement();
    }

    const T* findForward(const T& val) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->getElement() == val) {
                return &(current->getElement());
            }
            current = current->getNext();
        }
        return nullptr;
    }

    const T* findBackward(const T& val) const {
        Node* current = tail;
        while (current != nullptr) {
            if (current->getElement() == val) {
                return &(current->getElement());
            }
            current = current->getPrev();
        }
        return nullptr;
    }

    void erase(const T& val) {
        Node* current = head;
        while (current != nullptr) {
            if (val == current->getElement()) {
                Node* nextNode = current->getNext();
                Node* prevNode = current->getPrev();

                if (current == head) {
                    head = nextNode;
                }
                else {
                    prevNode->setNext(nextNode);
                }

                if (current == tail) {
                    tail = prevNode;
                }
                else {
                    nextNode->setPrev(prevNode);
                }

                delete current;
                return;
            }
            current = current->getNext();
        }
    }

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->getNext();
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
      //  cout << "all clear " << endl;
    }

    int size() const {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            ++count;
            current = current->getNext();
        }
        return count;
    }


    T& operator[](int i){
        if (i < 0 || i >= size()){
            cout << "Index out of range" << endl;
            throw out_of_range("Index out of range");
        }
        Node* current = head;
        for (int j = 0; j < i; j++) {
            current = current->getNext();
        }
        return current->getElement();
    }

    const T& operator[](int index)const{
        if (index < 0 || index >= size()) {
            cout << "Index out of range" << endl;
            throw std::out_of_range("Index out of range");
        }

        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->getNext();
        }

        return current->getElement();
    }

    void print()const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->getElement() << " ";
            current = current->getNext();
        }
        cout << endl;
    }
};


#endif //EX4_LINKEDLIST_H
