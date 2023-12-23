#include "HelperFn.h"

bool IsValue (string input)
{
	int dotCount = 0;
	for (int i = 0; i < input.length(); i++) {

		// check if the first character isn't a '.' or a letter
		if(i == 0){
			if ((input[i] == 46) || (input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122)) {
				return false;
				}
		}

		// chech if any character in the string is a '-' sign or a letter otherwise than the first character
		if (i > 0) {
			if ((input[i] == 45) || (input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122)) {
				return false;
			}
			else {
				if (input[i] == 46) {
					dotCount++;
				}
				if (dotCount > 1) {
					return false;
				}
			}

		}
		// check if there is a special character 
		if ((input[i] >= 0 && input[i] <= 44) || (input[i] >= 58 && input[i] <= 64) || (input[i] >= 91 && input[i] <= 96) || (input[i] >= 123 && input[i] <= 127) || (input[i] == 47)) {
			return false;
		}
		// check if last character is a dot
		if ((i == input.length() - 1) && (input[i] == 46)) {
			return true;
		}

		if ((input[i] >= 48 && input[i] <= 57)) {

			if (i == input.length() - 1) {
				return true;
			}
		}
		
	}
}




bool IsVariable (string input)
{
	for (int i = 0; i<input.length(); i++){

		// check first character in the string is not a number
		if (i == 0) {
			if (input[i] >= 48 && input[i] <= 57) {
				return false;
			}
		}

		if ((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122) || (input[i] >= 48 && input[i] <= 57) || (input[i] == 95) ) {
			if (i == input.length() - 1) {
				return true;
			}
		}
		else {
			return false;
		}
	}
}




OpType ValueOrVariable (string input)
{
	if (IsValue(input))  {
		return VALUE_OP;
	}
	else if (IsVariable(input)) {
		return VARIABLE_OP;
	}
	else {
		return INVALID_OP;
	}
}
