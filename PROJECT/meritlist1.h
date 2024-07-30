#include<stdio.h>
#include<string.h>
#include<conio.h>
#include"meritlist2.h"


int update_std_details()
{
	int i=0,m,k,count=0;
	FILE *ptr;
	ptr = fopen("Std_merit_list.bin","rb");
	rewind(ptr);
	while(fread(&s1,sizeof(s1),1,ptr)==1)
	{
		i++;
	}
	fclose(ptr);
	if(i>=10)
	{
		printf("\nYou have reached maximum limit!\n");
	    return 2;
	}
	printf("\nEnter the details of student:\n");
	do{
        printf("\nRoll no: ");
	    scanf("%d",&k);
	    i = compare(k);
	}while(i!=0);
	s1.rollno = k;
	printf("\nName: ");
	fflush(stdin);
	gets(s1.name);
	printf("\nEnter subject-wise marks:\n");
	for(i=0;i<5;i++)
	{
		if(i==0)
			printf("\nEngineering Mathematics: ");
		else if(i==1)
			printf("\nBasic Electrical Engineering: ");
		else if(i==2)
			printf("\nEngineering Chemistry: ");
		else if(i==3)
			printf("\nProgramming for Problem Solving: ");
		else if(i==4)
			printf("\nEngineering Graphics: ");
		scanf("%d",&m);
		if(m>=0&&m<=100)
			s1.marks[i] = m;
		else
		{
			printf("\nInvalid marks! Please, re-enter the marks\n");
			i--;
		}
	}
	ptr = fopen("Std_merit_list.bin","rb+");
	fseek(ptr,sizeof(s1)*count,SEEK_END);
	fwrite(&s1,sizeof(s1),1,ptr);
	fclose(ptr);
	printf("\nRecord has been successfully added.....");
	printf("\n\nDo you want to create another record?(yes=1,no=0) ");
	scanf("%d",&i);
	system("cls");
	return i;
}



void read_std()
{
	int i;
	FILE *ptr1;
	ptr1 = fopen("Std_merit_list.bin","rb");
	printf("\n");
	printf("\n\t\tRollno\t\tName\t\t\tMaths\t\tBEE\t\tChem\t\tPPS\t\tEG\n");
	printf("\t\t\t\t\t\t\tMarks\t\tMarks\t\tMarks\t\tMarks\t\tMarks");
	printf("\n\n");
	while(fread(&s1,sizeof(s1),1,ptr1)==1)
	{
		printf("\t\t%d\t\t",s1.rollno);
		printf("%s\t\t",s1.name);
		for(i=0;i<5;i++)
		{
			if(i==0)
		        printf("%d\t\t",s1.marks[i]);
		    else if(i==1)
		        printf("%d\t\t",s1.marks[i]);
		    else if(i==2)
		        printf("%d\t\t",s1.marks[i]);
		    else if(i==3)
		        printf("%d\t\t",s1.marks[i]);
		    else if(i==4)
		        printf("%d\n",s1.marks[i]);
		}
		printf("\n");
	}
	fclose(ptr1);
	printf("\n%-62sPress any key to exit!"," ");
	getch();
	system("cls");
}


void std_list()
{
	int op,ch;
	FILE *ptr1;
	do{
		int i=1,k,j;
		ptr1 = fopen("Std_merit_list.bin","rb");
		printf("\n\n%-33s"," ");
		for(j=0;j<20;j++)
		    printf("-");
		printf("\n%-35sList of students:\n"," ");
		printf("%-33s"," ");
		for(j=0;j<20;j++)
		    printf("-");
		printf("\n\n%-32ss.no\tRollno\tName\n"," ");
	    while(fread(&s1,sizeof(s1),1,ptr1)==1)
	    {
		    printf("\n%-32s%d\t%d\t"," ",i,s1.rollno);
		    puts(s1.name);
		    i++;
	    }
	    printf("\n\n%-20sEnter the s.no. of the student whose details you wanna access: "," ");
	    scanf("%d",&op);
	    system("cls");
	    if(op>(i-1))
	    {
	    	printf("\n\n%-40sError! Please try again!\n\n%-40sPress any key to exit!"," "," ");
	    	getch();
	    	system("cls");
	    	continue;
		}
	    rewind(ptr1);
	    fseek(ptr1,sizeof(s1)*(op-1),SEEK_SET);
	    fread(&s1,sizeof(s1),1,ptr1);
	    printf("\n%-32s"," ");
		for(j=0;j<20;j++)
		    printf("-");
	    printf("\n%-34sStudent details:\n"," ");
	    printf("%-32s"," ");
	    for(j=0;j<20;j++)
		    printf("-");
	    printf("\n\n%-30sRoll no of the student: %d\n"," ",s1.rollno);
	    printf("\n\n%-30sName of the student: %s\n"," ",s1.name);
		printf("\n\n%-30sEngineering Mathematics: %d\n"," ",s1.marks[0]);
		printf("\n\n%-30sBasic Electrical Engineering: %d\n"," ",s1.marks[1]);
		printf("\n\n%-30sEngineering Chemistry: %d\n"," ",s1.marks[2]);
		printf("\n\n%-30sProgramming for Problem Solving: %d\n"," ",s1.marks[3]);
		printf("\n\n%-30sEngineering Graphics: %d\n"," ",s1.marks[4]);
		k = s1.rollno;
		fclose(ptr1);
	    merit_position(k);
	    printf("\n\n%-20sDo you want to access another student data?(yes=1/no=0) "," ");
	    scanf("%d",&ch);
	    system("cls");
	    if(ch==0)
	        break;
	}while(1);
}


void merit_list()
{
	int op,ch,j;
	while(1)
	{
		printf("\nList of subjects:\n");
		printf("\n\n1.Engineering Mathematics");
		printf("\n\n2.Basic Electrical Engineering");
		printf("\n\n3.Engineering chemistry");
		printf("\n\n4.Programming for problem solving");
		printf("\n\n5.Engineering graphics\n\n");
	    printf("Select the subject to view merit list: ");
	    scanf("%d",&op);
	    system("cls");
	    if(op>0&&op<6)
	    {
	        if(op==1)
	        {
	            printf("\nMaths merit list:\n");
		        printf("\n\nMerit\t\tName\t\t\tRollno\t\tMath\n");
		        printf("Position\t\t\t\t\t\tMarks\n\n");
	        }
	        else if(op==2)
	        {
	            printf("\nBEE merit list:\n");
		        printf("\n\nMerit\t\tName\t\t\tRollno\t\tBEE\n");
		        printf("Position\t\t\t\t\t\tMarks\n\n");
	        }
	        else if(op==3)
	        {
	            printf("\nChemistry merit list:\n");
		        printf("\n\nMerit\t\tName\t\t\tRollno\t\tChem\n");
		        printf("Position\t\t\t\t\t\tMarks\n\n");
	        }
	        else if(op==4)
	        {
	            printf("\nPPS merit list:\n");
                printf("\n\nMerit\t\tName\t\t\tRollno\t\tPPS\n");
		        printf("Position\t\t\t\t\t\tMarks\n\n"," ");
	        }
	        else
	        {
	            printf("\nEG merit list:\n");
		        printf("\n\nMerit\t\tName\t\t\tRollno\t\tEG\n");
		        printf("Position\t\t\t\t\t\tMarks\n\n");
	        }
            sorting(op);
        }
        else
        {
        	system("cls");
        	printf("\n\nThe choice is not included in the menu!\n\n");
        }
        printf("\n\nDo you want to view merit list of another subject?(yes=1/no=0) ");
        scanf("%d",&ch);
        system("cls");
        if(ch==0)
            break;
    }
}
