#include <iostream>
#include <vector>

template <class T>
T squad(T a) 
{
	return (a * a);
}

template <class T>
std::vector<T> squad(const std::vector<T>& vec)
{
	std::vector<T> result;
	for (const auto& elem : vec)
	{
		result.push_back(squad(elem));
	}
	return result;
}

int main()
{
	int chislo1 = 0;
	std::vector<int> Vec;
	std::vector<int> VecResult;
	int SizeVector = 0;
	int vector = 0;
	int result=0;

	std::cout << "[IN]: ";
	std::cin >> chislo1;
	result = squad(chislo1);
	std::cout << "[OUT]: " << result << std::endl; 

	while (SizeVector == 0) 
	{
		std::cout << "Enter size of vector: ";
		std::cin >> SizeVector;
	}
	for (int i = 0; i < SizeVector; i++) 
	{
		std::cout << "Vector [" << i << "] : ";
		std::cin >> vector;
		Vec.push_back(vector);
	}
	VecResult = squad(Vec);

	std::cout << "Vector results: ";
	for (int i=0;i<SizeVector;i++)
	{
		std::cout << VecResult[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}