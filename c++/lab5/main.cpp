#include <iostream>
#include <fstream>

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
		// В деструктор поток не передаем
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

	void print_distance(ofstream& fout) {
		_calc();
		cout << "Distance between " << m_start << " and " << m_end << " is : " << m_distance << endl;
		fout << "Distance between " << m_start << " and " << m_end << " is : " << m_distance << endl;
	}

	void start_info(ofstream& fout);
	void end_info(ofstream& fout);

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
	ofstream fout;
	fout.open("output.txt");

	Route def;
	def.start_info(fout);
	def.end_info(fout);
	def.print_distance(fout);
	Route MskLon("Moscow", { 300, 300 }, "London", { 450, 450 });
	MskLon.start_info(fout);
	MskLon.end_info(fout);
	MskLon.print_distance(fout);
	Route PitLon("Piter", { 100, 700 });
	PitLon.start_info(fout);
	PitLon.end_info(fout);
	PitLon.print_distance(fout);
	Route MskLon2(MskLon);
	MskLon2.start_info(fout);
	MskLon2.end_info(fout);
	MskLon2.print_distance(fout);
	cout << endl;

	fout.close();
	return 0;
}

void Route::start_info(ofstream& fout) {
	cout << "Start city is " << m_start << " - (" << m_start_coords.m_x << ", " << m_start_coords.m_y << ") " << endl;
	fout << "Start city is " << m_start << " - (" << m_start_coords.m_x << ", " << m_start_coords.m_y << ") " << endl;
}

void Route::end_info(ofstream& fout) {
	cout << "End city is " << m_end << " - (" << m_end_coords.m_x << ", " << m_end_coords.m_y << ") " << endl;
	fout << "End city is " << m_end << " - (" << m_end_coords.m_x << ", " << m_end_coords.m_y << ") " << endl;
}