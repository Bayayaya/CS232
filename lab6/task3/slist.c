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
	int size;
};

struct slist * slist_create(){
	struct slist * slist_ptr;
	slist_ptr = (struct slist*)malloc(sizeof(struct slist));
	slist_ptr->front=NULL;
	slist_ptr->back=NULL;
	slist_ptr->size=0; // default size of slist is 0
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
	l->size ++;//size plus 1
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
	l->size++;//increase size by 1
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

/*uint32_t slist_length(struct slist *l){
  uint32_t i=0;
  struct snode* snode_trav;
  snode_trav = l->front;
  while(snode_trav != NULL){
  i++;
//printf("%d \n",i);
snode_trav = snode_trav->next;
}
return i;
}*/

//updated slist_length function
uint32_t slist_length(struct slist *l){
	return l->size;
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
			l->size--;//update the size before descroy
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

struct snode * slist_get_front(struct slist *l){
	return l->front;
}

struct snode * slist_get_back(struct slist *l){
	return l->back;
}

struct snode *slist_find_at(struct slist *list, int index){

	struct snode* find=list->front;
	if(index<list->size && index >= (-list->size)){
		if(index>=0){
			//find snode from front

			for(int i=0; i<index ; i++){
				find=find->next; 
			}

		} else {
			//find snode from back
			index=list->size + index;
			for(int i=0; i<index; i++){
				find = find->next;
			}	
		}
		return find;
	}
	return NULL;
}

void slist_delete_at(struct slist  *list, int index){
	struct snode ** snode_ptrptr;
	snode_ptrptr = &(list->front);
	struct snode* prev =NULL;
	if(index<0){
		index = list->size+index;
	}
	for(int i=0;i<index;i++){
		prev = *snode_ptrptr;
		snode_ptrptr = &((*snode_ptrptr)->next);//move snode_ptrptr to next snode*
	}
	struct snode * to_free;
	to_free = *snode_ptrptr;
	if(*snode_ptrptr==(list->back)){
		list->back = prev;
	}
	*snode_ptrptr = ((*snode_ptrptr)->next);
	list->size--;//update the size before destory
	snode_destroy(to_free);
	return;
}


