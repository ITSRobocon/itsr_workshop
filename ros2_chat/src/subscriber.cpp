#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class ChatSubscriber : public rclcpp::Node
{
public:
    ChatSubscriber()
        : Node("chat_subscriber")
    {
        subscription_ = create_subscription<std_msgs::msg::String>(
            "/chatter",
            10,
            std::bind(
                &ChatSubscriber::receive_message,
                this,
                std::placeholders::_1
            )
        );
    }

private:
    void receive_message(
        const std_msgs::msg::String::SharedPtr message
    )
    {
        RCLCPP_INFO(
            get_logger(),
            "Received: %s",
            message->data.c_str()
        );
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<ChatSubscriber>();

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}
