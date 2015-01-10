#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

#include "processOpts.h"

void processOpts(int* argc, char* argv[], int* add, int* sub, int* mult, int* div, int* numOpts)
{
	char* progName = argv[0];
	if (*argc == 1)
	{
		fprintf(stderr, "Missing values to math.");
		usage(progName, stderr);
	}
	struct option longopts[] =
	{
		{ "add", no_argument, NULL, 'a' },
		{ "subtract", no_argument, NULL, 's' },
		{ "multiply", no_argument, NULL, 'm' },
		{ "divide", no_argument, NULL, 'd' },
		{ "usage", no_argument, NULL, 'u' },
		{ NULL, 0, NULL, 0 }
	};
	
	char op;
	while((op = getopt_long(*argc, argv, "asmd", longopts, NULL)) != -1)
	{
		switch(op)
		{
			case 'a':
				*add = 1;
				break;
			case 's':
				*sub = 1;
				break;
			case 'm':
				*mult = 1;
				break;
			case 'd':
				*div = 1;
				break;
			case 'u':
				usage(progName, stdout);
				break;
			case '?':
				usage(progName, stderr);
				break;
			default:
				fprintf(stderr, "Fell in default.\n");
				break;
		}

	}
	*argc -= optind;
	*numOpts += optind;
}

void usage(char* progName, FILE *file)
{
	fprintf(file, "Usage: %s [-a] [-s] [-m] [-d] [numbers...]\n", progName);
	fprintf(file, "	--usage:	print this info and exit\n");
	fprintf(file, "	-a --add:	add numbers from stdin and print sum\n");
	fprintf(file, "	-s --subtract:	subtract numbers from stdin and print difference\n");
	fprintf(file, "	-m --multiply:	multiply numbers from stdin and print product\n");
	fprintf(file, "	-d --divide:	divide numbers from stdin and print quotient\n");
	if (file == stdout)
		exit(0);
	else
		exit(1); 
}
