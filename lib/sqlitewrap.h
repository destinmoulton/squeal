//
// Created by destin on 6/23/23.
//

#ifndef SQUEEL_DB_H
#define SQUEEL_DB_H

#include <string>
#include <sqlite3.h>

struct QueryResult {
    char **results;
    int rows;
    int cols;
};

class SQLiteWrap {

public:
    SQLiteWrap();

    ~SQLiteWrap();

    bool connect(std::string dbname);

    QueryResult *queryTable(std::string q);

    bool printResults(char **results, int rows, int cols);

    bool exec(std::string);

    bool query(std::string);

    QueryResult *get_all_tables();

private:
    sqlite3 *m_db;

    void printError();

};


#endif //SQUEEL_DB_H
