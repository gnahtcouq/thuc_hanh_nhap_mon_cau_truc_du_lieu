#include "Thang_DH52007101_B7_H.h"

int main() {
  Queue q;
  khoiTao(q);
  setValue(q);
  print(q);
  
  // Cau 1
  int x;
  cout << "\nNhap phan tu can them vao queue: ";
  cin >> x;
  enQueue(q, x);
  cout << "Queue sau khi them vao: ";
  print(q);

  // Cau 2
  int cau2 = deQueue(q);
  if (cau2 != -1)
    cout << "\nPhan tu duoc lay ra khoi queue la: " << cau2;

  // Cau 3
  int cau3 = xemGiaTriDau(q);
  cout << "\nGia tri dau cua hang doi la: " << cau3 << endl;
  cout << endl;

  // DSLK
  // Cau 1
  QueueLK(k);
  khoiTaoLK(k);
  setValueLK(k);
  printLK(k);

  // Cau 2
  int cau2lk = deQueue(k);
  if (cau2lk != -1)
    cout << "\nPhan tu duoc lay ra khoi queue la: " << cau2lk;

  // Cau 3
  int cau3lk = getFront(k);
  if (cau3lk != -1)
    cout << "\nGia tri dau cua hang doi la: " << cau3lk << endl;

  system("pause");
  return 0;
}