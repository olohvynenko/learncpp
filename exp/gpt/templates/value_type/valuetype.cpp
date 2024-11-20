#include <iostream>

template <typename BufferType>
void fillBuffer(BufferType& buffer, typename BufferType::value_type22 value) {
    for (int i = 0; i < buffer.size(); ++i) {
        buffer[i] = value; // Заповнюємо буфер значенням
    }
}

template <typename BufferType>
void printBuffer(const BufferType& buffer) {
    for (int i = 0; i < buffer.size(); ++i) {
        std::cout << buffer[i] << " ";
    }
    std::cout << "\n";
}

template<typename T, int N>
struct Buffer {
    using value_type22 = T;
    T data[N];

    constexpr int size() const { return N; }

    T& operator[](int index) { return data[index]; }
    const T& operator[](int index) const { return data[index]; }
};

int main() {
    Buffer<int, 5> intBuffer;
    fillBuffer(intBuffer, 42); // Заповнюємо буфер числом 42
    printBuffer(intBuffer);    // Виводимо: 42 42 42 42 42

    Buffer<double, 3> dblBuffer;
    fillBuffer(dblBuffer, 3.14); // Заповнюємо буфер числом 3.14
    printBuffer(dblBuffer);      // Виводимо: 3.14 3.14 3.14

    return 0;
}
