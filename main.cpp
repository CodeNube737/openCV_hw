#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Define GUI size using cv::Size
    cv::Size guiSize(600, 300);
    int width = guiSize.width;
    int height = guiSize.height;

    // Create a blank image with dynamic size
    cv::Mat image = cv::Mat::zeros(guiSize, CV_8UC3);

    // Draw "Hello, OpenCV!" text
    cv::putText(image, "Hello, OpenCV!", cv::Point(width / 4, height / 2),
                cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);

    // Define the margin from the edges for the shapes
    int margin = 20;

    // Draw a circle in the top-left corner
    cv::circle(image, cv::Point(margin + 50, margin + 50), 50, cv::Scalar(255, 0, 0), -1);

    // Draw a square in the top-right corner
    cv::rectangle(image, cv::Point(width - margin - 100, margin),
                  cv::Point(width - margin, margin + 100), cv::Scalar(0, 255, 255), -1);

    // Draw a triangle in the bottom-left corner
    std::vector<cv::Point> trianglePoints = {
        cv::Point(margin + 50, height - margin),
        cv::Point(margin, height - margin - 100),
        cv::Point(margin + 100, height - margin - 100)
    };
    cv::polylines(image, trianglePoints, true, cv::Scalar(0, 255, 0), 2);
    cv::fillPoly(image, std::vector<std::vector<cv::Point>>{trianglePoints}, cv::Scalar(0, 255, 0));

    // Draw a curvy line in the bottom-right corner
    std::vector<cv::Point> curvePoints = {
        cv::Point(width - margin - 120, height - margin - 30),
        cv::Point(width - margin - 80, height - margin - 90),
        cv::Point(width - margin - 40, height - margin - 30)
    };
    cv::polylines(image, curvePoints, false, cv::Scalar(255, 0, 255), 2);

    // Display the image
    cv::imshow("GUI with Shapes", image);
    cv::waitKey(0);

    return 0;
}
