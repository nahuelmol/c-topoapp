#include <iostream>

using namespace std;




class Coordinate {
	
	public:
		
		Coordinate(float x, float y): xcoor(x), ycoor(y) {}

		void coordinating() const {
		
			cout << "coordinating" << endl;
		}		
	private:
		float xcoor;
		float ycoor;
};


class GeographicCoordinate: public Coordinate {
	public:
		
		GeographicCoordinate(float x, float y, float time): Coordinate(x,y), time_(time){}

		void GeographicalDraw(){
			cout << "time: " << time_ << endl;
			cout << "graphical draw" << endl;
		}

	private:
		float time_;
};

class GeodesicCoordinate: public Coordinate {
	public:
		GeodesicCoordinate(float x, float y, float time): Coordinate(x,y), time_(time) {}

		void GeodesicalDraw(){
			cout << "time: " << time_ << endl;
			cout << "geodesical draw" << endl;
		}
		
	private:
		float time_;
};
