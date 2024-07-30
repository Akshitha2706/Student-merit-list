#include<stdio.h>
#include<windows.h>
#include"meritlist1.h"

int main()
{
	int ch,i,j,a;
	FILE *fp;
	fp = fopen("Std_merit_list.bin","rb");
	if(fp==NULL)
	{
		printf("Cannot open the file!");
		return 1;
	}
	fclose(fp);
	do{
		printf("\n\n\n\n\n%-61s"," ");
		for(i=0;i<30;i++)
		    printf("-");
		printf("\n%-74sMENU\n"," ");
		printf("%-61s"," ");
	    for(i=0;i<30;i++)
		    printf("-");
		printf("\n\n%-62s1.Update student details"," ");
		printf("\n\n%-62s2.Display all student details"," ");
		printf("\n\n%-62s3.Show student list"," ");
		printf("\n\n%-62s4.Merit list"," ");
		printf("\n\n%-62s5.Exit"," ");
	    printf("\n\n%-62sEnter your choice: "," ");
	    scanf("%d",&ch);
	    system("cls");
	    switch(ch)
	    {
	    	case 1: do{
	                    a=update_std_details();
	                }while(a==1);
	    	        break;
	    	case 2: printf("\n\n\n\n");
			        printf("%-45s"," ");
	                for(i=0;i<50;i++)
		                printf("-");
			        printf("\n%-62sSTUDENT DETAILS: \n"," ");
			        printf("%-45s"," ");
	                for(i=0;i<50;i++)
		                printf("-");
		            printf("\n");
	    	        read_std();
	    	        break;
	    	case 3: std_list();
	    	        break;
	    	case 4: merit_list();
	    	        break;
	    	case 5: printf("EXITING.........");
	    	        return 1;
	    	default: printf("\n\n\n%-45sInvalid input. Please, Re-enter!\n"," ");
	    	         printf("\n\n%-45sPress any key to exit!"," ");
	    	         getch();
	    	         system("cls");
		}
	}while(1);
	return 0;
}
