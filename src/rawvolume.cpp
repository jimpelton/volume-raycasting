#include "rawvolume.h"

#include <fstream>

RawVolume::~RawVolume() {

}

void RawVolume::load_volume(const std::string &filename) {
    std::ifstream rawFile(filename, std::ios::binary);
    if (!rawFile.is_open()){
        throw RawFileReadError("Cannot open file.");
    }

    std::vector<char> rawFile;



}

void RawVolume::uint8_normalised(void) {

}
