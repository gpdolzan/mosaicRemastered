#include "Image.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>

bool Image::PrivSetImageMatrix(std::string path)
{
    image_matrix = cv::imread(path, cv::IMREAD_COLOR);
    if (image_matrix.empty() == true)
    {
        std::cout << "The image: " << path << " wasn't able to be loaded!\n";
        return false;
    }

    std::cout << "The image: " << path << " was loaded successfully.\n";

    return true;
}

void Image::setImageMatrix(std::string path) // Wrapper Function
{
    if(PrivSetImageMatrix(path) == false)
    {
        std::cout << "Aborting execution!\n";
        exit(1);
    }
}

bool Image::IsMatrixEmpty()
{
    if(image_matrix.empty() == true)
        return true;
    return false;
}

cv::Mat Image::getImageMatrix()
{
    return image_matrix;
}

int Image::GetWidth()
{
    // Return the number of columns in the image matrix
    return image_matrix.cols;
}

int Image::GetHeight()
{
    // Return the number of rows in the image matrix
    return image_matrix.rows;
}

void Image::displayInfo()
{
    std::cout << "Width and Height: " << GetWidth() << "x" << GetHeight() << "\n";
}