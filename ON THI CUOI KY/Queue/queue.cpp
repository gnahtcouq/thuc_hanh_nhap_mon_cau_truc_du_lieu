#include<iostream>
using namespace std;
typedef int type;

const int MAX = 50;

typedef struct Node* Nodeptr;
struct Node {
  int data;
  Node* link;
};
struct Queue {
  Nodeptr front, rear;
};
void khoiTao(Queue& q);
int isEmpty(Queue q);
Nodeptr tao_Node(int x);
void enQueue(Queue& q, int x);
void setValue(Queue& q);
void print(Queue q);
int deQueue(Queue& q);
int getFront(Queue q);

int demSoLuongPhanTuX(Queue q, int x);

int main() {
  Queue(q);
  khoiTao(q);
  setValue(q);
  print(q);

  // // Cau 2
  // int cau2lk = deQueue(q);
  // if (cau2lk != -1)
  //   cout << "\nPhan tu duoc lay ra khoi queue la: " << cau2lk;

  // // Cau 3
  // int cau3lk = getFront(q);
  // if (cau3lk != -1)
  //   cout << "\nGia tri dau cua hang doi la: " << cau3lk << endl;

  int x;
  cout << "\nNhap gia tri x can dem so luong: ";
  cin >> x;
  int dem = demSoLuongPhanTuX(q, x);
  cout << "So luong phan tu co gia tri " << x << " trong queue la: " << dem;

  system("pause");
  return 0;
}

// DSLK
// Cau 1
void khoiTao(Queue& q) {
  q.front = NULL;
  q.rear = NULL;
}

int isEmpty(Queue q) {
  if (q.front == NULL)
    return 1;
  return 0;
}

Nodeptr tao_node(int x) {
  Nodeptr p;
  p = new Node;
  p->data = x;
  p->link = NULL;
  return p;
}

void enQueue(Queue& q, int x) {
  Nodeptr p;
  p = tao_node(x);
  if (isEmpty(q)) {
    q.front = p;
    q.rear = p;
  }
  else {
    q.rear->link = p;
    q.rear = p;
  }
}

void setValue(Queue& q) {
  int x;
  while (1) {
    cout << "Nhap gia tri cho Queue(nhap -99 de thoat): ";
    cin >> x;
    if (x == -99) break;
    enQueue(q, x);
  }
}

void print(Queue q) {
  Nodeptr p;
  p = q.front;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->link;
  }
}

// Cau 2
int deQueue(Queue& q) {
  if (isEmpty(q))
    return -1;
  else {
    Nodeptr p = q.front;
    q.front = p->link;
    int t = p->data;
    delete p;
    return t;
  }
}

// Cau 3
int getFront(Queue q) {
  if (isEmpty(q))
    return -1;
  int x = q.front->data;
  return x;
}

int demSoLuongPhanTuX(Queue q, int x) {
  Nodeptr p;
  int a;
  int dem = 0;
  while (isEmpty(q)) {
    p = q.rear;
    a = p->data;
    if (x == a)
      dem++;
    q.rear->link;
  }
  return dem;
}
