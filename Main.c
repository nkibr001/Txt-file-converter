#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#pragma warning(disable:4996)

int main(void)
{
	printf("Choose the conversion you'd like to perform:\n");
	printf("1: CSV -> TL5\n");
	printf("2: TL5 -> CSV\n");
	printf("3: CSV -> CSV\n");
	printf("4: TL5 -> TL5\n");

	int option;
	scanf("%d", &option);
	
	printf("Enter input file name:\n");
	char name[100];
	scanf("%s", name);
	printf("Enter output file name:\n");
	char name2[100];
	scanf("%s", name2);
	
	
	FILE* inFile = NULL;
	FILE* outFile = NULL;	

	inFile = fopen(name, "r");
	outFile = fopen(name2, "w");

	//make sure to put the address with double slash or else it won't understand haha
	if (inFile == NULL)
	{
		printf("Couldn't open input file.\n");
		return -1;
	}
	if (outFile == NULL)
	{
		printf("Couldn't open output file\n");
		return -1;
	}
	char c;
	char d;
	char e;
	char f;

	switch (option)
	{

	case 1:
		c = fgetc(inFile);
		//spaces shouldn't be in csv file since seperated by commas
		int x = 1;
		while (c != EOF)
		{
			if (c == ' ')
			{
				x = 0;
				break;
			}
			c = fgetc(inFile);
		}
		if (x == 0)
		{
			printf("This file isn't in the CSV format.\n");
		}


		else if (x == 1)
		{
			rewind(inFile);

			c = fgetc(inFile);
			char a = ' ';
			char b = '\n';
			char q = '|';
			int ctr = 0;
			int y = 0;
			while (c != EOF)
			{
				y = 0;
				ctr = 0;
				for (int i = 0; i < 5; i++)
				{
					if (c == ',')
					{
						for (int j = 0; j < 5 - i; j++)
						{
							fputc(a, outFile);
						}
						fputc(q, outFile);
						break;
					}
					else if (c == '\n')
					{
						for (int j = 0; j < 5 - i; j++)
						{
							fputc(a, outFile);
						}
						y = 1;
						fputc(b, outFile);

						break;
					}
					else if (c == EOF)
					{
						for (int j = 0; j < 5 - i; j++)
						{
							fputc(a, outFile);
						}
						break;
					}
					ctr++;
					fputc(c, outFile);
					c = fgetc(inFile);
				}
				if (ctr == 5 && c == '\n')
				{
					fputc(c,outFile);
					
					ctr = 0;
				}
				if (ctr == 5 && c == ',')
				{
					c = '|';
					fputc(c, outFile);
					ctr = 0;
				}
				c = fgetc(inFile);

				if (ctr == 5)
				{
					if (c != '\n' && c != ',')
					{
						while (c != '\n' && c != ',')
						{
							c = fgetc(inFile);
							if (c == ',')
							{
								c = '|';
								fputc(c, outFile);
								c = fgetc(inFile);
								break;
							}
							else if (c == '\n')
							{
								fputc(b, outFile);
								c = fgetc(inFile);
								break;

							}
							else if (c == EOF)
							{
								break;
							}
						}
					}

					else
					{
						if (c == ',')
						{
							c = '|';
							fputc(c, outFile);
							c = fgetc(inFile);
						}
						else if (c == '\n')
						{
							fputc(b, outFile);
							c = fgetc(inFile);
						}
						else
						{
							fputc(c, outFile);
							c = fgetc(inFile);
						}
					}
				}

			}
			printf("Conversion successful!\n");
		}
		fclose(inFile);
		fclose(outFile);

		break;


	case 2:
		d = fgetc(inFile);
		int z = 1;
		int ctr = 0;
		//every 6 chars should be a | seperating the values or a new line
		//should be 5 chars before the end of the file 
		while (d != EOF)
		{
			ctr++;
			if (ctr % 6 == 0)
			{
				if (d == '\n')
				{
					if (ctr % 6 != 0)
					{
						z = 0;
					}
					ctr = 0;
				}
				else if (d != '|')
				{
					z = 0;
					ctr = 0;
				}
				else
				{
					ctr = 0;
				}
			}
			if (d == '\n')
			{
				if (ctr % 6 != 0)
				{
					z = 0;
				}
				ctr = 0;
			}
			
			d = fgetc(inFile);
			
			if (d == EOF)
			{
				if (ctr != 5)
				{
					z = 0;
				}
			}

		}

		if (z == 0)
		{
			printf("This file isn't in the TL5 format.\n");
		}
			
		else if (z == 1)
		{
			rewind(inFile);
			d = fgetc(inFile);
			while (d != EOF)
			{
				if (d == ' ')
				{
					d = fgetc(inFile);

				}
				else if (d == '|')
				{
					d = ',';
					fputc(d, outFile);
					d = fgetc(inFile);
				}
				else
				{
					fputc(d, outFile);
					d = fgetc(inFile);
				}

			}
			printf("Conversion successful!\n");
		}
		fclose(inFile);
		fclose(outFile);

		break;

	case 3:
		e = fgetc(inFile);
		//spaces shouldn't be in csv file since seperated by commas
		int k = 1;
		while (e != EOF)
		{
			if (e == ' ')
			{
				k = 0;
				break;
			}
			e = fgetc(inFile);
		}
		if (k == 0)
		{
			printf("This file isn't in the CSV format.\n");
		}


		else if (k == 1)
		{
			rewind(inFile);
			e = fgetc(inFile);
			while (e != EOF)
			{
				fputc(e, outFile);
				e = fgetc(inFile);
			}
			printf("Conversion successful!\n");
		}
		fclose(inFile);
		fclose(outFile);
		break;

	case 4:
		f = fgetc(inFile);
		int m = 1;
		int ctr1 = 0;
		//every 6 chars should be a | seperating the values or a new line
		//should be 5 chars before the end of the file 
		while (f != EOF)
		{
			ctr1++;
			if (ctr1 % 6 == 0)
			{
				if (f == '\n')
				{
					if (ctr1 % 6 != 0)
					{
						m = 0;
					}
					ctr1 = 0;
				}
				else if (f != '|')
				{
					m = 0;
					ctr1 = 0;
				}
				else
				{
					ctr1 = 0;
				}
			}
			if (f == '\n')
			{
				if (ctr1 % 6 != 0)
				{
					m = 0;
				}
				ctr1 = 0;
			}

			f = fgetc(inFile);

			if (f == EOF)
			{
				if (ctr1 != 5)
				{
					m = 0;
				}
			}

		}

		if (m == 0)
		{
			printf("This file isn't in the TL5 format.\n");
		}

		else if (m == 1)
		{
			rewind(inFile);
			f = fgetc(inFile);
			while (f != EOF)
			{
				fputc(f, outFile);
				f = fgetc(inFile);
			}
			printf("Conversion successful!\n");
		}
		fclose(inFile);
		fclose(outFile);
		break;
	}
}