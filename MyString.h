#pragma once
#include <iostream>
using namespace std;
enum TMyStringExeption { strINDOUTOFRANGE };

class MyString
{
private:
  char* str; // ������
  int size; // ������ (max)
  int leng; // ����� ��������
public:
  // ������������ ---------------------------------
  MyString(void); // �� ���������
  MyString(const MyString& cms); // �����������
  MyString(const char* cstr); // �������������� ����
  MyString(double num); // �������������� ����
  MyString(int _leng, char fill = ' '); // ������������� 1
  explicit MyString(int _leng); // ������������� 2
  void Create(int _size); // �������� ������
  void Create(const char* cstr); // �������� ������
  void Destroy(); // �������� ������
  void StrCopy(const char*); // ����������� ������
  void StrCopy(const MyString&); // ����������� ������
  void Print(); // ����� ������ �� �����
  MyString AddSt(const MyString);// ����������� �����
  char* getstr()
  {
    return str;
  }
  int getleng()
  {
    return leng;
  }
  void Sum(MyString& a, MyString& b);



  //������
  MyString Dublicate(int k);
  int FindSim(char simvol);//��������� ��������
  int FindStr(MyString& slovo);//�����
  MyString* Razbienie(const char* elem);//������� �� ��������


private:
  void Rebuffer(int newSize, int sizeDelta = 10);
  void Resize(int newSize, int sizeDelta = 10);
  void _strcopy(char* s1, const char* s2);


public:
  //----����������
  ~MyString(void);
  // ���������� +,=,==, <, >, []  ��������� ���� � �����;

  char& operator[](int index); // �������� ����������
  const char& operator[](int index) const; // �������� ����������
  MyString& operator=(const MyString& _str); // �������� ������������
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
  TStrEXType extype; // ��� ����������
  int bspos; // ������� ����������� �������
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

      14 ������ ���
}
*/