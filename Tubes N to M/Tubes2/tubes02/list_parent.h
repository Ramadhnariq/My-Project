#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

typedef string infotype_parent;
typedef struct elmlist_parent *address_parent;

struct elmlist_parent {
    infotype_parent info;
    address_parent next;
};

struct List_parent {
    address_parent first;
};

void createListParent(List_parent &L);
address_parent alokasiParent(infotype_parent x);
void insertFirstParent(List_parent &L, address_parent P);
void insertAfterParent(List_parent &L, address_parent Prec, address_parent P);
void insertLastParent(List_parent &L, address_parent P);
address_parent deleteFirstParent(List_parent &L);
address_parent deleteLastParent(List_parent &L);
address_parent deleteAfterParent(List_parent &L, address_parent Prec);
void printInfoParent(List_parent L);
address_parent findElmParent(List_parent L, infotype_parent x);

int jumlahParent(List_parent L);

#endif // LIST_PARENT_H_INCLUDED
