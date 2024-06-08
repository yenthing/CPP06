#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void testClass(Base* base) {
    identify(base);
    identify(*base);
    delete base;
}

int main()
{
    Base* a = new A();
    Base* b = new B();
    Base* c = new C();

    std::cout << "Testing A:" << std::endl;
    testClass(a);

    std::cout << "\nTesting B:" << std::endl;
    testClass(b);

    std::cout << "\nTesting C:" << std::endl;
    testClass(c);

    std::cout << "\n---Randomly generates one of A, B, or C---" << std::endl;
    std::cout << "Testing generate():" << std::endl;
    for (int i = 0; i < 3; ++i) {
        Base* p = generate();
        testClass(p);
    }
    return 0;
}
