#include<iostream>

template<typename T> 
class Less_than { 
    const T val; // value to compare against 
public:
    Less_than(const T& v) :val(v) { } 
    bool operator()(const T& x) const 
    { 
        return x < val; 
    } // call operator 
};


template<typename C, typename P>
bool check(const C& inputValue, P pred) {
return pred(inputValue);
};

int main() {
    Less_than<int> lessThan5 { 5 };
    for(int i=0; i<3; i++) {
        int a;
        std::cin >> a;
        if (check(a, lessThan5)) std::cout << "Less than 5\n";
        else std::cout << "Equal or greater than 5\n";
    }

}
