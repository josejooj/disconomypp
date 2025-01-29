#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>
#include <vector>

class SQLite {
public:
    SQLite(const std::string& dbName);
    ~SQLite();

    bool open();
    void close();

private:
    std::string dbName;
    sqlite3* db;
};

extern SQLite sqlite;

#endif
