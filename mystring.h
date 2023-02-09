#ifndef __MySTRING__
#define __MYSTRING__

#include<iostream>
using namespace std;


class MyString
{
public:
	//无参构造
	MyString();
	//初始化字符串
	MyString(int n, char c);
	//有参构造
	MyString(const char* str);
	//拷贝构造
	MyString(const MyString& str);
	//拷贝赋值
	MyString& operator=(const MyString& str);

	//重载+ 参数为对象
	MyString operator+(const MyString& str);
	//重载+ 参数为char *
	MyString operator+(const char* str);
	//重载+= 参数为对象
	MyString& operator+=(const MyString& str);
	//重载+= 参数为char *
	MyString& operator+=(const char* str);
	//析构
	~MyString();
	//返回指针
	inline char* _get_c_str()const { return m_data; }
	//返回字符串大小
	inline int _get_size() const { return m_size; }

private:
	char* m_data;
	int m_size;
};

inline
MyString::MyString()
{
	m_data = new char[1];
	*m_data = '\0';
	this->m_size = 0;
}
MyString::MyString(int n, char c)
{
	m_data = new char[n + 1];
	for (int i = 0; i < n; i++)
	{
		m_data[i] = c;
	}
	m_data[n] = '\0';
	this->m_size = n;
}
inline
MyString::MyString(const char* str)
{
	if (str)
	{
		int len = strlen(str);
		m_data = new char[len + 1];
		strcpy(m_data, str);
		this->m_size = len;
	}
}
inline
MyString::MyString(const MyString& str)
{
	int len = strlen(str.m_data);
	m_data = new char[len + 1];
	strcpy(m_data, str.m_data);
	this->m_size = len;
}
inline MyString&
MyString::operator=(const MyString& str)
{
	if (this == &str)
	{
		return *this;
	}

	delete[] m_data;
	int len = strlen(str.m_data);
	m_data = new char[len + 1];
	strcpy(m_data, str.m_data);
	this->m_size = len;
	return  *this;
}
inline
MyString::~MyString()
{
	if (this->m_data)
	{
		delete[]this->m_data;
		this->m_data = NULL;
		this->m_size = 0;
	}
}
MyString
MyString::operator+(const MyString& str)
{
	int len = this->_get_size() + str._get_size();

	MyString temp;
	if (temp.m_data)
	{
		delete[] temp.m_data;
		temp.m_data = NULL;
	}


	temp.m_data = new char[len + 1];
	memset(temp.m_data, 0, len + 1);
	strcat(temp.m_data, this->m_data);
	strcat(temp.m_data, str.m_data);

	this->m_size = len;

	return temp;

}
MyString
MyString::operator+(const char* str)
{
	int len = this->_get_size() + strlen(str);

	char* newspace = new char[len + 1];
	memset(newspace, 0, len + 1);
	strcat(newspace, this->m_data);
	strcat(newspace, str);

	MyString temp;
	if (temp.m_data)
	{
		delete[] temp.m_data;
		temp.m_data = NULL;
	}
	temp.m_data = newspace;

	this->m_size = len;
	return temp;
}
MyString&
MyString::operator+=(const MyString& str)
{
	int len = this->_get_size() + str._get_size();
	cout << len << endl;
	char* newspace = new char[len + 1];
	memset(newspace, 0, len + 1);

	strcat(newspace, this->m_data);
	strcat(newspace, str.m_data);

	if (this->m_data)
	{
		delete[]this->m_data;
		this->m_data = NULL;
	}

	this->m_data = newspace;
	this->m_size = len;
	return *this;
}
MyString&
MyString::operator+=(const char* str)
{
	int len = this->_get_size() + strlen(str);

	char* newspace = new char[len + 1];
	memset(newspace, 0, len + 1);

	strcat(newspace, this->m_data);
	strcat(newspace, str);

	if (this->m_data)
	{
		delete[]this->m_data;
		this->m_data = NULL;
	}

	this->m_data = newspace;
	this->m_size = len;
	return *this;
}
ostream&
operator<<(ostream& cout, const MyString& str)
{
	cout << str._get_c_str();
	return cout;
}
//istream&
//operator>>(istream& cin, const MyString& str)
//{
//	char buf[1024];
//	cin >> buf;
//
//	if (true)
//	{
//
//	}
//
//
//	return cin;
//}










#endif // !__MYSTRING__
