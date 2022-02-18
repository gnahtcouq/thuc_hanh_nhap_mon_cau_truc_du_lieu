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
int timSoLuongMax(Nodeptr list);
void xuatMaSoCayButConSoLuongTonKhoNhieuNhat(Nodeptr list);
void xoaButBangHangSX(Nodeptr& list, CAYBUT cb);
void xoaThongTinTatCaButThuocHangX(Nodeptr& list, char *str);

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
void xoaPhanTuXThu2TroDi(QUEUE& q, int x);
// void chenSauNode(QUEUE& q, int x, int pos);

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
void daoNguocThuTuStack(STACK &s);
// void xoaPhanTuXThu2TroDi(STACK& s, int x);

int main() {
  // // Phan 1 - Cau 1
  // Nodeptr ds;
  // nhapDanhSachCayBut(ds);
  // xuatDanhSachCayBut(ds);
  // // Phan 1 - Cau 2
  // cout << endl;
  // xuatMaSoCayButConSoLuongTonKhoNhieuNhat(ds);

  // // Phan 1 - Cau 3
  // char str[30];
  // cin.ignore();
  // cout << "\nNhap Hang SX can xoa tat ca but: ";
  // cin.getline(str, 30);
  // xoaThongTinTatCaButThuocHangX(ds, str);
  // xuatDanhSachCayBut(ds);


  // // Phan 2 - Cau 1
  // QUEUE q;
  // init_Queue(q);
  // setValue_Queue(q);
  // print_Queue(q);
  // int x2;
  // cout << "\nNhap phan tu can xoa: ";
  // cin >> x2;
  // xoaPhanTuXThu2TroDi(q, x2);
  // cout << "\nQueue sau khi xoa: ";
  // print_Queue(q);


  // Phan 2 - Cau 2
  STACK s;
  init_Stack(s);
  input_Stack(s);
  output_Stack(s);
  daoNguocThuTuStack(s);
  cout << "\nNgan xep Stack sau khi dao nguoc: ";
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

// Phan 1 - Cau 1
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



// Phan 1 - Cau 2
int timSoLuongMax(Nodeptr list) {
  Nodeptr p;
  int max = list->data.soLuong;
  p = list->link;
  while (p != NULL) {
    if (max < p->data.soLuong)
      max = p->data.soLuong;
    p = p->link;
  }
  return max;
}

void xuatMaSoCayButConSoLuongTonKhoNhieuNhat(Nodeptr list) {
  int max = timSoLuongMax(list);
  if (list != NULL) {
    Nodeptr p = list;
    while (p != NULL) {
      if (p->data.soLuong == max) {
        cout << "Ma " << p->data.maCB << " ton kho so luong but nhieu nhat" << endl;
      }
      p = p->link;
    }
  }
}

// Phan 1 - Cau 3
void xoaButBangHangSX(Nodeptr& list, CAYBUT cb) {
  if (strcmp(list->data.hangSX, cb.hangSX) == 0) {
    Nodeptr p = list;
    list = list->link;
    delete p;
  }
  else {
    Nodeptr p, before;
    p = list;
    before = list;
    while (p != NULL && strcmp(p->data.hangSX, cb.hangSX) != 0) {
      before = p;
      p = p->link;
    }
    if (p != NULL) {
      before->link = p->link;
      delete p;
    }
  }
}

void xoaThongTinTatCaButThuocHangX(Nodeptr& list, char *str) {
  if (list != NULL) {
    Nodeptr p = list, q;
    while (p != NULL) {
      if (strcmp(p->data.hangSX, str) == 0) {
        q = p->link;
        xoaButBangHangSX(list, p->data);
        p = q;
      }
      else
        p = p->link;
    }
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

void xoaPhanTuXThu2TroDi(QUEUE& q, int x) {
  QUEUE tam;
  QUEUE p = q;
  init_Queue(tam);
  int check = 0;
  while (!isEmpty_Queue(p)) {
    if (getFront_Queue(p) != x)
      enQueue(tam, deQueue(p));
    else {
      if (check == 0)
        enQueue(tam, deQueue(p));
      check++;
      if (check > 1)
        deQueue(p);
    }
  }
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

// Phan 2 - Cau 3
void daoNguocThuTuStack(STACK &s) {
  STACK p = s;
  STACK temp;
  init_Stack(temp);
  while (!isEmpty_Stack(p)) {
    push(temp, pop(p));
  }
  s = temp;
}
