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

    QueryResult *queryTable(char *q);

    bool create_table(char *tablename);

    bool printResults(char **results, int rows, int cols);

    bool exec(char *exq);


    QueryResult *get_all_tables();

    void close_connection();

private:
    sqlite3 *m_db;

    void printError();

};


#endif //SQUEEL_DB_H
