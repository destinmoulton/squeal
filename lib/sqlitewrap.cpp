//
// SQLiteWrap is a simple sqlite c library wrapper
// This consolidates the intricacies of the sqlite3 library
// Created by destin on 6/23/23.
//

#include <iostream>
#include <string>
#include <sqlite3.h>
#include "sqlitewrap.h"

SQLiteWrap::SQLiteWrap() {
    m_db = nullptr;
}

SQLiteWrap::~SQLiteWrap() {
};

void SQLiteWrap::close_connection() {
    sqlite3_close_v2(m_db);
}

bool SQLiteWrap::query(std::string) {
}

bool SQLiteWrap::connect(std::string dbname) {
    std::cout << "connecting to " << dbname << std::endl;
    int res = sqlite3_open(dbname.c_str(), &m_db);
    if (res != SQLITE_OK) {
        printError();
        return false;
    }
    return true;
}

bool SQLiteWrap::exec(std::string ex) {
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

QueryResult *SQLiteWrap::queryTable(std::string q) {
    char *error;
    char **results = nullptr;
    int rows, cols;
    int qres = sqlite3_get_table(m_db, q.c_str(), &results, &rows, &cols, &error);
    std::cout << "queryTable(...) :: qres = " << qres << std::endl;
    if (qres != 0) {
        std::cerr << "error executing sqlite3_get_table" << std::endl;
        printError();
        sqlite3_free(error);
        return nullptr;
    }
    std::cout << "queryTable(...) :: query executed successfully" << std::endl;
    std::cout << "queryTable(...) :: number of rows found: " << rows << std::endl;
    return new QueryResult{
            results = results,
            rows = rows,
            cols = cols
    };
}

bool SQLiteWrap::printResults(char **results, int rows, int cols) {
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

void SQLiteWrap::printError() {
    std::cerr << sqlite3_errmsg(m_db) << std::endl;
}

// Get a list of the
QueryResult *SQLiteWrap::get_all_tables() {

    std::string q("SELECT name "
                  "FROM "
                  "    sqlite_schema "
                  "WHERE "
                  "    type ='table' AND "
                  "    name NOT LIKE 'sqlite_%';");

    return queryTable(q);
}



