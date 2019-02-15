/*
 * Copyright © 2018 Martino Pilia <martino.pilia@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#include "volume.h"



/*!
 * \brief Represent a VTK volume.
 *
 * This class allows to load a VTK volume from file.
 */
class VTKVolume : public VolumeData {

public:

    /*!
     * \brief Create an empty volume.
     */
    VTKVolume(void);

    /*!
     * \brief Create a volume from file.
     * \param filename File to be loaded.
     */
    VTKVolume(const std::string& filename);

    /*!
     * \brief Destructor.
     */
    virtual ~VTKVolume() override;

    /*!
     * \brief Load data from file, replacing any current data.
     * \param filename File to be loaded.
     */
    virtual void load_volume(const std::string& filename) override;

    /*!
     * \brief Cast the data to `unsigned char` and normalise it to [0, 255];
     */
    virtual void uint8_normalised(void) override;

private:
    void read_dimensions(const std::vector<std::string> &header);
    void read_origin(const std::vector<std::string> &header);
    void read_spacing(const std::vector<std::string> &header);
    void read_data_type(const std::vector<std::string> &header);
};
