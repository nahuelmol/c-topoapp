#include "controllers/someobjs.cpp"

int main(){
	
	cout << "--------------starting class tests----------------" << endl;
	
	GeodesicCoordinate Coor(34.3, 44.1);
	Coor.display();

	GeographicCoordinate Coor2(4,4);
	Coor2.display();

	return 0;
}
