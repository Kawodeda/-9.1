
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

void PrintTerm(const float term, const int power)
{
	const std::streamsize FLOAT_PRECISION = 4;

	if (term == 0)
	{
		return;
	}

	std::cout << std::setprecision(FLOAT_PRECISION) << term;

	if (power == 1)
	{
		std::cout << "x";
		return;
	}
	if (power == 0)
	{
		return;
	}

	std::cout << "x^" << power;
	return;
}

void PrintPolynomyal(const std::vector<float>& polynomial)
{
	size_t size = polynomial.size();
	if (size > 0)
	{		
		for (size_t i = 0; i < size - 1; ++i)
		{
			PrintTerm(polynomial[i], size - i - 1);
			if (polynomial[i + 1] != 0)
			{
				std::cout << " + ";
			}			
		}
		PrintTerm(polynomial[size - 1], 0);
		std::cout << std::endl;
	}	
}

std::vector<float> ScanPolynomial()
{
	std::cout << std::endl << "Enter the max power of x: ";
	int maxPower = 0;
	std::cin >> maxPower;

	size_t size = maxPower + 1;

	std::vector<float> result(size);
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << "coefficient of x^" << (size - i - 1) << " = ";
		std::cin >> result[i];
	}

	return result;
}

std::vector<float> MultiplyPolynomials
(const std::vector<float>& a, const std::vector<float>& b)
{
	int aSize = a.size();
	int bSize = b.size();
	int resultSize = aSize + bSize - 1;
	std::vector<float> result(resultSize);

	for (int n = 0; n < resultSize; ++n)
	{
		int minI = std::max<int>(aSize + n - resultSize, 0);
		int maxI = std::min<int>(bSize + aSize + n - resultSize - 1, aSize - 1);
		
		int j = std::min<int>(maxI, bSize - 1);
		for (int i = minI; i <= maxI; ++i)
		{
			result[n] += a[i] * b[j];
			--j;
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

		std::vector<float> result = MultiplyPolynomials(a, b);
		PrintPolynomyal(result);
	}
	catch (std::exception& e)
	{
		std::cout << std::endl << "Error: " << e.what();
		return -1;
	}

	return 0;
}
