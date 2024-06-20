#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#define LIMIT 100

int main()
{
  char word[LIMIT];
  List *list = init_history();
  while (1) {
    printf("Please input a word or a sentence or type (H) for History\n");
    printf(">");
    fgets(word, LIMIT, stdin);
    if (word[0] == 'H') {
      goto history; 
    }
    add_history(list, word);
    char **tokenizer = tokenize(word);
    print_tokens(tokenizer);
    free_tokens(tokenizer);
  }
 history:
  print_history(list);
  return 0;
}
