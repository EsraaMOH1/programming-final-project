#include "HelperFn.h"

bool IsValue (string input)
{
	// checks if the input string is a double value
	// return true if it's double value, false otherwise

	// Double values can be: 12.5, -12.5, -23, -23. , -23.0 …etc.

	//DONE: complete this function
	bool DotFound = false;

	if ('.' == input[0] || (('0' > input[0] || '9' < input[0]) && '-' != input[0]))
	{
		return false;
	}

	for (unsigned short i = 1; input[i] != '\0'; i++)
	{
		if (('0' > input[i] || '9' < input[i]) && '.' != input[i])
		{
			return false;
		}
		if ('.' == input[i] && DotFound)
		{
			return false;
		}
		if ('.' == input[i] && !DotFound)
		{
			DotFound = true;
		}
	}

	return true;
}

bool IsVariable (string input)
{
	// checks if the input string is a variable name
	// return true if it can be a variable name, false otherwise

	// Variable names must start with an alphabetic letter (small or capital) or an underscore (_). 
	// After the first initial letter, variable names can contain letters, numbers and underscores.  
	// No spaces or special characters; however, are allowed.

	//DONE: complete this function
	if (('a' > input[0] || 'z' < input[0]) && ('A' > input[0] || 'Z' < input[0]) && '_' != input[0])
	{
		return false;
	}
	for (unsigned short i = 1; input[i] != '\0'; i++)
	{
		if (('a' > input[i] || 'z' < input[i]) && ('A' > input[i] || 'Z' < input[i]) && ('0' > input[i] || '9' < input[i]) && '_' != input[i])
		{
			return false;
		}
	}

	return true;
}

OpType ValueOrVariable (string input)
{
	// checks if the input string is a double value or a variable name
	// chand returns enum "OpType" (the enum is declared in the .h)

	//TODO: complete this function
	if (IsValue(input))
	{
			return VALUE_OP;
	}
	else if (IsVariable(input))
	{
		return VARIABLE_OP;
	}
	else
	{
		return INVALID_OP;
	}
}

double StringToDouble (string input)
{
	//Defining variables
	double Value = 0;
	bool IsNegative = false;

	//Check for the negative sign
	if (input[0] == '-')
	{
		IsNegative = true;
	}

	//Add the pre-point numbers to the value
	unsigned int i = IsNegative;
	for (; '.' != input[i] && '\0' != input[i]; ++i)
	{
		Value *= 10;
		Value += input[i] - '0';
	}

	//Skipping the point for comming for-loop
	if ('.' == input[i])
	{
		++i;
	}

	//Add the post-point numbers to the value
	for (double divider = 10; '\0' != input[i]; ++i)
	{
		Value += (input[i] - '0') / divider;
		divider *= 10;
	}

	//Make the value negative if needed
	if (IsNegative)
	{
		Value *= (-1);
	}

	//Return value
	return Value;
}