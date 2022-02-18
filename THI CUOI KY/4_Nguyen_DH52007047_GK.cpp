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
void khoiTao(Nodeptr & x);
Nodeptr taoNode(CAYBUT a);
Nodeptr themCuoi(Nodeptr &x, CAYBUT c);
void nhap_DanhSachCayBut(Nodeptr &x);
void xuat_DanhSachCayBut(Nodeptr x);
void sapxep_GiamDanTheoGia(Nodeptr &x);

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
/* ---------------------- Queue ----------------------*/
void init_QUEUE(QUEUE &q);
int isEmpty_QUEUE(QUEUE q);
NODEPTR createNode_QUEUE(int x);
void enQueue_QUEUE(QUEUE &q, int x);
void setValue_QUEUE(QUEUE &q);
void print_QUEUE(QUEUE q);
int deQueue_QUEUE(QUEUE &q);
void cau1_QUEUE(QUEUE &q, int x, int pos);
/* ---------------------- STACK ----------------------*/
void init_STACK(STACK &s);
int isEmpty_STACK(STACK s);
NODEPTR createNode_STACK(int x);
int isFull_STACK(STACK s);
void push_STACK(STACK &s, int x);
int pop_STACK(STACK &s);
void input_STACK(STACK &s);
void output_STACK(STACK s);
void get_STACK(STACK &s);
int top_STACK(STACK &s);
void cau2_STACK(STACK &s, int x);

int main() {
    Nodeptr x;
    khoiTao(x);
    nhap_DanhSachCayBut(x);
    xuat_DanhSachCayBut(x);
    cout << "\nSap xep giam dan theo gia" << endl;
    sapxep_GiamDanTheoGia(x);
    xuat_DanhSachCayBut(x);

    QUEUE q;
    int x1, pos;
    init_QUEUE(q);
    setValue_QUEUE(q);
    cout << "\nHang doi da nhap la: ";
    print_QUEUE(q);
    cout << "\nNhap x  =  ";
    cin >> x1;
    cout << "\nBan muon chen vao sau vi tri nao: ";
    cin >> pos;
    cout << "\nQueue sau khi chen la: ";
    cau1_QUEUE(q, x1, pos);
    print_QUEUE(q);

    STACK s;
    int x2;
    init_STACK(s);
    input_STACK(s);
    cout << "\nNgan xep da nhap la: ";
    output_STACK(s);
    cout << "\nNhap gia tri can xoa tat ca trong ngan xep: ";
    cin >> x2;
    cout << "\nStack sau khi xoa la: ";
    cau2_STACK(s, x2);
    output_STACK(s);
    system("pause");
    return 0;
}

void khoiTao(Nodeptr &x) {
    x = NULL;
}

Nodeptr taoNode(CAYBUT c) {
    Nodeptr p;
    p = new NODECAYBUT;
    p->data = c;
    p->link = NULL;
    return p;
}

Nodeptr themCuoi(Nodeptr &x, CAYBUT c) {
    Nodeptr p = taoNode(c);
    if (x == NULL)
        x = p;
    else {
        Nodeptr q = x;
        while (q->link != NULL) 
            q = q->link;
        q->link = p;
    }
    return p;
}

void nhap_DanhSachCayBut(Nodeptr &x) {
    CAYBUT a;
    int dem = 1;
    do {
        cout << "\nCay but thu " << dem++;
        cout << "\nNhap ma cay but (nhap -1 de thoat):  ";
        cin >> a.maCB;
        if (a.maCB == -1)
            break;
        cin.ignore();
        cout << "Nhap ten cay but: ";
        cin.getline(a.tenCB, 30);
        cout << "Nhap so luong but: ";
        cin >> a.soLuong;
        cout << "Nhap gia cay but: ";
        cin >> a.donGia;
        cin.ignore();
        cout << "Nhap hang san xuat: ";
        cin.getline(a.hangSX, 30);
        cout << endl;
        themCuoi(x, a);
    } while (1);
}

void xuat_DanhSachCayBut(Nodeptr x) {
    while (x != NULL) {
        cout << endl;
        cout << "Ma cay but: " << x->data.maCB << endl;
        cout << "Ten cay but: " << x->data.tenCB << endl;
        cout << "So luong but: " << x->data.soLuong << endl;
        cout << "Don gia: " << x->data.donGia << endl;
        cout << "Hang san xuat: " << x->data.hangSX << endl;
        x = x->link;
    }
}

void sapxep_GiamDanTheoGia(Nodeptr &x) {
  for (Nodeptr bienTam = x; bienTam != NULL; bienTam = bienTam->link) {
    for (Nodeptr bienTam2 = bienTam->link; bienTam2 != NULL; bienTam2 = bienTam2->link) {
      if (bienTam->data.donGia < bienTam2->data.donGia) {
        CAYBUT butTam = bienTam->data;
        bienTam->data = bienTam2->data;
        bienTam2->data = butTam;
      }
    }
  }
}

/* ---------------------- Queue ----------------------*/
void init_QUEUE(QUEUE &q) {
    q.front = NULL;
    q.rear = NULL;
}

int isEmpty_QUEUE(QUEUE q) {
    if (q.front == NULL)
        return 1;
    return 0;
}

NODEPTR createNode_QUEUE(int x) {
    NODEPTR p;
    p = new NODE;
    p->data = x;
    p->link = NULL;
    return p;
}

void enQueue_QUEUE(QUEUE &q, int x) {
    NODEPTR p;
    p = createNode_QUEUE(x);
    if (isEmpty_QUEUE(q)) {
        q.front = p;
        q.rear = p;
    }
    else {
        q.rear->link = p;
        q.rear = p;
    }
}

int deQueue_QUEUE(QUEUE &q) {
    if (isEmpty_QUEUE(q))
        return -1;
    else {
        NODEPTR p = q.front;
        q.front = p->link;
        int t = p->data;
        delete p;
        return t;
    }
}

void setValue_QUEUE(QUEUE &q) {
    int a;
    while (1) {
        cout << "\nNhap vao hang doi (-1 de thoat): ";
        cin >> a;
        if (a == -1)
            break;
        enQueue_QUEUE(q, a);
    }
}

void print_QUEUE(QUEUE q) {
    NODEPTR p;
    p = q.front;
    while (p != NULL) {
        cout << " " << p->data;
        p = p->link;
    }
}

void cau1_QUEUE(QUEUE &q, int x, int pos) {
    QUEUE p = q;
    QUEUE bienTam;
    init_QUEUE(bienTam);
    int vitri = 0;
    while (vitri <= pos && !isEmpty_QUEUE(p)) {
        enQueue_QUEUE(bienTam, deQueue_QUEUE(p));
        vitri += 1;
    }
    enQueue_QUEUE(bienTam, x);
    while (!isEmpty_QUEUE(p))
        enQueue_QUEUE(bienTam, deQueue_QUEUE(p));
    q = bienTam;
}

/* ---------------------- Stack ----------------------*/
void init_STACK(STACK &s) {
    s.top = NULL;
}

int isEmpty_STACK(STACK s) {
    return s.top == NULL;
}

NODEPTR createNode_STACK(int x) {
    NODEPTR p = new NODE;
    p->data = x;
    p->link = NULL;
    return p;
}

void push_STACK(STACK &s, int x) {
    NODEPTR p;
    p = createNode_STACK(x);
    if (isEmpty_STACK(s))
        s.top = p;
    else {
        p->link = s.top;
        s.top = p;
    }
}

void input_STACK(STACK &s) {
    int x;
    while (1) {
        cout << "\nNhap vao ngap xep (-1 de thoat): ";
        cin >> x;
        if (x == -1)
            break;
        push_STACK(s, x);
    }
}

void output_STACK(STACK s) {
    NODEPTR p = s.top;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->link;
    }
}

int top_STACK(STACK &s) {
    NODEPTR p;
    if (!isEmpty_STACK(s)) {
        p = s.top;
        return p->data;
    }
}

int pop_STACK(STACK &s) {
    NODEPTR p;
    int x;
    if (!isEmpty_STACK(s)) {
        p = s.top;
        s.top = p->link;
        x = p->data;
        delete p;
        return x;
    }
}

void pushtop_STACK(STACK &s, int a) {
    NODEPTR p;
    p = createNode_STACK(a);
    if (isEmpty_STACK(s))
        s.top = p;
    else {
        NODEPTR q = s.top;
        while (q->link != NULL)
            q = q->link;
        q->link = p;
    }
}

void cau2_STACK(STACK &s, int x) {
    STACK p = s;
    STACK nganXepTam;
    init_STACK(nganXepTam);
    while (!isEmpty_STACK(p)) {
        if (top_STACK(p) != x)
            pushtop_STACK(nganXepTam, pop_STACK(p));
        else
            pop_STACK(p);
    }
    s = nganXepTam;
}