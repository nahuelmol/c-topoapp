#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <libpq-fe.h>
#include <iostream>

int main() {
    SQLHENV hEnv;
    SQLHDBC hDbc;
    SQLRETURN ret;

    // Initialize the ODBC environment
    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
    ret = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
    ret = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);

    // Connect to the database
    ret = SQLConnect(hDbc, (SQLCHAR*)"YourDSN", SQL_NTS, (SQLCHAR*)"Username", SQL_NTS, (SQLCHAR*)"Password", SQL_NTS);

    if (SQL_SUCCEEDED(ret)) {
        // Database connection is successful, execute queries here
        SQLHSTMT hStmt;
        ret = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);

        if (SQL_SUCCEEDED(ret)) {
            ret = SQLExecDirect(hStmt, (SQLCHAR*)"SELECT * FROM YourTable", SQL_NTS);

            if (SQL_SUCCEEDED(ret)) {
                // Process query results here

                // Close the statement
                SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
            }
        }

        // Close the database connection
        SQLDisconnect(hDbc);
    } else {
        std::cerr << "Database connection failed." << std::endl;
    }

    // Free resources
    SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
    SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

    return 0;
}
