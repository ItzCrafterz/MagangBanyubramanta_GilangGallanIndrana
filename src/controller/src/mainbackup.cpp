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

int red_hue = 0;
int yellow_hue = 30;
int blue_hue = 120;
int hue_lim = 20;
int min_satur = 50;
int min_val = 50;

void onTrackbar(int, void*)
{
}

class Detection : public rclcpp::Node
{
public:
  Detection() : Node("detect")
  { 
    publisher_ = this->create_publisher<flare::msg::Color>("detected", 10);
    camsrc_ = VideoCapture(0);

    if (!camsrc_.isOpened())
    {
      RCLCPP_ERROR(this->get_logger(), "Error while trying to capture video");
    }
    else
    {
      timer_ = this->create_wall_timer(500ms, std::bind(&Detection::topic_callback, this));
    }

    namedWindow("Color Thresholds", WINDOW_NORMAL);
    createTrackbar("Low H", "Color Thresholds", &red_hue, 179, onTrackbar);
    createTrackbar("High H", "Color Thresholds", &yellow_hue, 179, onTrackbar);
    createTrackbar("Low S", "Color Thresholds", &blue_hue, 179, onTrackbar);
    createTrackbar("High S", "Color Thresholds", &hue_lim, 179, onTrackbar);
    createTrackbar("Low V", "Color Thresholds", &min_satur, 255, onTrackbar);
    createTrackbar("High V", "Color Thresholds", &min_val, 255, onTrackbar);
  }
  
  ~Detection() {
    camsrc_.release();
    destroyAllWindows();
  }

private:
  void topic_callback() {

    Mat frame;
    
    if (!camsrc_.read(frame)) {
      RCLCPP_ERROR(this->get_logger(), "Error while trying to read frame from video source");
      return;
    }
    imshow("Frame", frame);
    waitKey(1);

    Mat framehsv; 
    cvtColor(frame, framehsv, COLOR_BGR2HSV); 
    if (framehsv.empty()) {
      RCLCPP_ERROR(this->get_logger(), "An error occurred while trying to convert frame -> HSV");
      return;
    }
    
    imshow("HSV Frame", framehsv);
    waitKey(1);

    Mat red, yellow, blue;
    inRange(framehsv, Scalar(max(0, red_hue - hue_lim), min_satur, min_val), Scalar(min(255, red_hue + hue_lim), 255, 255), red);
    inRange(framehsv, Scalar(max(0, yellow_hue - hue_lim), min_satur, min_val), Scalar(min(255, yellow_hue + hue_lim), 255, 255), yellow);
    inRange(framehsv, Scalar(max(0, blue_hue - hue_lim), min_satur, min_val), Scalar(min(255, blue_hue + hue_lim), 255, 255), blue);

    auto message = flare::msg::Color();
    message.red = countNonZero(red) > 0;
    message.yellow = countNonZero(yellow) > 0;
    message.blue = countNonZero(blue) > 0;
    publisher_->publish(message);
  }

  rclcpp::Publisher<flare::msg::Color>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  VideoCapture camsrc_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Detection>());
  rclcpp::shutdown();
  return 0;
}