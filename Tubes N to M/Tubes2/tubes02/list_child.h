#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

typedef string infotype_child;
typedef struct elmlist_child *address_child;

struct elmlist_child{
    infotype_child info;
    address_child next;
};

struct List_child{
    address_child first;
};

void createListChild(List_child &L);
address_child alokasiChild(infotype_child x);
void insertFirstChild(List_child &L, address_child P);
void insertLastChild(List_child &L, address_child P);
void insertAfterChild(List_child &L, address_child &Prec, address_child P);
address_child deleteFirstChild(List_child &L);
address_child deleteLastChild(List_child &L);
address_child deleteAfterChild(List_child &L, address_child Prec);
void printInfoChild(List_child L);
address_child findElmChild(List_child L, infotype_child x);

int jumlahChild(List_child L);

#endif // LIST_CHILD_H_INCLUDED
