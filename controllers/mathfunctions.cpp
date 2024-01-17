#include <math.h>

using std::exp;
using std::log;
using std::sin;
using std::cos;

float specialized_functions(){
		
	return result;
}

float sensible(){

	return result;
}

float multiplication(){

	return result;
}

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

bool symbol_exists(char symbol){

	using std::cout;
	using std::endl;
	
	cout << "symbol; "<< symbol << endl;	
	char OPERATIONS[] = {'-','+'};
	
	for(char ope : OPERATIONS){
		if(symbol == ope){
			return true;
		}
	}

	return false;
}


char * separate_terms(char* content,std::string* ops,float *numbers,int symbols,int* k){
    	using std::cout;
	using std::endl;
	
	//I just achieve the sum and rest operations
	//the rest operations leaves a minus sumbol in the result	

        int j = 0;
        while (*content != '\0') {

  	    	if(symbol_exists(*content)){
		
			*ops+=*content;
                	//char* substring = content +1;

			char* mystring = content - j;
                	char aux = *content;
			*content = '\0';
			cout << mystring << " number" << endl;
			float num = std::stof(mystring);	
			numbers[*k] = num;
			*content = aux;
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
    	

	return content;
    
};


