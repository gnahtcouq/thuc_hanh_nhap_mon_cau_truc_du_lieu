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