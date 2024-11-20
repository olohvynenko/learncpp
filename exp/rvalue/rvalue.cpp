#include <iostream>
#include <utility> // Для std::move

class Resource {
public:
    // Конструктор за замовчуванням
    Resource() { 
        std::cout << "Default constructor\n"; 
    }

    // Конструктор копіювання
    Resource(const Resource& other) { 
        std::cout << "Copy constructor\n"; 
    }

    // Конструктор переміщення
    Resource(Resource&& other) noexcept { 
        std::cout << "Move constructor\n"; 
    }

    // Оператор присвоєння копіювання
    Resource& operator=(const Resource& other) {
        std::cout << "Copy assignment operator\n"; 
        return *this;
    }

    // Оператор присвоєння переміщення
    Resource& operator=(Resource&& other) noexcept {
        std::cout << "Move assignment operator\n"; 
        return *this;
    }

    ~Resource() { 
        std::cout << "Destructor\n"; 
    }
};

// Функція, яка приймає lvalue (посилання на const)
void useLValue(const Resource& res) {
    std::cout << "Using lvalue\n";
}

// Функція, яка приймає rvalue (посилання на rvalue)
void useRValue(Resource&& res) {
    std::cout << "Using rvalue\n";
}

int main() {
    // 1. Виклик default constructor
    Resource res1; // Default constructor

    // 2. Виклик copy constructor
    Resource res2 = res1; // Copy constructor

    // 3. Використання lvalue
    useLValue(res1); // Викликається функція для lvalue

    // 4. Використання rvalue
    useRValue(Resource()); // Default constructor + Виклик функції для rvalue

    // 5. Виклик move constructor
    Resource res3 = std::move(res1); // Move constructor

    // 6. Присвоєння з копіюванням
    res2 = res3; // Copy assignment operator

    // 7. Присвоєння з переміщенням
    res2 = std::move(res3); // Move assignment operator

    return 0;
}
