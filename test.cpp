#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include "libary.h"

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


string mainMenuItem[] =
{
    "Them ho so moi",
    "In danh sach",
    "Sap xep",
    "Tim kiem",
    "Thong ke",
    "Thoat"
};
string m1MenuItem[] =
{
    "Ma lop",
    "Ma sinh vien",
    "Ho va ten",
    "Ngay sinh",
    "Diem TB"
};
string m3MenuItem1[] =
{
    "Selection Sort",
    "Insertion Sort",
    "Bubble Sort",
    "Quick Sort"
};
string m3MenuItem2[] =
{
    "Ma Sinh Vien",
    "Ho va Ten",
    "Ngay Sinh",
    "Diem trung binh",
    "Ma lop"
};
string m4MenuItem[] =
{
    "Ma Lop",
    "Ma Sinh Vien",
    "Ho va Ten",
    "Ngay Sinh",
    "Diem trung binh"
};
string m5MenuItem[] =
{
    "Lop",
    "Xep loai hoc tap"
};


void mainMenu(List &L);
void m1Menu(List &L);
void m2Menu(List &L);
void m3Menu(List &L);
void m4Menu(List &L);
void m5Menu(List &L);
void SreachField(List &L,int key);
void Stat(List L);

int main()
{
    ifstream infile;
    infile.open("danhsachSV.txt");
    ofstream outfile;
    List L;
    Init(L);
    Input(L,infile);
    infile.close();


    mainMenu(L);


    outfile.open("danhsachSV.txt");
    Output(L,outfile);
    outfile.close();
}
void mainMenu(List &L)
{
    cls();
    hideCursor();
    {
        for(int i=40; i<80; i++)
        {
            gotoxy(i,3);
            cout << "-";
            gotoxy(i,7);
            cout << "-";
            gotoxy(i,11);
            cout << "-";
            gotoxy(i,15);
            cout << "-";
            gotoxy(i,19);
            cout << "-";
            gotoxy(i,23);
            cout << "-";
            gotoxy(i,27);
            cout << "-";
        }
        for(int i=3; i<28; i++)
        {
            gotoxy(40,i);
            cout << "|";
            gotoxy(80,i);
            cout << "|";
        }
        // in ten muc
        {
            gotoxy(50,5);
            cout << mainMenuItem[0];
            gotoxy(50,9);
            cout << mainMenuItem[1];
            gotoxy(50,13);
            cout << mainMenuItem[2];
            gotoxy(50,17);
            cout << mainMenuItem[3];
            gotoxy(50,21);
            cout << mainMenuItem[4];
            gotoxy(50,25);
            cout << mainMenuItem[5];
        }
    }
    int y = 5;
    gotoxy(45,5);
    cout << (char)175;
    char c;
    // dieu khien = arrow key
    do
    {
        c = getch();

        if (c == 80)
        {
            gotoxy(45,y);
            cout << " ";
            y += 4;
            if (y >25)
            {
                y=5;
            }
            gotoxy(45,y);
            cout << (char)175;
        }
        if (c == 72)
        {
            gotoxy(45,y);
            cout << " ";
            y -= 4;
            if (y <5)
            {
                y=25;
            }
            gotoxy(45,y);
            cout << (char)175;
        }

        if (c == 13)
        {
            if (y==5)
            {
                m1Menu(L);
                break;
            }
            if (y==9)
            {
                m2Menu(L);
                break;
            }
            if (y==13)
            {
                m3Menu(L);
                break;
            }
            if (y==17)
            {
                m4Menu(L);
                break;
            }
            if (y==21)
            {
                m5Menu(L);
                break;
            }
            if (y==25)
            {
                break;
            }
        }
    }
    while(c!=27);
}
void m1Menu(List &L)
{
    cls();
    showCursor();
    for(int i=30; i<90; i++)
    {
        gotoxy(i,3);
        cout << "-";
        gotoxy(i,7);
        cout << "-";
        gotoxy(i,11);
        cout << "-";
        gotoxy(i,15);
        cout << "-";
        gotoxy(i,19);
        cout << "-";
        gotoxy(i,23);
        cout << "-";
    }
    for(int i=3; i<24; i++)
    {
        gotoxy(30,i);
        cout << "|";
        gotoxy(60,i);
        cout << "|";
        gotoxy(90,i);
        cout << "|";
    }
    // in ten muc
    {
        gotoxy(35,5);
        cout << m1MenuItem[0];
        gotoxy(35,9);
        cout << m1MenuItem[1];
        gotoxy(35,13);
        cout << m1MenuItem[2];
        gotoxy(35,17);
        cout << m1MenuItem[3];
        gotoxy(35,21);
        cout << m1MenuItem[4];

    }
    InputSV(L);
    mainMenu(L);
}
void m2Menu(List &L)
{
    cls();
    hideCursor();
    PrintList(L);
    int n = listLen(L);
    int y = 8;
    int last = 6+n*2;
    int i=1;
    char c;
    // dieu khien = arrow key
    gotoxy(7,y);
    cout << (char)175;
    do
    {
        c = getch();
        if (c == 80)
        {
            gotoxy(7,y);
            cout << " ";
            y += 2;
            i++;
            if (i > n)
            {
                y=8;
                i = 1;
            }
            gotoxy(7,y);
            cout << (char)175;
        }
        if (c == 72)
        {
            gotoxy(7,y);
            cout << " ";
            y -= 2;
            i--;
            if (i<1)
            {
                y=last;
                i = n;
            }
            gotoxy(7,y);
            cout << (char)175;
        }
        if(c == 13)
        {
            gotoxy(0,0);
            cout << "nhan phim (E) de chinh sua noi dung" << "\n" << "nhan phim  (D) de xoa sinh vien" << "\n" << "nhan phim bat ki de thoat";
            char g = getch();
            if(g == 100)
            {
                Delete(L,i);
                break;
            }
            else if(g == 101)
            {
                Fix(L,i);
                break;
            }
            else
            {
                for(int a=0; a<40; a++)
                {
                    for(int b=0; b<4; b++)
                    {
                        gotoxy(a,b);
                        cout << " ";
                    }
                }
            }
        }

    }
    while(c!=27);
    if(c == 27)
    {
        mainMenu(L);
    }
    else
    {
        m2Menu(L);
    }
}
void m3Menu(List &L)
{
    cls();
    hideCursor();
    {
        for(int i=30; i<90; i++)
        {
            gotoxy(i,3);
            cout << "-";
            gotoxy(i,7);
            cout << "-";
            gotoxy(i,11);
            cout << "-";
            gotoxy(i,15);
            cout << "-";
            gotoxy(i,19);
            cout << "-";
            if(i > 59)
            {
                gotoxy(i,23);
                cout << "-";
            }
        }
        for(int i=3; i<24; i++)
        {
            if(i<20)
            {
                gotoxy(30,i);
                cout << "|";
            }
            gotoxy(60,i);
            cout << "|";
            gotoxy(90,i);
            cout << "|";
        }
    }
    {
        gotoxy(35,5);
        cout << m3MenuItem1[0];
        gotoxy(35,9);
        cout << m3MenuItem1[1];
        gotoxy(35,13);
        cout << m3MenuItem1[2];
        gotoxy(35,17);
        cout << m3MenuItem1[3];
        gotoxy(65,5);
        cout << m3MenuItem2[0];
        gotoxy(65,9);
        cout << m3MenuItem2[1];
        gotoxy(65,13);
        cout << m3MenuItem2[2];
        gotoxy(65,17);
        cout << m3MenuItem2[3];
        gotoxy(65,21);
        cout << m3MenuItem2[4];
    }
    char c;
    int y = 5,
        x = 35;
    int Max = 17,
        Min = 5;
    int a,b;
    bool full = false;
    gotoxy(x-2,y);
    cout << (char)175;
    do
    {
        c = getch();
        if (c == 80)
        {
            gotoxy(x-2,y);
            cout << " ";
            y += 4;
            if (y > Max)
            {
                y=Min;
            }
            gotoxy(x-2,y);
            cout << (char)175;
        }
        if (c == 72)
        {
            gotoxy(x-2,y);
            cout << " ";
            y -= 4;
            if (y <Min)
            {
                y=Max;
            }
            gotoxy(x-2,y);
            cout << (char)175;
        }
        if (c == 13)
        {
            if (!full)
            {
                gotoxy(x-2,y);
                cout << " ";
                full = true;
                Max = 21;
                if(y == 5)
                {
                    a = 1;
                }
                else if(y == 9)
                {
                    a = 2;
                }
                else if(y == 13)
                {
                    a = 3;
                }
                else if(y == 17)
                {
                    a = 4;
                }
                x = 65;
                gotoxy(x-2,y);
                y = 5;
                cout << (char)175;
            }
            else
            {
                if(y == 5)
                {
                    b = 1;
                }
                else if(y == 9)
                {
                    b = 2;
                }
                else if(y == 13)
                {
                    b = 3;
                }
                else if(y == 17)
                {
                    b = 4;
                }
                else if(y == 21)
                {
                    b = 5;
                }

                if( a == 1 && b== 1 )
                {
                    numberSort_Selection(L);
                }
                if( a == 1 && b== 2 )
                {
                    nameSort_Selection(L);
                }
                if( a == 1 && b== 3 )
                {
                    dateSort_Selection(L);
                }
                if( a == 1 && b== 4 )
                {
                    pointSort_Selection(L);
                }
                if( a == 1 && b== 5 )
                {
                    classSort_Selection(L);
                }
                if( a == 2 && b== 1 )
                {
                    numberSort_Insertion(L);
                }
                if( a == 2 && b== 2 )
                {
                    nameSort_Insertion(L);
                }
                if( a == 2 && b== 3 )
                {
                    dateSort_Insertion(L);
                }
                if( a == 2 && b== 4 )
                {
                    pointSort_Insertion(L);
                }
                if( a == 2 && b== 5 )
                {
                    classSort_Insertion(L);
                }
                if( a == 3 && b== 1 )
                {
                    numberSort_Bubble(L);
                }
                if( a == 3 && b== 2 )
                {
                    nameSort_Bubble(L);
                }
                if( a == 3 && b== 3 )
                {
                    dateSort_Bubble(L);
                }
                if( a == 3 && b== 4 )
                {
                    pointSort_Bubble(L);
                }
                if( a == 3 && b== 5 )
                {
                    classSort_Bubble(L);
                }
                if( a == 4 && b== 1 )
                {
                    numberSort_Quick(L);
                }
                if( a == 4 && b== 2 )
                {
                    nameSort_Quick(L);
                }
                if( a == 4 && b== 3 )
                {
                    dateSort_Quick(L);
                }
                if( a == 4 && b== 4 )
                {
                    pointSort_Quick(L);
                }
                if( a == 4 && b== 5 )
                {
                    classSort_Quick(L);
                }
                break;
            }
        }
    }
    while (c!=27);
    if(c == 27)
    {
        mainMenu(L);
    }
    else
    {
        m2Menu(L);
    }
}
void m4Menu(List &L)
{
    cls();
    hideCursor();
    {
        for(int i=40; i<80; i++)
        {
            gotoxy(i,3);
            cout << "-";
            gotoxy(i,7);
            cout << "-";
            gotoxy(i,11);
            cout << "-";
            gotoxy(i,15);
            cout << "-";
            gotoxy(i,19);
            cout << "-";
            gotoxy(i,23);
            cout << "-";
        }
        for(int i=3; i<24; i++)
        {
            gotoxy(40,i);
            cout << "|";
            gotoxy(80,i);
            cout << "|";
        }
        // in ten muc
        {
            gotoxy(50,5);
            cout << m4MenuItem[0];
            gotoxy(50,9);
            cout << m4MenuItem[1];
            gotoxy(50,13);
            cout << m4MenuItem[2];
            gotoxy(50,17);
            cout << m4MenuItem[3];
            gotoxy(50,21);
            cout << m4MenuItem[4];
        }
    }
    int y = 5;
    gotoxy(45,5);
    cout << (char)175;
    char c;
    do
    {
        c = getch();
        if (c == 80)
        {
            gotoxy(45,y);
            cout << " ";
            y += 4;
            if (y >21)
            {
                y=5;
            }
            gotoxy(45,y);
            cout << (char)175;
        }
        if (c == 72)
        {
            gotoxy(45,y);
            cout << " ";
            y -= 4;
            if (y <5)
            {
                y=21;
            }
            gotoxy(45,y);
            cout << (char)175;
        }
        if (c == 13)
        {
            if (y==5)
            {
                SreachField(L,1);
                break;
            }
            if (y==9)
            {
                SreachField(L,2);
                break;
            }
            if (y==13)
            {
                SreachField(L,3);
                break;
            }
            if (y==17)
            {
                SreachField(L,4);
                break;
            }
            if (y==21)
            {
                SreachField(L,5);
                break;
            }
        }
    }
    while (c!=27);
    if(c == 27)
    {
        mainMenu(L);
    }
}
void m5Menu(List &L)
{

    List K = L;

    classSort_Selection(K);

    cls();
    hideCursor();

    int Count;

    {
        for(int i=40; i<80; i++)
        {
            gotoxy(i,5);
            cout << "-";
            gotoxy(i,9);
            cout << "-";
        }
        for(int i=5; i<10; i++)
        {
            gotoxy(39,i);
            cout << "|";
            gotoxy(60,i);
            cout << "|";
            gotoxy(80,i);
            cout << "|";
        }
        gotoxy(43,7);
        cout << "Ten lop";
        gotoxy(68,7);
        cout << "So SV";
    }
    gotoxy(0,0);
    Stat(K);

    char c;
    do
    {
        c = getch();
    }
    while (c!=27);
    if(c == 27)
    {
        mainMenu(L);
    }
}
void SreachField(List &L,int key)
{
    cls();
    showCursor();
    for(int i=5; i<40; i++)
    {
        gotoxy(i,0);
        cout << "-";
        gotoxy(i,4);
        cout << "-";
    }
    for(int i=0; i<5; i++)
    {
        gotoxy(4,i);
        cout << "|";
        gotoxy(40,i);
        cout << "|";
    }
    gotoxy(7,0);
    cout << "nhap du lieu sinh vien can tim";
    char c;
    string h;
    gotoxy(7,2);
    do
    {
        Node *P = L.Head;
        List K;
        Init(K);
        c = getch();
        if (c == 8)
        {
            if(h.size() >0 )
            {
                h.erase(h.size()-1);
            }
        }
        else if(((c>=32)&&(c<=64))||((c>=91)&&(c<=126)))
        {
            h = h+c;
        }
        gotoxy(7,2);
        if(h.size() < 33)
        {
            for(int i=7; i<40; i++)
            {
                gotoxy(i,2);
                cout << " ";
            }
            gotoxy(7,2);
            cout << h;
            if(key == 1)
            {
                while(P != NULL)
                {
                    if(stringObtain(P->Data.MaLop,h))
                    {
                        Insert(K,P->Data,listLen(K)+1);
                    }
                    P = P->next;
                }
            }
            if(key == 2)
            {
                while(P != NULL)
                {
                    if(stringObtain(P->Data.MSV,h))
                    {
                        Insert(K,P->Data,listLen(K)+1);
                    }
                    P = P->next;
                }
            }
            if(key == 3)
            {
                while(P != NULL)
                {
                    if(stringObtain(P->Data.Ten,h))
                    {
                        Insert(K,P->Data,listLen(K)+1);
                    }
                    P = P->next;
                }
            }
            if(key == 4)
            {
                while(P != NULL)
                {
                    if(stringObtain(showDate(P->Data.NgaySinh),h))
                    {
                        Insert(K,P->Data,listLen(K)+1);
                    }
                    P = P->next;
                }
            }
            if(key == 5)
            {
                while(P != NULL)
                {
                    if(stringObtain(to_string(P->Data.Dtb),h))
                    {
                        Insert(K,P->Data,listLen(K)+1);
                    }
                    P = P->next;
                }
            }
            for(int i=0; i<120; i++)
            {
                for(int j=5; j<30; j++)
                {
                    gotoxy(i,j);
                    cout << " ";
                }
            }
            PrintList(K);
            gotoxy(7,2);
        }
    }
    while(true);
}
void Stat(List L)
{
    int l = 11;
    Node *P = L.Head;
    string s = P->Data.MaLop;
    while(P != NULL)
    {
        int k = 1;
        s = P->Data.MaLop;
        while(P->next != NULL && s == P->next->Data.MaLop)
        {
            k++;
            P = P->next;
            //s = P->Data.MaLop;
        }
        {
            for(int i=40; i<80; i++)
            {
                gotoxy(i,l+2);
                cout << "-";
            }
            for(int i=l-2; i<l+3; i++)
            {
                gotoxy(39,i);
                cout << "|";
                gotoxy(60,i);
                cout << "|";
                gotoxy(80,i);
                cout << "|";
            }
            gotoxy(43,l);
            cout << s;
            gotoxy(70,l);
            cout << k;
        }

        P = P->next;
        l = l+4;
    }
    {
        for(int i=40; i<80; i++)
        {
            gotoxy(i,l+2);
            cout << "-";
        }
        for(int i=l-2; i<l+3; i++)
        {
            gotoxy(39,i);
            cout << "|";
            gotoxy(60,i);
            cout << "|";
            gotoxy(80,i);
            cout << "|";
        }
        gotoxy(43,l);
        cout << "Tong so";
        gotoxy(70,l);
        cout << listLen(L);
    }
}
