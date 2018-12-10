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
	int count; //if문을 돌릴때 해당하는 영화정보가 몇개인지 세는 변수 
	char select_country[100]; // 입력 받는 나라이름 
	int select_runtime; //입력 받는 런타임 
	float select_score; //입력 받는 점수 

	//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	printf("Reading the data files.... ");
	fp= fopen("movie.dat","r");
	if(NULL!= fp)
	{
		printf("\n Read done! ");
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
	printf(" %i  items are read\n",list_len(list)); // 총 몇개의 데이터가 읽혔는지 보여준다. 
	
	//1.4 FILE close
	fclose(fp);
	//2. program start
	while(exit_flag == 0) 
	{
		//2.1 print menu message and get input option
		option=0;
		printf("\n ----------------Menu---------------------");
		printf("\n 1.print all the movies");
		printf("\n 2. search for specific country movies");
		printf("\n 3. search for specific runtime movies");
		printf("\n 4. search for specific score movies");
		printf("\n 5. exit");
		printf("\n ----------------Menu---------------------");
		printf("\n --- select an option : ");
		scanf("%i",&option);
		
		switch(option)
		{
			case 1: //print all the movies
				printf("\n printing all the movies in the list.....\n\n\n");
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) == 0/* repeat until the ndPtr points to the end node */) //end노드 만날때 까지 실행한다 list_isEndNode 이것의 값이 1이면 end node이다. 
				{
					//2.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr = list_getNextNd(ndPtr);
					//get object of ndPtr to mvInfo void pointer
					mvInfo = list_getNdObj(ndPtr);
					//print the contents of the mvInfo
					printf("------------------------------------\n");
					mv_print(mvInfo);

				
				}
				printf("------------------------------------\n");
				printf("- totally %i movies are listed!",list_len(list));
				
				break;
				
			case 2: //print movies of specific country
				//2.3.1 get country name to search for
				printf("\n select the country : ");
				scanf("%s",select_country);

				count=0;
				ndPtr = list;
					while (list_isEndNode(ndPtr) == 0/* repeat until the ndPtr points to the end node */)
				{
					
					//2.3.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr = list_getNextNd(ndPtr);
					//get object of ndPtr to mvInfo void pointer
					mvInfo = list_getNdObj(ndPtr);
					//if the input country matches to the country of the movie,

					
					if(strncmp(select_country,mv_getCountry(mvInfo),strlen(select_country)) == 0) /*무비인포가 우리가 선택한 것과 같은 정보일때 프린트 하고 카운트의 숫자를 하나 늘린다 (해당 하는 무비의 개수를 센다)*/
					//then print the contents of the mvInfo
					{
						printf("------------------------------------\n");
						mv_print(mvInfo);
						count++;
					}
			
				}
				printf("------------------------------------\n");
				printf("- totally %i movies are listed!",count);
				break;
				
			case 3:
				//2.4.1 get minimal runtime value to search for
				printf("\n select the runtime : ");
				scanf("%i",&select_runtime);
				count=0;
				
				ndPtr = list;
					while (list_isEndNode(ndPtr) == 0/* repeat until the ndPtr points to the end node */)
				{
					//2.4.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr = list_getNextNd(ndPtr);
					//get object of ndPtr to mvInfo void pointer
					mvInfo = list_getNdObj(ndPtr);
					//if the input runtime is lower than the runtime of the movie,
					if(select_runtime < mv_getRunTime(mvInfo)) //만약 선택한 숫자보다 긴 러닝타임을 갖고있는 영화일 경우 출력한다 
					//then print the contents of the mvInfo
					{
						printf("------------------------------------\n");
						mv_print(mvInfo);
						count++;
					}
				}
				printf("------------------------------------\n");
				printf("- totally %i movies are listed!",count);
				break;
				
			case 4:
				//2.5.1 get minimal score value to search for
				printf("\n select the score  : ");
				scanf("%f",&select_score);
				count=0;
				
				ndPtr = list;
					while (list_isEndNode(ndPtr) == 0/* repeat until the ndPtr points to the end node */)
				{
					//2.5.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr = list_getNextNd(ndPtr);
					//get object of ndPtr to mvInfo void pointer
					mvInfo = list_getNdObj(ndPtr);
					//if the input score is lower than the score of the movie,
					if(select_score < mv_getScore(mvInfo)) //만약 선택한 점수보다 큰 영화라면 출력한다 
					//then print the contents of the mvInfo
					{
						printf("------------------------------------\n");
						mv_print(mvInfo);
						count++;
					}
				}
				printf("------------------------------------\n");
				printf("- totally %i movies are listed!",count);
				
				break;
				
			case 5:
				printf("Bye!\n\n");
				exit_flag = 1;
				break;
				
			default:
			{
				printf("wrong command! input again\n");
				break;
			}
		}
	}
	
	return 0;
}
