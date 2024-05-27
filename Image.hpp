#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include <opencv2/opencv.hpp>

class Image
{
private:
    cv::Mat image_matrix;
    bool PrivSetImageMatrix(std::string path);
public:
    void setImageMatrix(std::string path); // Wrapper Function
    bool IsMatrixEmpty();
    cv::Mat getImageMatrix();
    int GetWidth();
    int GetHeight();
    void displayInfo();
};

#endif