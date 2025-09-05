#include "Serializer.hpp"
#include <iostream>

int main() {
    Data d = {42, "alpha", 3.14};
    Data* p = &d;

    uintptr_t raw = Serializer::serialize(p);
    Data* q = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << p << std::endl;
    std::cout << "Deserialized pointer: " << q << std::endl;
    std::cout << "Data: " << q->id << ", " << q->label << ", " << q->score << std::endl;

    return 0;
}
