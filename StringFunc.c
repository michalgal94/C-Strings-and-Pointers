/*
 * StringFunc.c
 *
 *  Created on: 2 Dec 2018
 *      Author: michal
 */

#include "Stringfunc.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>


void initString(char* str,int size)
{
	getchar();
	printf("Please enter a sentence:\n");
	*str = '\0';
	if(fgets(str,size,stdin) == NULL)
		return;
	str[strcspn(str, "\n")] = '\0';

}


void printString(const char* str)
{


	printf("%s", str);


}

int countWords(const char* str)
{

	int counter =0;
	int result =0;

	while(*str != '\0') {

		if (!counter && isLetter(*str)) {
			counter =1;

		}

		if( counter && !isLetter(*str))
		{
			counter=0;
			result++;

		}

		str++;

	}

	return counter + result;

}

void longestInCapital(char* str)
{


	char* special = SPECIAL_CHARS;
	char* longestc = NULL;


	int i, counter=0 , maxlength =0 , longestIndex;
	for(i = 0; i <= strlen(str); i++)
	{
		if(! strchr(special, str[i]))
			counter++;
		else {
			if(counter> maxlength)
			{
				maxlength = counter;
				longestc = &str[i-counter];
				longestIndex = i-counter;
			}
			counter=0;
		}



	}

	for (i=0; i<maxlength ; i++)
		str[i+longestIndex] = toupper(longestc[i]);

}




void revertWords(char* str)
{

	char* start;
	char* end;
	int revert =1;



	while(*str !='\0')
	{
		if(revert && isSpecial(*str))
		{
			start =str ;
			revert=0;
		}

		if((!revert && !isSpecial(*str)) || (!revert && *(str+1) == '\0'))
		{
			if((!revert && !isSpecial(*str)))
				end =str -1;
			else
				end = str;
			revert =1;
			while(start <end)
				swap(start++,end--);

		}

		if(!isSpecial(*str))
			*str = '*';

		str++;
	}

}

int isLetter(char c)
{

	return ((c >= 'A' && c <= 'Z') ||  (c >= 'a' && c <= 'z')) ;
}



void swap(char* a, char* b)
{

	char temp =*a;
	*a = *b;
	*b=temp;

}


int isSpecial(char c)
{
	return strchr(SPECIAL_CHARS,c) == NULL;

}

void eraseCharsFromString(char *str,const char *symbols)
{

	//c=str
	char* c;
	for(c = str ; *c != '\0' ; c++,str++)
	{
		while(strchr(symbols,*c) != NULL && *c != '\0')
			c++;
		*str = *c;
	}
	*str = '\0';
}


int isPalindrome(const char* str)
{

	const char *start, *end;
	start =str;
	end = strchr(str, '\0');
	while(end>start)
	{
		while(!isLetter(*start))
			start++;
		while(!isLetter(*end))
			end--;
		if((tolower(*start)) != (tolower(*end)))
			return 0;

		start++;
		end--;
	}

	return 1;

}


