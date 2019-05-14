#include<iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<cstdlib>
#include<cstdbool>
#include<algorithm>
#include<sstream>
#include<iomanip>

using namespace std;
typedef struct Date
{
    int day=0;
    int month=0;
    int year=0;
} Date;

typedef struct SV
{
    string HoVaTen = "";
    string Ten = "";
    string MaLop = "";
    string MSV = "";
    Date NgaySinh;
    float Dtb = 0;
} item;

typedef struct Node
{
    Node *prev;
    item Data;
    Node *next;
} Node;
typedef struct
{
    Node *Head;
    Node *Tail;
} List;
// doublelyLinkedList
void Init(List &L);
bool IsEmpty(List L);
int listLen(List L);
Node *MakeNode(item x);
void Insert(List &L,item x,int k);
void Delete(List &L,int k);
int Sreach(List L, item x);
void Fix(List &L,int k);
//classStanderlizer
string makeClass();
//nameStanderlizer
string delUnnecessary(string &str);
string Standarlizer (string str);
string last_token( std::string str );
//dateStanderlizer
string showDate (Date D);
Date makeDate ();
bool checkDate(Date D);
int dateCompare(Date A,Date B);
//studentNumber
string studentNumber();
//studentMark
float studentMark();
//Sorting
void nameSort_Selection(List &L);
void nameSort_Bubble(List &L);
void nameSort_Insertion(List &L);
void nameSort_Quick(List &L);

void numberSort_Selection(List &L);
void numberSort_Bubble(List &L);
void numberSort_Insertion(List &L);
void numberSort_Quick(List &L);

void pointSort_Selection(List &L);
void pointSort_Bubble(List &L);
void pointSort_Insertion(List &L);
void pointSort_Quick(List &L);

void dateSort_Selection(List &L);
void dateSort_Bubble(List &L);
void dateSort_Insertion(List &L);
void dateSort_Quick(List &L);

void classSort_Selection(List &L);
void classSort_Bubble(List &L);
void classSort_Insertion(List &L);
void classSort_Quick(List &L);
//full progarm
SV makeSV();
void InputSV(List &L);
void Input(List &L,ifstream &infile);
Date stringSlipt(string Date);
void Output(List L,ofstream &outfile);
void gotoxy(int x, int y);
void PrintList(List L);
string toLower(string str);
bool stringObtain(string super,string sub);
void hideCursor();
void showCursor();
void cls();

// doublyLinkedList
void Init(List &L)
{
    L.Head = NULL;
    L.Tail = NULL;
}
bool IsEmpty(List L)
{
    return L.Head == NULL;
}
int listLen(List L)
{
    Node *PH = L.Head,*PT = L.Tail;
    int i = 0;
    if(PH != NULL)
    {
        i = 1;
    }
    while(PH != NULL)
    {
        if(PH == PT)
        {
            break;
        }
        PH = PH->next;
        i++;
        if(PH == PT)
        {
            break;
        }
        PT = PT->prev;
        i++;
    }
    return i;
}
Node *MakeNode(item A)
{
    Node *P = new Node();
    P->Data = A;
    P->next = NULL;
    P->prev = NULL;
    return P;
}
void Insert(List &L, item A, int k)
{
    Node *PH = L.Head, *PT, *R;
    SV sinhVien = A;
    int i = 1, l = listLen(L);
    if(k < 1 || k > l+1)
    {
        printf("vi tri chen khong hop le !");
    }
    else
    {
        R = MakeNode(sinhVien);
        if(k == 1)
        {
            if(IsEmpty(L))
            {
                L.Head =R;
                L.Tail =R;
            }
            else
            {
                R->next = L.Head;
                L.Head->prev = R;
                L.Head = R;
            }
        }
        else if(k == l+1)
        {
            if(IsEmpty(L))
            {
                L.Head = R;
                L.Tail = R;
            }
            else
            {
                L.Tail->next = R;
                R->prev = L.Tail;
                L.Tail = R;
            }
        }
        else
        {
            while(PH != NULL && i != k-1)
            {
                PH = PH->next;
                i++;
            }
            PT = PH->next;
            R->next = PT;
            R->prev = PH;
            PH->next = R;
            PT ->prev = R;
        }
    }
}
void Delete(List &L,int k)
{
    Node *PH = L.Head,*PT;
    int i = 1;
    if(k == 1)
    {
        L.Head = L.Head ->next;
    }
    else if(k == listLen(L))
    {
        L.Tail = L.Tail ->prev;
    }
    else
    {
        while (PH != NULL && i <k-1)
        {
            PH = PH->next;
            i++;
        }
        PT = PH->next->next;
        PH->next = PT;
        PT->prev = PH;

    }
}
int Sreach(List L/*, item x*/ )
{
    Node *P = L.Head;
    int i = 1;
    while (P != NULL /*&& P->Data != x*/)
    {
        P = P->next;
        i++;
    }
    if (P!= NULL)
    {
        return i;
    }
    else
    {
        return 0;
    }
}
void Fix(List &L,int k)
{
    SV A;
    Node *PH = L.Head;
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
        cout << "Ma lop";
        gotoxy(35,9);
        cout << "Ma sinh vien";
        gotoxy(35,13);
        cout << "Ho va ten";
        gotoxy(35,17);
        cout << "Ngay sinh";
        gotoxy(35,21);
        cout << "Diem TB";
    }
    A = makeSV();
    int i = 1;
    if(k == 1)
    {
        L.Head->Data = A;
    }
    else if(k == listLen(L))
    {
        L.Tail->Data = A;
    }
    else
    {
        while (PH != NULL && i <k-1)
        {
            PH = PH->next;
            i++;
        }
        PH->Data = A;
    }

}
//classStandarlizer
string makeClass()
{
    locale loc;
    string className;
    string ret = "";
    cin >> className;
    for (string::size_type i=0; i<className.length(); ++i)
    {
        ret = ret + toupper(className[i],loc);
    }
    return ret;
}
// nameStandarlizer
string Standarlizer(string str)
{
    // Initializing string`
    string full = "";
    string part;
    string name[10];
    int i=0;

    // Declaring iterator
    string::iterator it;

    delUnnecessary(str);
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    str.shrink_to_fit();

    for(it = str.begin(); it != str.end(); it++)
    {
        if(*it == ' ')
        {
            do
            {
                it++;
                if(it == str.end())
                {
                    break;
                }
            }
            while(*it == ' ');
            name[i] = part;
            i++;
            part = "";
        }
        part += *it;
    }
    name[i] = part;

    for(int k=0; k<=i; k++)
    {
        name[k][0] = toupper(name[k][0]);
    }
    for(int k=0; k<=i; k++)
    {
        full =  full + name[k] + " ";
    }
    delUnnecessary(full);
    return full;
}
string delUnnecessary(string &str)
{
    int size = str.length();
    for(int j = 0; j<=size; j++)
    {
        for(int i = 0; i <=j; i++)
        {
            if(str[i] == ' ' && str[i+1] == ' ')
            {
                str.erase(str.begin() + i);
            }
            else if(str[0]== ' ')
            {
                str.erase(str.begin());
            }
            else if(str[i] == '\0' && str[i-1]== ' ')
            {
                str.erase(str.end() - 1);
            }
        }
    }
    return str;
}
string last_token( std::string str )
{
    while(!str.empty() && std::isspace( str.back() ) )
        str.pop_back() ; // remove trailing white space

    const auto pos = str.find_last_of( " \t\n" ) ; // locate the last white space

    // if not found, return the entire string else return the tail after the space
    return pos == std::string::npos ? str : str.substr(pos+1) ;
}

// dateStandarlizer
string showDate(Date D)
{
    string BD;
    return BD =(to_string(D.day) + "/" +to_string(D.month) + "/" +to_string(D.year));
}

Date makeDate()
{
    for(int i=65; i<80; i++)
    {
        gotoxy(i,17);
        cout << " ";
    }
    gotoxy(65,17);
    Date D;
    bool key=true;
    cin >> D.day;
    if(cin.get() != '/')
    {
        key = false;
    }
    cin >> D.month;
    if(cin.get() != '/')
    {
        key = false;
    }
    cin >> D.year;
    if(!checkDate(D))
    {
        key = false;
    }
    if(key == false)
    {
        cout << "Ngay sinh khong hop le!! vui long nhap lai:";
        D=makeDate();
    }

    return D;
}
bool checkDate(Date D)
{
    int ngay = D.day, thang=D.month, nam=D.year,ngaymax;

    if (nam<0 || thang<0 || thang> 12 || ngay<0 || ngay> 31)
    {
        return false;
    }
    else
    {
        switch (thang)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            ngaymax=31;
            break;
        case 2:
            if ((nam%4==0 && nam%100!=0) || (nam%400==0))
                ngaymax=29;
            else
                ngaymax=28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            ngaymax=30;
            break;
        }
        if (ngay<=ngaymax)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
int dateCompare(Date A,Date B)
{
    if(A.year < B.year)
    {
        return -1;
    }
    else if (A.year == B.year)
    {
        if(A.month < B.month)
        {
            return -1;
        }
        else if (A.month == B.month)
        {
            if(A.day < B.day)
            {
                return -1;
            }
            else if (A.day == B.day)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}
//studentNumber
string studentNumber()
{
    for(int i=65; i<90; i++)
    {
        gotoxy(i,9);
        cout << " ";
    }
    gotoxy(65,9);
    bool key = true;
    string maSV;
    string::iterator it;
    cin >> maSV;
    if(maSV.length() != 8)
    {
        key = false;
    }
    {
        for(it= maSV.begin(); it != maSV.end(); it++)
        {
            if((int) *it < 30 || (int)*it >57)
            {
                key = false;
                break;
            }
        }
    }
    if(!key)
    {
        maSV = studentNumber();
    }
    return maSV;
}
//studentMark
float studentMark()
{
    gotoxy(65,21);
    float mark;
    cin >> mark;
    if( mark < 0 || mark > 10)
    {
        mark = 0;
    }
    return mark;
}
//Sorting
void nameSort_Selection(List &L)
{
    Node *P = L.Head,*J;
    for(P; P != NULL; P = P->next)
    {
        for(J = P ; J != NULL; J = J->next)
        {
            if(P->Data.Ten.compare(J->Data.Ten) == 1)
            {
                swap(P->Data,J->Data);
            }
        }
    }
}
void nameSort_Bubble(List &L)
{
    Node *P = L.Head,*J=L.Tail;
    for(P = L.Head; P != NULL; P = P->next)
    {
        for(J=L.Tail; J != P; J = J->prev)
        {
            if(P->Data.Ten.compare(J->Data.Ten) == 1)
            {
                swap(P->Data,J->Data);
            }
        }
    }
}
void nameSort_Insertion(List &L)
{
    Node *P, *J;
    for(P = L.Head->next; P!= NULL ; P = P->next)
    {
        item temp = P->Data;
        J = P->prev;

        while( (J != NULL) && temp.Ten.compare(P->prev->Data.Ten) == -1)
        {
            J->next->Data = J->Data;
            J = J->prev;
        }
        if(J==NULL)
        {
        L.Head->Data = temp;
        }
        else if(J->next !=P)
        {
            J->next->Data = temp;
        }
    }
}
void nameSort_Quick(List &L)
{
    List l1, l2;
    Node *J, *P;
    if(L.Head == L.Tail )
        return;
    Init(l1);
    Init(l2);
    J = L.Head;
    L.Head = L.Head->next; // cap nhat lai l.head
    J->next = NULL;// co lap tag
    while( L.Head!= NULL )
    {
        P = L.Head;
        L.Head = L.Head->next;
        P->next = NULL;
        if(P->Data.Ten.compare(J->Data.Ten) == -1 )
            Insert(l1,P->Data,1);
        else
            Insert(l2,P->Data,1);
    }
    nameSort_Quick(l1); // goi de qui sap xep l1, l2
    nameSort_Quick(l2);
    if(l1.Head != NULL )  // l1 k rong
    {
        L.Head = l1.Head; // lay head cua l1 gan cho head cua l;
        l1.Tail->next = J;
    } // l1 rong
    else
        L.Head = J;
    J->next = l2.Head;
    if(l2.Head!= NULL )
        L.Tail = l2.Tail;
    else
        L.Tail = J;
}

void numberSort_Selection(List &L)
{
    Node *P = L.Head,*J;
    for(P; P != NULL; P = P->next)
    {
        for(J = P ; J != NULL; J = J->next)
        {
            if(P->Data.MSV.compare(J->Data.MSV) == 1)
            {
                swap(P->Data,J->Data);
            }
        }
    }
}
void numberSort_Bubble(List &L)
{
    Node *P = L.Head,*J=L.Tail;
    for(P = L.Head; P != NULL; P = P->next)
    {
        for(J=L.Tail; J != P; J = J->prev)
        {
            if(P->Data.MSV.compare(J->Data.MSV) == 1)
            {
                swap(P->Data,J->Data);
            }
        }
    }
}
void numberSort_Insertion(List &L)
{
    Node *P, *J;
    for(P = L.Head->next; P!= NULL ; P = P->next)
    {
        item temp = P->Data;
        J = P->prev;

        while( (J->prev != NULL) && temp.MSV.compare(P->prev->Data.MSV) < 0)
        {
            J->next->Data = J->Data;
            J = J->prev;
        }
        if(J==NULL)
        {
        L.Head->Data = temp;
        }
        else if(J->next !=P)
        {
            J->next->Data = temp;
        }
    }
}
void numberSort_Quick(List &L)
{
    List l1, l2;
    Node *J, *P;
    if(L.Head == L.Tail )
        return;
    Init(l1);
    Init(l2);
    J = L.Head;
    L.Head = L.Head->next;
    J->next = NULL;
    while( L.Head!= NULL )
    {
        P = L.Head;
        L.Head = L.Head->next;
        P->next = NULL;
        if(P->Data.MSV.compare(J->Data.MSV) < 0)
        {
            Insert(l1,P->Data,1);
        }
        else
        {
            Insert(l2,P->Data,1);
        }
    }
    numberSort_Quick(l1);
    numberSort_Quick(l2);
    if(l1.Head != NULL )
    {
        L.Head = l1.Head;
        l1.Tail->next = J;
    }
    else
    {
        L.Head = J;
    }
    J->next = l2.Head;
    if(l2.Head!= NULL )
    {
        L.Tail = l2.Tail;
    }
    else
    {
        L.Tail = J;
    }
}

void pointSort_Selection(List &L)
{
    Node *P = L.Head,*J;
    for(P; P != NULL; P = P->next)
    {
        for(J = P ; J != NULL; J = J->next)
        {
            if(P->Data.Dtb < J->Data.Dtb)
            {
                swap(P->Data,J->Data);
            }
        }
    }
}
void pointSort_Bubble(List &L)
{
    Node *P = L.Head,*J=L.Tail;
    for(P = L.Head; P != NULL; P = P->next)
    {
        for(J=L.Tail; J != P; J = J->prev)
        {
            if(P->Data.Dtb < J->Data.Dtb)
            {
                swap(P->Data,J->Data);
            }
        }
    }
}
void pointSort_Insertion(List &L)
{
    Node *P, *J;
    for(P = L.Head->next; P!= NULL ; P = P->next)
    {
        item temp = P->Data;
        J = P->prev;

        while( (J->prev != NULL) && P->Data.Dtb < temp.Dtb)
        {
            J->next->Data = J->Data;
            J = J->prev;
        }
        if(J==NULL)
        {
        L.Head->Data = temp;
        }
        else if(J->next !=P)
        {
            J->next->Data = temp;
        }
    }
}
void pointSort_Quick(List &L)
{
    List l1, l2;
    Node *J, *P;
    if(L.Head == L.Tail )
        return;
    Init(l1);
    Init(l2);
    J = L.Head;
    L.Head = L.Head->next;
    J->next = NULL;
    while( L.Head!= NULL )
    {
        P = L.Head;
        L.Head = L.Head->next;
        P->next = NULL;
        if(P->Data.Dtb < J->Data.Dtb)
            Insert(l1,P->Data,1);
        else
            Insert(l2,P->Data,1);
    }
    pointSort_Quick(l1);
    pointSort_Quick(l2);
    if(l1.Head != NULL )
    {
        L.Head = l1.Head;
        l1.Tail->next = J;
    }
    else
        L.Head = J;
    J->next = l2.Head;
    if(l2.Head!= NULL )
        L.Tail = l2.Tail;
    else
        L.Tail = J;
}

void dateSort_Selection(List &L)
{
    Node *P = L.Head,*J;
    for(P; P != NULL; P = P->next)
    {
        for(J = P ; J != NULL; J = J->next)
        {
            if(dateCompare(P->Data.NgaySinh,J->Data.NgaySinh) == 1)
            {
                swap(P->Data,J->Data);
            }
        }
    }
}
void dateSort_Bubble(List &L)
{
    Node *P = L.Head,*J=L.Tail;
    for(P = L.Head; P != NULL; P = P->next)
    {
        for(J=L.Tail; J != P; J = J->prev)
        {
            if(dateCompare(P->Data.NgaySinh,J->Data.NgaySinh) == 1)
            {
                swap(P->Data,J->Data);
            }
        }
    }
}
void dateSort_Insertion(List &L)
{
    Node *P, *J;
    for(P = L.Head->next; P!= NULL ; P = P->next)
    {
        item temp = P->Data;
        J = P->prev;

        while( (J->prev != NULL) && dateCompare(P->Data.NgaySinh,J->Data.NgaySinh) == -1)
        {
            J->next->Data = J->Data;
            J = J->prev;
        }
        if(J==NULL)
        {
        L.Head->Data = temp;
        }
        else if(J->next !=P)
        {
            J->next->Data = temp;
        }
    }
}
void dateSort_Quick(List &L)
{
    List l1, l2;
    Node *J, *P;
    if(L.Head == L.Tail )
        return;
    Init(l1);
    Init(l2);
    J = L.Head;
    L.Head = L.Head->next; // cap nhat lai l.head
    J->next = NULL;// co lap tag
    while( L.Head!= NULL )
    {
        P = L.Head;
        L.Head = L.Head->next;
        P->next = NULL;
        if(dateCompare(P->Data.NgaySinh,J->Data.NgaySinh) == 1)
            Insert(l1,P->Data,1);
        else
            Insert(l2,P->Data,1);
    }
    dateSort_Quick(l1); // goi de qui sap xep l1, l2
    dateSort_Quick(l2);
    if(l1.Head != NULL )  // l1 k rong
    {
        L.Head = l1.Head; // lay head cua l1 gan cho head cua l;
        l1.Tail->next = J;
    } // l1 rong
    else
        L.Head = J;
    J->next = l2.Head;
    if(l2.Head!= NULL )
        L.Tail = l2.Tail;
    else
        L.Tail = J;
}

void classSort_Selection(List &L)
{
    Node *P = L.Head,*J;
    for(P; P != NULL; P = P->next)
    {
        for(J = P ; J != NULL; J = J->next)
        {
            if((P->Data.MaLop.compare(J->Data.MaLop) == 1)||((P->Data.MaLop.compare(J->Data.MaLop) == 0)&&(P->Data.Ten.compare(J->Data.Ten) == 1)))
            {
                swap(P->Data,J->Data);
            }
        }
    }
}
void classSort_Bubble(List &L)
{
    Node *P = L.Head,*J=L.Tail;
    for(P = L.Head; P != NULL; P = P->next)
    {
        for(J=L.Tail; J != P; J = J->prev)
        {
            if((P->Data.MaLop.compare(J->Data.MaLop) == 1)||((P->Data.MaLop.compare(J->Data.MaLop) == 0)&&(P->Data.Ten.compare(J->Data.Ten) == 1)))
            {
                swap(P->Data,J->Data);
            }
        }
    }
}
void classSort_Insertion(List &L)
{
    Node *P, *J;
    for(P = L.Head->next; P!= NULL ; P = P->next)
    {
        item temp = P->Data;
        J = P->prev;

        while( (J->prev != NULL) && ((temp.MaLop.compare(P->prev->Data.MaLop) == -1)||((temp.MaLop.compare(P->prev->Data.MaLop) == 0)&&(temp.MaLop.compare(P->prev->Data.MaLop) == 0))))
        {
            J->next->Data = J->Data;
            J = J->prev;
        }
        if(J==NULL)
        {
        L.Head->Data = temp;
        }
        else if(J->next !=P)
        {
            J->next->Data = temp;
        }
    }
}
void classSort_Quick(List &L)
{
    List l1, l2;
    Node *J, *P;
    if(L.Head == L.Tail )
        return;
    Init(l1);
    Init(l2);
    J = L.Head;
    L.Head = L.Head->next; // cap nhat lai l.head
    J->next = NULL;// co lap tag
    while( L.Head!= NULL )
    {
        P = L.Head;
        L.Head = L.Head->next;
        P->next = NULL;
        if((P->Data.MaLop.compare(J->Data.MaLop) == -1)||((P->Data.MaLop.compare(J->Data.MaLop) == 0)&&(P->Data.Ten.compare(J->Data.Ten) == -1)))
            Insert(l1,P->Data,1);
        else
            Insert(l2,P->Data,1);
    }
    classSort_Quick(l1); // goi de qui sap xep l1, l2
    classSort_Quick(l2);
    if(l1.Head != NULL )  // l1 k rong
    {
        L.Head = l1.Head; // lay head cua l1 gan cho head cua l;
        l1.Tail->next = J;
    } // l1 rong
    else
        L.Head = J;
    J->next = l2.Head;
    if(l2.Head!= NULL )
        L.Tail = l2.Tail;
    else
        L.Tail = J;
}
// full progarm
SV makeSV()
{
    SV A;
    gotoxy(65,5);
    A.MaLop = makeClass();
    gotoxy(65,9);
    A.MSV = studentNumber();
    cin.ignore();
    gotoxy(65,13);
    getline(cin,A.HoVaTen);
    A.HoVaTen = Standarlizer(A.HoVaTen);
    gotoxy(65,17);
    A.NgaySinh = makeDate();
    gotoxy(65,21);
    A.Dtb = studentMark();
    return A;
}
void InputSV(List &L)
{
    SV A;
    A = makeSV();
    Insert(L,A,listLen(L) +1);
}
void Input(List &L,ifstream &infile)
{
    SV A;
    string Name,
           Class,
           Number,
           Date;
    float  Mark;
    while (!infile.eof())
    {

        getline(infile,Name,'\t');
        infile >> Class >> Number >> Date >> Mark;
        A.HoVaTen = delUnnecessary(Name);
        A.Ten = last_token(A.HoVaTen);
        A.MaLop = Class;
        A.NgaySinh = stringSlipt(Date);
        A.MSV = Number;
        A.Dtb = Mark;
        if(infile.eof())
        {
            break;
        }
        Insert(L,A,listLen(L)+1);
    }
}
Date stringSlipt(string BD)
{
    Date D;
    stringstream ss(BD);
    string Day,
           Month,
           Year;

    getline(ss,Day,'/');
    getline(ss,Month,'/');
    getline(ss,Year,'/');

    D.day = stoi(Day);
    D.month = stoi(Month);
    D.year = stoi(Year);

    return D;
}

void Output(List L,ofstream &outfile)
{
    Node *P = L.Head;
    while (P != NULL)
    {
        outfile<< P->Data.HoVaTen << "\t"
               << P->Data.MaLop << "\t"
               << P->Data.MSV << "\t"
               << showDate(P->Data.NgaySinh) << "\t"
               << P->Data.Dtb << " ";
        P = P->next;
    }
}
void PrintList(List L)
{
    //gotoxy(20,20);
    int n=1;
    int y=8;
    for(int i=10; i <110; i++)
    {
        gotoxy(i,5);
        cout << "-";
        gotoxy(i,7);
        cout << "-";
    }
    for(int i=5; i<8; i++)
    {
        gotoxy(9,i);
        cout << "|";
        gotoxy(13,i);
        cout << "|";
        gotoxy(45,i);
        cout << "|";
        gotoxy(60,i);
        cout << "|";
        gotoxy(75,i);
        cout << "|";
        gotoxy(100,i);
        cout << "|";
        gotoxy(110,i);
        cout << "|";
    }
    {
        gotoxy(10,6);
        cout << "STT";
        gotoxy(25,6);
        cout << "Ho va Ten";
        gotoxy(50,6);
        cout << "Ma Lop";
        gotoxy(65,6);
        cout << "Ma SV";
        gotoxy(82,6);
        cout << "Ngay sinh";
        gotoxy(104,6);
        cout << "DTB";
    }
    Node *P = L.Head;
    while (P != NULL)
    {
        for(int i=10; i <110; i++)
        {
            gotoxy(i,y+1);
            cout << "-";
        }
        for(int i=y-1; i<y+2; i++)
        {
            gotoxy(9,i);
            cout << "|";
            gotoxy(13,i);
            cout << "|";
            gotoxy(45,i);
            cout << "|";
            gotoxy(60,i);
            cout << "|";
            gotoxy(75,i);
            cout << "|";
            gotoxy(100,i);
            cout << "|";
            gotoxy(110,i);
            cout << "|";
        }
        gotoxy(10,y);
        cout << n;
        gotoxy(15,y);
        cout << P->Data.HoVaTen;
        gotoxy(47,y);
        cout << P->Data.MaLop;
        gotoxy(62,y);
        cout << P->Data.MSV;
        gotoxy(77,y);
        cout << showDate(P->Data.NgaySinh);
        gotoxy(104,y);
        cout << fixed << setprecision(2) << P->Data.Dtb;
        y = y+2;
        n++;
        P = P->next;
    }
}
string toLower(string str)
{
    string res;
    std::locale loc;
    for (std::string::size_type i=0; i<str.length(); ++i)
    {
    res += std::tolower(str[i],loc);
    }
    return res;
}
bool stringObtain(string super,string sub)
{
    return (toLower(super).find(toLower(sub)) != string::npos);
}
void gotoxy(int x, int y)
{
// xoa toan bo man hinh
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hideCursor()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = FALSE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void showCursor()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = TRUE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void cls ()
{
    for(int i=0; i<120; i++)
    {
        for(int j=0; j<30; j++)
        {
            gotoxy(i,j);
            cout << " ";
        }
    }
}
