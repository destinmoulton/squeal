#include <iostream>

#include "src/DB.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    DB db;

    db.connect("test.db");

    return 0;
}
