#include "db/conn.h"
#include "libpq-fe.h"

void test(){
	PGconn * conn = StartConnection();
	ProveQueries(conn);
	PQfinish(conn);	
}


int main(){
	test();
}
