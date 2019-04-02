#include <algorithm>	//to get the declaration for sort
#include <stdexcept>	//for domain_error
#include <vector>		//for vector 
#include <numeric>

using std::domain_error; 	using std::sort;	using std::vector;

//compute the median of a vector<double>

double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;
	
	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error ("median of an empty vector");
		
	sort(vec.begin(), vec.end());
	
	vec_sz mid = size/2;
	
	return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
	
}

double optimistic_median(vector<double> vec)
{
	vector<double> non_zero;

	remove_copy(vec.begin(), vec.end(), back_inserter(non_zero), 0);

	if (non_zero.empty())
		return 0;
	else	
		return median(non_zero);
}

double average(const vector<double>& vec)
{
    return accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
}
