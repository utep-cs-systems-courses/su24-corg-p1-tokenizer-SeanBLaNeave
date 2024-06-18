#include <stdio.h>
#include "tokenizer.h"
#define LIMIT 100

int main()
{
  char word[LIMIT];
  printf("Please input a word or a sentence\n");
  printf(">");
  fgets(word, LIMIT, stdin);
  printf("%s", word);
  printf("%d\n", space_char(word[0]));
  return 0;
}
