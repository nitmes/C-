#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	int size, size2 = 0;
	std::ifstream f;
	f.open("in.txt");
	f >> size;
	int* firstArray = new int[size];
	for (int i = 0; i < size; ++i) {
		f >> firstArray[i];
	}
	f >> size2;
	int* secondArray = new int[size2];
	for (int i = 0; i < size2; ++i) {
		f >> secondArray[i];
	}
	f.close();
	std::ofstream z;
	z.open("out.txt");
	z << size2 << "\n";
	z << secondArray[size2-1] << " ";
	for (int i = 0; i < size2-1 ; ++i) {
		z << secondArray[i] << " ";
	}
	z << "\n";
	z << size << "\n";
	for (int i = 1; i < size; ++i) {
		z << firstArray[i] << " ";
	}
	z << firstArray[0] << "\n";
	z.close();
	delete[] firstArray;
	delete[] secondArray;
}