bool ProveQueries(PGconn *conn){
	using std::cout;
	using std::endl;

	PGresult *res = PQexec(conn, "SELECT * FROM mypoints;");

	if(PQresultStatus(res) != PGRES_TUPLES_OK){
		PQclear(res);
		PQfinish(conn);
		return false;
	} else {
		cout << "success query" << endl;
		return true;
	}


	int rows = PQntuples(res);

	for(int i = 0;i < rows; ++i){
	
		//here, each row could be process
	}

	PQclear(res);
}
