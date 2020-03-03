#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int value;
    struct node* next;
} node_t;

node_t *construct_3();




node_t * construct_3() {
    //Allocate three pointers: 
    //x for the first Node, and temporary pointers y and z for the other two Nodes.

    //Allocate three Node pointees and store references to them in the three pointers.

    //Dereference each pointer to store the appropriate number into the value field in its pointee.

    //Dereference each pointer to access the .next field in its pointee, 
    //and use pointer assignment to set the .next field to point to the appropriate Node.

node_t * x; //creat a note_t pointer x on stack


node_t * temp1;
temp1 = (node_t*) malloc(sizeof(node_t));
x = temp1; //next is pointer to note_t temp

temp1->value = 1;

node_t * temp2;
temp2 = (node_t*) malloc(sizeof(node_t));
temp1->next = temp2;

temp2->value = 2;

node_t * temp3;
temp3 = (node_t*) malloc(sizeof(node_t));
temp2->next = temp3;

temp3->value = 3;

temp3->next = temp1;

return x;

}

//You can ignore the following code for testing
int dump_all(node_t*);
int main (int argc, char ** argv) {

    node_t * x = construct_3();
    return dump_all(x);

}

int dump_all(node_t * x) {
    printf("x -> %d\n", x->value);
    node_t * y = x->next;
    printf("%d -> %d\n", x->value, y->value);
    node_t * z = y->next;
    printf("%d -> %d\n", y->value, z->value);
    if(z->next != x) {
    	printf("failed");
	return -1;
    } else {
        printf("%d -> %d\n", z->value, x->value);
        return 0;
    }
}
