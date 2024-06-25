#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

char **tokenize(char* str)
{
  int size = count_tokens(str);
  // printf("word count:%d\n", size);
  char **tokenVT = malloc((size + 1) * sizeof(char*));
  for (char i = 0; i < size; i++) {
    char *str_start = token_start(str);
    char *token_end = token_terminator(str_start);
    //printf("start of word: %c, size: %d\n", *str_start, token_size);
    char *token = copy_str(str_start, token_end - str_start);
    //printf("%s\n", token);
    tokenVT[i] = token;
    str = token_end;
  }
  char *term_token = malloc(1 * sizeof(char));
  term_token[0] = '\0';
  tokenVT[size] = term_token;
  return tokenVT;
}

void print_tokens(char **tokens)
{
  char count = 1;
  printf("\n");
  while (**tokens != '\0') {
    printf("Token %d: %s\n",count, *tokens);
    *tokens++;
    count++;
  }
  printf("\n");
}

void free_tokens(char **tokens)
{
  while (**tokens != '\0') {
    free(*tokens);
  }
  free(tokens);
}
