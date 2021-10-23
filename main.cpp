#include <iostream>

int main() {
    int b;
    int &k = b;
    std::cin >> b;

    auto f = [](int _a){return _a+666;};
    std::cout << f(k)<< std::endl;
    return 0;
}
