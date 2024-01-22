#include <math.h>
#include <vector>

using std::exp;
using std::log;
using std::sin;
using std::cos;


bool symbol_exists(char symbol){
	using std::cout;
	using std::endl;
	
	char OPERATIONS1[] = {'-','+'};
	char OPERATIONS2[] = {'*','/'};	
	for(char ope : OPERATIONS1){
		if(symbol == ope){
			return true;
		}
	}

	return false;
}
	
bool bothExists(char c, char n, std::string &scope){
	int count_c = 0;
	int count_n = 0;
	for(char che: scope){
		if(c == che){
			count_c++;
		}

		if(n == che){
			count_n++;
		}
	}

	if(count_c > 0 && count_n > 0){
		return false;
	} else {
		return true;
	}
}


bool same_level_ops(std::string &operation){
	char OPS1[] = {'+','-'};
	char OPS2[] = {'*', '/'};
	char numbers[] = {'1','2','3','4','5','6','7','8','9','0','.'};

	for(char c: OPS1){
		for(char n: OPS2){
			if(bothExists(c,n,operation)){
				return true;	
			} else {
				return false;
			};
		}	
	}
	return false;
}

float specialized_functions(){
	float result;	
	return result;
}

float sensible(char ope, float number1, float number2){
	//maybe the result should not be just floats, think about the double type
	//think about other operations that could be made in this stage
	std::vector<std::string> operations= {"potential", "sqrt"};
	for(auto& op: operations){
		if(ope == 'potential'){
			float base = number1;
			float exponent = number2;
			float result = std::pow(base, exponent);
			return result;
		}

		if(ope == 'sqrt'){
			float base = number1;
			float squarer = number2;
			
			float result = std::sqrt(base); 
			return result;
		}
	}
	float result;
	return result;
}

float operate(float *numbers, std::string ops){
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
				if(result == 0){
					result = numbers[j] - numbers[j+1];
				} else {
					result = numbers[j+1] - result;
				}
				
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

float calculation(std::vector<std::string> &numbers, std::vector<char> &symbols){
	int k = 1;
	std::vector<float> floatnumbers;
	for(std::string &str: numbers){
		float realnumber = std::stof(str);
		floatnumbers.push_back(realnumber);
	}
	float tresult = floatnumbers[0];
	for(char &sym: symbols){
		switch(sym){
			case '*':
			{
				tresult = tresult * floatnumbers[k];
			}
			break;
			case '/':
			{
				tresult = tresult / floatnumbers[k]; 
			}
			break;
			case '+':
			{
				tresult = tresult + floatnumbers[k];
			}
			break;
		}
		k++;
	}
	return tresult;
}


float operate_scope(std::string &operation){
	char numbers_available[] = {'1','2','3','4','5','6','7','8','9','0','.'};
	using std::cout;
	using std::endl;
	float result = 0.0;

	std::string number = "";
	std::vector<std::string> numbers;
	std::vector<char> symbols;
	for(char target: operation){
		int count = 0;	
		for(char c: numbers_available){
			if(c == target){
				count++;
			}	
		}
		if(count == 0){
			symbols.push_back(target);
			numbers.push_back(number);
			number = "";
		} else {
			number += target;
		}
	}
	numbers.push_back(number);
	
	if(numbers.size() == 1){
		return std::stof(numbers[0]);
	} else {
		return calculation(numbers, symbols); 
	}


	return 0.0; 
} 



void first_terms(char* complete,std::vector<std::string> &scopes, std::vector<char> &symbols){
	using std::cout;
	using std::endl;
	int symbol_count = 0;
	std::string scope = "";	

	while(*complete != '\0'){
		if(symbol_exists(*complete)){
			scopes.push_back(scope);
			scope = "";
			symbols.push_back(*complete);
		} else {
			std::string number(1, *complete);
			scope.append(number);
		}

		complete++;
			
	}
	scopes.push_back(scope);

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

			char* mystring = content - j;
                	char aux = *content;
			*content = '\0';
			//cout << mystring << " number" << endl;
			float num = std::stof(mystring);	
			numbers[*k] = num;
			*content = aux;
			
			*k = *k + 1;
			return content;
            	};
			
		if(*k == symbols){
			char* mystring = content;
			float num = std::stof(mystring);
			numbers[*k] = num;
			//cout << content << " number" << endl;
			*k = *k + 1;
			return content;
		}

            	content++;
            	j++;
        };
    	
	return content;
};


