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
	char while_check; //while�� ���� fgetc �޾� ������ ������ �ƴ��� Ȯ���ϴ� ���� 
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
		printf("\n ���� �б⸦ �����Ͽ����ϴ� �Ф� ");
		return 0;	
	}
	//1.2 list generation (use function list_genList() )
	list = list_genList(); //����Ʈ�� ����� 
	
	
	//1.3 read each movie data from the file and add it to the linked list �̺κп��� ������ �ϳ��� �о�´�. ��ȭ���������� ����ü�� �����. 
	while ((while_check = fgetc(fp)) != EOF)
	{	fscanf(fp,"%s %s %i %f",name, country, &runtime, &score);
		mvInfo = mv_genMvInfo(name, score, runtime, country);
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
		list_addTail(mvInfo, list); //�����ٰ� �����δ�. 

		
	
		
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
				arg = NULL; //�ʿ����.  //�����͵��� ����Ų��. 
				break;
				
			case 2: //print movies of specific country
				repFunc = mv_printCountry;
				//Ư�����۱����� �������� �տ� ��ĵ���� �� �־�� , ���۱��� ��ŷ� �ҷ�?
				//korea���� use���� ���� ������ �Ѱ��� 
				//arg = ; �� ���������� ������ ������ 
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
		list_repeatFunc(repFunc,arg,list); //��� ��ȭ������ ������. 
		//2.3 print number of movies
	}
	
	return 0;
}
