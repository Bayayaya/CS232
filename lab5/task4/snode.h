#ifndef _snode_H_
#define _snode_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct snode;
  //TODO: change str to dynamic allcoation
  //int length;

//TODO: change prototypes of functions to remove
//length
struct snode * snode_create(char *s);

void snode_destroy(struct snode * s);
 
#endif
