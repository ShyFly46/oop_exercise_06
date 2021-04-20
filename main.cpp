/**
 * Савченко И.В.
 * М8О-208Б-19
 * https://github.com/ShyFly46/oop_exercise_06
 *
 * Вариант 10:
 * Реализовать шаблон класса "квадрат" и шаблон
 * динамической коллекции "список".
 *
 * Реализовать аллокатор, работающий на основе
 * списка из стандартной библиотеки.
 **/

#include <iostream>
#include <algorithm>

#include "square.h"
#include "list.h"
#include "allocator.h"

void print_menu() {
	std::cout
		<< "p - push\n"
		<< "o - pop\n"
		<< "i - peep\n"
		<< "a - insert\n"
		<< "r - remove\n"
		<< "l - list\n"
		<< "x - exit\n"
		<< "\n";
}

int main() {
    list<square<int>, allocator<square<int>, 10>> s;
    print_menu();
    char cmd;
	std::cout << "> ";
    while (std::cin >> cmd) {
        switch(cmd){
		case 'p':
			{
				try {
					square<int> q;
					std::cin >> q;
					s.push(q);
					std::cout << "Pushed\n";
				}
				catch (std::exception &ex) {
					std::cout << "Not enough memory: " << ex.what() << '\n';
				}
			}
			break;

        case 'o':
			{
				try {
					s.pop();
					std::cout << "Popped\n";
				}
				catch (std::exception &ex) {
					std::cout << ex.what() << '\n';
				}
			}
			break;
			
        case 'i':
            try {
                auto t = s.top();
                std::cout << "Top: " << t << '\n';
            }
            catch (std::exception &ex) {
                std::cout << ex.what() << '\n';
            }
			break;
			
		case 'a':
			{
				square<int> q;
				std::cin >> q;
				unsigned int pos;
				std::cin >> pos;
				auto iter = s.begin();
				try {
					if (iter == s.end() && pos != 0) {
						throw std::runtime_error("Invalid position");
					}
					for (unsigned int i = 0; i < pos; ++i) {
						++iter;
						if (iter == s.end() && i != pos - 1) {
							throw std::runtime_error("Invalid position");
						}
					}
					s.insert(iter, q);
					std::cout << "Inserted\n";
				}
				catch (std::runtime_error &ex) {
					std::cout << ex.what() << '\n';
				}
				catch (std::bad_alloc &ex) {
					std::cout << "Not enough memory: " << ex.what() << '\n';
				}
			}
			break;
			
        case 'r':
			{
				unsigned int pos;
				std::cin >> pos;
				auto iter = s.begin();
				try {
					if (iter == s.end()) {
						throw std::runtime_error("Invalid position");
					}
					for (unsigned int i = 0; i < pos; ++i) {
						++iter;
						if (iter == s.end() && i != pos) {
							throw std::runtime_error("Invalid position");
						}
					}
					s.erase(iter);
					std::cout << "Erased\n";
				}
				catch (std::exception &ex) {
					std::cout << ex.what() << '\n';
				}
			}
			break;

        case 'l':
            std::for_each(s.begin(), s.end(), [](square<int> q) {
                std::cout << q << '\n';
            });
			break;

        case 'x':
            return 0;
			
        default:
            std::cout << "Invalid cmd\n";
			break;
        }
		
		std::cout << "> ";
    }
}
