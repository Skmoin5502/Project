#include<stdio.h>
#include<stdlib.h>
void insert();
void search();
void display();
void update();
void Delete();
	int r,f;
	char n[34],c[10];
int main()
{
	int ch;
	
	while(1)
	{
			printf("1.INSERT\n2.Display\n3.Search\n4.update\n5.delete\nEXIT\n");
	
	scanf("%d",&ch);
	if(ch==1)
	{
		insert();
	}
	else if(ch==2)
	{
		display();
	}
	else if(ch==3)
	{
		search();
	}
	else if(ch==4)
	{
		update();
	}
	else if(ch==5)
	{
		Delete();
	}
	else
	{
			printf("program ended succesfully\n");
		exit(0);
	
	}
	}

	return 0;
	
}
//===========INSERT===============
void insert()
{
	FILE *p;
	p=fopen("STUDENT_REC.txt","a");

	printf("Enter Roll no\n");
	scanf("%d",&r);
	printf("Enter name\n");
	scanf("%s",&n);
	printf("Enter course\n");
	scanf("%s",&c);
	printf("Enter fees\n");
	scanf("%d",&f);
	fprintf(p,"%d\t%s\t%s\t%d\n",r,n,c,f);
	printf("data saved\n");
	fclose(p);
}
//=================DISPLAY====================
void display()
{
	FILE *p;
	p=fopen("STUDENT_REC.txt","r");
	
	while(fscanf(p,"%d%s%s%d",&r,&n,&c,&f)!=EOF)
	{
			printf("%d\t%s\t%s\t%d\n",r,n,c,f);
	}

}
//===============SEARCH===========
void search()
{
	FILE *p;
	int r1;
	p=fopen("STUDENT_REC.txt","r");
	printf("Enter your roll no\n");
	scanf("%d",&r1);
	
	
		while(fscanf(p,"%d%s%s%d",&r,&n,&c,&f)!=EOF)
	{
		   if(r1==r)
		   {
		   		printf("%d\t%s\t%s\t%d\n",r,n,c,f);
		   }
		
	}
}
//=========UPDATE==================

void update()
{
	FILE *p,*t;
	p=fopen("STUDENT_REC.txt","r");
	t=fopen("temp.txt","a");
	int r1;
	printf("Enter your roll no\n");
	scanf("%d",&r1);
	while(fscanf(p,"%d%s%s%d",&r,&n,&c,&f)!=EOF)
	{
		   if(r1==r)
		   {
		   	printf("Enter ur updated name");
		   	scanf("%s",&n);
		   	 	fprintf(t,"%d\t%s\t%s\t%d\n",r,n,c,f);
		   	 	printf("DATA UPDATED");
		   }
		   else
		   {
		   	fprintf(t,"%d\t%s\t%s\t%d\n",r,n,c,f);
		   }
}

fclose(p);
fclose(t);
remove("STUDENT_REC.txt");
rename("temp.txt","STUDENT_REC.txt");
printf("file deleted and removed");
}
//============DELETE
void Delete()
{
		FILE *p,*t;
	p=fopen("STUDENT_REC.txt","r");
	t=fopen("temp.txt","a");
	int r1;
	printf("Enter your roll no\n");
	scanf("%d",&r1);
	while(fscanf(p,"%d%s%s%d",&r,&n,&c,&f)!=EOF)
	{
		   if(r1==r)
		   {
		   
		   	 	printf("DATA DELETED");
		   }
		   else
		   {
		   	fprintf(t,"%d\t%s\t%s\t%d\n",r,n,c,f);
		   }
}

fclose(p);
fclose(t);
remove("STUDENT_REC.txt");
rename("temp.txt","STUDENT_REC.txt");
printf("file deleted and removed");
}



