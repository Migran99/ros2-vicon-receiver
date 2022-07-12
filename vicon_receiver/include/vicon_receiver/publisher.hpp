#ifndef PUBLISHER_HPP
#define PUBLISHER_HPP
#include <unistd.h>
#include "rclcpp/rclcpp.hpp"
#include "vicon_receiver/msg/position.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/twist_stamped.hpp"

// Struct used to hold segment data to transmit to the Publisher class.
struct PositionStruct
{
    double translation[3];
    double rotation[4];
    std::string subject_name;
    std::string segment_name;
    std::string translation_type;
    unsigned int frame_number;

} typedef PositionStruct;


// Class that allows segment data to be published in a ROS2 topic.
class Publisher
{
private:
    rclcpp::Publisher<vicon_receiver::msg::Position>::SharedPtr position_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pose_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr twist_publisher_; // NOT USED: The VICON does not get twist info

    bool _pub_pose_twist;
    rclcpp::Node::SharedPtr _node;

public:
    bool is_ready = false;

    Publisher(std::string topic_name, rclcpp::Node::SharedPtr node);

    // Publishes the given position in the ROS2 topic whose name is indicated in
    // the constructor.
    void publish(PositionStruct p);
};

#endif