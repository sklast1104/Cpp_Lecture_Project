#pragma once

class Student;

template <typename T>
class DynamicArray
{
private :
	void resize() {
		m_capacity *= 2;
		T* new_data = new T[m_capacity];
		std::copy(m_data, m_data + m_size, new_data);
		delete[] m_data;
		m_data = new_data;
	}

	int m_size;
	int m_capacity;
	T* m_data;

public :
	DynamicArray() : m_size{ 0 }
		, m_capacity{ 1 }
		, m_data{ new T[m_capacity] }
	{
	}

	~DynamicArray() {
		delete[] m_data;
	}

	void push_back(const T& value) {
		if (m_size == m_capacity) {
			resize();
		}

		m_data[m_size++] = value;
	};
	void pop_back() {
		if (m_size > 0) {
			m_size--;
		}
	}

	T& operator[] (int index) {
		return m_data[index];
	}
	const T& operator[] (int index) const {
		return m_data[index];
	}

	int size() {
		return m_size;
	}
	int capacity() {
		return m_capacity;
	}
};

