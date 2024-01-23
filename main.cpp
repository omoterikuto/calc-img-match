#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{
    cv::Mat image1 = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    cv::Mat image2 = cv::imread(argv[2], cv::IMREAD_GRAYSCALE);

    if (image1.empty() || image2.empty())
    {
        std::cout << "failed to read image" << std::endl;
        return -1;
    }

    cv::Mat diff;
    cv::absdiff(image1, image2, diff);

    int threshold = std::stoi(argv[3]);

    int matching_pixels = 0;
    for (int y = 0; y < diff.rows; y++)
    {
        for (int x = 0; x < diff.cols; x++)
        {
            int pixel_diff = diff.at<uchar>(y, x);
            if (pixel_diff <= threshold)
            {
                matching_pixels++;
            }
        }
    }

    double match_percentage = (matching_pixels * 100.0) / (image1.rows * image1.cols);

    std::cout << "Match: " << match_percentage << "%" << std::endl;

    return 0;
}
