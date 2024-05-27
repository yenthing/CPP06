#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./convert <put value here>" << std::endl;
        return 1;
    }
    ScalarConverter sc(av[1]);
    sc.convert();
    // sc.print();
    return 0;
}
