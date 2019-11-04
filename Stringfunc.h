/*
 * StringFunc.h
 *
 *  Created on: 2 Dec 2018
 *      Author: michal
 */

#ifndef STRINGFUNC_H_
#define STRINGFUNC_H_

#define SPECIAL_CHARS ":,?- "

void initString(char* str,int size);
void printString(const char* str);
int countWords(const char* str);
void longestInCapital(char* str);
void revertWords(char* str);
int isLetter(char c);
void swap(char* a, char* b);
int isSpecial(char c);
void eraseCharsFromString(char* str,const char* symbols);
int isPalindrome(const char* str);


#endif /* STRINGFUNC_H_ */
