#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>
#include "slist.h"

struct snode {
  //TODO: change str to dynamic allcoation
  char* str;
  //int length;
  struct snode *next;
};


struct slist {
  struct snode *front; // front node
  struct snode *back;  // back node
};

struct slist * slist_create(){
	struct slist * slist_ptr;
	slist_ptr = (struct slist*)malloc(sizeof(struct slist));
	slist_ptr->front=NULL;
	slist_ptr->back=NULL;
	return slist_ptr;

}

struct snode* slist_add_back(struct slist *l, char *str){
	struct snode* snode_new_ptr;
	snode_new_ptr = snode_create(str);
	if(l->back==NULL){
		l->back = snode_new_ptr;
		l->front = snode_new_ptr;
	}else{
		l->back->next = snode_new_ptr;
		l->back = snode_new_ptr;
	}
	return snode_new_ptr;

}
struct snode* slist_add_front(struct slist *l, char *str){
	struct snode* snode_new_ptr;
	snode_new_ptr = snode_create(str);
	if(l->front == NULL){
		l->front = snode_new_ptr;
		l->back = snode_new_ptr;
	} else {
	struct snode* temp = l->front;
	l->front = snode_new_ptr;
	snode_new_ptr->next = temp;
	}
	return snode_new_ptr;
}

struct snode* slist_find(struct slist *l, char *str){
	struct snode* snode_check;
	snode_check = l->front;
	while(snode_check != NULL){
		if(0==strcmp(str,snode_check->str)){
			return snode_check;//check snode_check->str with give str, if match, return snode_check
			}else{
			snode_check = snode_check->next;//if doesn't match, move to next snode
			}
	}
	return NULL; //if no matching after while loop, return NULL
}

void slist_destroy(struct slist *l){
	struct snode* snode_free;
	snode_free = l->front;
	while(snode_free != NULL){
		struct snode* next = snode_free->next;
		snode_destroy(snode_free);
		snode_free = next;
	}
	free(l);
}

void slist_traverse(struct slist *l){
        struct snode* snode_trav;
        snode_trav = l->front;
        while(snode_trav != NULL){
                printf("%s \n",snode_trav->str);
		snode_trav = snode_trav->next;
        }
}

uint32_t slist_length(struct slist *l){
	uint32_t i=0;
	struct snode* snode_trav;
        snode_trav = l->front;
        while(snode_trav != NULL){
                i++;
		//printf("%d \n",i);
		snode_trav = snode_trav->next;
        }
	return i;
}

void slist_delete(struct slist *l, char *str){
	struct snode** snode_ptrptr;
	snode_ptrptr = &(l->front);
	struct snode* prev =NULL;
	while(*snode_ptrptr != NULL){
		if(0==strcmp(str,(*snode_ptrptr)->str)){
			struct snode * to_free;
			to_free = *snode_ptrptr;
			if(*snode_ptrptr==(l->back)){
				l->back = prev;
			}
			*snode_ptrptr = ((*snode_ptrptr)->next);
			snode_destroy(to_free);
			return;
			//check snode_ptrptr->str with give str, if match, relink list and free *snode_ptrptr
		}else{
			//if doesn't match, move to next snode
			prev = *snode_ptrptr;
			snode_ptrptr = &((*snode_ptrptr)->next);//move snode_ptrptr to next snode*

		}
	}

}

