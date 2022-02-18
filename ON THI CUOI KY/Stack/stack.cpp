#include<iostream>
using namespace std;
#define MAXSTACK 100
const int stop = -99;

struct Node {
  int data;
  Node* link;
};
typedef Node* Nodeptr;
struct Stack {
  Nodeptr top;
};

void init_Stack(Stack& s);
int isEmpty(Stack s);
Nodeptr tao_Node(int x);
void push(Stack& s, int a);
int pop(Stack& s);
int top(Stack& s);
void input_Stack(Stack& s);
void output_Stack(Stack s);

int demSoLuongPhanTuX(Stack s, int x);
int timViTriPhanTuXDauTien(Stack s, int x);
bool kiemTraNganXepCoTangHayKhong(Stack s);

int main() {
  // DSLK
  Stack s;
  init_Stack(s);
  input_Stack(s);
  output_Stack(s);

  // // Cau 1
  // int x;
  // cout << "\nNhap gia tri x can dem: ";
  // cin >> x;
  // int dem = demSoLuongPhanTuX(s, x);
  // cout << "So luong " << x << " = " << dem << endl;

  // // Cau 2
  // cout << "\nNhap gia tri can xuat ra vi tri dau tien: ";
  // cin >> x;
  // int vitri = timViTriPhanTuXDauTien(s, x);
  // cout << "\nVi tri gia tri " << x << " dau tien = " << vitri << endl;

  // Cau 3
  if (kiemTraNganXepCoTangHayKhong(s))
    cout << "\nNgan xep tang";
  else
    cout << "\nNgan xep khong tang";

  system("pause");
  return 0;
}

// DSLK
void init_Stack(Stack& s) {
  s.top = NULL;
}

int isEmpty(Stack s) {
  return s.top == NULL;
}

Nodeptr tao_Node(int x) {
  Nodeptr p;
  p = new Node;
  p->data = x;
  p->link = NULL;
  return p;
}

void push(Stack& s, int a) {
  Nodeptr p;
  p = tao_Node(a);
  if (isEmpty(s))
    s.top = p;
  else {
    p->link = s.top;
    s.top = p;
  }
}

void input_Stack(Stack& s) {
  int x;
  while (1) {
    cout << "Nhap gia tri cho Stack (Nhap -99) de dung: ";
    cin >> x;
    if (x == stop)
      break;
    push(s, x);
  }
}

void output_Stack(Stack s) {
  Nodeptr p = s.top;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->link;
  }
}

int pop(Stack& s) {
  Nodeptr p;
  int a;
  if (!isEmpty(s)) {
    p = s.top;
    s.top = p->link;
    a = p->data;
    delete p;
    return a;
  }
  return -1;
}

int top(Stack& s) {
  Nodeptr p;
  int a;
  if (!isEmpty(s)) {
    p = s.top;
    return p->data;
  }
  return -1;
}

// Cau 1
int demSoLuongPhanTuX(Stack s, int x) {
  Nodeptr p;
  int a;
  int dem = 0;
  while (!isEmpty(s)) {
    p = s.top;
    a = p->data;
    if (x == a)
      dem++;
    s.top = p->link;
  }
  return dem;
}

// Cau 2
int timViTriPhanTuXDauTien(Stack s, int x) {
  Nodeptr p;
  int a;
  int vitri = 0;
  int vitrireal;
  while (!isEmpty(s)) {
    p = s.top;
    a = p->data;
    vitri++;
    if (x == a) {
      vitrireal = vitri;
      break;
    }
    s.top = p->link;
  }
  return vitrireal - 1;
}

// Cau 3
bool kiemTraNganXepCoTangHayKhong(Stack s) {
  Nodeptr p;
  int a;
  int flag = 0;
  while (!isEmpty(s)) {
    p = s.top;
    a = p->data;
    pop(s);
    if (a < s.top->data) {
      flag = 0;
    }
    s.top = p->link;
  }
  if (flag == 0)
    return true;
  return false;
}