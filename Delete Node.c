#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
} *head;
 
void initialize(){
    head = NULL;
}
void insert(int num) {
  
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    newNode->next = head;
    head = newNode;
    printf("Inserted Element : %d\n", num);
}
 
void deleteNode(struct node *head, int num) {
    struct node *current = head, *previous;
    /* Input Validation */
    if (head == NULL) { 
       printf("Error : Invalid node pointer !!!\n");       
       return;  
    }
    if (current->data == num) {
        head = current->next;   
        free(current);        
        return;
    }
    while (current != NULL && current->data != num) {
        previous = current;
        current = current->next;
    }
    if (current == NULL){
        printf("%d not found in Linked List\n");
        return;
    }
    previous->next = current->next;
    free(current);
}
void printLinkedList(struct node *nodePtr) {
  while (nodePtr != NULL) {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
  }
}
  
int main() {
    initialize(){
    insert(2);  
    insert(4); 
    insert(5); 
    insert(9);
    printf("\nBefore Deletion\n");
    printLinkedList(head);
    deleteNode(head, 5);
    deleteNode(head, 2);
    printf("\nAfter Deletion\n");
    printLinkedList(head);
    return 0;
}
