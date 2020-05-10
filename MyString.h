#pragma once
#include <iostream>
using namespace std;
enum TMyStringExeption { strINDOUTOFRANGE };

class MyString
{
private:
  char* str; // строка
  int size; // размер (max)
  int leng; // длина реальная
public:
  // Конструкторы ---------------------------------
  MyString(void); // По умолчанию
  MyString(const MyString& cms); // Копирования
  MyString(const char* cstr); // Преобразования типа
  MyString(double num); // Преобразования типа
  MyString(int _leng, char fill = ' '); // Инициализатор 1
  explicit MyString(int _leng); // Инициализатор 2
  void Create(int _size); // создание строки
  void Create(const char* cstr); // создание строки
  void Destroy(); // удаление строки
  void StrCopy(const char*); // копирование строки
  void StrCopy(const MyString&); // копирование строки
  void Print(); // вывод строки на экран
  MyString AddSt(const MyString);// объединение строк
  char* getstr()
  {
    return str;
  }
  int getleng()
  {
    return leng;
  }
  void Sum(MyString& a, MyString& b);



  //Штрафы
  MyString Dublicate(int k);
  int FindSim(char simvol);//вхождение подслова
  int FindStr(MyString& slovo);//Буквы
  MyString* Razbienie(const char* elem);//Деление на подслова


private:
  void Rebuffer(int newSize, int sizeDelta = 10);
  void Resize(int newSize, int sizeDelta = 10);
  void _strcopy(char* s1, const char* s2);


public:
  //----деструктор
  ~MyString(void);
  // перегрузка +,=,==, <, >, []  потоковый ввод и вывод;

  char& operator[](int index); // операция индексации
  const char& operator[](int index) const; // операция индексации
  MyString& operator=(const MyString& _str); // операция присваивания
  friend ostream& operator<<(ostream& stream, const MyString& _str);
  friend istream& operator>>(istream& stream, MyString& _str);
  bool operator< (const MyString& other) const;
  bool operator> (const MyString& other) const;
  bool operator==(const MyString& other) const;
  friend MyString operator+(MyString& a, MyString& b);
};

enum TStrEXType { strNOTNUMERIC, strOUTOGRANGE };
struct TStrException
{
  TStrEXType extype; // вид исключения
  int bspos; // позиция нецифрового символа
  TStrException(TStrEXType _extype, int _bspos) :
    extype(_extype), bspos(_bspos) {}
};



/*
int StrToInt(const char str[])
{
  int num = 0;
  int i = 0;
  while (str[i])
    if (str[i] >= '0' && str[i] <= '9')
      num = num * 10 + str[i++] - '0';
    else
    {
      throw TStrException(strNOTNUMERIC, i);
    }

      return num;

      14 лекция крч
}
*/