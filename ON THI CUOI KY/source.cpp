#include <iostream>
using namespace std;

struct Node {
  int value;
  Node *next; // *link
};
typedef Node* Nodeptr;

void init(Nodeptr &head) {
  head = NULL;
}

Nodeptr createNode(int x) {
  Nodeptr p = new Node;
  p->value = x;
  p->next = NULL;
  return p;
}

Nodeptr addFirst(Nodeptr &head, int x) {
  Nodeptr p = createNode(x);
  p->next = head;
  head = p;
  return p;
}

Nodeptr addLast(Nodeptr &head, int x) {
  Nodeptr p = createNode(x);
  // Xac dinh node cuoi cung (last)
  Nodeptr last = head;
  if (head == NULL) { // Kiem tra danh sach rong
    head = p;
  }
  else {
    while (last->next != NULL) { // NullPointer
      last = last->next;
    }
    last->next = p;
  }
  return p;
}

void addAfter(Nodeptr head, int nodecantim, int x) {
  Nodeptr p = createNode(x);

  // Tim node co gia tri la v
  Nodeptr q = head;
  while (q != NULL && q->value != nodecantim) {
    q = q->next;
  }
  // q la node dai dien cho nodecantim tren DSLK
  if (q != NULL) { // Trong danh sach co phan tu gia tri nodecantim
    p->next = q->next;
    q->next = p;
  }
}

void deleteFirst(Nodeptr &head) {
  Nodeptr p = head;
  if (head != NULL) {
    head = p->next;
    p->next = NULL;
    delete p;
  }
}

void deleteLast(Nodeptr &head) {
  if (head != NULL) {
    // Xac dinh node cuoi cung va node truoc cua node cuoi cung
    Nodeptr last = head;
    Nodeptr prev = NULL;
    while (last->next != NULL) {
      prev = last;
      last = last->next;
    }
    if (prev == NULL) { // Danh sach chi co 1 phan tu
      deleteFirst(head);
    }
    else {
      // Xoa phan tu cuoi cung
      prev->next = NULL;
      delete last;
    }
  }
}

Nodeptr search(Nodeptr head, int x) {
	Nodeptr p = head;
	while (p != NULL) {
		if (p->value == x)
			return p;
		p = p->next;
	}
	return p;
}

void deleteNode(Nodeptr &head, int x) {
  if (head != NULL) {
    Nodeptr p = head;
    Nodeptr prev = NULL;
    while (p != NULL && p->value != x) {
      prev = p;
      p = p->next;
    }
    if (p != NULL) { // Tim thay phan tu can xoa
      if (prev == NULL) { // Danh sach chi co 1 phan tu
        deleteFirst(head);
      }
      else {
        prev->next = p->next;
        p->next = NULL;
        delete p;
      }
    }
  }
}

void clean(Nodeptr &head) {
  while (head != NULL) {
    deleteFirst(head);
  }
}

void outPut(Nodeptr head) {
  Nodeptr p = head;
  while (p != NULL) {
    cout << p->value << " ";
    p = p->next;
  }
}

int main() {
  Nodeptr head;
  init(head);


  system("pause");
  return 0;
}

// https://dotnet.edu.vn/ChuyenMuc/Danh-sach-Lien-ket-Don-787.aspx