#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class CirclePublisher : public rclcpp::Node
{
public:
    CirclePublisher()
        : Node("circle_publisher")
    {
        publisher_ = create_publisher<geometry_msgs::msg::Twist>(
            "/turtle1/cmd_vel",
            10
        );

        timer_ = create_wall_timer(
            100ms,
            std::bind(&CirclePublisher::publish_velocity, this)
        );
    }

private:
    void publish_velocity()
    {
        auto message = geometry_msgs::msg::Twist();

        message.linear.x = 2.0;
        message.angular.z = 1.5;

        publisher_->publish(message);

        RCLCPP_INFO(
            get_logger(),
            "Publishing cmd_vel: linear.x=%.2f, angular.z=%.2f",
            message.linear.x,
            message.angular.z
        );
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<CirclePublisher>();

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}
