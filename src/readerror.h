#ifndef READERROR_H
#define READERROR_H

#include <stdexcept>

class ReadError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

#endif // READERROR_H
