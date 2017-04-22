#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "Table.h"
#include "sqlite3.h"

using namespace std;

static int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    fprintf(stderr, "%s: ", (const char*)data);

    for(i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}

void executeSqlStatement(sqlite3 *db,const char* sql) {
    int rc = 0 ;
    char *zErrMsg = 0;

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);  // Here it doesn't work, rc=21;
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } 
    else {
        fprintf(stdout, "Operation done successfully\n");
    }
}

void Table::createTable(sqlite3 *db, string columnDetails) {
    this->sqlCommand =  "CREATE TABLE ";

    this->sqlCommand += (this->tableName + " (" + columnDetails + ");");
    executeSqlStatement(db, this->sqlCommand.c_str());
    printf(sqlCommand.c_str());
}