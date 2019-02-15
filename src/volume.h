#ifndef VOLUME_H
#define VOLUME_H

#include <string>
#include <vector>
#include <tuple>

class Volume {
public:
    virtual ~Volume();
    virtual void load_volume(const std::string &filename) = 0;
    virtual void uint8_normalised(void) = 0;

    enum class DataType {Int8, Uint8, Int16, Uint16, Int32, Uint32, Int64, Uint64, Float, Double};

    /*!
     * \brief Pointer to the data.
     */
    unsigned char * data_ptr(void) {
        return m_data.data();
    }

    /*!
     * \brief Get a copy of the data.
     */
    std::vector<unsigned char> data(void) {
        return m_data;
    }

    /*!
     * \brief Range of the image, in intensity value.
     * \return A pair, holding <minimum, maximum>.
     */
    constexpr std::pair<double, double> range(void) const {
        return m_range;
    }

    /*!
     * \brief Range of the image, in intensity value.
     * \return A pair, holding <minimum, maximum>.
     */
    constexpr std::tuple<size_t, size_t, size_t> size(void) const {
        return _size;
    }

    /*!
     * \brief Range of the image, in intensity value.
     * \return A pair, holding <minimum, maximum>.
     */
    constexpr std::tuple<float, float, float> origin(void) const {
        return _origin;
    }

    /*!
     * \brief Range of the image, in intensity value.
     * \return A pair, holding <minimum, maximum>.
     */
    constexpr std::tuple<float, float, float> spacing(void) const {
        return _spacing;
    }

protected:
    std::tuple<size_t, size_t, size_t> _size;    /*!< Number of voxels for each axis. */
    std::tuple<float, float, float> _origin;  /*!< Origin, in voxel coordinates. */
    std::tuple<float, float, float> _spacing; /*!< Spacing between voxels. */
    DataType m_datatype;                          /*!< Data type. */
    std::pair<double, double> m_range;            /*!< (min, max) of the original intensities, before normalisation. */
    std::vector<unsigned char> m_data;            /*!< Volume data, casted to `unsigned char` and normalised to [0, 255]. */
};

#endif // VOLUME_H
