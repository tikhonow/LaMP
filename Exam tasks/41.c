int main(){ 
	int year; 
	scanf("%d", &year); // вводим наш год 
		switch (year % 10) // при разных остатках ответы разные, 		{ 
		case 10 ... 15: printf("%d лет", year); 
			break; 
		case 1: printf("%d год", year); 
			break; 
		case 0: printf("%d лет", year); 
			break; 
		case 5 ... 9: printf("%d лет", year); 
			break; 
		case 2 ... 4: printf("%d года", year); 
			break; 
	}

}
