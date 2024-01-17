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

	//char entire_operation[] = input.c_str();
	//char* example = entire_operation;
	
	int count_symbol = frequency(example);	
	int count_number = count_symbol + 1;

	std::string operations = "";
	
	float* numbers = new float[count_number];
	cout << sizeof(*numbers) << endl;	
	int k = 0;

	while(*example != '\0'){
		if(k < count_number){
			example = separate_terms(example,&operations,numbers,count_symbol,&k);
		}

		example++;
	}
	
	float result = operate(numbers, operations);

	return result;
}



int main(){

	using std::cout;
	using std::endl;

	float result = testapp();
	cout << result << endl;

	return 0;
}
