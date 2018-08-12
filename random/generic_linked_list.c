/*Program to implement a linked list which can store any data*/
#include "stdio.h"
#include "stdlib.h"
typedef struct node
{
  void *data;
  struct node *next;
}node;

void printInt(void *data)
{
  printf("%d ",*(int *)data);
}
void printFloat(void *data)
{
  printf("%f ",*(float *)data);
}

void printList(node *start, void (*fp)(void *))
{
  while (NULL != start)
  {
    fp(start->data);
    start = start->next;
  }
}
void push(node **head, void *data, int size)
{
  int i = 0;
  node *tmp = (node *)malloc(sizeof(node));
  tmp->data = malloc(size);
  tmp->next = (*head);
  for (i = 0; i < size; i++)
  {
    *(char *)(tmp->data + i) = *(char *)(data + i);
  }
  (*head) = tmp;
}
int main(void)
{
  node *start = NULL;
  int arr[] = {10, 5, 3, 20, 25};
  int i = 0;
  for (i = 0; i < 5; i++)
    push(&start, &arr[i], sizeof(int));

  printf("\nCreated linked list for int: ");
  printList(start, printInt);

  start = NULL;
  float fl[] = {1.2, 3.4, 3.3, 7.0, 5.0};
  for (i = 0; i < 5; i++)
    push(&start, &fl[i], sizeof(float));

  printf("\n\nCreated linked list for float: ");
  printList(start, printFloat);
  printf("\n\n");
  return 0;
}
