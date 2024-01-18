#include <iostream>
#include <string>

class Figure {
protected:
	std::string name;
public:
	std::string get_name() {
		return name;
	}
	virtual void print() {
		std::cout << name;
	}
	void print_info(Figure* figure) {
		std::cout << name<<"\n";
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
public:
	Triangle(int a_s, int b_s, int c_s, int a_d, int b_d, int c_d): a_s(a_s), b_s(b_s), c_s(c_s), a_d(a_d), b_d(b_d), c_d(c_d) {
		name = "Треугольник";
	}
	std::string get_sides() {

		return("a="+std::to_string(a_s)+" "+"b="+std::to_string(b_s)+" "+"c="+std::to_string(c_s)+"\n");
	}
	std::string get_angles() {
		return("A=" + std::to_string(a_d) + " " + "B=" + std::to_string(b_d) + " " + "C=" + std::to_string(c_d) + "\n");
	}
	void print() override {
		print_info(this);
		std::cout << "Стороны: ";
		std::cout << get_sides();
		std::cout << "Углы: ";
		std::cout << get_angles() << "\n";
	}
};
class ra_triangle :public Triangle {
public:
	ra_triangle(int a_s, int b_s, int c_s, int a_d, int b_d) :Triangle(a_s, b_s, c_s, a_d, b_d, 90) {
		name = "Прямоугольный треугольник";
	};
};
class isosceles_triangle :public Triangle {
public:
	isosceles_triangle(int a_s, int b_s, int a_d, int b_d) :Triangle(a_s, b_s, a_s, a_d, b_d, a_d) {
		name = "Равнобедренный треугольник";
	};
};
class equil_triangle :public Triangle {
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
public:
	Quadrangle(int a_s, int b_s, int c_s,int d_s, int a_d, int b_d, int c_d,int d_d) : a_s(a_s), b_s(b_s), c_s(c_s),d_s(d_s), a_d(a_d), b_d(b_d), c_d(c_d),d_d(d_d) {
		name = "Четырехугольник";
	}
	std::string get_sides() {
		return("a=" + std::to_string(a_s) + " " + "b=" + std::to_string(b_s) + " " + "c=" + std::to_string(c_s) + " " + "d=" + std::to_string(d_s)+"\n");
	}
	std::string get_angles() {
		return("A=" + std::to_string(a_d) + " " + "B=" + std::to_string(b_d) + " " + "C=" + std::to_string(c_d) + " " + "D=" + std::to_string(d_d) + "\n");
	}
	void print() override {
		print_info(this);
		std::cout << "Стороны: ";
		std::cout << get_sides();
		std::cout << "Углы: ";
		std::cout << get_angles() << "\n";
	}
};
class rectangle : public Quadrangle 
{
public:
	rectangle(int a_s, int b_s) : Quadrangle(a_s, b_s, a_s, b_s, 90, 90, 90, 90) {
		Quadrangle::name = "Прямоугольник";
	}
};
class square : public Quadrangle 
{
public:
	square(int a_s) : Quadrangle(a_s, a_s, a_s, a_s, 90, 90, 90, 90) {
		Quadrangle::name = "Квадрат";
	}
};
class paralle : public Quadrangle 
{
public:
	paralle(int a_s, int b_s, int a_d, int b_d) : Quadrangle(a_s, b_s, a_s, b_s, a_d, b_d, a_d, b_d) {
		Quadrangle::name = "Параллелограмм";
	}
};
class rhomb : public Quadrangle 
{
public:
	rhomb(int a_s, int a_d, int b_d) : Quadrangle(a_s, a_s, a_s, a_s, a_d, b_d, a_d, b_d) {
		Quadrangle::name = "Ромб";
	}
};
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	Triangle triangle(10, 20, 30, 50, 60, 70);//
	Figure* t = &triangle;
	t ->print();
	ra_triangle ra_triangle(10, 20, 30, 50, 60);//
	Figure* ra_t = &ra_triangle;
	ra_t->print();
	isosceles_triangle isosceles_triangle(10,20,50,60);//
	Figure* i_t = &isosceles_triangle;
	i_t->print();
	equil_triangle equil_triangle(30);//
	Figure* e_t = &equil_triangle;
	e_t->print();
	Quadrangle qudrangle(10, 20, 30, 40, 50, 60, 70, 80);//
	Figure* q = &qudrangle;
	q->print();
	rectangle rectangle(10, 20);//
	Figure* f_rectangle = &rectangle;
	f_rectangle->print();
	square square(20);//
	Figure* f_square = &square;
	f_square->print();
	paralle paralle(20, 30, 30, 40);//
	Figure* f_parallelogram = &paralle;
	f_parallelogram->print();
	rhomb rhomb(30, 30, 40);//
	Figure* f_rhomb = &rhomb;
	f_rhomb->print();
	return 0;
}	