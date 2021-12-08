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
	Route(
		const string& start_city = "Moscow", 
		const Point& start_city_coords = { 300, 300 },
		const string& end_city = "Paris",
		const Point& end_city_coords = { 500, 600 }
	) {
		m_start = start_city;
		m_start_coords = start_city_coords;
		m_end = end_city;
		m_end_coords = end_city_coords;
		_calc();
	}

	Route(const Route& copied_route) {
		m_start = copied_route.m_start;
		m_start_coords = copied_route.m_start_coords;
		m_end = copied_route.m_end;
		m_end_coords = copied_route.m_end_coords;
		_calc();
	}

	~Route() {
		cout << "Route " << m_start << " - " << m_end << " has been deleted" << endl;
	}

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

	string m_start;
	string m_end;
	Point m_start_coords;
	Point m_end_coords;
	float m_distance;
};

int main()
{
	Route def;
	def.start_info();
	def.end_info();
	def.print_distance();
	Route MskLon("Moscow", { 300, 300 }, "London", { 450, 450 });
	MskLon.start_info();
	MskLon.end_info();
	MskLon.print_distance();
	Route PitLon("Piter", { 100, 700 });
	PitLon.start_info();
	PitLon.end_info();
	PitLon.print_distance();
	Route MskLon2(MskLon);
	MskLon2.start_info();
	MskLon2.end_info();
	MskLon2.print_distance();
	cout << endl;

	return 0;
}

void Route::start_info() {
	cout << "Start city is " << m_start << " - (" << m_start_coords.m_x << ", " << m_start_coords.m_y << ") " << endl;
}

void Route::end_info() {
	cout << "End city is " << m_end << " - (" << m_end_coords.m_x << ", " << m_end_coords.m_y << ") " << endl;
}