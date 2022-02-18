#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* pNext;
};
typedef struct Node NODE;

struct List {
  NODE* pHead, * pTail;
};
typedef struct List LIST;

void khoiTao(LIST& l);
NODE* taoNode(int x);
void themDau(LIST& l, NODE* p);
void themCuoi(LIST& l, NODE* p);
void nhap(LIST& l);
void xuat(LIST& l);
void giaiPhong(LIST& l);

int main() {
  LIST l;
  nhap(l);
  xuat(l);

  giaiPhong(l);
  cout << endl;
  return 0;
}

void khoiTao(LIST& l) {
  l.pHead = l.pTail = NULL;
}

NODE* taoNode(int x) {
  NODE* p = new NODE;
  if (p == NULL) {
    cout << "\nKhong du bo nho de cap phat";
    return NULL;
  }
  p->data = x;
  p->pNext = NULL;
  return p;
}

void themDau(LIST& l, NODE* p) {
  if (l.pHead == NULL) {
    l.pHead = l.pTail = p;
  }
  else {
    p->pNext = l.pHead;
    l.pHead = p;
  }
}

void themCuoi(LIST& l, NODE* p) {
  if (l.pHead == NULL) {
    l.pHead = l.pTail = p;
  }
  else {
    l.pTail->pNext = p;
    l.pTail = p;
  }
}

void nhap(LIST& l) {
  khoiTao(l);
  int n;
  cout << "\nNhap so luong phan tu trong danh sach: ";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int data;
    cout << "\nNhap vao data: ";
    cin >> data;
    NODE* p = taoNode(data);
    themCuoi(l, p);
  }
}

void xuat(LIST& l) {
  for (NODE* p = l.pHead; p != NULL; p = p->pNext) {
    cout << p->data << " ";
  }
}

void giaiPhong(LIST& l) {
  NODE* p;
  while (l.pHead != NULL) {
    p = l.pHead;
    l.pHead = l.pHead->pNext;
    delete p;
  }
}