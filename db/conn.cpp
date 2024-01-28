
std::string dbname = "dbname=TopoApp ";
std::string user = "user=Alumno ";
std::string pass = "password=alumno ";
std::string host = "host=localhost ";
std::string port = "port=5432";

PGconn * StartConnection(){
	std::string connsentence = dbname + user + pass + host + port;
	PGconn *conn = PQconnectdb(connsentence.c_str());

	if(PQstatus(conn) == CONNECTION_OK){
		std::cout << "Connection successful" << std::endl;	
		//return 1;
	} else {
		std::cout << "Connection failed" << std::endl;

	}

	return conn;
}


