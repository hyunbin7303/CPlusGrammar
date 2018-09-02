#pragma once
#include <iostream>

template <typename T, int MAX = 100>
class ArrayList
{
	T	m_array[MAX];
	int m_count;

public:
	ArrayList()
	{
		memset(m_array, 0, MAX);
		m_count = 0;
	}
	~ArrayList() {}

	void Add(T data)
	{
		m_array[m_count] = data;
		m_count++;
	}
	void Remove(T data)
	{
		RemoveAt(IndexOf(data));
	}
	// INDEX DATA DELETION
	T RemoveAt(int index)
	{
		T dataToRemove = m_array[index];
		for (int i = index; i < m_count - 1; i++)
		{
			m_array[i] = m_array[i + 1];
		}
		m_count--;
		return dataToRemove;
	}
	// INDEX DATA RETURN 
	T GetData(int index)
	{
		if (index < m_count)
		{
			return m_array[index];
		}
		return NULL;
	}

	int IndexOf(T data)
	{
		for (int i = 0; i < m_count; i++)
		{
			if (m_array[i] == data)return i;

		}
		return -1;
	}
	int Count() { return m_count; }
};
