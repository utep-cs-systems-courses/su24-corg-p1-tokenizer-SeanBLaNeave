#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int space_char(char c)
{
  return (c == '\t' || c == ' ') ? 1 : 0;
}
 
int non_space_char(char c)
{
  return (c != '\t' && c != ' ' && c != '\n') ? 1 : 0;
}

int count_tokens(char *str)
{
  char size = 0, inWord = 0;
  while (*str != '\0') {
    if (non_space_char(*str) == 1 && inWord == 0) {
      inWord = 1;
      size++;
    }else if (space_char(*str) == 1){
      inWord = 0;
    }
    *str++;
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

short token_len(char *str)
{
  short size = 0;
  while (non_space_char(*str) == 1){
    size++;
    *str++;
  }
  return size;
}

char *copy_str(char *inStr, short len)
{
  char *token = (char*) malloc((len + 1) * sizeof(char));
  for (char i = 0; i < len; i++) {
    char c = *inStr;
    token[i] = c;
    *inStr++;
  }
  token[len] = '\0';
  return token;
}

char *token_terminator(char *toekn){
  char *term = (char*) malloc(1 * sizeof(char));
  term[1] = '\0';
  return term;
}
