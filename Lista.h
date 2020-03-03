//
// Created by Jakub on 25-12-2019.
//

#ifndef LISTEXE_LISTA_H
#define LISTEXE_LISTA_H

#include <iostream>

template <typename Type>
class Lista {
    struct Node {
        explicit Node(Type data, Node* next = nullptr, Node* prev = nullptr) {
            this->data = data;
            this->next = next;
            this->previous = prev;
        }
        Type data;
        Node* next;
        Node* previous;
    };
    public:
        // Types
        typedef unsigned long int Index;
        // Vars
        const Index max_size{ 4294967295 };
        // Functions
        ~Lista();
        auto size();
        bool push_back(Type item);
        bool push_front(Type item);
        bool remove_back();
        bool remove_front();
        void print_all();
        Type &operator[](Index index);
    protected:
        // Vars
        const nullptr_t null_node{ nullptr };
        Node* back{ null_node };
        Node* front{ null_node };
    private:
        // Vars
        Index size_of_records{ 0 };
};


template<typename Type>
auto Lista<Type>::size() {
    return this->size_of_records;
}

template<typename Type>
bool Lista<Type>::push_back(Type item) {
    try {
        if (this->size() >= this->max_size) {
            // Reached maximum size of list
            throw;
        }

        Node* new_node = new Node(item);

        if (this->size() == 0) {
            this->front = new_node;
            this->back = new_node;
        } else {
            new_node->previous = this->back;
            this->back->next = new_node;
            this->back = new_node;
        }
    } catch (...) {
        return false;
    }

    this->size_of_records++;
    return true;
}

template<typename Type>
bool Lista<Type>::remove_back() {
    try {
        switch (this->size()) {
            case 0:
                throw;
            case 1:
                delete(this->back);
                delete(this->front);
                this->back = this->null_node;
                this->front = this->null_node;
                break;
            default:
                this->back = this->back->previous;
                delete(this->back->next);
                this->back->next = this->null_node;
                break;
        }
    } catch (...) {
        return false;
    }

    this->size_of_records--;
    return true;
}

template<typename Type>
Type &Lista<Type>::operator[](Index index) {
    if (index > this->size()) throw;

    Node* record = this->front;
    for (int i = 0; i < index; ++i) {
        record = record->next;
    }

    return record->data;
}


template<typename Type>
Lista<Type>::~Lista() {
    std::cout << "DELETE..." << std::endl;
    if (this->size() == 0) return;
    for (int i = 0; i < this->size(); ++i) {
        this->remove_back();
    }
    delete this->back;
    delete this->front;
}

template<typename Type>
bool Lista<Type>::push_front(Type item) {
    try {
        if (this->size() >= this->max_size) {
            // Reached maximum size of list
            throw;
        }

        Node* new_node = new Node(item);

        if (this->size() == 0) {
            this->front = new_node;
            this->back = new_node;
        } else {
            new_node->next = this->front;
            this->front->previous = new_node;
            this->front = new_node;
        }
    } catch (...) {
        return false;
    }

    this->size_of_records++;
    return true;
}

template<typename Type>
bool Lista<Type>::remove_front() {
    try {
        switch (this->size()) {
            case 0:
                throw;
            case 1:
                delete(this->back);
                delete(this->front);
                this->back = this->null_node;
                this->front = this->null_node;
                break;
            default:
                this->front = this->front->next;
                delete(this->front->previous);
                this->front->previous = this->null_node;
                break;
        }
    } catch (...) {
        return false;
    }

    this->size_of_records--;
    return true;
}

template<typename Type>
void Lista<Type>::print_all() {
    Node* node = this->front;
    while(node) {
        std::cout << "Node: " << node->data << std::endl;
        node = node->next;
    }
    std::cout << "Size: " << this->size() << std::endl;
    std::cout << "===============================" << std::endl;

    delete node;
}


#endif //LISTEXE_LISTA_H
