#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
  struct node *seed = (struct node *)malloc (sizeof(struct node)); //This is just an empty list
  seed = NULL;
  printf("Expecting: []\tResult: ");
  print_list(seed);
  printf("\n");

  printf("Fill list\n");
  int i = 1;
  for(;i<11;i++){
    seed = insert_front(seed, i);
  }
  printf("Expecting: [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]\tResult: ");
  print_list(seed);

  printf("Freeing list\n");
  seed = free_list(seed);
  print_list(seed);

  return 0;
}
