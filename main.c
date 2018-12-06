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
	int (*repFunc)(void* obj, void* arg); //function pointer for using list_repeatFunc() function
	void *arg; //a void pointer for passing argument to repFunc
	int cnt; //integer variable
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
	list = list_genList(); //리스트를 만든다 
	
	
	//1.3 read each movie data from the file and add it to the linked list 이부분에서 파일을 하나씩 읽어온다. 영화정보에대해 ㄱ조체를 만든다. 
	while ((while_check = fgetc(fp)) != EOF)
	{	fscanf(fp,"%s %s %i %f",name, country, &runtime, &score);
		mvInfo = mv_genMvInfo(name, score, runtime, country);
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
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
				printf("\nprinting all the movies in the list.....\n\n\n");
				printf("----------------------------------------\n");
				
				repFunc = mv_printAll;
				arg = NULL; //필요없다.  //포인터들이 가르킨다. 
				break;
				
			case 2: //print movies of specific country
				repFunc = mv_printCountry;
				//특정제작국가만 나오겠지 앞에 스캔에프 를 넣어야 , 제작국가 어떤거로 할래?
				//korea인지 use인지 무슨 선택을 한건지 
				//arg = ; 가 무엇값인지 조건을 따진다 
				break;
				
			case 3: //print movies with long runtime

				break;
				
			case 4: //print movies with high score
				
				break;
				
			case 5:
				printf("\n\nBye!\n\n");
				exit_flag = 1;
				
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
		
		//2.2 printing operation by function pointer (list_repeatFunc() is called here)
		list_repeatFunc(repFunc,arg,list); //모든 영화정보가 찍힌다. 
		//2.3 print number of movies
	}
	
	return 0;
}
