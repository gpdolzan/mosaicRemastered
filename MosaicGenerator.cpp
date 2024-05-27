#include "MosaicGenerator.hpp"
#include <iostream>

MosaicGenerator::MosaicGenerator(TileLibrary& library, int tileWidth, int tileHeight)
    : tileLibrary(library), tileWidth(tileWidth), tileHeight(tileHeight)
{
}

void MosaicGenerator::generateMosaic(const std::string& inputImagePath, const std::string& outputImagePath)
{
    // Load the input image
    cv::Mat inputImage = imread(inputImagePath, cv::IMREAD_COLOR);
    if (inputImage.empty())
    {
        std::cout << "Failed to load input image: " << inputImagePath << std::endl;
        return;
    }

    // Get the dimensions of the input image
    int inputWidth = inputImage.cols;
    int inputHeight = inputImage.rows;

    // Create an output image with the same dimensions
    cv::Mat mosaicImage(inputHeight, inputWidth, inputImage.type());

    // Process each tile-sized region of the input image
    for (int y = 0; y < inputHeight; y += tileHeight)
    {
        for (int x = 0; x < inputWidth; x += tileWidth)
        {
            // Define the region of interest (ROI) in the input image
            cv::Rect roi(x, y, cv::min(tileWidth, inputWidth - x), cv::min(tileHeight, inputHeight - y));
            cv::Mat inputTile = inputImage(roi);

            // Calculate the average color of the input tile
            cv::Scalar avgColor = mean(inputTile);

            // Find the best matching tile from the tile library
            Tile bestTile = tileLibrary.getBestMatchingTile(avgColor);

            // Resize the best matching tile to fit the current ROI
            cv::Mat bestTileImage = bestTile.getImageMatrix();
            cv::resize(bestTileImage, bestTileImage, cv::Size(roi.width, roi.height));

            // Copy the resized tile into the mosaic image
            bestTileImage.copyTo(mosaicImage(roi));
        }
    }

    // Save the mosaic image
    imwrite(outputImagePath, mosaicImage);

    std::cout << "Mosaic image saved to: " << outputImagePath << std::endl;
}