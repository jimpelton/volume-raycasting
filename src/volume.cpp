
#include "volume.h"

VolumeData::~VolumeData() noexcept { }

VolumeData::VolumeData() : VolumeData({0,0,0}, {0,0,0}, {0,0,0}) {}

VolumeData::VolumeData(std::tuple<size_t, size_t, size_t> size,
                       std::tuple<float, float, float> spacing,
                       std::tuple<float, float, float> origin)
    : _size{size}
    , _spacing{spacing}
    , _origin{origin}
{

}
