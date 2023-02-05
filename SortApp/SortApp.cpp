#include <iostream>
#include <ostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include "benchmark.h"
#include "../SortLib/BubbleSort.h"
#include "../SortLib/InsertionSort.h"
#include "../SortLib/SelectionSort.h"
#include "../SortLib/MergeSort.h"
#include "../SortLib/QuickSort.h"
#include "../SortLib/ShellSort.h"


int main()
{
	setlocale(LC_ALL, "pl-pl");
	std::vector<size_t> s = { 5000, 10000,15000, 20000, 30000, 40000, 50000, 60000, 80000, 100000 };
    for (auto n : s)
    {
		std::vector<unsigned int> v;

		// wygenerowanie losowej zawarto�ci kolekcji

		// wygenerowanie losowej zawarto�ci kolekcji

		auto seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937 generator((unsigned int)seed);

		for (size_t i = 0; i < n; i++)
			v.push_back(generator());

		// wy�wietlenie zawarto�ci kolekcji przed sortowaniem
		/*std::cout << "Kolekcja nieposortowana:" << std::endl;
		for (auto value : v)
			std::cout << value << std::endl;
		std::cout << std::endl;*/

		Benchmark<std::chrono::nanoseconds> b;
		//bubbleSort(v.begin(), v.end());
		//insertionSort(v.begin(), v.end());
		//selectionSort(v.begin(), v.end());
		//mergeSort(v.begin(), v.end());
		//quickSort(v.begin(), v.end());
		shellSort(v.begin(), v.end());
		auto t = b.elapsed();

		// wy�wietlenie zawarto�ci kolekcji po posortowaniu
    /*
		std::cout << "Kolekcja posortowana:" << std::endl;
        for (auto value : v)
            std::cout << value << std::endl;
		std::cout << std::endl;
    */
		std::cout << t /*<< "ns" */ << std::endl;
	}
}
