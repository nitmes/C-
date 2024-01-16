#include <iostream>


class Figure {
protected:
	int sides_count;
public:
	
	class Triangle :public Figure{};
	class Quadrangle :public Figure {};
};

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	
	return 0;
}