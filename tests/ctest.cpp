#include <vector>
#include "controllers/someobjs.cpp"
#include "controllers/PointsProfile.cpp"
#include "controllers/mathfunctions.cpp"

int main(){
	
	cout << "--------------starting class tests----------------" << endl;
	
	GeodesicCoordinate Coor(34.3, 44.1,13);
	Coor.coordinating();
	Coor.GeodesicalDraw();

	GeographicCoordinate Coor2(4,4,24);
	Coor2.coordinating();
	Coor2.GeographicalDraw();
	
	cout << "----------------Profile Makers---------------------" << endl;

	int many_points = 5;
	
	std::vector<StratPoint> points;

	for(int i = 0;i < many_points;i++){
		StratPoint point(5.1 + i,4.4 + i,60, 25, 73);
		points.push_back(point);
	}

	ProfileChevron* profile = new ProfileChevron(points); 	
	
	profile -> ShowGatheredPoints();
	profile -> GotChevronData();

	return 0;
}
