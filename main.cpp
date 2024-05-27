#include <iostream>
#include <filesystem>
#include <string>
#include "TileLibrary.hpp"
#include "MosaicGenerator.hpp"

namespace fs = std::filesystem;
using namespace std;

bool hasMosaicSubstring(const string& filename) {
    return filename.find("_mosaic_") != string::npos;
}

void generateMosaicsForDirectory(const string& dir, TileLibrary& tileLibrary, int tileSize) {
    for (const auto& entry : fs::directory_iterator(dir)) {
        if (entry.is_regular_file()) {
            string photo = entry.path().filename().string();
            if (!hasMosaicSubstring(photo)) {
                size_t dot_pos = photo.find(".");
                string mosaicName = dir + photo.substr(0, dot_pos) + "_mosaic_" + to_string(tileSize) + photo.substr(dot_pos, photo.size());

                // Create a MosaicGenerator with the TileLibrary
                MosaicGenerator mosaicGenerator(tileLibrary, tileSize, tileSize);

                // Generate the mosaic image
                mosaicGenerator.generateMosaic(dir + photo, mosaicName);
                cout << "Generated mosaic for: " << photo << endl;
            }
        }
    }
}

int main()
{
    // Create TileLibraries and add tiles from directories
    TileLibrary tileLibrary16, tileLibrary32;
    tileLibrary16.addTilesFromDirectory("D:/C++/Mosaic/16x_Tiles");
    tileLibrary32.addTilesFromDirectory("D:/C++/Mosaic/32x_Tiles");

    string dir = "D:/C++/Mosaic/images/";

    // Generate mosaics for images that do not contain "_mosaic_" in their names
    generateMosaicsForDirectory(dir, tileLibrary16, 16);
    generateMosaicsForDirectory(dir, tileLibrary32, 32);

    return 0;
}