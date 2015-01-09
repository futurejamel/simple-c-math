#include <stdlib.h>
#include <stdio.h>

#include "math.h"

int main(int argc, char* argv[])
{
	int add = 0;
	int sub = 0;
	int mult = 0;
	int div = 0;
	
	processOpts
	(
		&argc,
		argv,
		&add,
		&sub,
		&mult,
		&div
	);
	argv += 1;
	if (add == 1)
		printf("%f", sum(argc, argv));
	else if (sub == 1)
		printf("%f", difference(argc, argv));
	else if (mult == 1)
		printf("%f", product(argc, argv));
	else if (div == 1)
		printf("%f", quotient (argc, argv));
	return 0;
}


double sum (int numValues, char* values[])
{
	double sum = 0.0;
	int index;
	for (index = 0; index < numValues; index++)
	{
		sum += atof(values[index]);
	}
	return sum;
}

double difference (int numValues, char* values[])
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

double product (int numValues, char* values[])
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

double quotient (int numValues, char* values[])
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
