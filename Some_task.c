#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <time.h> 
#include <string.h> 

const char*months[] = { "January","February","March","April","May","June","July","August","September","October","November","December", 
"01","02","03","04","05","06","07","08","09","10","11","12", 
"1","2","3","4","5","6","7", "8", "9", "10", "11", "12", 
"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december", 
"Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec", 
"jan","feb","mar","apr","may","june","july","aug","sept","oct","nov","dec" }; //Массив с месяцами, записанными в различной форме
Я
main() 
{ 
	time_t timer; 	
	double seconds; 
	int day = 0; 
	int year = 0; 	
	struct tm date = { 0 }; 
	printf("Enter month \n"); 
	char* str = malloc(100 * sizeof(char)); 
	fgets(str, 100, stdin); 
	str = strtok(str, "\n"); 
	int value = 0; 
	for (int i = 0; i < 72; i++) 
	{ 
		if (!strcmp(months[i], str)) 
		{ 
			if (i % 12 == 0) 
			{ 
				value = 12; 
			} 
			else 
			{ 
				value = i%12+1; 
			} 
		printf("%d", value); 
		break; 
		} 
	} 
	if (value == 0) 
	{ 
		printf("Wrong input data\n"); //проверка на правильность ввода
	} 
	printf("Enter year\n"); 
	scanf("%d", &year); 
	if (year > 2017 || year < 1900) 
	{ 
		printf("Wrong input data\n"); //проверка на правильность ввода
	} 
	printf("Enter day\n"); 
	scanf("%d", &day); 
	if (day > 31 || day<1) 
	{ 
		printf("Wrong input data\n"); //проверка на правильность ввода
	} 
	date.tm_mon = value-1; 
	date.tm_year = year; 
	date.tm_year -= 1900; 
	date.tm_mday = day; 
	struct tm beginning = { 0 }; 
	beginning.tm_year = year-1900; 
	timer = _mkgmtime(&date); 
	time_t curTimer = {0}; 
	curTimer= _mkgmtime(&beginning); 
	seconds = difftime(timer, curTimer); 
	printf("%.f Days\n ", seconds/(3600*24)); 	
	return 0; 
}