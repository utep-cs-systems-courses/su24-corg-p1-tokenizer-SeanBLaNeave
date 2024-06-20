#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#define LIMIT 100

int main()
{
  char word[LIMIT];
  printf("Please input a word or a sentence\n");
  printf(">");
  fgets(word, LIMIT, stdin);
  char **tokenizer = tokenize(word);
  print_tokens(tokenizer);
  free_tokens(tokenizer);
  //char size = count_tokens(&word[0]) + 1;
  //char *tokenizer = malloc(size * sizeof(char));
  //for (char i = 0; i < size; i++) {
  //printf("%c, ", tokenizer[i]);
  //}
  return 0;
}
