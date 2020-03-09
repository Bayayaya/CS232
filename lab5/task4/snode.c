#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>
struct snode {
  //TODO: change str to dynamic allcoation
  char* str;
  //int length;
  struct snode *next;
};

struct snode *snode_create(char *s) {
        struct snode * snode_ptr;
	snode_ptr = (struct snode*)malloc(sizeof(struct snode));
        char* create_s=(char*)malloc((strlen(s)+1)*sizeof(char));
        strcpy(create_s,s);
	snode_ptr->str = create_s;
	snode_ptr->next=NULL;
        return snode_ptr;

 //TODO: implement snode_create, change the prototype to
 //match with header file
 //return node;
  
 }
 
void snode_destroy(struct snode * s) {
	free(s->str);
        free(s);

 //TODO: implement snode_destroy
 
}
 
