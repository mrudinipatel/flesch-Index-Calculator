#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fleschIndex.h"

int main(int argc, char * argv[]){
  char * filename = argv[1];
  char * str;
  int words, sentences, syllables, fleschIndex;

  /* Here I am calling all my functions and storing their return values
   * into the variables declared above.
  */
  str = readFile(filename);
  //printf("%s", str); //just a printf to test if the file stores and returns correctly.

  syllables = numberOfSyllables(str);

  sentences = numberOfSentences(str);

  words = numberOfWords(str);

  fleschIndex = calculateFleschIndex(syllables, words, sentences);

  outputFormattedFleschScores(syllables, words, fleschIndex, sentences);

  /*
   * I am freeing 'str' because it contains the returned string (file contents) from the readFile
   * function. I cannot free this in the function since I am returning the string to main, I must
   * free it here to prevent memory leaks. 
  */
  free(str);

  return 0;
}
