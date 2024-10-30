#include "Application.h"
#include <iostream>
#include <string>

Application::Application() {}

Application::~Application() {}

void Application::exec(Numbers& numbers)
{
    const char separator[] = "------------------------------------------------------------------------------------------------------------------------";
    const char commands[] =
        "1) ������ unsigned int ��� float\n"
        "2) ����������� ������ ����� ������� � �������� �������(������� � ����� ��������� �������������) unsigned int ��� float\n"
        "s) ������� �������� � ���������� ������������� unsigned int � float\n"
        "c) ������� ������ ������\n"
        "e) ����� �� ���������\n";

    std::string command = "c";

    do {
        if (command == "e") {
            std::cout << "��������� ��������� �������������\n";
            break;
        }
        else if (command == "c") {
            std::cout << commands;
        }
        else if (command == "s") {
            std::cout << "��������� ������������� �����: \n"
                << "Unsigned int: " << numbers.getUi() << '\n'
                << "              " << numbers.getUiBits() << '\n'
                << "Float: " << numbers.getF() << '\n'
                << "       " << numbers.getFBIts() << '\n';
        }
        else if (command == "1") {
            std::cout << "����� ����� �� ������� ������(ui/f): ";
            std::getline(std::cin, command);
            if (command == "ui") {
                std::cout << "������� unsigned int: ";
                unsigned int num;
                std::cin >> num;
                if (!std::cin.fail()) {
                    numbers.setUi(num);
                    std::cout << "����� ���� unsigned int ���� ������� �������\n";
                }
                else {
                    std::cout << "����� �� ���� �������!!!\n";
                }
            }
            else if (command == "f") {
                std::cout << "������� float: ";
                float num;
                std::cin >> num;
                if (!std::cin.fail()) {
                    numbers.setF(num);
                    std::cout << "����� ���� float ���� ������� �������\n";
                }
                else {
                    std::cout << "����� �� ���� �������\n";
                }
            }
            else {
                std::cout << "������������ ���!!!\n";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (command == "2") {
            std::cout << "� ����� ����� �� ������� ����������� ������ �����(ui/f): ";
            std::getline(std::cin, command);
            if (command == "ui") {
                std::cout << "������� ����� �������� ���� � ��������� �����: ";
                int index, count;
                std::cin >> index >> count;
                if (!std::cin.fail() && index >= 0 && index <= numbers.getOrder() && (index + count) <= numbers.getOrder() && count > 0) {
                    numbers.mirror(index, count, false);
                    std::cout << "������ ����� � ����� ���� unsigned int ���� ������� �����������\n";
                }
                else {
                    std::cout << "����� �� ���� ������� ���� �������� �����������!!!\n";
                }
            }
            else if (command == "f") {
                std::cout << "������� ����� �������� ���� � ��������� �����: ";
                int index, count;
                std::cin >> index >> count;
                if (!std::cin.fail() && index >= 0 && index <= numbers.getOrder() && (index + count) <= numbers.getOrder() && count > 0) {
                    numbers.mirror(index, count, true);
                    std::cout << "������ ����� � ����� ���� float ���� ������� �����������\n";
                }
                else {
                    std::cout << "����� �� ���� ������� ���� �������� �����������!!!\n";
                }
            }
            else {
                std::cout << "������������ ���!!!\n";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            std::cout << "������������ �������. ���������� �����.\n";
        }

        std::cout << separator << '\n';
        std::cout << "������� �������: ";
        std::getline(std::cin, command);

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "������������ ����! ���������� �����.\n";
            command = "c";
        }

        std::cout << '\n';

    } while (true);
}