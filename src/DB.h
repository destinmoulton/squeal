//
// Created by destin on 6/23/23.
//

#ifndef SQUEEL_DB_H
#define SQUEEL_DB_H

#include <string>
#include <sqlite3.h>

class DB {

public:
    DB();

    ~DB();

    bool connect(std::string dbname);

    bool queryTable(std::string q, char **results, int *rows, int *cols);

    bool printResults(char **results, int rows, int cols);

    bool exec(std::string);

    bool query(std::string);

private:
    sqlite3 *m_db;

    void printError();

};


#endif //SQUEEL_DB_H
