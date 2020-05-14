#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>
struct snode {
  //TODO: change str to dynamic allcoation
  void* data;
  //int length;
  struct snode *next;
};

struct snode *snode_create(void *s) {
        struct snode * snode_ptr;
	snode_ptr = (struct snode*)malloc(sizeof(struct snode));
	void* create_s=(void*)malloc((strlen(s)+1)*sizeof(*s));
        strcpy(create_s,s);
	snode_ptr->data = create_s;
	snode_ptr->next=NULL;
        return snode_ptr;

 //TODO: implement snode_create, change the prototype to
 //match with header file
 //return node;
  
 }
 
void snode_destroy(struct snode * s) {
	free(s->data);
        free(s);

 //TODO: implement snode_destroy
 
}
 
