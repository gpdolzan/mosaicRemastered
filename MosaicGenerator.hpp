#ifndef MOSAICGENERATOR_HPP
#define MOSAICGENERATOR_HPP

#include <string>
#include <opencv2/opencv.hpp>
#include "TileLibrary.hpp"
#include "Image.hpp"

class MosaicGenerator
{
private:
    TileLibrary tileLibrary;
    int tileWidth;
    int tileHeight;

public:
    MosaicGenerator(TileLibrary& library, int tileWidth, int tileHeight);
    void generateMosaic(const std::string& inputImagePath, const std::string& outputImagePath);
};

#endif // MOSAICGENERATOR_HPP