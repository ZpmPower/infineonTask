#include <algorithm>
#include <iostream>
#include<fstream>
#include <iomanip>
#include <vector>
#include "median.h"
using namespace std;

pair<unsigned int, unsigned int> getHighlights(vector<long long> v)
{
    int size = v.size();
	if(v.size() % 2 != 0)
	{
        return std::make_pair(-1, size / 2);
	}
    else
    {
        return std::make_pair((size - 1) / 2, size / 2);
    }
}


int main()
{
    try
    {
	    ifstream file("file.txt");
	    vector<long long> numbers;
	    long long num;
	    while (file >> num) {
			if (num < -70 || num >(2.28 * pow(10, 9))) throw out_of_range("Value out of range");
	        numbers.push_back(num);
	    }

	    cout << "Data from file: ";
	    for(auto i: numbers)
	    {
	        cout << i << ' ';
	    }
	    cout << endl;
		
	    sort(numbers.begin(), numbers.end());

	    pair<unsigned int, unsigned int> highlight = getHighlights(numbers);
		
	    cout << "Data from file sorted: ";
	    for(unsigned int i=0; i< numbers.size(); ++i)
	    {
	        if ((highlight.first == -1 && highlight.second == i) || (highlight.first != -1 && highlight.first == i))
	        {
	            cout << "[";
	        }
	        cout << numbers[i] << " ";
	        if ((highlight.first == -1 && highlight.second == i) || (highlight.first != -1 && highlight.second == i))
	        {
	            cout << "]";
	        }
	    }
	    const double medianNumber = median(numbers);
	    printf("Median is : %.2f\n", medianNumber);
	}
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
	return 0;
}