#include "Thang_DH52007101_B6_H.h"

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
        cout << "\nNhap x = (-99 de thoat) ";
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
    while (p != NULL) {
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
        cout << "\nNhap x = (thoat-99) ";
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