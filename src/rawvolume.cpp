#include "rawvolume.h"
#include "readerror.h"

#include <fstream>
#include <algorithm>

RawVolume::RawVolume(std::tuple<size_t, size_t, size_t> size,
                     std::tuple<float, float, float> spacing,
                     std::tuple<float, float, float> origin)
    : VolumeData(size, spacing, origin)
{ }

RawVolume::~RawVolume() noexcept {

}

void RawVolume::load_volume(const std::string &filename) {
    std::ifstream rawFile(filename, std::ios::binary);
    if (!rawFile.is_open()){
        throw ReadError("Cannot open file.");
    }
    std::vector<unsigned char> rawData(std::istreambuf_iterator<char>{rawFile},  {});

    auto min_max = std::minmax_element(rawData.begin(), rawData.end());
    _range = std::make_pair(
                static_cast<double>((*min_max.first)),
                static_cast<double>((*min_max.second)));
    _data = rawData;
    _datatype = DataType::Uint8;
}

void RawVolume::uint8_normalised(void) {

}
