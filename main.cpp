#include <iostream>
#include "sqlite3.h"
#include "Table.h"
using namespace std;

int openDatabase(sqlite3 *db);

int main() {
    sqlite3 *db;
    string columnValues, rowValues;   // these are for query
    Table Personal;
    Personal.SettableName("PERSONAL");
    columnValues = "NUME TEXT, ID TEXT";   // this is just an example

    openDatabase(db);

    Personal.createTable(db, columnValues);
    sqlite3_close(db);
    return 0;
}