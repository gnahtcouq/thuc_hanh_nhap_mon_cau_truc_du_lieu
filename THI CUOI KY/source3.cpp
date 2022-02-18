#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

// Phan 1
struct CAYBUT {
  int maCB; // ma so cua cay but
  char tenCB[30]; // ten cua cay but
  int soLuong; // so luong cua cay but trong kho
  float donGia; // don gia cua cay but
  char hangSX[30]; // hang san xuat
};

struct NODECAYBUT {
  CAYBUT data;
  NODECAYBUT *link;
};
typedef NODECAYBUT* Nodeptr;

void khoiTao(Nodeptr &list);
Nodeptr taoNode(CAYBUT x);
Nodeptr themCuoi(Nodeptr &list, CAYBUT x);
void giaiPhong(Nodeptr &list);
bool kiemTraTrungMaCB(Nodeptr& list, int ma);
void nhapDanhSachCayBut(Nodeptr &list);
void xuatDanhSachCayBut(Nodeptr list);
void sapXepGiamDanTheoDonGia(Nodeptr &list);

// Phan 2
struct NODE {
  int data;
  NODE* link;
};
typedef NODE* NODEPTR;

struct QUEUE {
  NODEPTR front, rear;
};
void init_Queue(QUEUE& q);
int isEmpty_Queue(QUEUE q);
NODEPTR taoNode_Queue(int x);
void enQueue(QUEUE& q, int x);
void setValue_Queue(QUEUE& q);
void print_Queue(QUEUE q);
int deQueue(QUEUE& q);
int getFront_Queue(QUEUE q);
void chenSauNode(QUEUE& q, int x, int pos);

struct STACK {
  NODEPTR top;
};
void init_Stack(STACK& s);
int isEmpty_Stack(STACK s);
NODEPTR taoNode_Stack(int x);
void push(STACK& s, int a);
int pop(STACK& s);
int top(STACK& s);
void input_Stack(STACK& s);
void output_Stack(STACK s);
void loaiBoCacPhanTuTrongStack(STACK& s, int x);

int main() {
  // Phan 1 - Cau 1
  Nodeptr ds;
  nhapDanhSachCayBut(ds);
  xuatDanhSachCayBut(ds);
  // Phan 1 - Cau 2


  // Phan 1 - Cau 3
  sapXepGiamDanTheoDonGia(ds);
  cout << "\nDanh sach sau khi sap xep giam dan theo don gia";
  xuatDanhSachCayBut(ds);
  cout << endl;

  // Phan 2 - Cau 1
  QUEUE q;
  init_Queue(q);
  setValue_Queue(q);
  print_Queue(q);
  int x;
  cout << "\nNhap phan tu can chen: ";
  cin >> x;
  int vitri;
  cout << "Nhap vi tri node can chen sau: ";
  cin >> vitri;
  chenSauNode(q, x, vitri);
  cout << "Queue sau khi chen: ";
  print_Queue(q);
  cout << "\n\n";

  // Phan 2 - Cau 2
  STACK s;
  init_Stack(s);
  input_Stack(s);
  output_Stack(s);
  int x2;
  cout << "\nNhap phan tu can xoa: ";
  cin >> x2;
  loaiBoCacPhanTuTrongStack(s, x2);
  cout << "\nStack sau khi xoa: ";
  output_Stack(s);

  system("pause");
  return 0;
}

// Phan 1
void khoiTao(Nodeptr &list) {
  list = NULL;
}

Nodeptr taoNode(CAYBUT x) {
  Nodeptr p;
  p = new NODECAYBUT;
  p->data = x;
  p->link = NULL;
  return p;
}

Nodeptr themCuoi(Nodeptr &list, CAYBUT x) {
  Nodeptr p = taoNode(x);
  if (list == NULL) {
    list = p;
  }
  else {
    Nodeptr q = list;
    while (q->link != NULL) {
      q = q->link;
    }
    q->link = p;
  }
  return p;
}

void giaiPhong(Nodeptr &list) {
  Nodeptr p = list;
  while (p != NULL) {
    list = list->link;
    delete p;
    p = list;
  }
}

bool kiemTraTrungMaCB(Nodeptr& list, int ma) {
  Nodeptr p = list;
  while (p != NULL) {
    if (p->data.maCB == ma)
      return true;
    p = p->link;
  }
  return false;
}

// Cau 1
void nhapDanhSachCayBut(Nodeptr &list) {
  CAYBUT cb;
  khoiTao(list);
  do {
    cout << "\nNhap ma cay but (nhap -99 de dung): ";
    cin >> cb.maCB;
    while (kiemTraTrungMaCB(list, cb.maCB)) {
      cout << "\t\tMa but bi trung";
      cout << "\nNhap lai ma but: ";
      cin >> cb.maCB;
    }
    if (cb.maCB == -99)
      break;
    cout << "Nhap ten cay but: ";
    cin.ignore();
    cin.getline(cb.tenCB, 30);
    cout << "Nhap so luong: ";
    cin >> cb.soLuong;
    cout << "Nhap don gia: ";
    cin >> cb.donGia;
    cout << "Nhap hang san xuat: ";
    cin.ignore();
    cin.getline(cb.hangSX, 30);
    cout << endl;
    themCuoi(list, cb);
  } while (1);
}

void xuatDanhSachCayBut(Nodeptr list) {
  cout << "\n\n\tDANH SACH CAC CAY BUT" << endl;
  cout << setw(10) << left << "Ma CB" << "\t";
  cout << setw(30) << left << "Ten CB" << "\t";
  cout << setw(15) << left << "So luong" << "\t" ;
  cout << setw(15) << left << "Don gia" << "\t";
  cout << setw(30) << left << "Hang san xuat" << "\t" << endl;
  while (list != NULL) {
    cout << setw(10) << left << list->data.maCB << "\t";
    cout << setw(30) << left << list->data.tenCB << "\t";
    cout << setw(15) << left << list->data.soLuong << "\t";
    cout << setw(15) << left << list->data.donGia << "\t";
    cout << setw(30) << left << list->data.hangSX << "\t" << endl;
  list = list->link;
  }
}

// Cau 2

// Cau 3
void sapXepGiamDanTheoDonGia(Nodeptr &list) {
  for (Nodeptr pTmp = list; pTmp != NULL; pTmp = pTmp->link)
    for (Nodeptr pTmp2 = pTmp->link; pTmp2 != NULL; pTmp2 = pTmp2->link)
      if (pTmp->data.donGia < pTmp2->data.donGia) {
        CAYBUT tmp = pTmp->data;
        pTmp->data = pTmp2->data;
        pTmp2->data = tmp;
      }
}

// Phan 2
// Cau 1
void init_Queue(QUEUE& q) {
  q.front = NULL;
  q.rear = NULL;
}

int isEmpty_Queue(QUEUE q) {
  if (q.front == NULL)
    return 1;
  return 0;
}

NODEPTR taoNode_Queue(int x) {
  NODEPTR p;
  p = new NODE;
  p->data = x;
  p->link = NULL;
  return p;
}

void enQueue(QUEUE& q, int x) {
  NODEPTR p;
  p = taoNode_Queue(x);
  if (isEmpty_Queue(q)) {
    q.front = p;
    q.rear = p;
  }
  else {
    q.rear->link = p;
    q.rear = p;
  }
}

void setValue_Queue(QUEUE& q) {
  int x;
  while (1) {
    cout << "Nhap gia tri cho Queue (nhap -99 de dung): ";
    cin >> x;
    if (x == -99)
      break;
    enQueue(q, x);
  }
}

void print_Queue(QUEUE q) {
  NODEPTR p;
  p = q.front;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->link;
  }
}

int deQueue(QUEUE& q) {
  if (isEmpty_Queue(q))
    return -1;
  else {
    NODEPTR p = q.front;
    q.front = p->link;
    int t = p->data;
    delete p;
    return t;
  }
}

int getFront_Queue(QUEUE q) {
  if (isEmpty_Queue(q))
    return -1;
  int x = q.front->data;
  return x;
}

void chenSauNode(QUEUE& q, int x, int pos) {
  QUEUE tam;
  QUEUE p = q;
  init_Queue(tam);
  int vitritam = 0;
  while (vitritam <= pos && !isEmpty_Queue(p)) {
    enQueue(tam, deQueue(p));
    vitritam += 1;
  }
  enQueue(tam, x);
  while (!isEmpty_Queue(p))
    enQueue(tam, deQueue(p));
  q = tam;
}

// Phan 2 - Cau 2
void init_Stack(STACK& s) {
  s.top = NULL;
}

int isEmpty_Stack(STACK s) {
  return s.top == NULL;
}

NODEPTR taoNode_Stack(int x) {
  NODEPTR p;
  p = new NODE;
  p->data = x;
  p->link = NULL;
  return p;
}

void push(STACK& s, int a) {
  NODEPTR p;
  p = taoNode_Stack(a);
  if (isEmpty_Stack(s))
    s.top = p;
  else {
    p->link = s.top;
    s.top = p;
  }
}

void push_top(STACK& s, int a) {
	NODEPTR p;
	p = taoNode_Stack(a);
	if (isEmpty_Stack(s))
		s.top = p;
	else
	{
		NODEPTR q = s.top;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
}

void input_Stack(STACK& s) {
  int x;
  while (1) {
    cout << "Nhap gia tri cho Stack (Nhap -99 de dung): ";
    cin >> x;
    if (x == -99)
      break;
    push(s, x);
  }
}

void output_Stack(STACK s) {
  NODEPTR p = s.top;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->link;
  }
}

int pop(STACK& s) {
  NODEPTR p;
  int a;
  if (!isEmpty_Stack(s)) {
    p = s.top;
    s.top = p->link;
    a = p->data;
    delete p;
    return a;
  }
  return -1;
}

int top(STACK& s) {
  NODEPTR p;
  int a;
  if (!isEmpty_Stack(s)) {
    p = s.top;
    return p->data;
  }
  return -1;
}

void loaiBoCacPhanTuTrongStack(STACK& s, int x) {
  STACK tam;
  STACK p = s;
  init_Stack(tam);
  while (!isEmpty_Stack(p)) {
    if (top(p) != x)
      push_top(tam, pop(p));
    else {
      pop(p);
    }
  }
  s = tam;
}