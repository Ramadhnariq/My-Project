#include "list_parent.h"

void createListParent(List_parent &L)
{
    first(L) = NULL;
}

address_parent alokasiParent(infotype_parent x)
{
    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertFirstParent(List_parent &L, address_parent P)
{
    address_parent Q;
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

void insertAfterParent(List_parent &L, address_parent Prec, address_parent P)
{
    if(next(Prec) == first(L))
    {
        insertLastParent(L, P);
    }
    else
    {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void insertLastParent(List_parent &L, address_parent P)
{
    address_parent Q;
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

address_parent deleteFirstParent(List_parent &L)
{
    address_parent P = first(L);
    address_parent Q = first(L);
    while(next(P) != first(L))
    {
        P = next(P);
    }
    next(P) = next(Q);
    first(L) = next(P);
    next(Q) = NULL;
    return Q;
}

address_parent deleteLastParent(List_parent &L)
{
    address_parent Q = first(L);
    if(next(first((L))) == first(L))
    {
        first(L) = NULL;
        return Q;
    }
    else
    {
        address_parent P = next(first(L));
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

address_parent deleteAfterParent(List_parent &L, address_parent Prec)
{
    address_parent Q = next(Prec);
    if(next(Q) == first(L))
    {
        Q = deleteLastParent(L);
        return Q;
    }
    else if(next(Prec) == first(L))
    {
        Q = deleteFirstParent(L);
        return Q;
    }
    else
    {
        next(Prec) = next(Q);
        next(Q) = NULL;
        return Q;
    }
}

void printInfoParent(List_parent L)
{
    address_parent P = first(L);
    int x = 1;
    if(first(L) != NULL) {
        do {
            cout << x << ". " << info(P) << endl;
            x += 1;
            P = next(P);
        } while(P != first(L));
    }
}

address_parent findElmParent(List_parent L, infotype_parent x)
{
    address_parent P = first(L);
    do {
        if(info(P) == x) {
            cout << "Nama ditemukan" << endl;
            return P;
        }
        P = next(P);
    } while(P != first(L));
    cout << "Nama tidak ditemukan" << endl;
    return NULL;
}

int jumlahParent(List_parent L)
{
    address_parent P = first(L);
    int x = 1;
    if(first(L) != NULL) {
        do {
            x += 1;
            P = next(P);
        } while(next(P) != first(L));
    }
    return x;
}
