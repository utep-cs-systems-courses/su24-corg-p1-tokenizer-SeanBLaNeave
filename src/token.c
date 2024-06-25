#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int space_char(char c)
{
  return (c == '\t' || c == ' ') ? 1 : 0;
}
 
int non_space_char(char c)
{
  return (c != '\t' && c != ' ') ? 1 : 0;
}

int count_tokens(char *str)
{
  int size = 0;
  while (*str != '\0') {
    str = token_start(str);
    if (*str != '\n') {
      size++;
    }
    str = token_terminator(str);
  }
  return size;
}

char *token_start(char *s)
{
  while (*s != '\0' && space_char(*s) == 1){
    *s++;
  }
  return s;
}

char *copy_str(char *inStr, short len)
{
  char *token = malloc((len + 1) * sizeof(char));
  for (char i = 0; i < len; i++) {
    char c = *inStr;
    token[i] = c;
    *inStr++;
  }
  token[len] = '\0';
  return token;
}

char *token_terminator(char *token)
{
  while (*token != '\0' && non_space_char(*token) == 1){
    *token++;
  }
  return token;
}
