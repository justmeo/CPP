
#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    int i = 1;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    while(i < argc)
    {
        while(*argv[i])
        {
            std::cout << (char)toupper(*argv[i]);
            argv[i]++;
        }
        i++;
    }
    std::cout << std::endl;
    return 0;
}