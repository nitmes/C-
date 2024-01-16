#include <iostream>


class Figure {
protected:
	int sides_count;
	std::string name;
	Figure(int sides_count, std::string name) {
		this->sides_count = sides_count;
		this->name = name;
	}
public:
	Figure() :Figure(0, "Фигура") {};
	int get_sides_count() {
		return sides_count;
	}
	std::string get_name(){
		return name;	
	}
};
class Triangle :public Figure {
public:
	Triangle() :Figure(3, "Треугольник") {};
};
class Quadrangle :public Figure {
public:
	Quadrangle() :Figure(4, "Четырехугольник") {};
};

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	Figure f;
	Triangle t;
	Quadrangle q;
	std::cout << "Количество сторон: \n";
	std::cout << f.get_name() << " " << f.get_sides_count() <<"\n";
	std::cout << t.get_name() << " " << t.get_sides_count() << "\n";
	std::cout << q.get_name() << " " << q.get_sides_count() << "\n";
	return 0;
}