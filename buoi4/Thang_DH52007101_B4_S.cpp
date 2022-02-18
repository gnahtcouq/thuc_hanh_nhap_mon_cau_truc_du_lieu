#include "Thang_DH52007101_B4_H.h"

// Cau 1
void khoiTao(Nodeptr& list) {
	list = NULL;
}
int isEmpty(Nodeptr list) {
	return (list == NULL ? 1 : 0);
}
Nodeptr tao_Node(TYPEINFO x) {
	Nodeptr p;
	p = new Node;
	p->data = x;
	p->link = NULL;
	return p;
}
Nodeptr them_Dau(Nodeptr& list, TYPEINFO x) {
	Nodeptr p;
	p = tao_Node(x);
	p->link = list;
	list = p;
	return p;
}

void nhap_DanhSach(Nodeptr& list)
{
	khoiTao(list);
	int x;
	do {
		cout << "\n Nhap vao x = (thoat -99) ";
		cin >> x;
		if (x == -99)
			break;
		them_Dau(list, x);
	} while (1);
}
void xuat_DanhSach(Nodeptr list) {
	Nodeptr p = list;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->link;
	}
}
void giaiPhong(Nodeptr& list) {
	Nodeptr p = list;
	while (p != NULL) {
		list = list->link;
		delete p;
		p = list;
	}
}
// Cau 2
Nodeptr them_Cuoi(Nodeptr& list, TYPEINFO x) {
	Nodeptr p;
	p = tao_Node(x);
	if (list == NULL)
		list = p;
	else {
		Nodeptr q = list;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
	return p;
}
void nhap_DanhSach1(Nodeptr& list)
{
	khoiTao(list);
	int x;
	do {
		cout << "\n Nhap vao x = (thoat -99) ";
		cin >> x;
		if (x == -99)
			break;
		them_Cuoi(list, x);
	} while (1);
}
// Cau 3
Nodeptr tim_Node_X(Nodeptr list, TYPEINFO x) {
	Nodeptr p = list;
	while (p != NULL) {
		if (p->data == x)
			return p;
		p = p->link;
	}
	return p;
}
// Cau 4
Nodeptr chenSau_Q(Nodeptr q, TYPEINFO x) {
	Nodeptr p = tao_Node(x);
	p->link = q->link;
	q->link = p;
	return q;
}
void chenSau(Nodeptr& list) {
	int x, q;
	cout << "\nNhap phan tu can tim: ";
	cin >> q;
	if (tim_Node_X(list, q) == NULL){
		cout << "\nKhong tim thay";
	}
	else{
		cout << "\nHay nhap phan tu can chen: ";
		cin >> x;
		chenSau_Q(tim_Node_X(list, q), x);
		xuat_DanhSach(list);
	}
}
// Cau 5
void xoa_Dau(Nodeptr& list) {
	Nodeptr p;
	if (list != NULL) {
		p = list;
		list = p->link;
		delete p;
	}
}
void xoa_Cuoi(Nodeptr& list) {
	Nodeptr p, before;
	p = list;
	before = list;
	if (p->link == NULL) {
		delete p;
		list = NULL;
	}
	else {
		while (p->link != NULL) {
			before = p;
			p = p->link;
		}
		if (p->link == NULL) {
			delete p;
			before -> link = NULL;
		}
	}
}
// Cau 6
void del_node_x(Nodeptr& list, int x) {
	Nodeptr p = list, before = list;
	if (list->data == x) {
		list = list->link;
		delete p;
	}
	else {
		while (p != NULL && p->data != x) {
			before = p;
			p = p->link;
		}
		if (p != NULL) {
			before->link = p->link;
			delete p;
		}
	}
}
// Cau 7
void daoNguocDSLK(Nodeptr& list) {
	Nodeptr p = list->link;
	list->link = NULL;
	while (p != NULL) {
		Nodeptr before = p;
		p = p->link;
		before->link = list;
		list = before;
	}
}
// BTVN
// Cau 1
void tachDSLKChanLe(Nodeptr& list, Nodeptr& chan, Nodeptr& le) {
	khoiTao(chan);
	khoiTao(le);
	Nodeptr p = list;
	while (p != NULL) {
		if (p->data % 2 == 0)
			them_Dau(chan, p->data);
		else
			them_Dau(le, p->data);
		p = p->link;
	}
}
// Cau 2
void del_All_X(Nodeptr& list, int x) {
	Nodeptr p = list, q = list;
	while (p != NULL) {
		if (list->data == x) {
			xoa_Dau(list);
			q = list;
			p = list;
		}
		else {
			if (p->data == x) {
				q->link = p->link;
				delete p;
				p = q;
			}
		}
		q = p;
		p = p->link;
	}
}