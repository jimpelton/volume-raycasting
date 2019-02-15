#ifndef RAWVOLUME_H
#define RAWVOLUME_H

#include "volume.h"

class RawFileReadError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class RawVolume : public VolumeData {
    virtual ~RawVolume() noexcept override;
    virtual void load_volume(const std::string &filename) override;
    virtual void uint8_normalised(void) override;
};

#endif // RAWVOLUME_H
