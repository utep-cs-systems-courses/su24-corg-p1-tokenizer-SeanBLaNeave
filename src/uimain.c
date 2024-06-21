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
  char input;
  char **tokenizer;
 ui:
  printf("type (S) to input or type (H) for history or type (C) to clear histroy or type (Q) to quit\n");
  while ((input = getchar()) != EOF) {
    if (input == 'S') {
      goto tokenizer;
    } else if (input == 'H') {
      goto history;
    } else if (input == 'Q') {
      goto quit;
    } else if (input == 'C') {
      goto clear;
    }
  }
  if (input == EOF)
    goto quit;
 tokenizer:
  printf("\ninput a word or sentians\n");
  printf(">");
  fgets(word, LIMIT - 2, stdin);
  if (word[0] == '\n' && word[1] == '\0')
    fgets(word, LIMIT - 2, stdin);
  printf("%s", word);
  add_history(list, word);
  tokenizer = tokenize(word);
  print_tokens(tokenizer);
  free_tokens(tokenizer);
  goto ui;
 history:
  print_history(list);
  printf("\n");
  printf("please select an id or type 0 to go back\n");
  while (1) {
    printf("!");
    scanf("%d", &id);
    if (id == 0){
      printf("\n");
      goto ui;
    }
    char *word_id = get_history(list, id);
    if (word_id != NULL) {
      add_history(list, word_id);
      tokenizer = tokenize(word_id);
      print_tokens(tokenizer);
      free_tokens(tokenizer);
      goto ui;
    }
  }
 clear:
  free_history(list);
  list = init_history();
  printf("\nthe data has been cleared\n");
  goto ui;
 quit:
  free_history(list);
  return 0;
}
