#ifndef TILELIBRARY_HPP
#define TILELIBRARY_HPP

#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <algorithm>
#include <filesystem>
#include "Tile.hpp"

class TileLibrary
{
private:
    std::vector<Tile> tiles;
public:
    void addTile(std::string path);
    void addTilesFromDirectory(std::string directory);
    Tile getBestMatchingTile(cv::Scalar& color);
    void displayLibraryInfo();
};

#endif
