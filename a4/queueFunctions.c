#include "a4header.h"



void dequeue (tweet ** head, tweet ** tail){
  int counter = 0;
  int end = 1;
  tweet *local;
  local = *head;

  while(end == 1){
    if(local->next != (*tail)){
      local = local->next;
      counter++;
    }
    else{
      (*tail)->id = local->id;
      strcpy((*tail)->user,local->user);
      strcpy((*tail)->text,local->text);
      free(local);
      end = 0;
    }
  }
  end = 1;
  tweet *local2;
  local2 = *head;

  for(int i = 0; i < counter-1;i++){
    local2 = local2->next;
  }
  local2->next = *tail;

}

void enqueue (tweet ** head, tweet ** tail, tweet * node){
  tweet *local;
  local = malloc(sizeof(tweet));

  local->id = node->id;
  strcpy(local->user,node->user);
  strcpy(local->text,node->text);
  local->next = NULL;



  (*tail)->next = local;
  *tail = local;
}


void printQueue (tweet * head){
  printf("%d: Created by %s: %s\n",head->id,head->user,head->text );

  if(head->next != NULL){
    printQueue(head->next);
  }
}

int isEmpty (tweet * head){
  if(head->text[0] == '\0' &&
    head->next == NULL){
      return 0;
    }
    else{
      return 1;
    }
}
