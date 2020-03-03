/* Include the system headers we need */
#include <stdlib.h>
#include <stdio.h>

/* Include our header */
#include "mystring.h"

/* Define what our struct is */
struct mystring_t {
	size_t size;
	char *data;
};

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed() {
	fprintf(stderr, "Out of memory.\n");
	exit(1);
}

/* Bad example of how to create a new mystring */
mystring_t *bad_string_new() {
	/* Create the string and a pointer to it */
	/*This is a bad constructor as v gets destroyed once contructor returns*/
	mystring_t *retval, v;
	retval = &v;

	/* Initialize attributes */
	retval->size = 1; //why size+1? size is the actual char lenght.
	//we must reseve an extra space for null
	retval->data = (char*) malloc((retval->size + 1) * sizeof(char));
	if (retval->data == NULL) {
		allocation_failed();
	}

	retval->data[0] = ' ';
	retval->data[retval->size] = '\0';
	return retval;
}

/* Another suboptimal way of creating a string */
mystring_t also_bad_string_new() {
	/* Create the string */
	/*why is this bad? does v get destroyed upon returning? */
	mystring_t s;

	/* Initialize attributes */
	s.size = 1; //why size+1? an extra space for null
	s.data = (char*) malloc((s.size + 1) * sizeof(char));
	if (s.data == NULL) {
		allocation_failed();
	}
	s.data[0] = ' ';
	s.data[s.size] = '\0';
	return s;
}

/* Create a new string with a size (length) of 1
   and set its single component to zero... the
   RIGHT WAY */
mystring_t *mystring_new() {
	mystring_t *retval;
	retval = (mystring_t*) malloc (sizeof(mystring_t));
	if (retval == NULL) {
		allocation_failed();
	}

	retval->size = 1;
	retval->data = (char*) malloc(sizeof(char));
	if (retval == NULL) {
		allocation_failed();
	}

	retval->data[0] = '0'; //set the single component to zero
	//YOUR CODE HERE
	return retval;
}

/* Return the value at the specified location/component "loc" of the mystring */
char mystring_get(mystring_t *s, size_t loc) {
	//size_t is unsigned int
	if(loc>=0 && loc < s->size){
		return s->data[loc];
	}
	else{
		return ' ';
	}
	//YOUR CODE HERE
}

/* Free up the memory allocated for the passed mystring.
   Remember, you need to free up ALL the memory that was allocated. */
void mystring_delete(mystring_t *s) {
free(s->data);
free(s);
	/* YOUR CODE HERE */
}

int mystring_get_len(mystring_t *s) {
	return s->size;
	/* YOUR CODE HERE */
}

char* mystring_get_data(mystring_t *s) {
	/* YOUR CODE HERE*/
	return s->data;
}
void mystring_cat(mystring_t *s, char *s2) {
	/*mystringe_cat(mystring_t *dest, char * src) 
	function appends the src C string to the dest mystring, 
	overwriting the terminating null byte ('\0') at the end of dest,  
	and  then adds  a  terminating  null  byte.*/
	int i = 0;
	while(1){
		if (s2[i]=='\0'){
			break;
		} else
		i++;
	}//i is length of s2

	s->data = (char*) realloc(s->data,sizeof(char)*(s->size+i+1));
	for (int j=s->size-1;j<(s->size+i+1);j++){
		s->data[j]=s2[j-s->size+1];
	}
	s->size += i;
	//s->data[s->size+1] = '0';
	/* YOUR CODE HERE*/
}

/* Set a value in the mystring. If the extra memory allocation fails, call
   allocation_failed(). Unset space should be value of space */
void mystring_set(mystring_t *s, size_t loc, char value) {

	if(loc > 0 && loc < s->size){
		s->data[loc] = value;
	}
	else {if (loc>=0){
		s->data = (char*) realloc(s->data,sizeof(char)*(loc+1));
		for(int i = s->size; i<loc+1; i++){
			s->data[i]=' ';
		}
		s->data[loc] = value;
		s->size = loc+1;
		//s->data[loc+1] = '\0';
		}
		
	}

	/* YOUR CODE HERE*/
}
