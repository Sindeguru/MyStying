#include "MyString.h"

int main()
{
  MyString s1; // ����������� �� ���������
  MyString s2("������"); // ����������� �������������� ����
  MyString s4(9.14); // ����������� �������������� ����
  MyString s5(10, '#'); // ����������� ������������� 1
  MyString s6("���");
  MyString s7(s2); // ����������� �����������

  cout << (s2==s7) << endl;
  cout << (s2 + s4) << endl;
  cout << s2.FindSim('�') << endl;
  cout << s2.FindStr(s6) << endl;
  cout << s4.Dublicate(4) << endl;


  return 0;
}