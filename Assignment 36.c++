STL: array

1. Using STL Array gets and sets a reference to an element based on a given index.
2. Using STL Array returns the total number of elements in the array.
3. Find the first and last element using the STL array.
4. Returns the element from the given index using the STL array.
5. C++ STL program to demonstrate example of array::rbegin() and array::rend()
functions
6. Using STL to check whether an array is empty or not.
7. Sort an array in ascending order using sort() function in C++ STL
8. Sort an array in descending order using sort() function in C++ STL
9. C++ program to find the integers which come an odd number of times in an array
using C++ STL.
10. Given an integer array nums , return an array answer such that answer[i] is equal to
the product of all the elements of nums except nums[i] .

Solution:-

1. #include <iostream>
#include <array>

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};

    // Get a reference to the element at index 2
    int& ref = arr[2];
    std::cout << "Element at index 2: " << ref << std::endl;

    // Set the element at index 2
    ref = 10;
    std::cout << "Updated element at index 2: " << arr[2] << std::endl;

    return 0;
}

2. #include <iostream>
#include <array>

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::cout << "Total number of elements: " << arr.size() << std::endl;

    return 0;
}

3. #include <iostream>
#include <array>

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};

    std::cout << "First element: " << arr.front() << std::endl;
    std::cout << "Last element: " << arr.back() << std::endl;

    return 0;
}

4. #include <iostream>
#include <array>

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    int index = 2;

    std::cout << "Element at index " << index << ": " << arr.at(index) << std::endl;

    return 0;
}

5. #include <iostream>
#include <array>

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};

    std::cout << "Array in reverse order: ";
    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

6. #include <iostream>
#include <array>

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::array<int, 0> emptyArr;

    std::cout << "Is array empty? " << std::boolalpha << arr.empty() << std::endl;
    std::cout << "Is empty array empty? " << std::boolalpha << emptyArr.empty() << std::endl;

    return 0;
}

7. #include <iostream>
#include <array>
#include <algorithm>

int main() {
    std::array<int, 5> arr = {5, 3, 4, 1, 2};

    std::sort(arr.begin(), arr.end());

    std::cout << "Array sorted in ascending order: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

8. #include <iostream>
#include <array>
#include <algorithm>

int main() {
    std::array<int, 5> arr = {5, 3, 4, 1, 2};

    std::sort(arr.begin(), arr.end(), std::greater<int>());

    std::cout << "Array sorted in descending order: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

9. #include <iostream>
#include <array>
#include <unordered_map>
#include <vector>

int main() {
    std::array<int, 11> arr = {1, 2, 3, 2, 3, 1, 3, 3, 3, 1, 1};
    std::unordered_map<int, int> frequency;

    for (const auto& elem : arr) {
        frequency[elem]++;
    }

    std::vector<int> oddFrequencyElements;
    for (const auto& pair : frequency) {
        if (pair.second % 2 != 0) {
            oddFrequencyElements.push_back(pair.first);
        }
    }

    std::cout << "Elements with odd frequency: ";
    for (const auto& elem : oddFrequencyElements) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

10. #include <iostream>
#include <vector>

std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n, 1);
    int left = 1, right = 1;

    for (int i = 0; i < n; ++i) {
        result[i] *= left;
        left *= nums[i];
    }

    for (int i = n - 1; i >= 0; --i) {
        result[i] *= right;
        right *= nums[i];
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> result = productExceptSelf(nums);

    std::cout << "Product of elements except self: ";
    for (const auto& elem : result) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
