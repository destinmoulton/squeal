#include <iostream>
#include <filesystem>
#include "src/DB.h"

int main() {
    std::cout << "initializing..." << std::endl;
    DB db;

    std::cout << "current_path=" << std::filesystem::current_path() << std::endl;

    db.connect(std::string("test.db"));

    char **results = nullptr;
    int rows, cols;

    std::string q("SELECT name "
                  "FROM "
                  "    sqlite_schema "
                  "WHERE "
                  "    type ='table' AND "
                  "    name NOT LIKE 'sqlite_%';");

    if (db.queryTable(q, results, &rows, &cols)) {

        db.printResults(results, rows, cols);
    }


    return 0;
}
