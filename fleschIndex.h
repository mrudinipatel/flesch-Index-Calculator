#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 Student Name: Mrudini Patel
 Student ID: 1141712
 Due Date: February 26, 2021
 Course: CIS*2500
 I have exclusive control over this submission via my password.
 By including this header comment, I certify that:
 1) I have read and understood the policy on academic integrity.
 2) I have completed Moodle's module on academic integrity.
 3) I have achieved at least 80% on the academic integrity quiz
 I assert that this work is my own. I have appropriate acknowledged
 any and all material that I have used, be it directly quoted or
 paraphrased. Furthermore, I certify that this assignment was written
 by me in its entirety.
*/

/* COMPILING TAGS
 * Please compile using a makefile with the following flags:
 * -std=c99 -Wall -lm
 * NOTE: the -lm tag has been added by me since the math.h library
 * requires this tag for the code to compile correctly.
*/

char * readFile ( char * filename);
int numberOfWords (char * str);
int numberOfSentences (char * str);
int numberOfSyllables (char * str);
int calculateFleschIndex(int syllables, int words, int sentences);
void outputFormattedFleschScores(int syllables, int words, int fleshIndex, int sentenceCount);
