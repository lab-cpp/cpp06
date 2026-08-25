#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h> // Required for uintptr_t in C++98
#include "Data.hpp"

class Serializer {
    private:
        // Private constructors to enforce the class being uninstantiable
        Serializer();
        Serializer(const Serializer& src);
        Serializer& operator=(const Serializer& rhs);
        ~Serializer();

    public:
        // Converts a pointer into an unsigned integer
        static uintptr_t serialize(Data* ptr);
        
        // Converts an unsigned integer back into a pointer
        static Data* deserialize(uintptr_t raw);
};

#endif
