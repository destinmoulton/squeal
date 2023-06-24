//
// Created by destin on 6/23/23.
//

#include <iostream>
#include <sqlite3.h>
#include "DB.h"

DB::DB() {
    m_db = nullptr;
}

DB::~DB() {
    sqlite3_close_v2(m_db);
};

bool DB::connect(char const *dbname) {
    std::cout << "connecting to " << dbname << std::endl;
    int res = sqlite3_open(dbname, &m_db);
    if (res != SQLITE_OK) {
        printError();
    }
    return true;
}


void DB::printError() {
    std::cerr << sqlite3_errmsg(m_db) << std::endl;
}


