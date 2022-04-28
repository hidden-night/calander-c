#include <stdio.h>

const int n_months[]={31,28,31,30,31,30,31,31,30,31,30,31};

enum bool{false,true};

enum bool leap_year(int year)
{
	if (year%400==0)
		return true;
	else if (year%100==0)
		return false;
	else if (year%4==0)
		return true;
	else
		return false;
}

int get_odd_days(int month,int year)
{
	int years=year%400-1;
	int odd_days=(years/4-years/100)*2+(years-(years/4-years/100));
	for(int months=0;months<month-1;months++)
	{
		odd_days+=n_months[months];
		if(months==2 && leap_year(year))
			odd_days+=1;
	}
	odd_days+=1;
	return odd_days%7;
}

void print_calander(int month,int year)
{
	int odd_days=get_odd_days(month,year);
	int date=1;
	printf("\033[1;4mSu Mo Tu We Th Fr Sa\033[0m\n");
	for(int blank=0;blank<odd_days;blank++)
		printf("   ");
	for (int i=odd_days;i<7;i++)
	{
		if (i!=odd_days)
			printf("  %d",date);
		else
			printf(" %d",date);
		date++;
	}
	printf("\n");
	int month_days;
	if (leap_year(year) && month==1)
		month_days=29;
	else month_days=n_months[month-1];
	while (date<month_days+1)
	{
		int week=0;
		while (date<month_days+1 &&week<7)
		{
			if(week>0)
				printf(" ");
			if(date<10)
				printf(" %d",date);
			else
				printf("%d",date);
			date++;
			week++;
		}
		printf("\n");
	}
}

enum bool valid(int month,int year)
{
	if (year<1 || month<1 || month>12)
		return false;
	else
		return true;
}

int main(void)
{
	int month,year;
	char seperator;
	printf("Enter month and year(month/year):");
	scanf("%d%c%d",&month,&seperator,&year);
	if (valid(month,year))
		print_calander(month,year);
	else
		printf("Invalid input!\n");
	return 0;
}
