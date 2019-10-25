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
  printf("\n");

  //removing a the indexes indicated by the number after finding
  struct node *finding0 = (struct node *)malloc (sizeof(struct node));
  finding0 = NULL;
  finding0 = insert_front(finding0, 0);
  printf("Initial list:\n");
  print_list(finding0);
  printf("Testing remove, empty list expected\n");
  finding0 = remove_node(finding0, 0);
  print_list(finding0);
  printf("\n");

  finding0 = insert_front(finding0, 0);
  finding0 = insert_front(finding0, 1);
  printf("Initial list:\n");
  print_list(finding0);
  printf("Testing remove, expecting: [1]\n");
  finding0 = remove_node(finding0, 0);
  print_list(finding0);
  free_list(finding0);
  printf("\n");

  struct node *finding1 = (struct node *)malloc (sizeof(struct node));
  finding1 = NULL;
  finding1 = insert_front(finding1, 0);
  finding1 = insert_front(finding1, 1);
  printf("Initial list:\n");
  print_list(finding1);
  printf("Testing remove, expected: [1]\n");
  finding1 = remove_node(finding1, 0);
  print_list(finding1);
  free_list(finding1);
  printf("\n");

  struct node *finding2 = (struct node *)malloc (sizeof(struct node));
  finding2 = NULL;
  finding2 = insert_front(finding2, 0);
  finding2 = insert_front(finding2, 1);
  finding2 = insert_front(finding2, 2);
  printf("Initial list:\n");
  print_list(finding2);
  printf("Testing remove, expected: [2, 1]\n");
  finding2 = remove_node(finding2, 0);
  print_list(finding2);
  free_list(finding2);
  return 0;
}
