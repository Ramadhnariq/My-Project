#include <iostream>

using namespace std;
#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"

int main()
{
    List_parent LP;
    List_child LC;
    List_relasi LR;


    createListParent(LP);
    createListChild(LC);
    createListRelasi(LR);

    program(LP,LC,LR);
    cout << "Program selesai digunakan..." << endl;

    return 0;
}
