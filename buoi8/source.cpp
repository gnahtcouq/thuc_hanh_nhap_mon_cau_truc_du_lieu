#include<iostream>
using namespace std;
#define MAXSTACK 100
const int stop = -99;
typedef int TYPE;
struct Stack {
  int sp;
  TYPE elem[MAXSTACK];
};
void init_Stack(Stack& s);
int isEmpty(Stack s);
int isFull(Stack s);
void push(Stack& s, int x);
int pop(Stack& s);
void input_Stack(Stack& s);
void output_Stack(Stack s);
void get_Stack(Stack& s);
int top(Stack s);

typedef int TYPEINFO;
struct Node {
  TYPEINFO data;
  Node* link;
};
typedef Node* Nodeptr;
struct Stack_DSLK {
  Nodeptr top;
};

void init_Stack_DSLK(Stack_DSLK& s);
int isEmpty_DSLK(Stack_DSLK s);
Nodeptr tao_Node_DSLK(TYPEINFO x);
void push_DSLK(Stack_DSLK& s, TYPEINFO a);
int pop_DSLK(Stack_DSLK& s);
int top_DSLK(Stack_DSLK& s);
void input_Stack_DSLK(Stack_DSLK& s);
void output_Stack_DSLK(Stack_DSLK s);
int top_DSLK(Stack_DSLK& s);

int main() {
  Stack s;
  init_Stack(s);
  input_Stack(s);
  output_Stack(s);
  int get = pop(s);
  cout << "\nPhan tu dau bi lay ra khoi stack la: " << get;
  cout << "\nDanh sach cac phan tu con lai trong stack la: ";
  output_Stack(s);
  int cau3 = top(s);
  cout << "\nPhan tu dau cua stack la: " << cau3;

  // DSLK
  Stack_DSLK k;
  init_Stack_DSLK(k);
  input_Stack_DSLK(k);
  output_Stack_DSLK(k);
  cout << "\nPhan tu o top la: " << pop_DSLK(k);
  cout << "\nDanh sach sau khi pop la: ";
  output_Stack_DSLK(k);
  cout << "\nPhan tu o top la: " << top_DSLK(k);
  cout << "\nDanh sach sau khi top la: ";
  output_Stack_DSLK(k);

  return 0;
}

void init_Stack(Stack& s) {
  s.sp = -1;
}

int isEmpty(Stack s) {
  return s.sp == -1;
}

int isFull(Stack s) {
  return s.sp == MAXSTACK - 1;
}

void push(Stack& s, int x) {
  if (isFull(s))
    cout << "\n Ngan xep day";
  else {
    s.sp++;
    s.elem[s.sp] = x;
  }
}

void output_Stack(Stack s) {
  for (int i = 0; i <= s.sp; i++)
    cout << s.elem[i] << " ";
}

void input_Stack(Stack& s) {
  cout << "Nhap gia tri cho stack (Nhap 0 de ket thuc): " << endl;
  int x;
  do {
    cin >> x;
    if (x != 0)
      push(s, x);
  } while (x != 0);
}

int pop(Stack& s) {
  int a;
  if (isEmpty(s))
    return -1;
  else {
    a = s.elem[s.sp];
    s.elem[s.sp--];
  }
  return a;
}

int top(Stack s) {
  if (isEmpty(s))
    cout << "\nNgan xep rong!" << endl;
  else {
    int x = s.elem[s.sp];
    s.sp--;
    return x;
  }
}

// DSLK
void init_Stack_DSLK(Stack_DSLK& s) {
  s.top = NULL;
}

int isEmpty_DSLK(Stack_DSLK s) {
  return s.top == NULL;
}

Nodeptr tao_Node_DSLK(TYPEINFO x) {
  Nodeptr p; p = new Node;
  p->data = x;
  p->link = NULL;
  return p;
}

void push(Stack_DSLK& s, TYPEINFO a) {
  Nodeptr p;
  p = tao_Node_DSLK(a);
  if (isEmpty_DSLK(s))
    s.top = p;
  else {
    p->link = s.top;
    s.top = p;
  }
}

void input_Stack_DSLK(Stack_DSLK& s) {
  int x;
  while (1) {
    cout << "Nhap gia tri cho Stack (Nhap -99) de dung: ";
    cin >> x;
    if (x == stop)
      break;
    push(s, x);
  }
}

void output_Stack_DSLK(Stack_DSLK s) {
  Nodeptr p = s.top;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->link;
  }
}

int pop_DSLK(Stack_DSLK& s) {
  Nodeptr p;
  TYPEINFO a;
  if (!isEmpty_DSLK(s)) {
    p = s.top;
    s.top = p->link;
    a = p->data;
    delete p;
    return a;
  }
}

int top_DSLK(Stack_DSLK& s) {
  Nodeptr p;
  TYPEINFO a;
  if (!isEmpty_DSLK(s)) {
    p = s.top;
    return p->data;
  }
}

void xoaPhanTuXThu2TroDi(STACK& s, int x) {
  STACK tam;
  STACK p = s;
  khoiTao_StackLK(tam);
  int check = 0;
  while (!isEmpty_StackLK(p)) {
    if (top_StackLK(p) != x)
      pushtop_StackLK(tam, pop_StackLK(p));
    else {
      if (check == 0)
        pushtop_StackLK(tam, pop_StackLK(p));
      check++;
      if (check > 1)
        pop_StackLK(p);
    }
  }
  s = tam;
}