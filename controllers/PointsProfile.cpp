#include <cmath>

class Point {
	
	public:
		int pointid;

	public:
		Point(float x, float y)
			:x_distance(x), 
			y_distance(y){}
		
		void show_coors(){
			cout << "coors" << endl;
			cout << "x: " << x_distance << endl;
			cout << "y: " << y_distance << endl;
		}

	private:
		float x_distance;
		float y_distance;
};



class StratPoint : public Point {
	//this values are received in deegres
	//math functions return rads values
	float alpha_;
	float az_;
	float buzareal_;

	//aparent buza (buzap) and rumbo, are profile's direction data that 
	//must be entered
	//to draw the profile in that specific direction
	//if direction forms an angle of 90 with the asymuth of the formation
	//or zero with the real buza (alpha)
	
	//the real buza could be given to calculate the aparent buza
	//taking into account alpha angle
	public:
		StratPoint(float x, float y, float az, float buzareal, float alpha)
			:Point(x,y), 
			az_(az), 
			buzareal_(buzareal), 
			alpha_(alpha) {}
		
		void FindAparentBuzz(){
			float alpha_rads = alpha_ * M_PI / 180.0;
			float buzareal_rads = buzareal_ * M_PI / 180.0;
			float buzap_rads = atan(tan(buzareal_rads) / sin(alpha_rads));
		      	float buzap = buzap_rads * 180.0 / M_PI;	
			
			cout << "buzap: " << buzap << endl;
		}	

};

class NormalPoint: public Point {
	//the real buza could be given to calculate the aparent buza
	//taking into account alpha angle
	public:
		NormalPoint(float x, float y)
			:Point(x,y), 
		
};



class Profile {
	//Profile object receives points and add them in lists
	//later it will gathers the points and build the profile
	//based on an specific technic
	using std::cout;
	using std::endl;

	public:
		int profileid;
			
		std::vector<StratPoint> points_;

		Profile(std::vector<StratPoint> points)
			:points_(points){}

		void DrawProfile(){
			cout << "The draw should be here" << endl;
		}

		void ShowGatheredPoints(){
			for(auto& point: points_){
				point.show_coors();
			}
		}
		
		void warning(){
			cout << "Building Profile" << endl;
		}	
};

class ProfileAngles: public Profile {
	using std::cout;
	using std::endl;

	public:
		ProfileWithAngles(std::vector<StratPoint> points): 
			Profile(points){} 
		
		void GotAnglesData():
			for(auto& point: points_){
				point.FindAparentBuzz();
			}

		void warning(){
			cout << "Building Angles Profile" << endl;
		}
};

class ProfileChevron: public Profile {
	using std::cout;
	using std::endl;

	public:
		ProfileChevron(std::vector<StratPoint> points)
			:Profile(points) {}
		
		void GotChevronData(){
			for(auto& point: points_){
				point.FindAparentBuzz();
			}
		}

		void warning(){
			cout << "Building Chevron Profile" << endl;
		}
};


