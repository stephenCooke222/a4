#include "a4header.h"



int main(){

  tweet *head;
  head = malloc(sizeof(tweet));

  tweet *tail;
  tail = malloc(sizeof(tweet));
  char wait[20];

  tweet *tempTweet;
  tempTweet = malloc(sizeof(tweet));
  tempTweet->next = NULL;
  tail = head;
  printf("Generating a queue list of size 4\n");

  //ADDING NODES
  head->id = 100;
  strcpy(head->user,"First\0");
  strcpy(head->text,"Test1\0");

  tempTweet->id = 103;
  strcpy(tempTweet->user,"Second\0");
  strcpy(tempTweet->text,"Test2\0");

  enqueue(&head,&tail,tempTweet);

  tempTweet->id = 102;
  strcpy(tempTweet->user,"Third\0");
  strcpy(tempTweet->text,"Test3\0");

  enqueue(&head,&tail,tempTweet);

  tempTweet->id = 101;
  strcpy(tempTweet->user,"Fourth\0");
  strcpy(tempTweet->text,"Test4\0");
  enqueue(&head,&tail,tempTweet);
  //PRINT QUE
  printf("Displaying queue contents with printQueue\n");
  printQueue(head);
  printf("\n");
  fgets(wait,20,stdin);
  //ENQUEUE
  printf("Adding a new node with enqueue\n");
  printf("Iteration [1]: [Node]: 107: Created by Fifth: Fifth");
  printf("\n" );
  tempTweet->id = 107;
  strcpy(tempTweet->user,"Fifth\0");
  strcpy(tempTweet->text,"Fifth\0");
  enqueue(&head,&tail,tempTweet);
  printf("New Que looks like\n");
  printQueue(head);
  printf("\n");
  fgets(wait,20,stdin);

  printf("Iteration [2]: [Node]: 110: Created by Sixth: test6");
  printf("\n" );
  tempTweet->id = 110;
  strcpy(tempTweet->user,"Sixth\0");
  strcpy(tempTweet->text,"test6\0");
  enqueue(&head,&tail,tempTweet);
  printf("New Que looks like\n");
  printQueue(head);
  printf("\n" );
  fgets(wait,20,stdin);

  printf("Iteration [3]: [Node]: 108: Created by Seventh: test7");
  printf("\n" );
  tempTweet->id = 108;
  strcpy(tempTweet->user,"Seventh\0");
  strcpy(tempTweet->text,"test7\0");
  enqueue(&head,&tail,tempTweet);
  printf("New Que looks like\n");
  printQueue(head);
  printf("\n" );
  fgets(wait,20,stdin);

  //DEQUEUE
  printf("Testing DEQUEUE\n");

  printf("Iteration [1] of Running dequeue\n" );
  dequeue(&head,&tail);
  printf("New queue\n" );
  printQueue(head);
  printf("\n" );
  fgets(wait,20,stdin);


  printf("Iteration [2] of Running dequeue\n" );
  dequeue(&head,&tail);
  printf("New queue\n" );
  printQueue(head);
  printf("\n" );
  fgets(wait,20,stdin);



  printf("Iteration [3] of Running dequeue\n" );
  dequeue(&head,&tail);
  printf("New queue\n" );
  printQueue(head);
  printf("\n" );
  fgets(wait,20,stdin);

  printf("Testing is empty\n" );
  printf("queue should not be empty\n" );
  if(isEmpty(head) == 1){
    printf("Queue is not empty\n");
  }
  printQueue(head);
  printf("\n" );
  fgets(wait,20,stdin);

  printf("Deuqing another node\n" );
  dequeue(&head,&tail);
  printf("queue should not be empty\n" );
  if(isEmpty(head) == 1){
    printf("Queue is not empty\n");
  }
  printQueue(head);
  printf("\n" );
  fgets(wait,20,stdin);

  printf("Testing with an empty queue\n" );
  tweet *empty;
  empty = malloc(sizeof(tweet));
  empty->text[0] = '\0';
  empty->next = NULL;

  printf("queue should be empty\n" );
  if(isEmpty(empty) == 0){
    printf("Queue is empty\n");
  }
  free(empty);
  printf("Old queue is\n" );
  tempTweet->id = 101;
  strcpy(tempTweet->user,"Fourth\0");
  strcpy(tempTweet->text,"Test4\0");
  enqueue(&head,&tail,tempTweet);
  printQueue(head);
  printf("\n" );
  fgets(wait,20,stdin);



  sortID(&head,&tail);

    printf("\n" );

  reverse(&head,&tail);

  sortUsername(&head,&tail);



  int end = 1;
  tweet *next;
  tweet *local;
  local = head;
  while(end == 1){
    if(next->next != NULL){
      next = local->next;
    }
    else{
      end = 0;
    }
    free(local);
    local = next;
  }
  free(tempTweet);
}
