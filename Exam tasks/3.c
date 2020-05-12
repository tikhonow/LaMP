//сразу извиняюсь, написано на отъебись

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_WORLD 300

//элемент списка
typedef struct lNode {
    char world[MAX_LEN_WORLD];
    int count;
    struct lNode *next;
} lNode;

typedef struct list {
    struct lNode *head;
    struct lNode *tail;
} List;

//если 2 строки равы - 1, иначе 0
int equal(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return 0;
        i++;
    }
    if (s1[i] != s2[i])
        return 0;

    return 1;
}

//добавляет новое слово в конец списка
void push(const char *world, List *list) {
    //на всякий случай, чтобы не было ошибки
    if (list == NULL)
        return;

    lNode *buff = (lNode *) malloc(sizeof(lNode));

    //копироване слова
    strcpy(buff->world, world);
    buff->count = 1;
    buff->next = NULL;

    //если список пуст
    if (list->tail == NULL) {
        list->head = buff;
        list->tail = buff;

    } else {
        //последни элемент связываем с новым
        list->tail->next = buff;
        list->tail = buff;
    }
}

//если слово есть в списке - вернет указатель на структуру, иначе - NULL
lNode *find(const char *world, List *list) {
    //на всякий случай, чтобы не было ошибки
    if (list == NULL)
        return NULL;

    lNode *buff = list->head;
    //пока не дошли до конца списка или не встретили нужное слово
    while (buff != NULL && !equal(buff->world, world))
        buff = buff->next;

    return buff;
}

//меняет местами 2 элемента массива
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//пузырек с флажком
void sort(int *a, int n) {
    int flag;
    for (int i = 0; i < n; i++) {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                flag = 1;
                swap(&a[j], &a[j + 1]);
            }
        }

        if (flag == 0)
            return;
    }
}

//полностью удаляет список
void clear(List *list) {
    if (list == NULL)
        return;

    lNode *buff = list->head;
    while (buff != NULL) {
        list->head = list->head->next;
        free(buff);
        buff = list->head;
    }
}



int main() {
    FILE *fin, *fout;
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
    List list = {.head = NULL, .tail = NULL};

    lNode *buff;
    char world[MAX_LEN_WORLD];
    //пока не дошли до конца файла
    while (!feof(fin)) {
        fscanf(fin, "%s", world);
        //на всякий случай ставим последним символ завершения строки
        world[MAX_LEN_WORLD - 1] = '\0';

        buff = find(world, &list);

        //если такое слово уже встречалось - увеличиваем счетчик, иначе добавляем слово в список
        if (buff == NULL)
            push(world, &list);
        else
            buff->count++;
    }

    //высчитывааем количество элементов в списке
    buff = list.head;
    int count = 0;
    while (buff != NULL) {
        count++;
        buff = buff->next;
    }

    //заполняем массив с повторениями слов и сортируем его
    int arr[count];
    buff = list.head;
    for (int i = 0; buff != NULL; i++, buff = buff->next)
        arr[i] = buff->count;
    sort(arr, count);

    //для каждого числа находим все слова которые встречаются такоетакое же количество раз
    int last = -1;
    for (int i = 0; i < count; i++) {
        if (arr[i] != last) {
            buff = list.head;
            while (buff != NULL) {
                if (arr[i] == buff->count)
                    fprintf(fout, "%d  %s\n", arr[i], buff->world);
                buff = buff->next;
            }
        }
        last = arr[i];
    }

    clear(&list);

    fclose(fin);
    fclose(fout);
    return 0;
}

