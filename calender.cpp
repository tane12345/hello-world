#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char week[7][50],month[12][50],m[50];
	int k=1,i,j,a,x[11],y[11],sumx=0,sumy=0,b,c[6][7],d;
	for(i=0;i<11;i++)
	{
		if(i==3||i==5||i==8||i==10)
		{
		y[i]=2;x[i]=0;}
		else if(i==0||i==2||i==4||i==6||i==7||i==9)
		{
		x[i]=3;y[i]=0;}
		else
		{
			x[i]=0;
			y[i]=0;
		}
	}
	strcpy(month[0],"January");
	strcpy(month[1],"Feburay");
	strcpy(month[2],"March");
	strcpy(month[3],"April");
	strcpy(month[4],"May");
	strcpy(month[5],"June");
	strcpy(month[6],"July");
	strcpy(month[7],"August");
	strcpy(month[8],"September");
	strcpy(month[9],"October");
	strcpy(month[10],"November");
	strcpy(month[11],"December");
	strcpy(week[1],"Mon");
	strcpy(week[2],"Tue");
	strcpy(week[3],"Wed");
	strcpy(week[4],"Thur");
	strcpy(week[5],"Fri");
	strcpy(week[6],"Sat");
	strcpy(week[0],"Sun");
	printf("Enter the month=\t");
	gets(m);
	printf("Enter the year=\t");
	scanf("%d",&d);
	d=d-1969;
	for(i=0;i<12;i++)
	{
		if(strcmp(m,month[i])==0)
		a=i;
	}
	for(i=0;i<a;i++)
	{
		sumx=sumx+x[i];
		sumy=sumy+y[i];
		//printf("x[%d]=%d\n",i,x[i]);
	}
	if (d%4==3&&a>1)
	{
	b=(3+(d/4)+d+sumx+sumy)%7+1;
	if(b==7)
	b=1;
	}
	else
	b=(3+(d/4)+d+sumx+sumy)%7;
	//puts(week[b]);
	//printf("\n%d\n%d",a,sumy);
	for(i=0;i<6;i++)
	{
		for(j=0;j<7;j++)
		{
			if(i==0&&j<b)
			c[i][j]=0;
			else if(i==0&&j==b)
			c[i][j]=k++;
			else 
			{
				if (a==0||a==2||a==4||a==6||a==7||a==9||a==11)
				{
					if(k<32)
					c[i][j]=k++;
					else
					c[i][j]=0;
				}	
				else if(a==1&&d%4!=0)
				{
					if(k<30)
					c[i][j]=k++;
					else
					c[i][j]=0;
				}
				else if(a==1&&d%4==0)
				{
					if(k<29)
					c[i][j]=k++;
					else
					c[i][j]=0;
				}
				else
				{
					if(k<31)
					c[i][j]=k++;
					else
					c[i][j]=0;
				}
			}
			
		}
	}
	for(i=0;i<7;i++)
	{
		printf("%s\t",week[i]);
	}
	printf("\n");
	for(i=0;i<6;i++)
	{
		for(j=0;j<7;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	//printf("\n\n\n\n%d\n%d",d%4,b);
	getch();
	return 0;
}
