#include <iostream>
using namespace std;

struct TNode
{
    int data;
    TNode *next;
};

TNode *head, *tail;

void init()
{
    head = NULL;
    tail = NULL;
}

int isEmpty()
{
    if (tail == NULL)
        return 1;
    return 0;
}

void insertDepan(int databaru)
{

    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;

    if (isEmpty() == 1)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

void insertBelakang(int databaru)
{
    TNode *baru, *bantu;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;

    if (isEmpty() == 1)
    {
        head = baru;
        tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

void tampil()
{
    TNode *bantu;
    bantu = head;

    if (isEmpty() == 0)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
    }
    else
    {
        cout << "Linked list kosong" << endl;
    }
}

void tampilIndex(int index)
{
    TNode *bantu;
    bantu = head;
    int i = 0;

    if (isEmpty() == 0)
    {
        while (bantu != NULL)
        {
            if (i == index)
            {
                cout << bantu->data << endl;
                return;
            }

            bantu = bantu->next;
            i++;
        }

        cout << "Index tidak ditemukan" << endl;
    }
    else
    {
        cout << "Linked list kosong" << endl;
    }
}

void hapusDepan()
{
    TNode *hapus;
    int d;

    if (isEmpty() == 0)
    {
        if (head != tail)
        {
            hapus = head;
            d = hapus->data;
            head = head->next;
            delete hapus;
        }
        else
        {
            d = tail->data;
            head = tail = NULL;
        }
    }
    else
    {
        cout << "Linked list kosong" << endl;
    }
}

void hapusBelakang()
{
    TNode *hapus, *bantu;
    int d;

    if (isEmpty() == 0)
    {
        if (head->next != NULL)
        {
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }

            hapus = tail;
            tail = bantu;   
            d = hapus->data;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            d = tail->data;
            head = tail = NULL;
        }
    }
    else
    {
        cout << "Linked list kosong" << endl;
    }
}

void clear()
{
    TNode *bantu, *hapus;
    bantu = head;

    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = NULL;
    tail = NULL;
}

int main()
{
    init();

    while (true)
    {
        int choice;
        cout << "\n1. Insert Depan\n2. Insert Belakang\n3. Tampil\n4. Tampil Index\n5. Hapus Depan\n6. Hapus Belakang\n7. Clear\n8. Keluar\nPilih: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int dataDepan;
            cout << "Masukkan data depan: ";
            cin >> dataDepan;
            insertDepan(dataDepan);
            break;
        case 2:
            int dataBelakang;
            cout << "Masukkan data belakang: ";
            cin >> dataBelakang;
            insertBelakang(dataBelakang);
            break;
        case 3:
            tampil();
            break;
        case 4:
            int index;
            cout << "Masukkan index: ";
            cin >> index;
            tampilIndex(index);
            break;
        case 5:
            hapusDepan();
            break;
        case 6:
            hapusBelakang();
            break;
        case 7:
            clear();
            break;
        case 8:
            return 0;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    }
    return 0;
}