#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <tuple>
#include <numeric>
#include <cstring>
#include <fstream>

bool is_little_endian();

bool is_binary(const std::vector<std::string> &header);

/*!
 * \brief Invert the endianness of the input value.
 * \param p Pointer to the first byte of an input value of size `N`.
 */
template<size_t N>
void swap_byte_order(unsigned char* p)
{
    unsigned char tmp;
    for (size_t i = 0; i < N / 2; ++i) {
        tmp = p[i];
        p[i] = p[N-i-1];
        p[N-i-1] = tmp;
    }
}

/**
 * \brief Read VTK data from file.
 * \param file Stream from the open file.
 * \param image_data Array of `unisgned char` to store the resulting data of type `T`.
 * \param binary Whether the VTK file is binary.
 * \param element_count Number of elements to read.
 * \return The range of the read data.
 */
template<typename T>
void read_data(std::ifstream& file, const bool binary, const size_t element_count, std::vector<unsigned char>& image_data, std::pair<double, double>& range) {

    std::vector<T> data;
    data.resize(element_count);

    if (binary) {
        file.read(reinterpret_cast<char*>(data.data()), static_cast<std::streamsize>(sizeof (T) * element_count));
        if (is_little_endian() && sizeof (T) > 1) {
            for (size_t i = 0; i < element_count; ++i) {
                swap_byte_order<sizeof (T)>(reinterpret_cast<unsigned char*>(data.data() + i));
            }
        }
    }
    else {
        T voxel;
        for (size_t i = 0; i < element_count; ++i) {
            file >> voxel;
            data.push_back(voxel);
        }
    }

    // Find range
    range = {std::numeric_limits<double>::max(), std::numeric_limits<double>::min()};
    for (size_t i = 0; i < element_count; ++i) {
        if (data[i] > range.second) {
            range.second = data[i];
        }
        if (data[i] < range.first) {
            range.first = data[i];
        }
    }

    size_t size = data.size() * sizeof (data[0]);
    image_data.clear();
    image_data.resize(size);
    std::memcpy(image_data.data(), reinterpret_cast<char*>(data.data()), size);
}


/*!
 * \brief Cast the data to `unsigned char`, and normalise its range to [0,255].
 * \param data Input data of type `T`.
 * \param range Range of the input data.
 * \param normal_data Array to store the resulting normalised data.
 * \param element_count Number of input elements.
 */
template<typename T>
void cast_and_normalise(std::vector<unsigned char>& data, const std::pair<double, double>& range, std::vector<unsigned char>& normal_data, const size_t element_count) {
    auto *p = reinterpret_cast<T*>(data.data());

    // Normalise and cast
    normal_data.clear();
    normal_data.resize(element_count);
    for (size_t i = 0; i < element_count; ++i) {
        normal_data[i] = static_cast<unsigned char>(255 * (static_cast<double>(p[i]) - range.first) / (range.second - range.first));
    }
}





#endif // NORMALISE_H
