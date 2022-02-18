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