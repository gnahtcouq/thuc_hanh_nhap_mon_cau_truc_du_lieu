#include <iostream>
using namespace std;
const int MAX = 50;
//Cau truc DS DAC
struct DaySo {
    int ds[MAX];
    int n; //So Phan tu ds dac
};
void khoiTao(DaySo& x);
int isEmpty(DaySo x);
int isFull(DaySo x);
int listSize(DaySo x);
void doc_DanhSach(DaySo& x);
void xuat_DanhSach(DaySo x);
//Cau 2
void chen_ViTri(DaySo& x, int pos, int a);
//Cau 3
void xoa_ViTri(DaySo& x, int pos);
//Cau 4
void xoa_GiaTri_K(DaySo& x, int k);
//Cau 5
int timKiem_TuanTu(DaySo x, int a);
//Cau 6
void sapXep(DaySo& x);
int timKiem_NhiPhan(DaySo x, int a);
//Cau 7