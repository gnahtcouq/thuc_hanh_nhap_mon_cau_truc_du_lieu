#include<iostream>
using namespace std;
typedef int TYPEINFO;
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
void xuat_Ds_Nguoc(Dlist L);
void them_Cuoi(Dlist& l, TYPEINFO x);
void xoa_Dau(Dlist& l);
void xoa_Cuoi(Dlist& l);
int tim_Vitri_X(Dlist l, TYPEINFO x);
void giaiPhong(Dlist& list);

// DSLK Vong
typedef int TYPEINFOC;
struct NodeC {
  TYPEINFOC data;
  NodeC* link;
};
typedef NodeC* NodeptrC;
struct List {
  NodeptrC first;
  NodeptrC last;
};
NodeptrC tao_NodeC(TYPEINFOC x);
void khoiTaoC(List& list);
int isEmptyC(List list);
void them_DauC(List& list, TYPEINFOC x);
void them_CuoiC(List& list, TYPEINFOC x);
void readListC(List& list);
void printListC(List list);
void xoa_DauC(List& list);
void xoa_CuoiC(List& list);
int tim_Giatri_X_C(List list, TYPEINFOC x);
void giaiPhong2(List& list);

int main() {
  Dlist list;
  khoi_Tao(list);
  nhap_Ds(list);
  cout << "\nXuat danh sach theo chieu thuan: ";
  xuat_Ds_Thuan(list);

  // Cau 1
  cout << "\nXuat danh sach theo chieu nguoc: ";
  xuat_Ds_Nguoc(list);

  // Cau 2
  // Cau 3
  cout << "\nDanh sach sau khi xoa dau: ";
  xoa_Dau(list);
  xuat_Ds_Thuan(list);

  // Cau 4
  cout << "\nDanh sach sau khi xoa cuoi: ";
  xoa_Cuoi(list);
  xuat_Ds_Thuan(list);

  // Cau 5
  int x;
  cout << "\nNhap phan tu can tim: ";
  cin >> x;
  int result = tim_Vitri_X(list, x);
  if (result == -2)
    cout << "Khong co phan tu can tim";
  else
    cout << "Phan tu can tim o vi tri: " << result << endl;
  
  giaiPhong(list);

  // Cau 6
  List list2;
  khoiTaoC(list2);
  readListC(list2);
  printListC(list2);

  // Cau 7a
  xoa_DauC(list2);
  cout << "\nDSLK vong sau khi xoa dau: ";
  printListC(list2);

  // Cau 7b
  xoa_CuoiC(list2);
  cout << "\nDSLK vong sau khi xoa cuoi: ";
  printListC(list2);

  // Cau 8
  int x2;
  cout << "\nNhap phan tu can tim: ";
  cin >> x2;
  int result2 = tim_Giatri_X_C(list2, x2);
  if (result2 == 0)
    cout << "Tim thay";
  else
    cout << "Khong tim thay";

  giaiPhong2(list2);

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

// Cau 1
void xuat_Ds_Nguoc(Dlist L) {
  Nodeptr p = L.last;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->pre;
  }
}

// Cau 2
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

// Cau 3
void xoa_Dau(Dlist& l) {
  if (l.first != NULL) {
    Nodeptr p = l.first;
    l.first = l.first->next;
    delete p;
    if (l.first != NULL) {
      l.first->pre = NULL;
    }
  }
}

// Cau 4
void xoa_Cuoi(Dlist& l) {
  if (l.first->next == NULL) {
    xoa_Dau(l);
    return;
  }
  Nodeptr p = l.last;
  (p->pre)->next = NULL;
  l.last = p->pre;
  delete p;
}

// Cau 5
int tim_Vitri_X(Dlist l, TYPEINFO x) {
  int vitri = 0;
  Nodeptr p = l.first;
  while (p != NULL) 	{
    vitri++;
    if (p->data == x)
      return vitri - 1;
    p = p->next;
  }
  return -2;
}

void giaiPhong(Dlist& list) {
  Nodeptr p;
  while (list.first != NULL) {
    p = list.first;
    list.first = list.first->next;
    delete p;
  }
}

// DSLK Vong
// Cau 6a
NodeptrC tao_NodeC(TYPEINFOC x) {
  NodeptrC p = new NodeC;
  if (p == NULL)
    return 0;
  p->link = NULL;
  p->data = x;
  return p;
}
void khoiTaoC(List& list) {
  list.first = list.last = NULL;
}
int isEmptyC(List list) {
  if (list.first == NULL)
    return 1;
  return 0;
}
void them_DauC(List& list, TYPEINFOC x) {
  NodeptrC p = tao_NodeC(x);
  if (isEmptyC(list) == 1)
    list.first = list.last = p;
  else {
    p->link = list.first;
    list.first = p;
  }
  list.last->link = list.first;
}

void readListC(List& list) {
  int x;
  do {
    cout << "Nhap x = (thoat-99) ";
    cin >> x;
    if (x == -99)
      break;
    // them_DauC(list, x);
    them_CuoiC(list, x);
  } while (1);
}

void printListC(List list) {
  if (list.first != NULL) {
    NodeptrC p = list.first;
    do {
      cout << p->data << " ";
      p = p->link;
    } while (p != list.first);
  }
  else
    cout << "\nDS rong";
}

// Cau 6b
void them_CuoiC(List& list, TYPEINFOC x) {
  NodeptrC p;
  p = tao_NodeC(x);
  if (isEmptyC(list) == 1) {
    list.first = list.last = p;
  }
  else {
    list.last->link = p;
    list.last = p;
  }
  list.last->link = list.first;
}

// Cau 7a
void xoa_DauC(List& list) {
  if (list.first != NULL) {
    if (list.first != list.last) {
      NodeptrC p = list.first;
      list.first = list.first->link;
      list.last->link = list.first;
      delete p;
    }
    else
      list.first = NULL;
  }
}

// Cau 7b
void xoa_CuoiC(List& list) {
  if (list.last != NULL) {
    if (list.last != list.first) {
      NodeptrC p = list.first;
      while (p->link != list.last) p = p->link;
      NodeptrC q = list.last;
      list.last = p;
      list.last->link = list.first;
      delete q;
    }
    else
      list.last = NULL;
  }
}

// Cau 8
int tim_Giatri_X_C(List list, TYPEINFOC x) {
	if (list.first != NULL) {
		NodeptrC p = list.first;
		do {
			if (p->data == x) 
				return 0;
			p = p->link;
		} while (p != list.first);
	}
  return 1;
}

void giaiPhong2(List& list) {
  NodeptrC p;
  while (list.first != NULL) {
    p = list.first;
    list.first = list.first->link;
    delete p;
  }
}