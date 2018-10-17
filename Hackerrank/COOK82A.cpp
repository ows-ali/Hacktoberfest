#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	
	int numofiterations;
	scanf("%d", &numofiterations);
	int i,j;//loopnig variables
	char teamname[30];

	int goals[4];	
	
	int teamgoals;
	for (i=0;i<numofiterations;i++)
	{
		for (j=0;j<4;j++)
		{
			cin>>teamname>>teamgoals;
			
			if (strcmp(teamname,"Barcelona")==0	)
			{
				goals[0]=teamgoals;			
			}
			else if(strcmp(teamname,"Malaga")==0)
			{
				goals[1]=teamgoals;
			}
			else if(strcmp(teamname,"RealMadrid")==0)
			{
				goals[2]=teamgoals;
			}
			else //if(teamname=="Eibar")
			{
				goals[3]=teamgoals;
			}
		}
		
		if (goals[1]>goals[2] && goals[0]>goals[3])
		{
			printf("Barcelona\n");
		}
		else
			printf("RealMadrid\n");
	}
	
	
}
