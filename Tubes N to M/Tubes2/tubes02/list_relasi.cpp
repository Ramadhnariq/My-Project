#include "list_relasi.h"

void createListRelasi(List_relasi &L)
{
    first(L) = NULL;
}

address_relasi alokasiRelasi(address_parent P, address_child C)
{
    address_relasi Q = new elmlist_relasi;
    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
    return Q;
}

void insertFirstRelasi(List_relasi &L, address_relasi P)
{
    next(P) = first(L);
    first(L) = P;
}

void insertAfterRelasi(address_relasi &Prec, address_relasi P)
{
    next(P) = next(Prec);
    next(Prec) = P;
}

void printInfoRelasi(List_relasi L) {
    address_relasi P = first(L);
    while(P != NULL) {
        cout << info(parent(P)) << " bersaudara dengan " << info(child(P)) << endl;
        P = next(P);
    }
}

address_relasi findElmRelasi(List_relasi L, address_parent P, address_child C)
{
    address_relasi Q = first(L);
    while(Q != NULL) {
        if(parent(Q) == P && child(Q) == C) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

void program(List_parent& LP, List_child& LC, List_relasi& LR)
{
    address_child C, C2;
    address_parent P, P2;
    address_relasi R;
    int x;
    char a = 'y';
    string nama, nama2;

    cout << "======= Input Nama User =======" << endl << endl;
    cout << "Masukkan Jumlah User: ";
    cin >> x;
    for(int i = 1; i <= x; i++)
    {
        cout << "Masukkan nama: ";
        cin >> nama;
        P = alokasiParent(nama);
        insertLastParent(LP, P);
    }
    cout << "Input nama user selesai..." << endl;
    sleep(3);

    cout << endl << "=====================" << endl << endl;
    cout<<"List Nama"<<endl;
    printInfoParent(LP);
    sleep(5);
    cout << endl;

    cout << "======= Hapus Nama User =======" << endl << endl;
    cout << "Hapus nama user?(y/n) ";
    cin >> a;
    while(a == 'y')
    {
        cout << "1. Hapus User pertama" << endl;
        cout << "2. Hapus User Terakhir" << endl;
        cout << "3. Hapus User sesudah User yang dicari" << endl;
        cout << "Pilih: ";
        cin >> x;
        switch(x)
        {
        case 1:
            P = deleteFirstParent(LP);
            cout << "User " << info(P) << " telah dihapus." << endl;
            break;
        case 2:
            P = deleteLastParent(LP);
            cout << "User " << info(P) << " telah dihapus." << endl;
            break;
        case 3:
            do
            {
                cout << "Masukkan nama user: ";
                cin >> nama;
                P = findElmParent(LP,nama);
            }while(P == NULL);
            P2 = deleteAfterParent(LP,P);
            cout << "User " << info(P) << " telah dihapus." << endl;
        }
        cout << "Hapus nama user lagi?(y/n) ";
        cin >> a;
    }
    cout << "Hapus nama user selesai..." << endl;
    sleep(3);

    cout << endl << "=====================" << endl << endl;
    cout<<"List Nama"<<endl;
    printInfoParent(LP);
    sleep(5);
    cout << endl;

    cout << "======= Input Nama Saudara =======" << endl << endl;
    cout << "Masukkan Jumlah Orang: ";
    cin >> x;
    for(int i = 1; i <= x; i++)
    {
        cout << "Masukkan nama saudara: ";
        cin >> nama;
        C = alokasiChild(nama);
        insertLastChild(LC, C);
    }
    cout << "Input nama saudara selesai..." << endl;
    sleep(3);

    cout << endl << "=====================" << endl << endl;
    cout<<"List Nama Saudara"<<endl;
    printInfoChild(LC);
    sleep(5);
    cout << endl;

    cout << "======= Hapus Nama Saudara =======" << endl << endl;
    cout << "Hapus nama saudara?(y/n) ";
    cin >> a;
    while(a == 'y')
    {
        cout << "1. Hapus saudara pertama" << endl;
        cout << "2. Hapus saudara Terakhir" << endl;
        cout << "3. Hapus saudara sesudah saudara yang dicari" << endl;
        cout << "Pilih: ";
        cin >> x;
        switch(x)
        {
        case 1:
            C = deleteFirstChild(LC);
            cout << "Saudara " << info(P) << " telah dihapus." << endl;
            break;
        case 2:
            C = deleteLastChild(LC);
            cout << "Saudara " << info(P) << " telah dihapus." << endl;
            break;
        case 3:
            do
            {
                cout << "Masukkan nama saudara: ";
                cin >> nama;
                C = findElmChild(LC,nama);
            }while(P == NULL);
            C2 = deleteAfterChild(LC,C);
            cout << "Saudara " << info(C2) << " telah dihapus." << endl;
        }
        cout << "Hapus nama saudara lagi?(y/n) ";
        cin >> a;
    }
    cout << "Hapus nama saudara selesai..." << endl;
    sleep(3);

    cout << endl << "=====================" << endl << endl;
    cout<<"List Nama"<<endl;
    printInfoChild(LC);
    sleep(5);
    cout << endl;

    cout << "======= Merelasikan =======" << endl;
    do
    {
        cout << endl << "List Nama:" << endl;
        printInfoParent(LP);
        cout << endl;
        do
        {
            cout << "Masukkan nama: ";
            cin >> nama;
            P = findElmParent(LP, nama);
        }while(P == NULL);
        cout << endl << "List nama saudara: " << endl;
        printInfoChild(LC);
        cout << endl;
        do
        {
            cout << "Masukkan nama saudara: ";
            cin >> nama2;
            C = findElmChild(LC, nama2);
        }while(C == NULL);
        R = alokasiRelasi(P,C);
        insertFirstRelasi(LR,R);
        cout << "Relasi berhasil, ";
        cout << "relasikan lagi?(y/n)";
        cin >> a;
    }while(a == 'y');

    cout<<endl<<"list relasi"<<endl;
    printInfoRelasi(LR);
    sleep(3);

    x = jumlahParent(LP);
    cout << endl << "Jumlah Nama: " << x << endl;
    x = jumlahChild(LC);
    cout << "Jumlah Saudara: " << x << endl;
}
