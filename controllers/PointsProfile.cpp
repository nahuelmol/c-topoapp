#include <cmath>

class Point {

	public:
		Point(float x, float y): x_distance(x), y_distance(y){}
		
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
	
	//aparent buza (buzap) and rumbo, are profile's direction data that 
	//must be entered
	//to draw the profile in that specific direction
	//if direction forms an angle of 90 with the asymuth of the formation
	//or zero with the real buza (alpha)
	
	//the real buza could be given to calculate the aparent buza
	//taking into account alpha angle
	
	public:
		StratPoint(float x, float y, float az, float buzareal, float alpha): Point(x,y), az_(az), buzareal_(buzareal), alpha_(alpha) {}
		
		void FindBuzAparent(){
			float alpha_rads = alpha_ * M_PI / 180.0;
			float buzareal_rads = buzareal_ * M_PI / 180.0;
			float buzap_rads = atan(tan(buzareal_rads) / sin(alpha_rads));
		      	float buzap = buzap_rads * 180.0 / M_PI;	
			
			cout << "buzap: " << buzap << endl;
		}	

	private:
		//this values are received in deegres
		//math functions return rads values
		float alpha_;
		float az_;
		float buzareal_;
};



class Profile {

	//Profile object receives points and add them in lists
	//later it will gathers the points and build the profile
	//based on an specific technic
	
	public:
		
		Profile(Point * point): point_(point){}

		void DrawProfile(){
			cout << "The draw should be here" << endl;
		}

		void ShowGatheredPoints(){
			//cout << *points << endl;
		}

	private:
		Point * point_;
		Point * points;
};

class ProfileWithAngles: public Profile {
	public:
		ProfileWithAngles(Point * point, bool end): Profile(point), finalpoint(end){}

		void warning(){
			cout << "building porifle with angles" << endl;
		}

	private:
		bool finalpoint;
};

class ProfileKraven : public Profile {
	public:
		ProfileKraven(Point * point, bool end): Profile(point), finalpoint(end) {}

		void warning(){
			cout << "Building Profile Kraven" << endl;
		}

	private:
		bool finalpoint;


};


