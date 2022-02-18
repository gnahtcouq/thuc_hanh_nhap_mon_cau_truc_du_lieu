#include<iostream>
using namespace std;
typedef int type;
const int MAX = 50;
const int STOP = -99;
struct Queue {
  int front, rear;
  int elem[MAX];
};
void khoiTao(Queue& q);
int isEmpty(Queue q);
int isFull(Queue q);
int enQueue(Queue& q, type x);
void print(Queue q);
void setValue(Queue& q);
int deQueue(Queue& q);
int xemGiaTriDau(Queue q);

typedef struct Node* Nodeptr;
typedef int TYPEINFO;
struct Node {
  int data;
  Node* link;
};
struct QueueLK {
  Nodeptr front, rear;
};
void khoiTaoLK(QueueLK& k);
int isEmptyLK(QueueLK k);
Nodeptr tao_NodeLK(TYPEINFO x);
void enQueueLK(QueueLK& k, TYPEINFO x);
void setValueLK(QueueLK& k);
void printLK(QueueLK k);
TYPEINFO deQueue(QueueLK& k);
TYPEINFO getFront(QueueLK k);