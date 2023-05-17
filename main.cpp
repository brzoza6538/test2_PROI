#include<iostream>

class Dane {
public:

	class Iterator
	{
	public:
		using value_type = double;
		using pointer = double*;
		using reference = double&;

		Iterator(pointer ptr)
			: m_ptr(ptr) {}

		Iterator& operator++()
		{
			m_ptr++;
			return *this;
		}

		reference operator*()
		{
			return *m_ptr;
		}

		bool operator!=(const Iterator& other) const
		{
			return m_ptr != other.m_ptr;
		}

	private:
		pointer m_ptr;
	};

	std::istream& operator>> (std::istream& is)
	{
		return is;
	}

	Dane(double a = 0, int b = NULL, int c = NULL)
	{
		list[0] = a;
		list[1] = b;
		list[2] = c;

		m_data = &(list[0]);
	}

	int size()
	{
		return 3;
	}

	Iterator begin()
	{
		return Iterator(m_data);
	}

	Iterator end()
	{
		return Iterator(m_data + size());
	}
private:
	double list[3];
	double* m_data = nullptr;
};


int main()
{
	Dane dane(1, 2, 3);
	for (auto& d : dane) {
		std::cout << d;
	}
	return 0;
}