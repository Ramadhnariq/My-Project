#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_relasi.h"
#include "list_child.h"
#include "list_parent.h"

#include <iostream>
#include <stdio.h>
#include <unistd.h>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_child child;
    address_parent parent;
};

struct List_relasi{
    address_relasi first;
};

void createListRelasi(List_relasi &L);
address_relasi alokasiRelasi(address_parent P, address_child C);
void dealokasiRelasi(address_relasi P);
void insertFirstRelasi(List_relasi &L, address_relasi P);
void insertLastRelasi(List_relasi& L, address_relasi P);
void insertAfterRelasi(address_relasi &Prec, address_relasi P);
void printInfoRelasi(List_relasi L);
address_relasi findElmRelasi(List_relasi L, address_parent P, address_child C);

void program(List_parent& LP, List_child& LC, List_relasi& LR);

#endif // LIST_RELASI_H_INCLUDED
