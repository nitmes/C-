#include <cmath>
#include "function.h"

double add(double x, double y) {
	return x + y;
}
double sub(double x, double y) {
	return x - y;
}
double mul(double x, double y) {
	return x * y;
}double divy(double x, double y) {
	return x / y;
}double exp(double x, double y) {
	return std::pow(x,y);
}