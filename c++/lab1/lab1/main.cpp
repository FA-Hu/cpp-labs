#include <iostream>

using namespace std;

class Numbers
{
public:
	int m_first_number = 0;
	int m_seconsd_number = 0;

	void print() {
		cout << "Numbers(" << m_first_number << ", " << m_seconsd_number << ")" << endl;
	}

	void set(int first_number, int seconsd_number) {
		m_first_number = first_number;
		m_seconsd_number = seconsd_number;
	}
};

int main() {
	Numbers n1;
	n1.set(3, 3); // �������������� ������ n1 ���������� 3 � 3
	Numbers n2{ 4, 4 }; // �������������� ������ n2 ���������� 4 � 4  
	n1.print();
	n2.print();

	return 0;
}