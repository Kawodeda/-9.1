
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

void PrintPolynomyal(const std::vector<float> polynomial)
{
	const std::streamsize FLOAT_PRECISION = 4;

	if (polynomial.size() > 0)
	{
		std::cout << std::setprecision(FLOAT_PRECISION) << polynomial[0];
		for (int i = 1; i < polynomial.size(); ++i)
		{
			std::cout << ", " << std::setprecision(FLOAT_PRECISION) << polynomial[i];
		}
	}	
}

std::vector<float> ScanPolynomial()
{
	std::cout << std::endl << "Enter the number of terms: ";
	size_t size = 0;
	std::cin >> size;

	std::vector<float> result(size);
	for (int i = 0; i < size; ++i)
	{
		std::cout << "term" << (i + 1) << " = ";
		std::cin >> result[i];
	}

	return result;
}

std::vector<float> MultiplyPolynomials
(const std::vector<float>& a, const std::vector<float>& b)
{
	size_t resultSize = a.size() * b.size();
	std::vector<float> result(resultSize);

	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < b.size(); ++j)
		{
			result[i * b.size() + j] = a[i] * b[j];
		}
	}

	return result;
}

int main()
{
	try
	{
		std::cout << "Enter two polynomials:" << std::endl;
		std::vector<float> a = ScanPolynomial();
		std::vector<float> b = ScanPolynomial();
		std::cout << std::endl << "The product: ";
		PrintPolynomyal(MultiplyPolynomials(a, b));
	}
	catch (std::exception& e)
	{
		std::cout << std::endl << "Error: " << e.what();
		return -1;
	}

	return 0;
}
