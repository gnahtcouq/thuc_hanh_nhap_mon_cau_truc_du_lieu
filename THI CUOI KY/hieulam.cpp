#include<iostream>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;
typedef float TYPEINFO;
struct Node {
  TYPEINFO data;
  Node* next;
  Node* pre;
};
typedef Node* Nodeptr;
struct Dlist {
  Nodeptr first;
  Nodeptr last;
};
void khoi_Tao(Dlist& list);
int isEmpty(Dlist L);
Nodeptr tao_Node(TYPEINFO x);
void them_Dau(Dlist& L, TYPEINFO x);
void nhap_Ds(Dlist& L);
void xuat_Ds_Thuan(Dlist list);
void them_Cuoi(Dlist& l, TYPEINFO x);
int tim_ViTriXuatHienSauCung(Dlist l);
void giaiPhong(Dlist& list);


struct NodeTree {
  int Data;
  struct NodeTree* Left, * Right;
  bool TinhTrangDuyet;
  int ThuTuDuyet;
  struct NodeTree* Cha;
};
typedef struct NodeTree NODE;

NODE* TimKiemNode_KhuDeQuy(NODE* Root, int x);
NODE* TimKiemNode_DeQuy(NODE* Root, int x, NODE* NodeTruocNull);
void INit(NODE*& Root);
NODE* GetNode(int x);
int ThemNodeVaoCay_KhuDeQuy(NODE*& Root, int x);
void TaoCayTuDaySo(NODE*& Root, int a[], int n);
void NLR(NODE* Root);
void LRN(NODE* Root);

int main() {
  Dlist list;
  khoi_Tao(list);
  nhap_Ds(list);
  cout << "\nXuat danh sach theo chieu xuoi: ";
  xuat_Ds_Thuan(list);
  int result = tim_ViTriXuatHienSauCung(list);
  if (result == -1)
    cout << "\nKhong co phan tu can tim";
  else
    cout << "\nVi tri phan tu xuat hien sau cung: " << result << endl;
  giaiPhong(list);

  // Phan 2

  int a[] = { 40, 5, 35, 45, 15, 56, 35, 35, 35, 48, 13, 16, 49, 47 };
  int n = sizeof(a) / sizeof(a[0]);

  NODE* Root;
  INit(Root);
  TaoCayTuDaySo(Root, a, n);

  for (int i = 0; i < n; i++)
    cout << a[i] << " ";

  int x2;
  cout << "\nNhap x can tim: ";
  cin >> x2;
  NODE* p = TimKiemNode_DeQuy(Root, x2, Root);
  if (p->Data != x2)
    cout << "\nKhong tim thay node trong cay co gia tri la: " << x2;
  else
    cout << "\nDa tim thay node trong cay co gia tri la: " << p->Data;

  cout << "\nNLR: ";
  NLR(Root);
  cout << "\nLRN: ";
  LRN(Root);

  cout << endl;
  system("pause");
  return 0;
}

void khoi_Tao(Dlist& list) {
  list.first = NULL;
  list.last = NULL;
}

int isEmpty(Dlist list) {
  return (list.first == NULL ? 1 : 0);
}

Nodeptr tao_Node(TYPEINFO x) {
  Nodeptr p;
  p = new Node;
  p->data = x;
  p->next = NULL;
  p->pre = NULL;
  return p;
}

void them_Dau(Dlist& list, TYPEINFO x) {
  Nodeptr p;
  p = tao_Node(x);
  if (isEmpty(list)) {
    list.first = p;
    list.last = p;
  }
  else {
    p->next = list.first;
    list.first->pre = p;
    list.first = p;
  }
}

void nhap_Ds(Dlist& list) {
  int x;
  khoi_Tao(list);
  do {
    cout << "Nhap x = (-99 de thoat) ";
    cin >> x;
    if (x == -99)
      break;
    // them_Dau(list, x);
    them_Cuoi(list, x);
  } while (1);
}

void xuat_Ds_Thuan(Dlist list) {
  Nodeptr p = list.first;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->next;
  }
}

void them_Cuoi(Dlist& l, TYPEINFO x) {
  Nodeptr p;
  p = tao_Node(x);
  if (isEmpty(l)) {
    l.first = p;
    l.last = p;
  }
  else {
    l.last->next = p;
    p->pre = l.last;
    l.last = p;
  }
}

int tim_ViTriXuatHienSauCung(Dlist l) {
  int vitri = 0;
  Nodeptr p = l.first;
  while (p != NULL) {
    vitri++;
    if (p->data == l.last->data)
      return vitri - 1;
    p = p->next;
  }
  return -1;
}

void giaiPhong(Dlist& list) {
  Nodeptr p;
  while (list.first != NULL) {
    p = list.first;
    list.first = list.first->next;
    delete p;
  }
}

// Phan 2
void INit(NODE*& Root) {
  Root = NULL;
}

NODE* GetNode(int x) {
  NODE* p = (NODE*)malloc(sizeof(NODE));
  if (p == NULL)
    return NULL;

  p->Data = x;
  p->Left = p->Right = NULL;
  p->ThuTuDuyet = 0;
  p->TinhTrangDuyet = false;
  p->Cha = NULL;

  return p;
}


void NLR(NODE* Root) {
  if (Root != NULL) {
    cout << Root->Data << " ";
    NLR(Root->Left);
    NLR(Root->Right);
  }
}

void LRN(NODE* Root) {
  if (Root != NULL) {
    LRN(Root->Left);
    LRN(Root->Right);
    cout << Root->Data << " ";
  }
}

NODE* TimKiemNode_DeQuy(NODE* Root, int x, NODE* NodeTruocNull) {
  if (Root == NULL)
    return NodeTruocNull;

  if (x > Root->Data)
    return TimKiemNode_DeQuy(Root->Right, x, Root);
  else if (x < Root->Data)
    return TimKiemNode_DeQuy(Root->Left, x, Root);
  else
    return Root;
}

int ThemNodeVaoCay_KhuDeQuy(NODE*& Root, int x) {
  if (Root == NULL) {
    Root = GetNode(x);
  }
  else {

    NODE* p = TimKiemNode_DeQuy(Root, x, Root);

    if (p->Data != x) {
      NODE* ConMoi = GetNode(x);

      if (ConMoi == NULL)
        return -1;
      if (x > p->Data)
        p->Right = ConMoi;
      else if (x < p->Data)
        p->Left = ConMoi;

      ConMoi->Cha = p;
    }
    else {
      return 0;
    }
  }
  return 1;
}

void TaoCayTuDaySo(NODE*& Root, int a[], int n) {
  INit(Root);
  for (int i = 0; i < n; ++i) {
    ThemNodeVaoCay_KhuDeQuy(Root, a[i]);
  }
}