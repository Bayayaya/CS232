/******************************************************
* File: asciimation.c
*
* This is implementation of asciimation
*
* Change Log:
* 12/02/2006, By Jun Yuan, created for CS101, Huazhong University of Sci. & Tech., Wuhan, China
* 01/05/2016, By Jun Yuan-Murray, modified for BCS230, SUNY Farmingdale, NY
* 02/11/2017, By Jun Yuan-Murray, modified for BCS230, SUNY Farmingdale, NY
* 02/18/2017, By Jun Yuan-Murray, modified for BCS230, SUNY Farmingdale, NY
* 04/16/2019, By Jun Yuan-Murray, modified for CS232, Pace University, NY
* 04/29/2020, By Jun Yuan-Murray, modified for CS232, Pace University, NY
******************************************************/
#define _POSIX_C_SOURCE 199309L
//#define _GNU_SOURCE


#include "asciimation.h"
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>


static int get_num_frames(char *path) {
	DIR * dir;
	struct dirent * pdir;
	dir = opendir(path);
	int n = 0;
	while((pdir = readdir(dir))) {
		if(strcmp(pdir->d_name, ".") != 0 && strcmp(pdir->d_name, "..") != 0) {
			printf("%s", pdir->d_name);
		//debugging printf, you can use this line to print out ascii file names.
			n++;
		}

	}
	closedir(dir);
	return n;

}

void sleep_helper(int fps, int rep_counter){

	float time = 1.0/fps*rep_counter;

	struct timespec timesp;
	
	int t = time;
	timesp.tv_sec = t;
	timesp.tv_nsec = (time - t) * 1000*1000*1000;

	nanosleep(&timesp,NULL);
}

asciimation_t * asciimation_new(char * path, int fps){
	asciimation_t * ascm = (asciimation_t *) malloc(sizeof(asciimation_t));
	if(!ascm) {
		perror("failed allocation\n");
		return 0;
	}
	ascm->frames_per_second = fps;
	//figure out how many frames are in the dir?
	int n = get_num_frames(path);
	//create a list of frames
	ascm->frames = slist_create();//TODO: create a new slist;
	// we know the number of frames, we can simply reconstruct the name of each ascii file, and construct a frame obj for 
	// each ascii file. Must implement frame_new first
	for(int i=0; i<n; i++) {
		char asciipath[4096];
		strcpy(asciipath, path);
		int len = strlen(asciipath);
		if(asciipath[len-1] != '/') 
			sprintf(asciipath+len, "/%d", i+1);
		else	
			sprintf(asciipath+len, "%d", i+1);
		//if your path is ./data/a, and i=0, then asciipath = ./data/a/1, exactly what we want to load
		//printf("before frame_new\n");
		struct frame_t * aframe = frame_new(asciipath,i);
		//printf("before slist_add_back\n");
		slist_add_back(ascm->frames,aframe);
		//printf("after slist_add_back\n");

		//ascm->frames[i]=aframe;
		//TODO:add aframe to ascm->frames;
	}
	
	return ascm;
}

void asciimation_delete(asciimation_t * ascm){
	//TODO:your code here
	//reversed steps of asciimation_new
	// 1. free all the frames, must implement frame_delete first.(why?)
	// 2. free the list
	// 3. free the ascm itself

	struct snode* snode_ptr = ascm->frames->front;
	while(snode_ptr!=NULL){
		frame_t* frame_ptr = snode_ptr->data;
		frame_delete(frame_ptr);
		snode_ptr = snode_ptr->next;
	}
	slist_destroy(ascm->frames);
	free(ascm);
}

void asciimation_play(asciimation_t * ascm){
	//TODO:your code here
	//loop through the list of frames and print out each frame, ? is also to be done by you
	//for(int i=0; i<?; i++) {
		//printf(?);
		//sleep for frames_per_second * repetition_counter_of_the_frame
		//clear the screen
	//}
	//uint32_t n = slist_length(ascm->frames); 
	// printf("Nodes number in slist %d\n", n );
	//slist_traverse(ascm->frames);
	struct snode* snode_ptr = ascm->frames->front;
	while(snode_ptr!=NULL){
		int a = system("clear");
		assert (a!=0 || a!= -1 || a !=127);
		frame_t* frame_ptr = snode_ptr->data;
		//printf("repcounter is %d\n", frame_ptr->rep_counter);
		//printf("Print frame and id is %d\n", frame_ptr->id);
		char* picture = frame_ptr->content;
		printf("%s\n", picture);
		//usleep(1000.0*1000.0/ascm->frames_per_second*frame_ptr->rep_counter);
		sleep_helper(ascm->frames_per_second,frame_ptr->rep_counter);
		//system("@cls||clear");
		snode_ptr = snode_ptr->next;
	}

}
void asciimation_reverse(asciimation_t * ascm){
	//TODO:Your code here
	//same logic as above, only difference is loop through the list backward.
	uint32_t n = slist_length(ascm->frames); 
	struct snode* snode_ptr = ascm->frames->front;
	struct snode* snode_arr[n];
	for(int i=0; i<n; i++){
		snode_arr[i] = snode_ptr;
		snode_ptr = snode_ptr->next;
	}
	for(int j=n-1; j>=0; j--){
		int a = system("clear");
		assert (a!=0 || a!= -1 || a !=127);
		frame_t* frame_ptr = snode_arr[j]->data;
		printf("%s\n", frame_ptr->content);
		//usleep(1000.0*1000.0/ascm->frames_per_second*frame_ptr->rep_counter);
		sleep_helper(ascm->frames_per_second,frame_ptr->rep_counter);
	}
}


