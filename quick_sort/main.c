#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename ItType>
void quickSort(ItType start, ItType end) {
    using ValueType = typename std::iterator_traits<ItType>::value_type;

    if (std::distance(start, end) <= 1) return;
    
    auto pivotIt = std::prev(end);
    ValueType pivotVal = *pivotIt;

    auto i = start;
    auto j = pivotIt;
    while (i != j) {
        while (*i < pivotVal && i != j) i = std::next(i);
        while (*j >=pivotVal && i != j) j = std::prev(j);

        
        if (i != j) std::iter_swap(i, j);
    }

    if (*i > pivotVal) {
        std::iter_swap(i, pivotIt);
    }
    
    quickSort(start, i);
    quickSort(std::next(i), end);
}

// comment out main() before running tests
int main() {
    
    vector<double> arr = {9.1, 9.5, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0, 0};
    quickSort(arr.begin(), arr.end());

    cout << "Sorted Array: ";
    for (double num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
