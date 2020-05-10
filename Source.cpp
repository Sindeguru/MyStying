#include "MyString.h"

int main()
{
  MyString s1; // конструктор по умолчанию
  MyString s2("Москва"); // конструктор преобразования типа
  MyString s4(9.14); // конструктор преобразования типа
  MyString s5(10, '#'); // конструктор инициализатор 1
  MyString s6("Ква");
  MyString s7(s2); // конструктор копирования

  cout << (s2==s7) << endl;
  cout << (s2 + s4) << endl;
  cout << s2.FindSim('с') << endl;
  cout << s2.FindStr(s6) << endl;
  cout << s4.Dublicate(4) << endl;


  return 0;
}