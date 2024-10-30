#include "Application.h"
#include <iostream>
#include <string>

Application::Application() {}

Application::~Application() {}

void Application::exec(Numbers& numbers)
{
    const char separator[] = "------------------------------------------------------------------------------------------------------------------------";
    const char commands[] =
        "1) Ввести unsigned int или float\n"
        "2) Отзеркалить группу битов начиная с младшего разряда(начиная с конца двоичного представления) unsigned int или float\n"
        "s) Вывести исходное и внутреннее представления unsigned int и float\n"
        "c) Вывести список команд\n"
        "e) Выход из программы\n";

    std::string command = "c";

    do {
        if (command == "e") {
            std::cout << "Программа завершена пользователем\n";
            break;
        }
        else if (command == "c") {
            std::cout << commands;
        }
        else if (command == "s") {
            std::cout << "Внутренне представление чисел: \n"
                << "Unsigned int: " << numbers.getUi() << '\n'
                << "              " << numbers.getUiBits() << '\n'
                << "Float: " << numbers.getF() << '\n'
                << "       " << numbers.getFBIts() << '\n';
        }
        else if (command == "1") {
            std::cout << "Какое число вы желаете ввести(ui/f): ";
            std::getline(std::cin, command);
            if (command == "ui") {
                std::cout << "Введите unsigned int: ";
                unsigned int num;
                std::cin >> num;
                if (!std::cin.fail()) {
                    numbers.setUi(num);
                    std::cout << "Число типа unsigned int было успешно введено\n";
                }
                else {
                    std::cout << "Число не было введено!!!\n";
                }
            }
            else if (command == "f") {
                std::cout << "Введите float: ";
                float num;
                std::cin >> num;
                if (!std::cin.fail()) {
                    numbers.setF(num);
                    std::cout << "Число типа float было успешно введено\n";
                }
                else {
                    std::cout << "Число не было введено\n";
                }
            }
            else {
                std::cout << "Некорректный тип!!!\n";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (command == "2") {
            std::cout << "В каком числе вы желаете отзеркалить группу битов(ui/f): ";
            std::getline(std::cin, command);
            if (command == "ui") {
                std::cout << "Введите номер младшего бита и количесто битов: ";
                int index, count;
                std::cin >> index >> count;
                if (!std::cin.fail() && index >= 0 && index <= numbers.getOrder() && (index + count) <= numbers.getOrder() && count > 0) {
                    numbers.mirror(index, count, false);
                    std::cout << "Группа битов в числе типа unsigned int была успешно отзеркалена\n";
                }
                else {
                    std::cout << "Числа не были введены либо диапазон некорректен!!!\n";
                }
            }
            else if (command == "f") {
                std::cout << "Введите номер младшего бита и количесто битов: ";
                int index, count;
                std::cin >> index >> count;
                if (!std::cin.fail() && index >= 0 && index <= numbers.getOrder() && (index + count) <= numbers.getOrder() && count > 0) {
                    numbers.mirror(index, count, true);
                    std::cout << "Группа битов в числе типа float была успешно отзеркалена\n";
                }
                else {
                    std::cout << "Числа не были введены либо диапазон некорректен!!!\n";
                }
            }
            else {
                std::cout << "Некорректный тип!!!\n";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            std::cout << "Некорректная команда. Попробуйте снова.\n";
        }

        std::cout << separator << '\n';
        std::cout << "Введите команду: ";
        std::getline(std::cin, command);

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод! Попробуйте снова.\n";
            command = "c";
        }

        std::cout << '\n';

    } while (true);
}