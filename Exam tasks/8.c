#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define YEAR 365

int main(){
setlocale(LC_ALL, "Rus");

int day, month, error_counter = 0;

printf("Введите номер месяца:\n");
scanf("%d",&month);

printf("Введите день:\n");
scanf("%d", &day);
if (day > 31){
    error_counter = 0;
}

switch(month){
        case 1:
            month = 365 - day;
            break;
        case 2:
            month = YEAR - 31 - day;
            break;
        case 3:
            month = YEAR - 59 - day;
            break;
        case 4:
            month = YEAR - 90 - day;
            break;
        case 5:
            month = YEAR - 120 - day;
            break;
        case 6:
            month = YEAR - 151 - day;
            break;
        case 7:
            month = YEAR - 181 -day;
            break;
        case 8:
            month = YEAR - 212 - day;
            break;
        case 9:
            month = YEAR - 243 - day;
            break;
        case 10:
            month = YEAR - 273 - day;
            break;
        case 11:
            month = YEAR - 304 - day;
            break;
        case 12:
            month = YEAR - 334 - day;
            break;
        default  :
            printf("Введены неверные данные \n");
            error_counter = 1;
            break;

 }
 if (error_counter == 0){
        printf("До Нового года осталось ");
        printf("%d%c", month, ' ');
        printf("дней.\n");
        }
}
