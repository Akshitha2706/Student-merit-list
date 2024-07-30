#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	int rollno;
	char name[30];
	int marks[5];
}s1;

int compare(int c)
{
	int temp[10];
	int flag=0,i;
	int j=0;
	FILE *ptr1;
	ptr1 = fopen("Std_merit_list.bin","rb");
	while(fread(&s1,sizeof(s1),1,ptr1)==1)
	{
		temp[j]=s1.rollno;
		j++;
	}
	for(i=0;i<j;i++)
	{
		if(temp[i] == c)
		{
		    flag = 1;
		    break;
		}
	}
	fclose(ptr1);
	if(flag)
	{
	    printf("\nEntry of this roll number already exists. Please, Re-enter!\n");
	    return 1;
    }
	else
	    return 0;
}



void merit_position(int c)
{
	int i,j=0,k,temp,id[10],total[10];
	FILE *fp = fopen("Std_merit_list.bin","rb");
	while(fread(&s1,sizeof(s1),1,fp)==1)
	{
		temp=0;
		id[j] = s1.rollno;
		for(i=0;i<5;i++)
		    temp = temp+s1.marks[i];
		total[j] = temp;
		j++;
	} 
	for(i=0;i<(j-1);i++)
	{
		for(k=i+1;k<j;k++)
		{
		    if(total[i]<total[k])
		    {
			    temp = total[i];
			    total[i] = total[k];
			    total[k] = temp;
			
			    temp = id[i];
			    id[i] = id[k];
			    id[k] = temp;
		    }
		}
	}
	for(i=0;i<j;i++)
	{
		if(id[i] == c)
		    break;
	}
	fclose(fp);
	printf("\n\n%-30sOverall merit position of student: %d\n"," ",(i+1));
}



void sorting(int op)
{
	int i=0,j,k,a,temp,arr[10],id[10];
	char *std_name[1];
	FILE *fs = fopen("Std_merit_list.bin","rb");
	while(fread(&s1,sizeof(s1),1,fs)==1)
	{
		id[i] = s1.rollno;
		arr[i] = s1.marks[(op-1)];
		i++;
	} 
	for(j=0;j<(i-1);j++)
	{
		for(k=j+1;k<i;k++)
		{
		    if(arr[j]<arr[k])
		    {
			    temp = arr[j];
			    arr[j] = arr[k];
			    arr[k] = temp;
			
			    temp = id[j];
			    id[j] = id[k];
			    id[k] = temp;
		    }
		}
	}
	char *t = (char *)malloc(30*sizeof(char));
	for(j=0;j<i;j++)
	{
	    rewind(fs);
	    while(fread(&s1,sizeof(s1),1,fs)==1)
	    {
	    	a = s1.rollno;
	    	if(id[j] == a)
	    	{
	    		t = s1.name;
	    		break;
	    	}
		}
		std_name[1] = t;
	    printf("\n%d\t\t%s\t\t%d\t\t%d\n",j+1,std_name[1],id[j],arr[j]);
	}
	printf("\n");
	fclose(fs);
}
