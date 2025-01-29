#include "sqlite.h"
#include <iostream>

SQLite sqlite("database.sqlite");
SQLite::SQLite(const std::string &dbName) : dbName(dbName), db(nullptr) {}
SQLite::~SQLite()
{
    close();
}

bool SQLite::open()
{
    int result = sqlite3_open(dbName.c_str(), &db);
    if (result != SQLITE_OK)
    {
        std::cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

void SQLite::close()
{
    if (db)
    {
        sqlite3_close(db);
    }
}