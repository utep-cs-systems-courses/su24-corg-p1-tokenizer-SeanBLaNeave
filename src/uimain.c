#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#define LIMIT 100

int main()
{
  List *list = init_history();
  char word[LIMIT];
  int id;
 ui:
  while (1) {
    printf("Please input a word or a sentence or type (H) for History\n");
    printf(">");
    fgets(word, LIMIT, stdin);
    if (word[0] == '\n')
      fgets(word, LIMIT, stdin);
    if (word[0] == 'H')
      goto history; 
    add_history(list, word);
    char **tokenizer = tokenize(word);
    print_tokens(tokenizer);
    free_tokens(tokenizer);
  }
 history:
  print_history(list);
  printf("please select an id\n");
  while (1) {
    id = atoi(getchar());
    char *word_id = get_history(list, id);
    if (word_id[0] != '\0') {
      char **tokenizer = tokenize(word_id);
      print_tokens(tokenizer);
      free_tokens(tokenizer);
      goto ui;
    }
  }
  return 0;
}
