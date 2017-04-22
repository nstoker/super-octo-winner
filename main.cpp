#include <iostream>
#include "Table.h"
using namespace std;



int main() {
    sqlite3 *db;
    sqlite3_open_v2("test.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
    string columnValues, rowValues;   // these are for query
    Table Personal;
    Personal.SettableName("PERSONAL");
    columnValues = "NUME TEXT, ID TEXT";   // this is just an example


    Personal.createTable(db, columnValues);
    sqlite3_close(db);
    return 0;
}