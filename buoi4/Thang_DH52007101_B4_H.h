#include <iostream>
using namespace std;
typedef int TYPEINFO;
struct Node
{
	TYPEINFO data;
	Node *link;
};
typedef Node *Nodeptr;
void khoiTao(Nodeptr &list);
int isEmpty(Nodeptr list);
Nodeptr tao_Node(TYPEINFO x);
Nodeptr them_Dau(Nodeptr &list, TYPEINFO x);
void nhap_DanhSach(Nodeptr &list);
void xuat_DanhSach(Nodeptr list);
void giaiPhong(Nodeptr &list);
Nodeptr them_Cuoi(Nodeptr &list, TYPEINFO x);
void nhap_DanhSach1(Nodeptr &list);
Nodeptr tim_Node_X(Nodeptr list, TYPEINFO x);
Nodeptr chenSau_Q(Nodeptr q, TYPEINFO x);
void chenSau(Nodeptr &list);
void xoa_Dau(Nodeptr &list);
void xoa_Cuoi(Nodeptr &list);
void del_node_x(Nodeptr &list, int x);
void daoNguocDSLK(Nodeptr &list);
void tachDSLKChanLe(Nodeptr &list, Nodeptr &chan, Nodeptr &le);
void del_All_X(Nodeptr &list, int x);