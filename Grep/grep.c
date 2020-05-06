#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//вспомогательная функция паматетра -m 
int isnumber(char *num)
{
	int t = 0, len = (int)strlen(num);
	for (int i = 0; i < len; i++)
	{
		t += (isdigit(num[i])) ? 1 : 0;
	}
	return (t == len || (num[0] == '-' && len - 1 == t)) ? 1 : 0;
}

// поиск индекса паттерна
int searchPattern(char **argv)
{
	for (int i = 1; argv[i] != NULL; i++)
	{
		if (strcmp(argv[i-1], "-m") == 0 && isnumber(argv[i]) == 0)
		{
			printf("После параметра -m должно следовать число\n");
			exit(1);
		}
			if (argv[i][0] != '-' && strcmp(argv[i-1], "-m") != 0)
				return i;
	}
}

// нахождение кол-во файлов
int countFiles(char **argv, int i_pattern)
{
	int count = 0;
	for (i_pattern; argv[i_pattern] != NULL; i_pattern++)
	{
		count++;
	}
	return count;
}

// поиск -v
int vOption(char **argv, int index_pattern)
{
	for (int i = 1; i < index_pattern; i++)
	{
		if (strcmp(argv[i], "-v") == 0)
		{
			return 0;
		}
	}
	return 1;
}

// предел поиска(-m NUM)
int mOption(char **argv, int index_pattern)
{
	for (int i = 1; i < index_pattern; i++)
	{
		if (strcmp(argv[i-1], "-m") == 0 && isnumber(argv[i]) == 1)
		{
			if (atoi(argv[i]) < 0)
			{
				return 0;
			} else {
				return atoi(argv[i]);
			}
		}
	}
	return -1;
}

// поиск -h -H
int hHOption(char **argv, int index_pattern, int c_files)
{
	int name_status = 0;
	if (c_files > 1)
		name_status = 1;

	for (int k = 1; k < index_pattern; k++)
	{
		if (!strcmp(argv[k], "-H"))
		{
			name_status = 1;
		}
		if (!strcmp(argv[k], "-h"))
		{
			name_status = 0;
		}
	}
	return name_status;
}

// поиск -c
int cOption(char **argv, int index_pattern)
{
	for (int i = 1; i < index_pattern; i++)
	{
		if (strcmp(argv[i], "-c") == 0)
		{
			return 1;
		}
	}
	return 0;
}
// поиск
void search(FILE *file, char *pattern, int v_param, char **argv, int index_file, int count_files, int c, int hH, int m) 
{
	char str[1000];
	int count = 0;
	while (fgets(str, 1000, file))
	{
		str[strlen(str)-1] = (str[strlen(str)-1] != '\n') ? '\n' : '\n';
		if ((strstr(str, pattern) && v_param == 1  || !strstr(str, pattern) && v_param == 0) && (m == -1 || m > count))
		{	
			if (index_file == 0){
				argv[index_file]= "standart input" ;
			}
			count++;
			if (c == 0){	
				if (hH == 1){
					printf("%s%s%s",argv[index_file],":"," ");
					printf("%s", str);
				}
				else 
					printf("%s", str);
			}
		}
	}
		if (c == 1){
			if (hH == 1) {
				printf("%s%s%s",argv[index_file],":"," ");
						}
		printf("%d\n", count);}
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("Введите: ./grep [OPTION]... PATTERN [FILE]...\n");
		return 0;
	}
	int index_pattern = searchPattern(argv);
	int count_files   = countFiles(argv, index_pattern + 1);
	int v_option      = vOption(argv, index_pattern);
	int c_option      = cOption(argv, index_pattern);
	int hH_option     = hHOption(argv, index_pattern, count_files );
	int m_option	  = mOption(argv, index_pattern);

	if (count_files == 0)
	{	int s_input = 0;
		FILE *file = stdin;
		search(file, argv[index_pattern], v_option, argv, s_input , count_files , c_option, hH_option, m_option);
	}
	for (int i = 0; i < count_files; i++)
	{	int index_file = index_pattern + 1 +i;
		FILE *file = fopen(argv[index_file], "rt");
		if (file == NULL)
		{
			printf("Файла %s не существует!\n", argv[index_pattern + 1 + i]);}
		else
		{
		search(file, argv[index_pattern], v_option, argv, index_file,count_files, c_option, hH_option, m_option);}
	}
}