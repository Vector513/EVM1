#ifndef APPLICATION_H
#define APPLICATION_H

#include "number.h"

class Application {
public:
    Application();
    ~Application();

    void exec(Numbers& numbers);
};

#endif // APPLICATION_H