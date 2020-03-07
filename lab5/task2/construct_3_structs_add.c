#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
	node_t * head ;
    head=(node_t*)malloc(sizeof(node_t));
    node_t* node1;
    node_t* node2;
    node_t* node3;
    node1 = head;
    node1->length = 5;
    char* str1 = "hello";
    for(int i=0; i<node1->length+1; i++){
            node1->str[i]=str1[i];}
    node2=(node_t*) malloc(sizeof(node_t));
    node1->next=node2;

    node2->length = 5;
    char* str2 = "there";
    for(int i=0; i<node2->length+1; i++){
            node2->str[i]=str2[i];}
    node3=(node_t*) malloc(sizeof(node_t));
    node2->next=node3;

    node3->length = 4;
    char* str3 = "prof";
    for(int i=0; i<node3->length+1; i++){
            node3->str[i]=str3[i];}
    node3->next = NULL;

   return head;

}

void teardown(node_t* head) {
         node_t* trav;
        trav = head;
        while(trav!=NULL){
                node_t* next=trav->next;
                free(trav);
                trav=next;
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
}
}

void add(node_t ** head, char * str, int length){
    //TODO: implement add to add a new node to front, pointed by head
    node_t* newnode = (node_t*) malloc (sizeof(node_t));
    newnode->length = length;
    for (int i=0; i<length+1; i++){
    	newnode->str[i]=str[i];
    }
    newnode->next=*head;
    *head = newnode;
}

//You can ignore the following code for testing
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    dump_all(head);
    teardown(head);
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}
