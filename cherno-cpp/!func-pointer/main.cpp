#include <iostream>

void funcExecute(int a, int b, void* func) {
    int result = func(a, b);
    std::cout << result << std::endl;
}

int someFunc(int a, int b)
{
    return a * b;
}

int main() {
    funcExecute(5, 6, &someFunc);
}
