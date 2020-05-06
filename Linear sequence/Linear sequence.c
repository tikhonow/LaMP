#include <stdlib.h>
#include <stdio.h>
#include "linear_sequence.h"

typedef struct ListNode {
    LSQ_BaseTypeT data;
    struct ListNode *prev, *next;
} Node;

typedef struct {
    LSQ_IntegerIndexT count;
    Node *head, *tail;
} Container;

typedef struct {
    Container *cont;
    Node *node;
} Iterator;

static Iterator *makeIter(LSQ_HandleT handle);
static Node *findElemByIndex(LSQ_HandleT handle, LSQ_IntegerIndexT index);
static Node *makeNode(Node *prev, Node *next, LSQ_BaseTypeT elem);

LSQ_HandleT LSQ_CreateSequence(void) {
    Container *cont = (Container *) malloc(sizeof(Container));
    if (cont == NULL) return LSQ_HandleInvalid;
    cont->count = 0;
    cont->head = (Node *) malloc(sizeof(Node));
    cont->tail = (Node *) malloc(sizeof(Node));
    if (cont->head == NULL || cont->tail == NULL) {
        free(cont->head);
        free(cont->tail);
        free(cont);
        return LSQ_HandleInvalid;
    }
    cont->head->prev = cont->head;
    cont->head->next = cont->tail;
    cont->tail->prev = cont->head;
    cont->tail->next = cont->tail;
    return cont;

}
void LSQ_DestroySequence(LSQ_HandleT handle) {
    Container *cont = (Container *) handle;
    if (cont == LSQ_HandleInvalid) return;
    while (cont->head != cont->tail) {
        Node *tmp = cont->head;
        cont->head = cont->head->next;
        free(tmp);
    }
    free(cont->tail);
    free(cont);
}
LSQ_IntegerIndexT LSQ_GetSize(LSQ_HandleT handle) {
    if (handle == LSQ_HandleInvalid) return 0;
    return ((Container *) handle)->count;

}
int LSQ_IsIteratorDereferencable(LSQ_IteratorT iterator) {
    if (iterator == NULL) return 0;
    Iterator *iter = (Iterator *) iterator;
    return iter->node != iter->cont->head && iter->node != iter->cont->tail;
}
int LSQ_IsIteratorPastRear(LSQ_IteratorT iterator) {
    if (iterator == NULL) return 0;
    Iterator *iter = (Iterator *) iterator;
    return iter->node == iter->cont->tail;
}
int LSQ_IsIteratorBeforeFirst(LSQ_IteratorT iterator) {
    if (iterator == NULL) return 0;
    Iterator *iter = (Iterator *) iterator;
    return iter->node == iter->cont->head;
}
LSQ_BaseTypeT* LSQ_DereferenceIterator(LSQ_IteratorT iterator) {
    if (iterator == NULL) return NULL;
    return &(((Iterator *) iterator)->node->data);
}
static Iterator *makeIter(LSQ_HandleT handle) {
    if (handle == LSQ_HandleInvalid) return NULL;
    Iterator *iter = (Iterator *) malloc(sizeof(Iterator));
    if (iter == NULL) return NULL;
    iter->cont = (Container *) handle;
    return iter;
}
static Node *findElemByIndex(LSQ_HandleT handle, LSQ_IntegerIndexT index) {
    Container *cont = (Container *) handle;
    LSQ_IntegerIndexT i;
    Node *tmp;
    if (index > cont->count / 2) {
        tmp = cont->tail;
        for (i = cont->count; i > index; i--) tmp = tmp->prev;
    } else {
        tmp = cont->head;
        for (i = -1; i < index; i++) tmp = tmp->next;
    }
    return tmp;
}
LSQ_IteratorT LSQ_GetElementByIndex(LSQ_HandleT handle, LSQ_IntegerIndexT index) {
    Iterator *iter = makeIter(handle);
    if (iter == NULL) return NULL;
    iter->node = findElemByIndex(handle, index);
    return iter;
}
LSQ_IteratorT LSQ_GetFrontElement(LSQ_HandleT handle) {
    Iterator *iter = makeIter(handle);
    if (iter == NULL) return NULL;
    iter->node = findElemByIndex(handle, 0);
    return iter;
}
LSQ_IteratorT LSQ_GetPastRearElement(LSQ_HandleT handle) {
    Iterator *iter = makeIter(handle);
    if (iter == NULL) return NULL;
    iter->node = findElemByIndex(handle, ((Container *) handle)->count);
    return iter;
}
void LSQ_DestroyIterator(LSQ_IteratorT iterator) {
    free(iterator);
}
void LSQ_AdvanceOneElement(LSQ_IteratorT iterator) {
    LSQ_ShiftPosition(iterator, 1);
}
void LSQ_RewindOneElement(LSQ_IteratorT iterator) {
    LSQ_ShiftPosition(iterator, -1);
}
void LSQ_ShiftPosition(LSQ_IteratorT iterator, LSQ_IntegerIndexT shift) {
    if (iterator == NULL) return;
    Iterator *iter = (Iterator *) iterator;
    LSQ_IntegerIndexT i;
    for (i = 0; i < abs(shift); i++) iter->node = shift > 0 ? iter->node->next : iter->node->prev;
}
void LSQ_SetPosition(LSQ_IteratorT iterator, LSQ_IntegerIndexT pos) {
    if (iterator == NULL) return;
    Iterator *iter = (Iterator *) iterator;
    iter->node = findElemByIndex(iter->cont, pos);
}
void LSQ_InsertFrontElement(LSQ_HandleT handle, LSQ_BaseTypeT element) {
    LSQ_IteratorT iterator = LSQ_GetFrontElement(handle);
    LSQ_InsertElementBeforeGiven(iterator, element);
    LSQ_DestroyIterator(iterator);
}
void LSQ_InsertRearElement(LSQ_HandleT handle, LSQ_BaseTypeT element) {
    LSQ_IteratorT iterator = LSQ_GetPastRearElement(handle);
    LSQ_InsertElementBeforeGiven(iterator, element);
    LSQ_DestroyIterator(iterator);
}
static Node *makeNode(Node *prev, Node *next, LSQ_BaseTypeT elem) {
    Node *tmp = (Node *) malloc(sizeof(Node));
    if (tmp == NULL) return NULL;
    tmp->prev = prev;
    tmp->next = next;
    tmp->data = elem;
    return tmp;
}
void LSQ_InsertElementBeforeGiven(LSQ_IteratorT iterator, LSQ_BaseTypeT newElement) {
    if (iterator == NULL) return;
    if (LSQ_IsIteratorBeforeFirst(iterator)) return;
    Iterator *iter = (Iterator *) iterator;
    Node *tmp = makeNode(iter->node->prev, iter->node, newElement);
    if (tmp == NULL) return;
    iter->node->prev->next = tmp;
    iter->node->prev = tmp;
    iter->cont->count++;
    iter->node = tmp;
}
void LSQ_DeleteFrontElement(LSQ_HandleT handle) {
    LSQ_IteratorT iterator = LSQ_GetFrontElement(handle);
    LSQ_DeleteGivenElement(iterator);
    LSQ_DestroyIterator(iterator);

}
void LSQ_DeleteRearElement(LSQ_HandleT handle) {
    LSQ_IteratorT iterator = LSQ_GetPastRearElement(handle);
    LSQ_RewindOneElement(iterator);
    LSQ_DeleteGivenElement(iterator);
    LSQ_DestroyIterator(iterator);

}
void LSQ_DeleteGivenElement(LSQ_IteratorT iterator) {
    if (iterator == NULL) return;
    if (!LSQ_IsIteratorDereferencable(iterator)) return;
    Iterator *iter = (Iterator *) iterator;
    Node *tmp = iter->node->prev->next = iter->node->next;
    iter->node->next->prev = iter->node->prev;
    free(iter->node);
    iter->cont->count--;
    iter->node = tmp;

}