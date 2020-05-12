#include <stdio.h>

#include <stdlib.h>

int main()

{

int months[12] = {31 , 28, 31, 30, 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};

int m,d,x,days = 0; //m-месяц который вводим с клавиатуры и d - день.

scanf("%d %d" , &m , &d);

x = months[m-1] - d; // остаток дней месяца, который мы ввели

for (int i = m; i < 12; i++){

days = months[i] + days;//суммируются дни со следующего месяца

}

days += x;//прибавляем остаток

printf("%d" , days);

return 0;

}
