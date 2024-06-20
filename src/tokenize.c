#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

char **tokenize(char* str)
{
  char size = count_tokens(str);
  // printf("word count:%d\n", size);
  char **tokenVT = malloc((size + 1) * sizeof(char*));
  for (char i = 0; i < size; i++) {
    char *str_start = token_start(str);
    short token_size = token_len(str_start);
    //printf("start of word: %c, size: %d\n", *str_start, token_size);
    char *token = copy_str(str_start, token_size);
    //printf("%s\n", token);
    tokenVT[i] = token;
    str += token_size + 1;
  }
  char *term_token = token_terminator(token_start(str));
  tokenVT[size] = term_token;
  return tokenVT;
}

void print_tokens(char **tokens)
{
  char count = 1;
  while (**tokens != '\0') {
    printf("Token %d: %s\n ",count, *tokens);
    *tokens++;
    count++;
  }
}

void free_tokens(char **tokens)
{
  while (**tokens != '\0') {
    free(*tokens);
  }
  free(tokens);
}
