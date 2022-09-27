#include <string.h>

#include <iostream>
using namespace std;

struct CAYBUT {
    int maCB;
    char tenCB[30];
    int soLuong;
    float donGia;
    char hangSX[30];
};
struct NODECAYBUT {
    CAYBUT data;
    NODECAYBUT* link;
};
typedef NODECAYBUT* Nodeptr;
struct NODE {
    int data;
    NODE* link;
};
typedef NODE* NODEPTR;
struct QUEUE {
    NODEPTR front, rear;
};
struct STACK {
    NODEPTR top;
};

void init(Nodeptr& l);
Nodeptr taoNode(CAYBUT a);
Nodeptr addTail(Nodeptr& l, CAYBUT a);
void nhap_DSCB(Nodeptr& l);
void xuat_DSCB(Nodeptr l);
void xoa_ButBangHangSX(Nodeptr& list, CAYBUT a);
void xoa_ThongTinTatCaButThuocHangX(Nodeptr& list, char* str);

void khoiTao_QueueLK(QUEUE& k);
int isEmpty_QueueLK(QUEUE k);
NODEPTR tao_Node_QueueLK(int x);
void enQueue_QueueLK(QUEUE& k, int x);
void setValue_QueueLK(QUEUE& k);
void print_QueueLK(QUEUE k);
int deQueue_QueueLK(QUEUE& k);
int getFront_QueueLK(QUEUE k);
void chenSauNode_QueueLK(QUEUE& k, int x, int pos);

void khoiTao_StackLK(STACK& s);
int isEmpty_StackLK(STACK s);
NODEPTR taoNode_StackLK(int x);
int isFull_StackLK(STACK s);
void push_StackLK(STACK& s, int x);
int pop_StackLK(STACK& s);
void input_StackLK(STACK& s);
void output_StackLK(STACK s);
void get_StackLK(STACK& s);
int top_StackLK(STACK& s);
void loaiBoCacPhanTuTrongStack(STACK& s, int x);

int main() {
    Nodeptr ds;
    QUEUE q;
    STACK s;
    init(ds);
    nhap_DSCB(ds);
    cout << "\nDanh sach cac cay but";
    xuat_DSCB(ds);
    char str[30];
    cin.ignore();
    cout << "\nNhap Hang SX can xoa tat ca but: ";
    cin.getline(str, 30);
    xoa_ThongTinTatCaButThuocHangX(ds, str);
    cout << "\nDanh sach sau khi xoa: ";
    xuat_DSCB(ds);

    khoiTao_QueueLK(q);
    setValue_QueueLK(q);
    print_QueueLK(q);
    int a, pos;
    cout << "\nNhap phan tu muon chen: ";
    cin >> a;
    cout << "\nPos can chen: ";
    cin >> pos;
    chenSauNode_QueueLK(q, a, pos);
    print_QueueLK(q);

    khoiTao_StackLK(s);
    input_StackLK(s);
    output_StackLK(s);
    int b;
    cout << "\nNhap phan tu muon xoa: ";
    cin >> b;
    loaiBoCacPhanTuTrongStack(s, b);
    output_StackLK(s);
    system("pause");
    return 0;
}

void init(Nodeptr& l) {
    l = NULL;
}

Nodeptr taoNode(CAYBUT a) {
    Nodeptr p;
    p = new NODECAYBUT;
    p->data = a;
    p->link = NULL;
    return p;
}

Nodeptr addTail(Nodeptr& l, CAYBUT a) {
    Nodeptr p = taoNode(a);
    if (l == NULL)
        l = p;
    else {
        Nodeptr q = l;
        while (q->link != NULL)
            q = q->link;
        q->link = p;
    }
    return p;
}

void nhap_DSCB(Nodeptr& l) {
    CAYBUT a;
    do {
        cout << "\n\tNhap 0 de thoat";
        cout << "\nNhap Ma CB:  ";
        cin >> a.maCB;
        if (a.maCB == 0)
            break;
        cin.ignore();
        cout << "Nhap Ten CB: ";
        cin.getline(a.tenCB, 30);
        cout << "Nhap SL: ";
        cin >> a.soLuong;
        cout << "Nhap Gia: ";
        cin >> a.donGia;
        cin.ignore();
        cout << "Nhap Hang SX: ";
        cin.getline(a.hangSX, 30);
        cout << endl;
        addTail(l, a);
    } while (1);
}

void xuat_DSCB(Nodeptr l) {
    while (l != NULL) {
        cout << "\nMa But: " << l->data.maCB;
        cout << "\nTen But: " << l->data.tenCB;
        cout << "\nSo luong: " << l->data.soLuong;
        cout << "\nDon gia: " << l->data.donGia;
        cout << "\nHang san xuat: " << l->data.hangSX;
        cout << "-------------" << endl;
        l = l->link;
    }
}

void xoa_ButBangHangSX(Nodeptr& list, CAYBUT a) {
    if (strcmp(list->data.hangSX, a.hangSX) == 0) {
        Nodeptr p = list;
        list = list->link;
        delete p;
    } else {
        Nodeptr p, before;
        p = list;
        before = list;
        while (p != NULL && strcmp(p->data.hangSX, a.hangSX) != 0) {
            before = p;
            p = p->link;
        }
        if (p != NULL) {
            before->link = p->link;
            delete p;
        }
    }
}

void xoa_ThongTinTatCaButThuocHangX(Nodeptr& list, char* str) {
    if (list != NULL) {
        Nodeptr p = list, q;
        while (p != NULL) {
            if (strcmp(p->data.hangSX, str) == 0) {
                q = p->link;
                xoa_ButBangHangSX(list, p->data);
                p = q;
            } else
                p = p->link;
        }
    }
}

void khoiTao_QueueLK(QUEUE& k) {
    k.front = NULL;
    k.rear = NULL;
}

int isEmpty_QueueLK(QUEUE k) {
    if (k.front == NULL)
        return 1;
    return 0;
}

NODEPTR tao_Node_QueueLK(int x) {
    NODEPTR p;
    p = new NODE;
    p->data = x;
    p->link = NULL;
    return p;
}

void enQueue_QueueLK(QUEUE& k, int x) {
    NODEPTR p;
    p = tao_Node_QueueLK(x);
    if (isEmpty_QueueLK(k)) {
        k.front = p;
        k.rear = p;
    } else {
        k.rear->link = p;
        k.rear = p;
    }
}

void setValue_QueueLK(QUEUE& k) {
    int a;
    while (1) {
        cout << "\n\tNhap 0 de thoat";
        cout << "\nNhap queue: ";
        cin >> a;
        if (a == 0)
            break;
        enQueue_QueueLK(k, a);
    }
}

void print_QueueLK(QUEUE k) {
    NODEPTR p;
    p = k.front;
    while (p != NULL) {
        cout << " " << p->data;
        p = p->link;
    }
}

int deQueue_QueueLK(QUEUE& k) {
    if (isEmpty_QueueLK(k))
        return -1;
    else {
        NODEPTR p = k.front;
        k.front = p->link;
        int t = p->data;
        delete p;
        return t;
    }
}

int getFront_QueueLK(QUEUE k) {
    if (isEmpty_QueueLK(k))
        return -1;
    int x = k.front->data;
    return x;
}

void chenSauNode_QueueLK(QUEUE& k, int x, int pos) {
    QUEUE p = k;
    QUEUE tam;
    khoiTao_QueueLK(tam);
    int vitritam = 0;
    while (vitritam <= pos && !isEmpty_QueueLK(p)) {
        enQueue_QueueLK(tam, deQueue_QueueLK(p));
        vitritam += 1;
    }
    enQueue_QueueLK(tam, x);
    while (!isEmpty_QueueLK(p))
        enQueue_QueueLK(tam, deQueue_QueueLK(p));
    k = tam;
}

void khoiTao_StackLK(STACK& s) {
    s.top = NULL;
}

int isEmpty_StackLK(STACK s) {
    return s.top == NULL;
}

NODEPTR taoNode_StackLK(int x) {
    NODEPTR p = new NODE;
    p->data = x;
    p->link = NULL;
    return p;
}

void push_StackLK(STACK& s, int x) {
    NODEPTR p;
    p = taoNode_StackLK(x);
    if (isEmpty_StackLK(s))
        s.top = p;
    else {
        p->link = s.top;
        s.top = p;
    }
}

void pushtop_StackLK(STACK& s, int a) {
    NODEPTR p;
    p = taoNode_StackLK(a);
    if (isEmpty_StackLK(s))
        s.top = p;
    else {
        NODEPTR q = s.top;
        while (q->link != NULL)
            q = q->link;
        q->link = p;
    }
}

void input_StackLK(STACK& s) {
    int x;
    while (1) {
        cout << "\n\tNhap 0 de thoat";
        cout << "\nNhap stack: ";
        cin >> x;
        if (x == 0)
            break;
        push_StackLK(s, x);
    }
}

void output_StackLK(STACK s) {
    NODEPTR p = s.top;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->link;
    }
}

int pop_StackLK(STACK& s) {
    NODEPTR p;
    int x;
    if (!isEmpty_StackLK(s)) {
        p = s.top;
        s.top = p->link;
        x = p->data;
        delete p;
        return x;
    }
}

int top_StackLK(STACK& s) {
    NODEPTR p;
    if (!isEmpty_StackLK(s)) {
        p = s.top;
        return p->data;
    }
}

void loaiBoCacPhanTuTrongStack(STACK& s, int x) {
    STACK p = s;
    STACK tam;
    khoiTao_StackLK(tam);
    while (!isEmpty_StackLK(p)) {
        if (top_StackLK(p) != x)
            pushtop_StackLK(tam, pop_StackLK(p));
        else {
            pop_StackLK(p);
        }
    }
    s = tam;
}