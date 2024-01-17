#include <math.h>

using std::exp;
using std::log;
using std::sin;
using std::cos;

float operate(float * numbers, std::string ops){
	using std::cout;
	using std::endl;

	cout << "operations: "<< ops << endl;
	
	int j = 0;
	float result = 0;	

	for(char op : ops){

		switch(op){
			case '+':
			{	
				if(result == 0){
					result = numbers[j+1] + numbers[j];
				
				} else {
					result = numbers[j+1] + result;
				}
			} break;

			case '-':
			{	
				cout << "-" <<endl;

				if(result == 0){

					result = numbers[j] - numbers[j+1];
				} else {
					result = numbers[j+1] - result;
				}
			} break;
			
			case '*':
			{
				cout << "*" << endl;
			} break;
			
			case '/':
			{
			} break;
			default:
				std::cout << "There's not a valid symbol" << endl; 
		}


		j++;
	}
	
	std::cout << "result: " << result << endl;

	return result;

}

int frequency(const char* str){
	using std::cout;
	using std::endl;

	int count = 0;

    	char AVAILABLE_OPERATIONS[] = {'+','-'};

	for(int j = 0;j < sizeof(AVAILABLE_OPERATIONS);j++){
		for(int i=0; str[i] != '\0'; i++){
			
			if(str[i] == AVAILABLE_OPERATIONS[j]){
				count++;
			}
		}
	}

	cout << "many: " << count << endl;
	return count;
}



char * separate_terms(char* content,std::string* ops,float *numbers,int symbols,int* k){
    	using std::cout;
	using std::endl;
	
	//this function just act over the firs symbol, because 
	//the loop is breaked once the k iterator in completed
	//if symbols switched their position in the following array
	//they are perceived or not
	//just the one in the first position is considered
	//think how to change it
    	char AVAILABLE_OPERATIONS[] = {'-','+'};

    	std::size_t  size_operations = sizeof(AVAILABLE_OPERATIONS);
	
    	for(int i = 0;i < size_operations; i++){
        	char delimiter = AVAILABLE_OPERATIONS[i];

        	int j = 0;
        	while (*content != '\0') {

  	    		if(*content == delimiter){
				cout << "delimiter: "<< delimiter << endl;
				*ops+=delimiter;
                		//char* substring = content +1;

				char* mystring = content - j;
                		*content = '\0';
				cout << mystring << " number" << endl;
				float num = std::stof(mystring);	
				numbers[*k] = num;
				*content = delimiter;
				//content = content + j;
			
				
				*k = *k + 1;

				return content;
            		};
			
			if(*k == symbols){
				char* mystring = content;
				float num = std::stof(mystring);
				numbers[*k] = num;
				cout << content << " number" << endl;
				*k = *k + 1;
				return content;
			}

            		content++;
            		j++;
        	};
    	};

	return content;
    
};


