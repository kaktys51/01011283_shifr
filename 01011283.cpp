#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;

namespace Alpabet
{
	const string alpabet[53] = 
	{ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", " ",
	"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
}

class Crypt
{
protected:
	string text;
	bool foundDuplicate = false;
	std::vector<string> testCrypt;
public:
	Crypt():testCrypt(53) {}
	Crypt(string a) : text(a), testCrypt(53) { }
	void inCrypt() // ����� ������� ������� ���� �� ������ ������ ������, � ��������� �� �� �������� ��������
	{
		string code = "onethingidontknowwhyitdoesntevenmatterhowhardyoutrykeepthatinmindidesignedthisrhyme";
		for (int i = 0; i < 53; ++i)
		{
			testCrypt[i] = code.substr(i, 5);
		}

		for (size_t i = 0; i < testCrypt.size(); ++i)
		{
			for (size_t j = i + 1; j < testCrypt.size(); ++j)
			{
				if (testCrypt[i] == testCrypt[j])
				{
					foundDuplicate = true;
					break;
				}
			}

			if (foundDuplicate)
			{
				break;
			}
		}
	}
	void CryptStr() // ���������� ���������
	{
		inCrypt();

		string* result = new string;
		string searchString;
		int searchIndex = 0;
		for (size_t i = 0; i < text.length(); ++i)
		{
			searchString = text.substr(i, 1); // ����������� ������ ��� ������
			for (int j = 0; j < 53; ++j)  // �������� ��������� ������ �� ������ ��������
			{
				if (Alpabet::alpabet[j] == searchString) // ������ ������� �������� �����
				{
					searchIndex = j; 
					break;
				}
			}
			*result += testCrypt[searchIndex];
		}
		text = *result;
		cout << std::endl;
		cout << "Crypted" << std::endl;
		cout << text << std::endl;
		delete result;
	}

	void decrypt() //�����������
	{
		string* result1 = new string;
		string searchString;
		for (size_t i = 0; i < text.length(); i +=5) //����� ������� 5 �������, ��� ��� ������� ������������ ������ ����������� 5-������� ������
		{
			searchString = text.substr(i, 5); //������� ������
			for (int j = 0; j < 53; ++j)
			{
				if (searchString == testCrypt[j]) //������ �� ����� ��������
				{
					*result1 += Alpabet::alpabet[j];
					break;
				}
			}
		}
		text = *result1;
		cout << std::endl;
		cout << "Decrypted" << std::endl;
		cout << text << std::endl;
		delete result1;
	}
};

int main()
{
	Crypt p("It starts with one");

	p.CryptStr();

	p.decrypt();

	return 0;
}
