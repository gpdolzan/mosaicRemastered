#include "Tile.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>

void Tile::calculateAvgColor()
{
    if (IsMatrixEmpty() == true)
    {
        std::cout << "Image is empty, can't calculate average.\n";
        return;
    }

    avgColor = cv::mean(getImageMatrix());
}

void Tile::setImageMatrix(std::string path)
{
    Image::setImageMatrix(path);
    calculateAvgColor();
}

cv::Scalar Tile::getAvgColor()
{
    return avgColor;
}

void Tile::displayInfo()
{
    Image::displayInfo();
    std::cout << "Average Color: " << "B: " << avgColor[0] << ", "
    << "G: " << avgColor[1] << ", "
    << "R: " << avgColor[2] << std::endl;
}