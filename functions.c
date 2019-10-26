#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void print_list(struct node *n){
  if (n == NULL){
    printf("Printing empty list: []\n");
  }else{
    printf("Printing list: [  ");
    while (n -> next != NULL){
      printf("%d,  ", n->i);
      n = n->next;
    }
    printf("%d  ", n->i);
    printf("]\n");
  }
}

struct node * insert_front(struct node *seed, int i){
  struct node *newNode = (struct node *)malloc (sizeof(struct node));
  newNode -> i = i;
  newNode -> next = seed;
  return newNode;
}

struct node * free_list(struct node *n){
  if (n == NULL){
    free(n);
    printf("List freed. \n");
    return NULL;
  }else{
    printf("Freeing node: %d\n", n->i);
    struct node *save = n -> next;
    free(n);
    return free_list(save);
  }
}

struct node * remove_node(struct node *front, int data){
  if (front == NULL){
    printf("Empty list.\n");
    return front;
  }if (front->i == data){
    return front->next;
  }else{
    struct node *oneBefore = front;
    struct node *iterate = front -> next;
    while(iterate != NULL){
      if (iterate -> i == data){
        oneBefore -> next = iterate -> next;
        free(iterate);
        return front;
      }
      oneBefore = iterate;
      iterate = iterate -> next;
    }
    return front;
  }
}
