PGconn *conn = PQconnectdb("dbname=mydatabase user=myuser password=mypass host=localhost");

if(PQstatus(conn) != CONNECTION_OK){
	PQfinish(conn);
	return 1;
}


PGresult *res = PQexec(conn, "SELECT * FROM mytable")

if(PQresltStatus(res) != PQRES_TUPLES_OK){
	PQclear(res);
	PQfinish(conn);
	return 1;
}


int rows = PQntuples(res);

for( int i = 0;i < rows; ++i){
	//here, each row could be process
}

PQclear(res);
