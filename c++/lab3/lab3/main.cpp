#include <iostream>

using namespace std;

class Point {
public:
	float m_x = 0;
	float m_y = 0;

	template <typename T>
	T operator-(const T& point) const {
		return {
			this->m_x - point.m_x,
			this->m_y - point.m_y,
		};
	}
};

class Route {
public:
	void set_start(const string& start, const Point& coords) {
		m_start = start;
		m_start_coords = coords;
	}

	void set_end(const string& end, const Point& coords) {
		m_end = end;
		m_end_coords = coords;
	}

	void print_distance() {
		_calc();
		cout << "Distance between " << m_start << " and " << m_end << " is : " << m_distance << endl;
	}

	void start_info();
	void end_info();

private:
	void _calc() {
		Point temp_point;
		temp_point = m_end_coords - m_start_coords;
		m_distance = sqrt(pow(temp_point.m_x, 2) + pow(temp_point.m_y, 2));
	}

	string m_start = "";
	string m_end = "";
	Point m_start_coords;
	Point m_end_coords;
	float m_distance = 0;
};

int main()
{
	Route MskLon;// инициализируем объект MskLon
	MskLon.set_start("Moscow", { 300, 300 });
	MskLon.set_end("London", { 450, 450 });

	MskLon.start_info();
	MskLon.end_info();
	MskLon.print_distance();
	return 0;
}

void Route::start_info() {
	cout << "Start city is " << m_start << " - (" << m_start_coords.m_x << ", " << m_start_coords.m_y << ") " << endl;
}

void Route::end_info() {
	cout << "End city is " << m_end << " - (" << m_end_coords.m_x << ", " << m_end_coords.m_y << ") " << endl;
}