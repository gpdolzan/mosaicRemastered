#include "TileLibrary.hpp"

namespace fs = std::filesystem;

void TileLibrary::addTile(std::string path)
{
    Tile tile;
    tile.setImageMatrix(path);
    tiles.push_back(tile);
}

void TileLibrary::addTilesFromDirectory(std::string directory)
{
    for (auto& entry : fs::directory_iterator(directory))
    {
        if (entry.is_regular_file())
        {
            addTile(entry.path().string());
        }
    }
}

Tile TileLibrary::getBestMatchingTile(cv::Scalar& color)
{
    if (tiles.empty())
    {
        std::cout << "Tile library is empty." << std::endl;
        return Tile();
    }

    Tile bestTile = tiles[0];
    double bestDistance = norm(bestTile.getAvgColor() - color);

    for (auto& tile : tiles)
    {
        double distance = norm(tile.getAvgColor() - color);
        if (distance < bestDistance)
        {
            bestDistance = distance;
            bestTile = tile;
        }
    }

    return bestTile;
}

void TileLibrary::displayLibraryInfo()
{
    std::cout << "Tile Library Info:" << std::endl;
    std::cout << "Number of tiles: " << tiles.size() << std::endl;
    system("pause");
}