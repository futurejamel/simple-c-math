#include <stdlib.h>
#include <stdio.h>

#include "math.h"

int main(int argc, char* argv[])
{
	int addFlag = 0;
	int subFlag = 0;
	int multFlag = 0;
	int divFlag = 0;
	int numOpts = 0;	
	processOpts
	(
		&argc,
		argv,
		&addFlag,
		&subFlag,
		&multFlag,
		&divFlag,
		&numOpts
	);
	argv += numOpts;
	if (addFlag == 1)
		printf("%-12s %.3f\n", "Sum:", add(argc, argv));
	if (subFlag == 1)
		printf("%-12s %.3f\n", "Difference:", sub(argc, argv));
	if (multFlag == 1)
		printf("%-12s %.3f\n", "Product:", mult(argc, argv));
	if (divFlag == 1)
		printf("%-12s %.3f\n", "Quotient:", divide(argc, argv));
	return 0;
}


double add (int numValues, char* values[])
{
	double sum = 0.0;
	int index;
	for (index = 0; index < numValues; index++)
	{
		sum += atof(values[index]);
	}
	return sum;
}

double sub (int numValues, char* values[])
{
	double diff = 0.0;
	if (numValues > 0)
	{
		diff = atof(values[0]);
		int index;
		for (index = 1; index < numValues; index++)
		{
			diff -= atof(values[index]);
		}
	}
	return diff;
}

double mult (int numValues, char* values[])
{
	double prod = 0.0;
	if (numValues > 0)
	{
		prod = atof(values[0]);
		int index;
		for (index = 1; index < numValues; index++)
		{
			prod *= atof(values[index]);
		}
	}
	return prod;
}

double divide (int numValues, char* values[])
{
	double quot = 0.0;
	if (numValues > 0)
	{
		quot = atof(values[0]);
		int index;
		for (index = 1; index < numValues; index++)
		{
			quot /= atof(values[index]);
		}
	}
	return quot;
}
