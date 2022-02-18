#include "Thang_DH52007101_B7_H.h"

void khoiTao(Queue& q) {
  q.front = -1;
  q.rear = -1;
}

int isEmpty(Queue q) {
  if (q.front == -1)
    return 1;
  return 0;
}

int isFull(Queue q) {
  return (q.rear - q.front == MAX - 1);
}

// Cau 1
int enQueue(Queue& q, type x) {
  int i;
  if (isFull(q))
    return 0;
  else {
    if (q.front == -1)
      q.front = 0;
    else if (q.rear == MAX - 1) {
      for (i = q.front; i <= q.rear; i++)
        q.elem[i - q.front] = q.elem[i];
      q.rear -= q.front;
      q.front = 0;
    }
    q.rear++;
    q.elem[q.rear] = x;
    return q.rear;
  }
}

void print(Queue q) {
  if (isEmpty(q) != -1) {
    for (int i = q.front; i <= q.rear; i++) {
      cout << q.elem[i] << " ";
    }
  }
  else
    cout << "Rong";
}

void setValue(Queue& q) {
  int x;
  while (1) {
    cout << "Nhap DL vao Queue(nhap -99 de thoat): ";
    cin >> x;
    if (x == STOP) break;
    enQueue(q, x);
  }
}

// Cau 2
int deQueue(Queue& q) {
  if (isEmpty(q) != -1) {
    if (q.front == q.rear)
      khoiTao(q);
    else {
      int t = q.elem[q.front];
      q.front = q.front + 1;
      return t;
    }
  }
  return 0;
}

// Cau 3
int xemGiaTriDau(Queue q) {
  return q.elem[q.front];
}


// DSLK
// Cau 1
void khoiTaoLK(QueueLK& k) {
  k.front = NULL;
  k.rear = NULL;
}

int isEmptyLK(QueueLK k) {
  if (k.front == NULL)
    return 1;
  return 0;
}

Nodeptr tao_nodeLK(TYPEINFO x) {
  Nodeptr p;
  p = new Node;
  p->data = x;
  p->link = NULL;
  return p;
}

void EnQueueLK(QueueLK& k, TYPEINFO x) {
  Nodeptr p;
  p = tao_nodeLK(x);
  if (isEmptyLK(k)) {
    k.front = p;
    k.rear = p;
  }
  else {
    k.rear->link = p;
    k.rear = p;
  }
}

void setValueLK(QueueLK& k) {
  int x;
  while (1) {
    cout << "Nhap gia tri cho QueueLK(nhap -99 de thoat): ";
    cin >> x;
    if (x == STOP) break;
    EnQueueLK(k, x);
  }
}

void printLK(QueueLK k) {
  Nodeptr p;
  p = k.front;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->link;
  }
}

// Cau 2
TYPEINFO deQueue(QueueLK& k) {
  if (isEmptyLK(k))
    return -1;
  else {
    Nodeptr p = k.front;
    k.front = p->link;
    TYPEINFO t = p->data;
    delete p;
    return t;
  }
}

// Cau 3
TYPEINFO getFront(QueueLK k) {
  if (isEmptyLK(k))
    return -1;
  int x = k.front->data;
  return x;
}
