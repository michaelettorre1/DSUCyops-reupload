#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Max line size
#define MAXLINE 500

// Assignment: A3 - File IO / Strings
//    Student: Michael Ettorre
//       Term: SP2020

// Student Functions
int getShift();
void getString(char str[]);
void encryptString(char str[], int shift);
void decryptString(char str[], int shift);
void encryptFile(int shift);
void decryptFile(int shift);
int getMenuOption(int shift);

// Included helper functions
void cleanInputStream();

int main(int argv, char * argc[])
{
  // main should store the shift value and individual strings to be manipulated
	int Shift = 3;
	char Strn[500];
  // menu choices should be evaluated and executed here

int option;
do {
	option = getMenuOption(Shift);
	switch (option)
	{
		case 5: Shift = getShift();
			break;
		case 1: getString(Strn);
				 encryptString(Strn, Shift);
					printf("%s\n", Strn);
			break;
		case 2: getString(Strn);
			 	decryptString(Strn, Shift);
					printf("%s\n", Strn);
			break;
		case 3: encryptFile (Shift);
			break;
		case 4: decryptFile (Shift);
			break;
		case 6: return 0;
	}
	}while ( option > 0 || option < 7 );
  // all file IO should take place in encryptFile or decryptFile
  return 0;
}

// Removes new line left over from scanning an integer
void cleanInputStream()
{
  char c = getchar();
  while (c != '\n')
    c = getchar();
}

int getShift()
{
  // Returns a user selected shift amount from 1 to 10
	int Shift;
	do
	{
	printf("Give me a shift amount 1-10: ");
	scanf("%d", &Shift);
		if ( Shift > 10 || Shift < 1)
			{
				printf("Number is outside the zone\n");
			}

	} while ( Shift > 10 || Shift < 1);

	return Shift;
  // Should validate that shift is >= 1 and <= 10
}

void encryptString(char str[], int shift)
{
  // Encrypt a provided string by subtracting the shift value here
	int len, k;
	len = strlen (str) - 1;
		for ( k = 0 ; k < len ; k++)
			{
				str[k] = str[k] - shift;
			}

}

void decryptString(char str[], int shift)
{
  // Decrypt a provided string by adding the shift value here
	int len, k;
	len = strlen (str) - 1;
		for ( k = 0 ; k < len ; k++)
			{
				str[k] = str[k] + shift;
			}
}

int getMenuOption(int shift)
{
	int Option;
  // Print a menu and get a valid menu option here
  // Menu options and numbers must match example
  // in README.md
printf("------------------------\n");
printf("| 1) Encrypt a string  |\n");
printf("| 2) Decrypt a string  |\n");
printf("| 3) Encrypt a file    |\n");
printf("| 4) Decrypt a file    |\n");
printf("| 5) Change shift (03) |\n");
printf("| 6) Exit application  |\n");
printf("------------------------\n ");
printf("Choose Options: ");
scanf("%d", &Option);
cleanInputStream();
return Option;
}

void encryptFile(int shift)
{
	char strn[100];
	FILE* fp;
	FILE* ofp;
	printf("Input a file name: ");
	scanf("%s", strn);
  // Encrypt the contents of that file and output to a file called "out.txt"
	 fp = fopen(strn, "r");
	if (fp == NULL)
		{
			printf("Error, could not open file");
			exit(1);
		}
			ofp = fopen("out.txt" , "w");
			fgets(strn, 100, fp);			while ( !feof (fp))
				{
					encryptString(strn, shift);
					fprintf(ofp, "%s", strn);
					fgets(strn, 100, fp);
				}

  // Each line of the file should be encrypted using encryptString
}

void decryptFile(int shift)
{
	char strn[100];
	FILE* fp;
	FILE* ofp;
	printf("Input a file name: ");
	scanf("%s", strn);
	fp = fopen(strn,  "r");
	if (fp == NULL)
		{
			printf("Error, could no open file");
			exit(1);
		}
			ofp = fopen("out.txt" , "w");
			fgets(strn, 100, fp);
			while( !feof (fp))
				{
					decryptString(strn, shift);
					fprintf(ofp, "%s", strn);
					fgets(strn, 100, fp);
				}

  // Get a filename from the user on stdin
  // Decrypt the contents of that file and output to a file called "out.txt"
  // Each line of the file should be decrypted using decryptString
}

void getString(char str[])
{
  // Prompt the user to input a string and store that string in str
	printf("Input a string: ");
	fgets(str, 500, stdin);
}
