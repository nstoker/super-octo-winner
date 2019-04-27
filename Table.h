#ifndef __TABLE_H
#define __TABLE_H

#include <sqlite3.h>
using namespace std;
void executeSqlStatement(sqlite3 *db);
int callback(void *data, int argc, char **argv, char **azColName);
class Table
{
public:
    void SettableName(string val){tableName = val;}
    void createTable(sqlite3 *db, string columnDetails);    
    string tableName;
    string sqlCommand;
};
#end
