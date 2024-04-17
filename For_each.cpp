#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <future>
#include <numeric>

template<typename Func>

Func par_for_each(std::vector<int>::iterator begin, std::vector<int>::iterator end, Func function) {
   
    const auto diff = std::distance(begin, end);
    std::cout << diff << std::endl;
    if (diff < 11) {
      return std::for_each(begin, end, function);
       
    }
    
    auto middle = begin;
    std::advance(middle, diff / 2);

    auto fut_res = std::async(par_for_each<Func>, begin, middle, function);

    auto lf_res = par_for_each(middle, end, function);
    return fut_res.get();
    
}

int main()
{
    setlocale(LC_ALL, "russian");

    std::vector<int> vec{ 3,7,4,9,1,3,5,6,2,9,5,8,1 };


    par_for_each(vec.begin(), vec.end(), [](int begin) {
        std::cout << begin << " ";
       });
    return 0;
}
