#include "list_child.h"

void createListChild(List_child &L) {
    first(L) = NULL;
}

address_child alokasiChild(infotype_child x)
{
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertFirstChild(List_child &L, address_child P)
{
    address_child Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertLastChild(List_child &L, address_child P)
{
    address_child Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
    }
}

void insertAfterChild(List_child &L, address_child &Prec, address_child P)
{
    if(next(Prec) == first(L))
    {
        insertLastChild(L,P);
    }
    else
    {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

address_child deleteFirstChild(List_child &L)
{
    address_child P = first(L);
    address_child Q = first(L);
    while(next(P) != first(L))
    {
        P = next(P);
    }
    next(P) = next(Q);
    first(L) = next(P);
    next(Q) = NULL;
    return Q;
}

address_child deleteLastChild(List_child &L)
{
    address_child Q = first(L);
    if(next(first((L))) == first(L))
    {
        first(L) = NULL;
        return Q;
    }
    else
    {
        address_child P = next(first(L));
        while(next(P) != first(L))
        {
            Q = P;
            P = next(P);
        }
        next(Q) = first(L);
        next(P) = NULL;
        return P;
    }
}

address_child deleteAfterChild(List_child &L, address_child Prec)
{
    address_child Q = next(Prec);
    if(next(Q) == first(L))
    {
        Q = deleteLastChild(L);
        return Q;
    }
    else if(next(Prec) == first(L))
    {
        Q = deleteFirstChild(L);
        return Q;
    }
    else
    {
        next(Prec) = next(Q);
        next(Q) = NULL;
        return Q;
    }
}

void printInfoChild(List_child L)
{
    address_child P = first(L);
    int x = 1;
    if(first(L)!=NULL) {
        do {
            cout << x << ". " << info(P) << endl;
            x += 1;
            P = next(P);
        } while(P != first(L));
    }
}

address_child findElmChild(List_child L, infotype_child x)
{
    address_child P = first(L);
    while(P != NULL) {
        if(info(P)==x) {
            cout << "Child ditemukan" << endl;
            return P;
        }
        P = next(P);
    }
    cout << "Child tidak ditemukan" << endl;
    return NULL;
}

int jumlahChild(List_child L)
{
    address_child P = first(L);
    int x = 0;
    if(first(L)!=NULL) {
        do {
            x += 1;
            P = next(P);
        } while(P != first(L));
    }
    return x;
}
