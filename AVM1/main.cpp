#include "application.h"
#include "Windows.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Application application;
    Numbers numbers;
    application.exec(numbers);
    
    return 0;
}