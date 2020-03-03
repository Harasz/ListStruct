#include <iostream>
#include "Lista.h"

int main() {
    Lista<int> lista;
    lista.push_back(1);
    std::cout << "Push back 1" << std::endl;
    lista.print_all();

    lista.remove_front();
    std::cout << "Remove front" << std::endl;
    lista.print_all();

    lista.push_back(2);
    std::cout << "Push back 2" << std::endl;
    lista.print_all();

    lista.push_back(3);
    std::cout << "Push back 3" << std::endl;
    lista.print_all();

    lista.push_back(4);
    std::cout << "Push back 4" << std::endl;
    lista.print_all();

    lista.push_front(4);
    std::cout << "Push front 4" << std::endl;
    lista.print_all();

    lista.push_front(152);
    std::cout << "Push front 152" << std::endl;
    lista.print_all();


    lista.remove_back();
    std::cout << "Remove back" << std::endl;
    lista.print_all();


    return 0;
}
