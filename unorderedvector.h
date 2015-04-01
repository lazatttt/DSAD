#ifndef xUNORDEREDVECTOR_H
#define xUNORDEREDVECTOR_H

#include <vector>
using std::vector;

template <typename T>
class S2 {
public:
	// ���캯��.
	S2();
	// ��key���뼯����.
	void insert(const T& key);
	// ��posλ�����ڵ�Ԫ��ɾ��, ǰ����pos��0��size() - 1֮��.
	void erase(int pos);
	// ��key�ڼ������򷵻���λ��, ���򷵻�size().
	int search(const T& key) const;
	// ���ؼ��������Ԫ�ص�λ��, ������Ϊ���򷵻�size().
	int maximum_at() const;
	// ���ؼ�������СԪ�ص�λ��, ������Ϊ���򷵻�size().
	int minimum_at() const;
	// ����posλ��Ԫ�صĳ�������, ע��δ�ṩ�ǳ����汾
	const T& operator()(int pos) const;
	// ���ؼ�����Ԫ�صĸ���.
	int size() const;
private:
	vector<T> data;
	int count;					// ʵ�����ݸ���
};

template <typename T>
S2<T>::S2()
	: count(0), data(1024)
{
	// Ϊ�����ýϴ�����, ��ʼ�������ȶ�Ϊ1024, Ԫ�ظ�����Ϊ0
}

template <typename T>
void S2<T>::insert(const T& key)
{
	if (count == data.size())
		data.resize( 2 * data.size() );
	data[count] = key;
	count++;
}

template <typename T>
void S2<T>::erase(int pos)
{
	// ע��ִ��erase��ǰ����count > 0
	count--;
	data[pos] = data[count];
}

template <typename T>
int S2<T>::search(const T& key) const
{
	// ������ñȽ�ֱ�ӵĲ���, ���Ļ�����Ϻõĳ���ʵ��(�ڱ�����)
	int i = 0;
	int pos = count;
	while (i < count)
	{
		if (data[i] == key)
		{
			pos = i;
			i = count;
		}
		else
			i++;
	}
	return pos;
}

template <typename T>
int S2<T>::maximum_at() const
{
	int max_pos = 0;
	if (count > 0)
		for (int i = 1; i < count; i++)
			if (data[max_pos] < data[i])
				max_pos = i;
	return max_pos;
}

template <typename T>
int S2<T>::minimum_at() const
{
	int min_pos = 0;
	if (count > 0)
		for (int i = 1; i < count; i++)
			if (data[i] < data[min_pos])
				min_pos = i;
	return min_pos;
}

template <typename T>
const T& S2<T>::operator()(int pos) const
{
	return data[pos];
}

template <typename T>
int S2<T>::size() const
{
	return count;
}

#endif  // xUNORDEREDVECTOR_H