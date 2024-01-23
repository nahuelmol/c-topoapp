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
			case '-':
			{
				tresult = tresult - floatnumbers[k];
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
			if((target != '(') && (target != ')')){
				symbols.push_back(target);
				numbers.push_back(number);	
				number = "";
			}
		
		} else {
			number += target;
		}
	}
	numbers.push_back(number);
	
	for(std::string &numbs: numbers){
		cout << "numb: " << numbs << endl;
	}

	for(char c: symbols){
		cout << "symbs" << c << endl;
	}
	
	if(numbers.size() == 1){
		return std::stof(numbers[0]);
	} else {
		return calculation(numbers, symbols); 
	}

	return 0.0; 
} 


void separate(std::string &complete,std::vector<std::string> &scopes,std::vector<char> &symbols){
	using std::cout;
	using std::endl;
	int symbol_count;
	char numbers_available[] = {'1','2','3','4','5','6','7','8','9','0','.'};

	std::string scope= "";
	bool brackets = false;
	std::string parenthesis = "";
	int interns = 0;
	int charactercount = 0;
	for(char c: complete){
		if(brackets){
			if(c==')'){
				if(interns == 0){
					brackets = false;
					scopes.push_back(scope);
					scope = "";
				} else {
					interns--;
				}
				
			} else if(c == '('){
				interns++;
			} else {
				std::string number(1,c);
				scope.append(number);
			}

		} else if(symbol_exists(c)){
			if(scope != ""){
				scopes.push_back(scope);
				scope = "";
			}
			symbols.push_back(c);
		} else if(c == '('){
			brackets = true;
		} else {
			int cnum = 0;
			for(char numa: numbers_available){
				if(c == numa){
					cnum++;	
				}
			}
			if((cnum == 0) && (complete[charactercount+1] == '(')){
				scopes.push_back(scope);
				symbols.push_back(c);
				scope = "";
			} else {
				std::string number(1, c);
				scope.append(number);
			}
		}
		charactercount++;
	}
	if(scope != ""){
		scopes.push_back(scope);
	}
}
