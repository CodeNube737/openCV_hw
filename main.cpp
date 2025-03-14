#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat image = cv::Mat::zeros(300, 600, CV_8UC3);
    cv::putText(image, "Hello, OpenCV!", cv::Point(50, 150), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);
    cv::imshow("Test", image);
    std::cout << "Hello World!\n"; // added to learn gitHub better
    // random comment for new branch push
    cv::waitKey(0);

    return 0;
}
