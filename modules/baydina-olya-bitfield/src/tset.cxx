#include "tset.h"

TSet::TSet(int mp) : BitField(mp), MaxPower(mp)
{
}

// ����������� �����������
TSet::TSet(const TSet &s) : BitField(s.BitField), MaxPower(s.MaxPower)
{
}

// ����������� �������������� ����
TSet::TSet(const TBitField &bf) : BitField(bf), MaxPower(bf.GetLength())
{
}

TSet::operator TBitField()
{
	return TBitField(MaxPower);
}

int TSet::GetMaxPower(void) const // �������� ����. �-�� ��-���
{
	return MaxPower;
}

int TSet::IsMember(const int Elem) const // ������� ���������?
{
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // ��������� �������� ���������
{
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // ���������� �������� ���������
{
	BitField.ClrBit(Elem);
}

// ���������-������������� ��������

TSet& TSet::operator=(const TSet &s) // ������������
{
	BitField = s.BitField;
	MaxPower = s.MaxPower;

	return *this;
}

int TSet::operator==(const TSet &s) const // ���������
{
	return (BitField == s.BitField);
}

int TSet::operator!=(const TSet &s) const // ���������
{
	return (BitField != s.BitField);
}

TSet TSet::operator+(const TSet &s) // �����������
{
	return (BitField | s.BitField);
}

//TSet TSet::operator+(const int Elem) // ����������� � ���������
//{
//	TSet result = *this;
//	result.BitField.SetBit(Elem);
//
//	return result;
//}
//
//TSet TSet::operator-(const int Elem) // �������� � ���������
//{
//	TSet result = *this;
//	result.BitField.ClrBit(Elem);
//
//	return result;
//}

TSet TSet::operator*(const TSet &s) // �����������
{
	return (BitField & s.BitField);
}

TSet TSet::operator~(void) // ����������
{
	return (~BitField);
}

// ���������� �����/������

istream &operator>>(istream &istr, TSet &s) // ����
{
	char ch;
	int i;

	while (1)
	{
		istr >> ch;
		istr >> i;
		s.InsElem(i);
		istr >> ch;
		if (ch == '.') break;
	}

	return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // �����
{
	ostr << "{ ";

	for (int i = 0; i<s.GetMaxPower(); i++)
		if (s.IsMember(i))
			ostr << 'A' << i << ' ';

	ostr << "}";

	return ostr;
}