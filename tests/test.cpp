#include <iostream>
#include "controllers/mathfunctions.cpp"
#include <cstring>


float testapp(){
	using std::cout;
	using std::endl;
	using std::cin;

	std::string input; 
	cout << "Enter an operation: " << endl;
	cin >> input;
	
	char* example = new char[input.length() + 1];
	std::strcpy(example, input.c_str());

	std::vector<float> numbers;
	std::vector<char> symbols;
	std::vector<std::string> scopes;
	first_terms(example, scopes, symbols);
	int count_scopes = 1;
	std::vector<float> scope_results;
	float temp;
	for(std::string& scope: scopes){
		cout << "scope: " << count_scopes << "; "<< scope << endl;
		if(same_level_ops(scope)){
			temp = operate_scope(scope);
			scope_results.push_back(temp);
		}
		count_scopes++;
	}
	
	std::vector<std::string> strnumbers;
	for(float &number: scope_results){
		std::string strn = std::to_string(number);
		strnumbers.push_back(strn);
	}
	
	float result = calculation(strnumbers, symbols);
	cout << "final result: " << result << endl;
	return 0.0;
}

float potandsqrt(){
	//float result = sensible('potential',4,4);
	//cout << "result: " << result << endl;
	float result = 0.0;
	return result;
}

int main(){

	using std::cout;
	using std::endl;

	float result = testapp();
	return 0;
}
