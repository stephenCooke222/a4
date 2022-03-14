#include "a4header.h"

void sortUsername (tweet ** head, tweet ** tail){
  tweet *temp;
  temp = malloc(sizeof(tweet));
  int counter =0;
  int end = 0;
  tweet *local;
  tweet *comp;
  local = *head;
  int nextLarger = 0;
  int bigger = 0;


  while(end == 0){
    if(local->next == NULL){
      end = 1;
    }
    else{
      local = local->next;
    }
    counter++;
  }


  for(int i = 0; i < counter;i++){
    local = *head;
    comp = local->next;

    for(int j = 0; j < counter-1; j++){
      bigger = 0;
      nextLarger = 0;
      int i = 0;
      while(bigger == 0){

        if(local->user[i] < comp->user[i]){

          bigger = 1;
        }
        else if(local->user[i] > comp->user[i]){

          bigger = 1;
          nextLarger = 1;
        }
        else if(i == (strlen(local->user)-1)){
          bigger = 1;
        }
        else if(i == (strlen(comp->user)-1)){
          bigger = 1;
          nextLarger = 1;
        }
        i++;
      }
      if(nextLarger == 1){
        temp->id = local->id;
        local->id = comp->id;
        comp->id = temp->id;

        strcpy(temp->user,local->user);
        strcpy(local->user,comp->user);
        strcpy(comp->user,temp->user);

        strcpy(temp->text,local->text);
        strcpy(local->text,comp->text);
        strcpy(comp->text,temp->text);
      }
      local = local->next;
      comp = comp->next;
    }
  }

    free(temp);
}


void reverse (tweet ** head, tweet ** tail){
  tweet *temp;
  temp = malloc(sizeof(tweet));
  tweet *local;
  local = *head;
  tweet *receiver;
  int counter = 0;
  int end = 0;
  while(end == 0){
    if(local->next == NULL){
      end = 1;
    }
    else{
      local = local->next;
    }
    counter++;
  }
  local = *head;


  for(int i = 0; i < (counter/2);i++){
    receiver = *head;
    for(int j = 0; j < (counter-i)-1;j++){
      receiver = receiver->next;
    }

    temp->id = local->id;
    local->id = receiver->id;
    receiver->id = temp->id;

    strcpy(temp->user,local->user);
    strcpy(local->user,receiver->user);
    strcpy(receiver->user,temp->user);

    strcpy(temp->text,local->text);
    strcpy(local->text,receiver->text);
    strcpy(receiver->text,temp->text);

    local = local->next;
  }



  free(temp);
}


void sortID (tweet ** head, tweet ** tail){
  tweet *temp;
  temp = malloc(sizeof(tweet));
  tweet *local;
  local = *head;

  int counter = 0;
  int end = 0;
  while(end == 0){
    if(local->next == NULL){
      end = 1;
    }
    else{
      local = local->next;
    }
    counter++;
  }
  //Bubble sort method
  for(int i = 0; i < counter; i++){
    local = *head;
    for(int j = 0; j < counter-1;j++){
      if(local->id > local->next->id){
        temp->id = local->id;
        local->id = local->next->id;
        local->next->id = temp->id;

        strcpy(temp->user,local->user);
        strcpy(local->user,local->next->user);
        strcpy(local->next->user,temp->user);

        strcpy(temp->text,local->text);
        strcpy(local->text,local->next->text);
        strcpy(local->next->text,temp->text);
      }
      local = local->next;
    }
  }
  free(temp);
}
