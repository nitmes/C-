#include <iostream>
#include <string>

class Figure {
protected:
	std::string name;
	int count_sides = 0;
	bool status = false;
	virtual bool check() {
		if (count_sides == 0) {
			return true;
		}
		else {
			return false;
		}
	}
public:
	Figure() {
		name = "Фигура";
	}
	std::string get_name() {
		return name;
	}
	virtual void print_info() {
		std::cout << name << ": \n";
		if (check()) {
			std::cout << "Правильная \n";
		}
		else {
			std::cout << "Неправильная \n";
		}
		std::cout << "Количество сторон: " << count_sides << "\n";
		if (count_sides == 0){
			std::cout << "\n";
		}
	}

};
class Triangle :public Figure {
protected:
	int a_s = 0;
	int b_s = 0;
	int c_s = 0;
	int a_d = 0;
	int b_d = 0;
	int c_d = 0;
	bool check() override {
		if ((a_d + b_d + c_d) == 180) {
			return true;
		}
		else {
			return false;
		}
	}
public:
	Triangle(int a_s, int b_s, int c_s, int a_d, int b_d, int c_d) : a_s(a_s), b_s(b_s), c_s(c_s), a_d(a_d), b_d(b_d), c_d(c_d) {
		name = "Треугольник";
		count_sides = 3;
		status = check();
	}
	std::string get_sides() {
		return("a=" + std::to_string(a_s) + " " + "b=" + std::to_string(b_s) + " " + "c=" + std::to_string(c_s) + "\n");
	}
	std::string get_angles() {
		return("A=" + std::to_string(a_d) + " " + "B=" + std::to_string(b_d) + " " + "C=" + std::to_string(c_d) + "\n");
	}
	void print_info() override {
		Figure::print_info();
		std::cout << "Стороны: ";
		std::cout << get_sides();
		std::cout << "Углы: ";
		std::cout << get_angles() << "\n";
	}
};
class ra_triangle :public Triangle {
protected:
	bool check() override {
		if (Triangle::check() && c_d == 90) {
			return true;
		}
		else {
			return false;
		}
	}
public:
	ra_triangle(int a_s, int b_s, int c_s, int a_d, int b_d) :Triangle(a_s, b_s, c_s, a_d, b_d, 90) {
		name = "Прямоугольный треугольник";
	};
};
class isosceles_triangle :public Triangle {
protected:
	bool check() override {
		if (Triangle::check() && (a_s == c_s) && a_d == c_d) {
			return true;
		}
		else {
			return false;
		}
	}
public:
	isosceles_triangle(int a_s, int b_s, int a_d, int b_d) :Triangle(a_s, b_s, a_s, a_d, b_d, a_d) {
		name = "Равнобедренный треугольник";
	};
};
class equil_triangle :public Triangle {
protected:
	bool check() override {
		if (Triangle::check() && (a_s == b_s && b_s== c_s) && (a_d == 60 && b_d ==60 && c_d == 60)) {
			return true;
		}
		else {
			return false;
		}
	}
public:
	equil_triangle(int a_s) :Triangle(a_s, a_s, a_s, 60, 60, 60) {
		name = "Равносторонний треугольник";
	};
};
class Quadrangle :public Figure {
protected:
	int a_s = 0;
	int b_s = 0;
	int c_s = 0;
	int d_s = 0;
	int a_d = 0;
	int b_d = 0;
	int c_d = 0;
	int d_d = 0;
	virtual bool check() {
		if ((a_d + b_d + c_d + d_d) == 360) {
			return true;
		}
		else {
			return false;
		}
	}
	bool sqad() {
		if (a_s == b_s && b_s == c_s && c_s == d_s) {
			return true;
		}
		else {
			return false;
		}
	}
	bool parall() {
		if (a_s == c_s && b_s == d_s) {
			return true;
		}
		else {
			return false;
		}
	}
	bool degrees() {
		if (a_d == 90 && b_d == 90 && c_d == 90 && d_d == 90) {
			return true;
		}
		else {
			return false;
		}
	}
public:
	Quadrangle(int a_s, int b_s, int c_s, int d_s, int a_d, int b_d, int c_d, int d_d) : a_s(a_s), b_s(b_s), c_s(c_s), d_s(d_s), a_d(a_d), b_d(b_d), c_d(c_d), d_d(d_d) {
		name = "Четырехугольник";
		count_sides = 4;
	}
	std::string get_sides() {
		return("a=" + std::to_string(a_s) + " " + "b=" + std::to_string(b_s) + " " + "c=" + std::to_string(c_s) + " " + "d=" + std::to_string(d_s) + "\n");
	}
	std::string get_angles() {
		return("A=" + std::to_string(a_d) + " " + "B=" + std::to_string(b_d) + " " + "C=" + std::to_string(c_d) + " " + "D=" + std::to_string(d_d) + "\n");
	}
	void print_info() override {
		Figure::print_info();
		std::cout << "Стороны: ";
		std::cout << get_sides();
		std::cout << "Углы: ";
		std::cout << get_angles() << "\n";
	}
};
class rectangle : public Quadrangle{
protected:
	bool check() override {
		if (Quadrangle::check() && Quadrangle::parall() && Quadrangle::degrees()) {
			return true; 
		}
		else {
			return false;
		}
	};
public:
	rectangle(int a_s, int b_s) : Quadrangle(a_s, b_s, a_s, b_s, 90, 90, 90, 90) {
		Quadrangle::name = "Прямоугольник";
	}
};
class square : public Quadrangle{
protected:
	bool check() override {
		if (Quadrangle::check() && Quadrangle::sqad() && Quadrangle::degrees()) {
			return true;
		}
		else {
			return false;
		}
	};
public:
	square(int a_s) : Quadrangle(a_s, a_s, a_s, a_s, 90, 90, 90, 90) {
		Quadrangle::name = "Квадрат";
	}
};
class paralle : public Quadrangle{
protected:
	bool check() override {
		if (Quadrangle::check() && Quadrangle::parall() && Quadrangle::degrees()) {
			return true;
		}
		else {
			return false;
		}
	};
public:
	paralle(int a_s, int b_s, int a_d, int b_d) : Quadrangle(a_s, b_s, a_s, b_s, a_d, b_d, a_d, b_d) {
		Quadrangle::name = "Параллелограмм";
	}
};
class rhomb : public Quadrangle{
protected:
	bool check() override {
		if (Quadrangle::check() && Quadrangle::sqad() && Quadrangle::degrees()) {
			return true;
		}
		else {
			return false;
		}
	};
public:
	rhomb(int a_s, int a_d, int b_d) : Quadrangle(a_s, a_s, a_s, a_s, a_d, b_d, a_d, b_d) {
		Quadrangle::name = "Ромб";
	}
};
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	Figure Figure1;//Фигура
	Figure1.print_info();
	Triangle triangle(10, 20, 30, 50, 60, 70);//Треугольник
	Figure* t = &triangle;
	t->print_info();
	ra_triangle r_triangle(10, 20, 30, 50, 60);//Прямоугольный
	Figure* ra_t = &r_triangle;
	ra_t->print_info();
	ra_triangle pra_triangle(10, 20, 30, 50, 40);//Прямоугольный
	Figure* pra_t = &pra_triangle;
	pra_t->print_info();
	isosceles_triangle isosceles_triangle(10, 20, 50, 60);//
	Figure* i_t = &isosceles_triangle;
	i_t->print_info();
	equil_triangle equil_triangle(30);//
	Figure* e_t = &equil_triangle;
	e_t->print_info();
	Quadrangle qudrangle(10, 20, 30, 40, 50, 60, 70, 80);//
	Figure* q = &qudrangle;
	q->print_info();
	rectangle rectangle(10, 20);//
	Figure* f_rectangle = &rectangle;
	f_rectangle->print_info();
	square square(20);//
	Figure* f_square = &square;
	f_square->print_info();
	paralle paralle(20, 30, 30, 40);//
	Figure* f_parallelogram = &paralle;
	f_parallelogram->print_info();
	rhomb rhomb(30, 30, 40);//
	Figure* f_rhomb = &rhomb;
	f_rhomb->print_info();
	return 0;
}