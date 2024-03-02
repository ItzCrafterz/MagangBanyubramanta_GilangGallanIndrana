#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joy.hpp>
#include <controller/msg/motion.hpp>

using namespace std::chrono_literals;
using std::placeholders::_1;

class ControlNode : public rclcpp::Node
{
public:
    ControlNode(): Node("control")
    {
        publisher_ = this->create_publisher<controller::msg::Motion>("motion", 10);
        subscriber_ = this->create_subscription<sensor_msgs::msg::Joy>("joy", 10, std::bind(&ControlNode::joyCallback, this, _1));
    }

private:
    void joyCallback(const sensor_msgs::msg::Joy::SharedPtr msg) const
    {
        auto motion_msg = std::make_unique<controller::msg::Motion>();
        motion_msg->x_cmd = msg->axes[0] * 500;
        motion_msg->y_cmd = msg->axes[1] * 500;
        motion_msg->yaw = msg->axes[3] * 500;
        motion_msg->depth = msg->axes[4] * 500;

        publisher_->publish(std::move(motion_msg));
        RCLCPP_INFO(this->get_logger(), "Publishing successful.");
    }

    rclcpp::Publisher<controller::msg::Motion>::SharedPtr publisher_;
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscriber_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ControlNode>());
    rclcpp::shutdown();

    return 0;
}
