#include<iostream>
using namespace std;

struct Node {
  int data;
  Node* link;
};
typedef Node* Nodeptr;
struct Stack {
  Nodeptr top;
};

void init(Stack& s);
int isEmpty(Stack s);
Nodeptr tao_Node(int x);
void push(Stack& s, int a);
int pop(Stack& s);
int top(Stack& s);
void input_Stack(Stack& s);
void output_Stack(Stack s);

int demSoLuongPhanTuCoGiaTriX(Stack s, int x);
int timViTriDauTienPhanTuCoGiaTriX(Stack s, int x);
int timViTriCuoiCungPhanTuCoGiaTriX(Stack s, int x);
int timViTriThu2PhanTuCoGiaTriX(Stack s, int x);
void xoaPhanTuX(Stack &s, int x);

int main() {
  Stack s;
  init(s);
  input_Stack(s);
  output_Stack(s);

  // Cau 1
  int x;
  cout << "\nNhap gia tri x = ";
  cin >> x;
  int dem = demSoLuongPhanTuCoGiaTriX(s, x);
  cout << "So luong phan tu co gia tri la " << x << " = " << dem << endl;

  // Cau 2
  cout << "\nNhap gia tri x = ";
  cin >> x;
  cout << "Vi tri dau tien cua " << x << " = " << timViTriDauTienPhanTuCoGiaTriX(s, x) << endl;
  // Cau 4
  cout << "Vi tri cuoi cung cua " << x << " = " << timViTriCuoiCungPhanTuCoGiaTriX(s, x) << endl;
  // Cau 5
  cout << "Vi tri thu 2 cua " << x << " = " << timViTriThu2PhanTuCoGiaTriX(s, x) << endl;
  // Cau 6
  cout << "\nNgan xep sau khi xoa " << x << endl;
  xoaPhanTuX(s, x);
  output_Stack(s);

  system("pause");
  return 0;
}

void init(Stack& s) {
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
    cout << "Nhap gia tri cho Stack (Nhap -99 de dung): ";
    cin >> x;
    if (x == -99)
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
int demSoLuongPhanTuCoGiaTriX(Stack s, int x) {
  Nodeptr p;
  int dem = 0;
  while (!isEmpty(s)) {
    p = s.top;
    int a = p->data;
    if (x == a)
      dem++;
    s.top = p->link;
  }
  return dem;
}

// Cau 2
int timViTriDauTienPhanTuCoGiaTriX(Stack s, int x) {
  Nodeptr p;
  int i = 0;
  int vitri;
  while (!isEmpty(s)) {
    p = s.top;
    int a = p->data;
    i++;
    if (x == a) {
      vitri = i - 1;
      break;
    }
    s.top = p->link;
  }
  return vitri;
}

// Cau 4
int timViTriCuoiCungPhanTuCoGiaTriX(Stack s, int x) {
  Nodeptr p;
  int i = 0;
  int vitri;
  while (!isEmpty(s)) {
    p = s.top;
    int a = p->data;
    i++;
    if (x == a) {
      vitri = i - 1;
    }
    s.top = p->link;
  }
  return vitri;
}

// Cau 5
int timViTriThu2PhanTuCoGiaTriX(Stack s, int x) {
  Nodeptr p;
  int i = 0;
  int check = 0;
  int vitri;
  while (!isEmpty(s)) {
    p = s.top;
    int a = p->data;
    i++;
    if (x == a) {
      check++;
      if (check == 2) {
        vitri = i - 1;
      }
    }
    s.top = p->link;
  }
  return vitri;
}

// Cau 6
void xoaPhanTuX(Stack &s, int x) {
  Nodeptr p = s.top;
  Stack temp;
  while (p != NULL) {
    if (p->data != x) {
      push(temp, pop(s));
    }
    p = p->link;
  }
  // s = temp;
  while (temp.top != NULL) {
    push(s, pop(temp));
  }
}