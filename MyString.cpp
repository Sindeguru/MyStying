#define _CRT_SECURE_NO_WARNINGS

#include "MyString.h"
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

// Конструкторы ---------------------------------
MyString::MyString(void) // По умолчанию
{
  leng = 0; size = 0; str = 0;
}
MyString::MyString(const MyString& cms) // Копирования
{
  size = cms.size;
  leng = cms.leng;
  str = new char[size];
  for (int i = 0; i < size; i++)
    str[i] = cms.str[i];
}
MyString::MyString(const char* cstr) // Преобразования типа
{
  leng = 0;
  while (cstr[leng]) leng++;
  size = leng + 1;
  str = new char[size];
  for (int i = 0; i < size; i++)
    str[i] = cstr[i];
}
MyString::MyString(int _leng, char fill) // Инициализатор 1
{
  leng = _leng; size = _leng + 1;
  str = new char[size];
  for (int i = 0; i < leng; i++)
    str[i] = fill;
  str[leng] = '\0';
}
MyString::MyString(int _leng) // Инициализатор 2
{
  leng = _leng; size = _leng + 1;
  str = new char[size];
  str[leng] = 0;
}
//Дестркутор
MyString::~MyString(void)
{
  if (size)
    delete[] str;
  leng = 0;
  size = 0;
  str = 0;
}

char& MyString::operator[](int index)
{
  if (index < 0 || index >= leng) 
  {
    TMyStringExeption expt = strINDOUTOFRANGE;
    throw expt;
  }
  return str[index];
}

const char& MyString::operator[](int index) const
{
  if (index < 0 || index >= leng) 
  {
    TMyStringExeption expt = strINDOUTOFRANGE;
    throw expt;
  }
  return str[index];
}

MyString& MyString::operator=(const MyString& _str)
{
  if (this != &_str)
  {
    if (size < _str.size)
    {
      delete[] str;
      size = _str.size;
      leng = _str.leng;
      str = new char[size];
    }
    for (int i = 0; i < leng; i++)
      (*this)[i] = _str[i];
  }
  return *this;

}
bool MyString :: operator< (const MyString& other) const
{
  if (strcmp(str, other.str) < 0) return true;
  else return false;
}

bool MyString::operator > (const MyString& other) const
{
  if (strcmp(str, other.str) > 0) return true;
  else return false;
}
bool MyString::operator==(const MyString& other) const
{

  if (strcmp(str, other.str) == 0) return true;
  else return false;

}

MyString operator +(MyString& a, MyString& b)
{
  MyString c(a);
  c.Sum(a, b);
  return c;
}


// создание строки -----------------------------
void MyString::Create(int _size)
{
  str = new char[size]; 
  str[0] = 0;
  size = _size;
  leng = 0;
}
// создание строки -----------------------------
void MyString::Create(const char* cstr)
{
  leng = 0;
  while (cstr[leng++]);
  size = leng + 1;
  str = new char[size];
  int i = 0;
  while (str[i] = cstr[i]) i++;
}
// удаление строки ----------------------------
void MyString::Destroy()
{
  if (size)
    delete[] str;
  str = 0;
  leng = 0;
  size = 0;
}
// копирование --------------------------------
void MyString::StrCopy(const char* cstr)
{
  int len = 0;
  while (cstr[len]) len++;
  if (len > size)
    Rebuffer(len);
  _strcopy(str, cstr);
  leng = len;
}
// копирование --------------------------------
void MyString::StrCopy(const MyString& _str)
{
  if (_str.leng > leng)
    Rebuffer(_str.leng);
  _strcopy(str, _str.str);
  leng = _str.leng;
}
void MyString::Print()
{
  cout << str << endl;
}
// объединение строк --------------------------
MyString MyString::AddSt(const MyString _str)
{
  MyString tmp;
  tmp.Create(leng + _str.leng + 1);
  _strcopy(tmp.str, str); // копируем себя
  _strcopy(tmp.str + leng, _str.str); // копируем _str
  tmp.leng = leng + _str.leng;
  tmp.size = leng + _str.leng + 1;
  return tmp;
}
// увеличение длины буфера
void MyString::Rebuffer(int newSize, int sizeDelta)
{
  delete[] str;
  str = new char[newSize + sizeDelta];
  size = newSize + sizeDelta;
  str[0] = '\0';
  leng = 0;
}
// увеличение длины строки
void MyString::Resize(int newSize, int sizeDelta)
{
  char* tmp = new char[newSize + sizeDelta];
  _strcopy(tmp, str);
  size = newSize + sizeDelta;
  delete[] str;
}
// копирование строки
void MyString::_strcopy(char* s1, const char* s2)
{
  do
  {
    *s1++ = *s2;
  } while (*s2++);
}
ostream& operator<<(ostream& stream, const MyString& _str)
{
  stream << _str.str << endl;
  return stream;
}

istream& operator>>(istream& stream, MyString& _str)
{
  char ss[255];
  stream.getline(ss, 255);
  _str = ss;
  return stream;
}




MyString* MyString::Razbienie(const char* elem)
{
  int k = 0;
  for (int i = 1; i < size - 2; i++)
    if (elem)
      k++;
  MyString* mas_strok = new MyString[k];
  char* other = strtok(str, elem);
  k = 0;
  while (other)
  {
    mas_strok[k] = other;
    k++;
    other = strtok(NULL, elem); // здесь параметр NULL указывает, что мы ПРОДОЛЖАЕМ обрабатывать str
  }
  return mas_strok;
}

void MyString::Sum(MyString& a, MyString& b)
{
  str = new char[a.getleng() + 1 + b.getleng()];
  leng = a.getleng() + b.getleng();
  size = a.getleng() + 1 + b.getleng();
  for (int i = 0; i < a.getleng(); i++) str[i] = a.getstr()[i];
  for (int i = 0; i < b.getleng(); i++) str[i + a.getleng()] = b.getstr()[i];
  str[a.getleng() + b.getleng()] = 0;
}

MyString MyString::Dublicate(int k)
{
  MyString tmp;
  tmp.Create(leng * k + 1);
  for(int i = 0; i < k; i++)
    for (int j = 0; j < size; j++)
      tmp.str[i * size + j] = this->str[j];

  return tmp;
}

int MyString::FindSim(char simvol)
{
  for (int i = 0; i < size; i++)
    if (str[i] == simvol)
      return i;
  return -1;
}

int MyString::FindStr(MyString& slovo)
{
  bool f = false;
  for (int i = 0; i < size; i++)
  {
    f = false;
    for (int j = 0; j < slovo.size - 1; j++)
      if (str[i + j] != slovo.str[j])
      {
        f = true;
        break;
      }
      else
        cout << i << ' ';
  }
  cout << endl;
  return -1;
}
