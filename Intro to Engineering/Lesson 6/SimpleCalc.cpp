#include <iostream>


float calc(float num1, float num2, char oper, float &error);


int main(){
	float num1;
	float num2;
	char oper;
	//this value is for the invalid output
	float error = 0;
	//all this is for interface
	std::cout<< "Welcome to this simple calcuator! \n\nPlease enter two rational numbers in decimal form and and an operator. \nAccepted operators are +, -, *, and /";
	std::cout<< "\n\nPlease enter your first number: ";
	//enter numbers and operator
	std::cin>> num1;
	std::fflush(stdin);
	//echo
	std::cout<< "You entered: " << num1;
	std::cout<< "\nPlease enter your second number: ";
	std::cin>> num2;
	std::fflush(stdin);
	//echo
	std::cout<< "You entered: " << num2;
	std::cout<< "\nNow, please enter an operand: ";
	std::cin>> oper;
	//echo
	std::cout<< "You entered: " << oper;
	float result = calc(num1, num2, oper, error);
	if(result != error){
		std::cout<< "\n\n\n" << num1 << ' ' << oper << ' ' << num2 << " = " << result;
		return 0;
	}
	return 1;
}


float calc(float num1, float num2, char oper, float &error){
	if(oper == '+'){
		//changes error so it will never be the return value
		error = num1 + num2 + 1;
		return num1 + num2;
	} else if(oper == '-'){
		error = num1 - num2 + 1;
		return num1 - num2;
	} else if(oper == 'x' || oper == '*'){
		error = num1 * num2 + 1;
		return num1 * num2;
	} else if(oper == '/'){
		error = (num1 + 0.0) / num2 + 1;
		return (num1 + 0.0) / num2;
	} else {
		std::cout<< "\n\n\nThat operation is invalid! Please try again";
		/*since error is set to something else if it was valid, 
		this makes it impossible for there to be an error message if it was valid */
		return error;
	}
}
