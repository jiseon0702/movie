#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

typedef struct movInfo{
	char name[200];
	float score;
	int runTime;
	char madeIn[10];
} movInfo_t;


void* mv_genMvInfo(char* name, float score, int runTime, char* country)
{
	movInfo_t* mvPtr;
	//���� �޸� �Ҵ� & ������ ����
	mvPtr = (movInfo_t*)malloc( sizeof(movInfo_t) );
	
	if (mvPtr == NULL)
	{
		printf("\n ERROR ! mvPtr is NULL");
		return NULL;
		
	 } 
	 
	//������ ����
	strcpy(mvPtr->name,name);
	mvPtr->score = score;
	mvPtr->runTime = runTime;
	strcpy(mvPtr->madeIn,country);
	//allocate memory and set the member variables
	
	return (void*)mvPtr;
}

void mv_print(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	
	return;
}


//return the score value from the input instance of movInfo_t structure
float mv_getScore(void* obj)
{	
	movInfo_t* mvPtr = (movInfo_t*)obj;
	return (mvPtr->score); 
}

//return the runtime value from the input instance of movInfo_t structure
int mv_getRunTime(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	return (mvPtr->runTime); 
}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)
{	
	char country[100];// �Է¹��� ���� �̸� 
	
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	strcpy(country,mvPtr->madeIn);
	
	return country;
	
}


