#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>

#include "rclcpp/rclcpp.hpp"
#include "opencv2/opencv.hpp"
#include "flare/msg/color.hpp"

using std::placeholders::_1;
using namespace std;
using namespace cv;

class Detection : public rclcpp::Node
{
public:
    Detection() : Node("detect")
    {
        publisher_ = this->create_publisher<flare::msg::Color>("object_found", 10);
        camsrc_ = VideoCapture(0);

        namedWindow("Edit value");
        createTrackbar("hue thresh", "values", &hue_lim, 90);
        createTrackbar("min sat", "values", &min_satur, 255);
        createTrackbar("min val", "values", &min_val, 255);
        createTrackbar("min area", "values", &min_area, 10000);
        createTrackbar("red hue", "values", &red_hue, 180);
        createTrackbar("yellow hue", "values", &yellow_hue, 180);
        createTrackbar("blue hue", "values", &blue_hue, 180);

        if (!camsrc_.isOpened())
        {
            RCLCPP_ERROR(this->get_logger(), "An error occurred while trying to capture video");
        }
        else
        {
            timer_ = this->create_wall_timer(100ms, std::bind(&Detection::topic_callback, this));
        }
    }

    ~Detection()
    {
        camsrc_.release();
        destroyAllWindows();
    }

private:
    void send_msg(cv::Moments &moment, const flare::msg::Color &color)
    {
        if (moment.m00 < min_area)
            return;

        auto message = flare::msg::Color();
        message.red = color.red;
        message.yellow = color.yellow;
        message.blue = color.blue;
        publisher_->publish(message);
    }

    void topic_callback(){

    Mat frame;
    if (!camsrc_.read(frame))
    {
        RCLCPP_ERROR(this->get_logger(), "An error occurred while trying to read frame from video source");
        return;
    }

    Mat framehsv;
    cvtColor(frame, framehsv, COLOR_BGR2HSV);
    if (framehsv.empty())
    {
        RCLCPP_ERROR(this->get_logger(), "An error occurred while trying to convert frame -> HSV");
        return;
    }

    Mat red, yellow, blue;
    inRange(framehsv, Scalar(max(0, red_hue - hue_lim), min_satur, min_val), Scalar(min(255, red_hue + hue_lim), 255, 255), red);
    inRange(framehsv, Scalar(max(0, yellow_hue - hue_lim), min_satur, min_val), Scalar(min(255, yellow_hue + hue_lim), 255, 255), yellow);
    inRange(framehsv, Scalar(max(0, blue_hue - hue_lim), min_satur, min_val), Scalar(min(255, blue_hue + hue_lim), 255, 255), blue);

    Moments red_moments = moments(red), yellow_moments = moments(yellow), blue_moments = moments(blue);

    flare::msg::Color red_color_msg, yellow_color_msg, blue_color_msg;
    red_color_msg.red = 1;
    yellow_color_msg.yellow = 1;
    blue_color_msg.blue = 1;

    this->send_msg(red_moments, red_color_msg);
    this->send_msg(yellow_moments, yellow_color_msg);
    this->send_msg(blue_moments, blue_color_msg);

    imshow("red", red);
    imshow("yellow", yellow);
    imshow("blue", blue);
    waitKey(1);
}
    rclcpp::Publisher<flare::msg::Color>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    VideoCapture camsrc_;

    int red_hue = 0, yellow_hue = 30, blue_hue = 120;
    int hue_lim = 10;
    int min_satur = 150;
    int min_val = 50;
    int min_area = 10000;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Detection>());
    rclcpp::shutdown();
    return 0;
}
