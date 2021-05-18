#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fleschIndex.h"

char * readFile (char * filename){
  int size;
  FILE * file;
  file = fopen(filename,"r"); // opening the .txt from command line and reading it here.

  char * fileInput = NULL;

  if (file == NULL){
    printf("Error, this file does not exist or cannot be opened.\n"); // error message to handle NULL values.
    exit(0); // this exits the rest of the functions if file cannot be opened so it doesn't give a seg fault error.
  }
  else {
    /* I am using fseek and ftell to scan the file using the pointer's positon
     * and storing its size in the 'size' variable, and then resetting the 
     * pointer back to the start of the file.
    */
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    /* I am allocating memory using the 'size' from above. Using calloc over malloc because calloc
     * always initializes the memory block to NULL. If I use malloc in this case, 
     * I will encounter memory errors. Then I use fread to scan in the file contents into fileInput
     * and return fileInput back to main.
    */
    fileInput = calloc(1, sizeof(char) * size + 1); 
    
    fread(fileInput, size, 1, file);
  }
  fclose(file);
  
  return fileInput;
}

int numberOfSyllables (char * str){
  int syllableCount = 0, counter = 0, total = 0, i = 0;
  /* since I will be using strtok in this function, and strtok modifies the original string,
   * I will use 'buffer' and strcpy the string into buffer and strtok buffer instead. I have tokenized
   * " \n" because this way each word will be seperated.
  */
  char buffer[strlen(str) + 1];
  char * token;

  strcpy(buffer, str);

  token= strtok(buffer, " \n");

  /* This while loop iterates until token hits a null character. It then goes through each tokenized word
   * and checks if there is a vowel surrounded by constanants, if so, syllableCount increments. If there is an 'e'
   * at the end word, then the syllableCount will decrease (to remove the previous increase). If by these 2 rules, the
   * syllableCount is 0, then 'counter' will increment and will only be added to the total number of syllables if 
   * the counter is a 1 because words like 'you' and 'readymade' will otherwise be added twice. Then, I reset the counter
   * and syllableCount and return total syllables back to main.
  */
  while (token != NULL){
    for (i = 0; i < strlen(token); i++){
      if ((token[i] == 'a') || (token[i] == 'e') || (token[i] == 'i') || (token[i] == 'o') || (token[i] == 'u') || (token[i] == 'y') || (token[i] == 'A') || (token[i] == 'E') || (token[i] == 'I') || (token[i] == 'O') || (token[i] == 'U') || (token[i] == 'Y')){
        if ((token[i+1] != 'a') && (token[i+1] != 'e') && (token[i+1] != 'i') && (token[i+1] != 'o') && (token[i+1] != 'u') && (token[i+1] != 'y') && (token[i+1] != 'A') && (token[i+1] != 'E') && (token[i+1] != 'I') && (token[i+1] != 'O') && (token[i+1] != 'U') && (token[i+1] != 'Y')){
          syllableCount++;
        }
      }

      if (token[i] == 'e'){
        if ((token[i+1] == ' ') || (token[i+1] == '\n') || (token[i+1] == '\0') || (token[i+1] == '.') || (token[i+1] == '!') || (token[i+1] == '?') || (token[i+1] == ':') || (token[i+1] == ';')){
          syllableCount--;
        }
      }
    }
    if (syllableCount == 0){
      counter++;
    }

    if (counter == 1){
      total += counter;
    }
    else {
      total += syllableCount;
    }

    syllableCount = 0;
    counter = 0;
    
    token= strtok(NULL, " \n");
  }

  return total;
}

int numberOfSentences (char * str){
  int sentenceCount = 0;
  
  /* This for loop will iterate through str and find a appropriate punctuation. Note: sentenceCount is
   * incremented if and only if the next character after the punctuation is not another punctuation.
   * Then, I return the sentenceCount back to main.
  */
  for(int i = 0; str[i] != '\0'; i++){
    if((str[i] == '.') || (str[i] == '?') || (str[i] == '!') || (str[i] == ':') || (str[i] == ';')){
      if ((str[i+1] != '.') && (str[i+1] != '?') && (str[i+1] != '!') && (str[i+1] != ':') && (str[i+1] != ';')){
        sentenceCount++;
      }
    }
  }

  return sentenceCount;
}

int numberOfWords (char * str){
  int wordCount = 0;
  char * token;

  /* Using strtok, I tokenize each word and increment wordCount
   * until the token hits NULL. I then return wordCount back to main.
  */

  token = strtok(str, " \n");

  while (token != NULL){
    wordCount++;
    token = strtok(NULL, " \n");
  }

  return wordCount;
}

int calculateFleschIndex(int syllables, int words, int sentences){
  float index, roundedIndex;

  /* I am using the given forumla to calculate the flesch index. I am then using the
   * round function from the math.h library to round up the index to an integer.
   * I then return that roundedIndex back to main.
  */

  index = 206.835 - 84.6 * (syllables / words) - 1.015 * (words / sentences);
  roundedIndex = round(index);

  //printf("\nIndex: %f %f\n", index, roundedIndex); // just a printf to test if the rounding works.

  return roundedIndex;
}

void outputFormattedFleschScores(int syllables, int words, int fleshIndex, int sentenceCount){
  /* Here I am just simply printing out the syllables, words, fleschIndex, and sentenceCount
   * that were returned to main and passed into this function. I am printing them according to the 
   * given format.
  */
  printf("Flesch Index = %d\n", fleshIndex);
  printf("Syllable Count = %d\n", syllables);
  printf("Word Count = %d\n", words);
  printf("Sentence Count = %d\n", sentenceCount);
}
