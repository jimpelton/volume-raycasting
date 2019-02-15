
#include "util.h"
#include "readerror.h"

/*!
 * \brief Check whether the architecture is little endian.
 * \return `true` if little endian, `false` if big endian.
 */
bool is_little_endian()
{
    union {
        unsigned long l;
        unsigned char c[sizeof(unsigned long)];
    } x;
    x.l = 1;
    return x.c[0] == 1;
}




/*!
 * \brief Check if a VTK file is binary.
 * \param header Header lines of the file.
 * \return `true` if binary.
 */
bool is_binary(const std::vector<std::string> &header)
{
    for (auto it = header.begin(); it != header.end(); ++it) {
        if (it->substr(0, 6) == "BINARY") {
            return true;
        }
        else if (it->substr(0, 5) == "ASCII") {
            return false;
        }
    }
    throw ReadError("Cannot read file format.");
}
