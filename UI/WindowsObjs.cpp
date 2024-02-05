#include <iostream>

using std::endl;
using std::cout;

class ParentWindow {

    private:
        std::vector<const char*> sons;

    public: 
        void add_son_window(const char* sonwindow){
            sons.push_back(sonwindow);
        }

        void show_sons(){
            for(auto& son: sons){
                cout << "son: " << son << endl;
            }
        }
        
};
