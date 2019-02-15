#ifndef RAWVOLUME_H
#define RAWVOLUME_H

#include "volume.h"

class RawVolume : public VolumeData {
public:
    RawVolume(std::tuple<size_t, size_t, size_t> size,
              std::tuple<float, float, float> spacing,
              std::tuple<float, float, float> origin);

    virtual ~RawVolume() noexcept override;
    virtual void load_volume(const std::string &filename) override;
    virtual void uint8_normalised(void) override;
};

#endif // RAWVOLUME_H
