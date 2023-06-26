//
// Created by destin on 6/23/23.
//

#include <iostream>
#include <string>
#include <sqlite3.h>
#include "DB.h"

DB::DB() {
    m_db = nullptr;
}

DB::~DB() {
    sqlite3_close_v2(m_db);
};

bool DB::connect(std::string dbname) {
    std::cout << "connecting to " << dbname << std::endl;
    int res = sqlite3_open(dbname.c_str(), &m_db);
    if (res != SQLITE_OK) {
        printError();
        return false;
    }
    return true;
}

bool DB::exec(std::string ex) {
    char *error;
    int exeres = sqlite3_exec(m_db, ex.c_str(), NULL, NULL, &error);
    if (exeres != 0) {
        std::cerr << "error executing sql" << std::endl;
        printError();
        sqlite3_free(error);
        return false;
    }
    return true;
}

bool DB::queryTable(std::string q, char **results, int *rows, int *cols) {
    char *error;
    int qres = sqlite3_get_table(m_db, q.c_str(), &results, rows, cols, &error);
    std::cout << "queryTable(...) :: qres = " << qres << std::endl;
    if (qres != 0) {
        std::cerr << "error executing sqlite3_get_table" << std::endl;
        printError();
        sqlite3_free(error);
        return false;
    }
    std::cout << "queryTable(...) :: query executed successfully" << std::endl;
    std::cout << "queryTable(...) :: number of rows found: " << *rows << std::endl;
    return true;
}

bool DB::printResults(char **results, int rows, int cols) {
    if (rows == 0) {
        std::cout << "printResults(...) :: no rows found";
        return false;
    }
    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= cols; j++) {

            int cellPos = (i * cols) + j;
            std::cout << results[cellPos] << "      ";
        }

        std::cout << std::endl;
    }
    return true;
}

void DB::printError() {
    std::cerr << sqlite3_errmsg(m_db) << std::endl;
}



