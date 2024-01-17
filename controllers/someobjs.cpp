#include <iostream>

using namespace std;




class Coordinate {
	
	public:
		float time;
		float xcoor;
		float ycoor;
		

};


class GeographicCoordinate: Coordinate {
	public:
		
		GeographicCoordinate(float x, float y){
			xcoor = x;
			ycoor = y;
		}

		void display(){
			cout << "Geographic Coors" << endl;
		}
};

class GeodesicCoordinate: Coordinate {
	public:
		GeodesicCoordinate(float x, float y){
			xcoor = x;
			ycoor = y;
		}

		void display(){
			cout << "Geodesic Coors" << endl;
		}
};
