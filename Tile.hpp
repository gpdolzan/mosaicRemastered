#ifndef TILE_HPP
#define TILE_HPP

#include "Image.hpp"

class Tile: private Image
{
private:
    cv::Scalar avgColor;
    void calculateAvgColor();
public:
    void setImageMatrix(std::string path);
    using Image::getImageMatrix;
    cv::Scalar getAvgColor();
    void displayInfo();
};


#endif