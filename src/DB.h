//
// Created by destin on 6/23/23.
//

#ifndef SQUEEL_DB_H
#define SQUEEL_DB_H

#include <sqlite3.h>

class DB {

public:
    DB();

    ~DB();

    bool connect(const char *dbname);

    bool query(const char *query);


private:
    sqlite3 *m_db;

    void printError();
};


#endif //SQUEEL_DB_H
