#include "Thang_DH52007101_B8_H.h"

int main() {
  Stack s;
  init_Stack(s);
  input_Stack(s);
  output_Stack(s);
  int get = pop(s);
  cout << "\nPhan tu dau bi lay ra khoi stack la: " << get;
  cout << "\nDanh sach cac phan tu con lai trong stack la: ";
  output_Stack(s);
  int cau3 = top(s);
  cout << "\nPhan tu dau cua stack la: " << cau3;

  // DSLK
  Stack_DSLK k;
  init_Stack_DSLK(k);
  input_Stack_DSLK(k);
  output_Stack_DSLK(k);
  cout << "\nPhan tu o top la: " << pop_DSLK(k);
  cout << "\nDanh sach sau khi pop la: ";
  output_Stack_DSLK(k);
  cout << "\nPhan tu o top la: " << top_DSLK(k);
  cout << "\nDanh sach sau khi top la: ";
  output_Stack_DSLK(k);

  return 0;
}