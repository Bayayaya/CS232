#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;//node_t is a one word name for struct snode

node_t * setup() {
    node_t * head ;
    //TODO:head declared for you
    //Allocate three more pointers
    //head for the first Node, and temporary pointers node1, node2 and node3
    //Allocate three node pointees and store references to them in the three pointers
    //Dereference each pointer to store the appropriate number and string into
    //the length and str fields in its pointee.
    //Dereference each pointer to access the .next field in its pointee, 
    //and use pointer assignment to set the .next field to point to the
    //appropriate Node. 
    head=(node_t*)malloc(sizeof(node_t));
    node_t* node1; 
    node_t* node2; 
    node_t* node3;
    node1 = head;
    //node1=(node_t*) malloc(sizeof(node_t));
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
	}
    //TODO: free all dynamic memory you requested.
}

//You can ignore the following code for testing
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
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
