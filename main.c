#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp; //FILE pointer for reading movie data 
	char name[200]; //movie name
	char country[10]; //movie country
	int runtime; //movie runtime
	float score; //movie score
	
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	void *ndPtr; //void pointer for linked list node
	char while_check; //while문 돌때 fgetc 받아 파일의 끝인지 아닌지 확인하는 변수 
	
	//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	printf("Reading the data files.... ");
	fp= fopen("movie.dat","r");
	if(NULL!= fp)
	{
		printf("\n Read done! items are read \n");
	}
	else
	{
		printf("\n 파일 읽기를 실패하였습니다 ㅠㅠ ");
		return 0;	
	}
	//1.2 list generation (use function list_genList() )
	list = list_genList();
	
	//1.3 read each movie data from the file and add it to the linked list
	while ((while_check = fgetc(fp)) != EOF)
	{	fscanf(fp,"%s %s %i %f",name, country, &runtime, &score);
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
		mvInfo = mv_genMvInfo(name, score, runtime, country);

		list_addTail(mvInfo, list); //끝에다가 덧붙인다. 
	}
	//1.4 FILE close
	fclose(fp);
	//2. program start
	while(exit_flag == 0) 
	{
		//2.1 print menu message and get input option
		printf("\n ----------------Menu---------------------");
		printf("\n 1.print all the movies");
		printf("\n 2. search for specific country movies");
		printf("\n 3. search for specific runtime movies");
		printf("\n 4. search for specific score movies");
		printf("\n exit");
		printf("\n ----------------Menu---------------------");
		printf("\n --- select an option : ");
		scanf("%i",&option);
		
		switch(option)
		{
			case 1: //print all the movies
				printf("printing all the movies in the list.....\n\n\n");
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) == 0/* repeat until the ndPtr points to the end node */) //end노드 만날때 까지 실행한다 list_isEndNode 이것의 값이 0이면 1이면 ㄱ 
				{
					//2.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr = list_getNextNd(ndPtr);
					//get object of ndPtr to mvInfo void pointer
					mvInfo = list_getNdObj(ndPtr);
					//print the contents of the mvInfo
					mv_print(ndPtr);
					
				
				}
				
				break;
				
			case 2: //print movies of specific country
				//2.3.1 get country name to search for
				printf("\n select the country : ");
				
				ndPtr = list;
					while (1/* repeat until the ndPtr points to the end node */)
				{
					//2.3.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr = list_getNextNd(ndPtr);
					//get object of ndPtr to mvInfo void pointer
					
					//if the input country matches to the country of the movie,
					if(1)
					//then print the contents of the mvInfo
					mv_print(ndPtr);
				}
				
				break;
				
			case 3:
				//2.4.1 get minimal runtime value to search for
				
				ndPtr = list;
					while (1/* repeat until the ndPtr points to the end node */)
				{
					//2.4.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					//get object of ndPtr to mvInfo void pointer
					//if the input runtime is lower than the runtime of the movie,
					//then print the contents of the mvInfo
				}
				
				break;
				
			case 4:
				//2.5.1 get minimal score value to search for
				
				ndPtr = list;
					while (1/* repeat until the ndPtr points to the end node */)
				{
					//2.5.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					//get object of ndPtr to mvInfo void pointer
					//if the input score is lower than the score of the movie,
					//then print the contents of the mvInfo
				}
				break;
				
			case 5:
				printf("Bye!\n\n");
				exit_flag = 1;
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
	}
	
	return 0;
}
