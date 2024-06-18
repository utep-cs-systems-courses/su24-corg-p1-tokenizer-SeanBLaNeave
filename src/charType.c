#include "tokenizer.h"

int space_char(char c)
{
  return (c == '\t' || c == ' ') ? 1 : 0;
}
 
int non_space_char(char c)
{
  return (c != '\t' && c != ' ') ? 1 : 0;
}
