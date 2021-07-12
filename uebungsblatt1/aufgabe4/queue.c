#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

queue *enter(queue *q, char* value){
	
	queue *first = q;
	queue *tail = malloc(sizeof(queue));
	
	//tail->value = malloc(sizeof(value));
	tail->value = value;
	tail->next = NULL;
	
	if(q == NULL){
		return tail;
	}
	
	while(q->next != NULL){
		q = q->next;
	}
	
	q->next = tail;
	
	return first;
}

int is_empty(queue *q){
	
	if(q == NULL){
		return 1;
	}
	return 0;
}

char  *front(queue *q){
	
	if(is_empty(q)){
		fprintf(stderr, "ERROR  in function 'front': empty queue");
		return NULL;
	}
	return q->value;
	
}

queue *leave(queue *q){
	if(is_empty(q)){
		return NULL;
	}
	
	queue *h = q->next;
	free(q);
	return h;
}
