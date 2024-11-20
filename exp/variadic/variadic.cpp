#include<iostream>

void f() { } // do nothing 

template<typename T>
void g(T arg) 
{
    std::cout << arg << "\n";
}

template<typename T, typename ... Tail> 
void f(T head, Tail... tail) 
{
    g(head); // do something to head 
    f(tail...); // tr y again with tail 
}

int main()
{
    f(1, 2.1, "whats up");
}
