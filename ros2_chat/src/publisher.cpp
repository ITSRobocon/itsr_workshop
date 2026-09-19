#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class ChatPublisher : public rclcpp::Node
{
public:
    ChatPublisher()
        : Node("chat_publisher")
    {
        publisher_ = create_publisher<std_msgs::msg::String>(
            "/chatter",
            10
        );

        timer_ = create_wall_timer(
            1s,
            std::bind(&ChatPublisher::publish_message, this)
        );
    }

private:
    void publish_message()
    {
        auto message = std_msgs::msg::String();
        message.data = "Hello ROS2!";

        publisher_->publish(message);

        RCLCPP_INFO(
            get_logger(),
            "Publishing: %s",
            message.data.c_str()
        );
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<ChatPublisher>();

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}
