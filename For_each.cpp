#include <iostream>
#include <vector>
#include <thread>

template<typename Func>

Func for_each(std::vector<int>::iterator begin, std::vector<int>::iterator end, Func&& function) {

    while (begin < end) {
        function(begin);     
        begin = begin + 1;
        return for_each(begin, end, function);

    }

}

int main()
{
    setlocale(LC_ALL, "russian");

    std::vector<int> vec{ 3,7,4,9,1,3,5,6,2 };


    for_each(vec.begin(), vec.end(), [](std::vector<int>::iterator begin) {
        std::cout << *begin << " ";
       });

    


    return 0;
}
