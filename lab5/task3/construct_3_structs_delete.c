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

    //TODO:copy setup func from task2
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
    node_t* newnode = (node_t*) malloc (sizeof(node_t));
    newnode->length = length;
    for (int i=0; i<length+1; i++){
        newnode->str[i]=str[i];
    }
    newnode->next=*head;
    *head = newnode;
    //TODO: copy add func from task2
}
void delete_node_at(node_t ** head, int idx) {
	node_t* trav, *needfree, *pre;
	trav = *head;
	needfree = *head;
	pre=*head;
	if(idx == 0){
	*head=(*head)->next;
	free(needfree);
	return;
	}
	for(int i =0; i<idx+1; i++){
		if(trav==NULL){
		printf("End of list\n");
		return;
		}else{
	//printf("i's position  %d\n", i);		
	pre=needfree;
	needfree=trav;
	trav=trav->next;
	}
	}
	pre->next=needfree->next;
	free(needfree);
    //TODO: implement delete a node based on index
	//deletes a node at index idx, which ranges from zero to the length of the list - 1.
}

int doesmatch(char * key, char * nodestr, int length){
	int check;
	for (int i=0; i<length; i++){

	if(key[i]!=nodestr[i]){
	check = 1;
	return check;//if string doesn't match, return 1
	
		}
	}	
	return 0;//if string matchs, return 0

}

void delete_node_key(node_t **head, char * key) {
	node_t** trav;
	node_t* needfree;
	trav=head;
	int check;
	while(*trav != NULL){
		check = doesmatch(key,(*trav)->str,(*trav)->length);
		if(check == 0){
			needfree=*trav;
			*trav = (*trav)->next;
			free(needfree);
			//free node_t that is refering to by *trav and move *trav to next
			//so no need to move trav because *trav already moved
		} else {
			trav = &((*trav)->next);//trave move on it key doesn't match str
		}
	}

	//TODO: implement delete a node based on key
	//given a certain key, find and delete. 
}

//You can ignore the following code for testing
void dump_all(node_t*);
int main (int argc, char ** argv) {
	node_t * head = setup();
	add(&head, "hi", 2);
	delete_node_key(&head, "prof");
	delete_node_at(&head, 0);
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
