#include "vicon_receiver/publisher.hpp"

Publisher::Publisher(std::string topic_name, rclcpp::Node* node, bool publish_odom)
{
    position_publisher_ = node->create_publisher<vicon_receiver::msg::Position>(topic_name, 10);
    odom_publisher_ = node->create_publisher<nav_msgs::msg::Odometry>("odom/"+topic_name,10);
    _pub_odom = publish_odom;
    is_ready = true;
}

void Publisher::publish(PositionStruct p)
{
    auto msg = std::make_shared<vicon_receiver::msg::Position>();
    msg->x_trans = p.translation[0];
    msg->y_trans = p.translation[1];
    msg->z_trans = p.translation[2];
    msg->x_rot = p.rotation[0];
    msg->y_rot = p.rotation[1];
    msg->z_rot = p.rotation[2];
    msg->w = p.rotation[3];
    msg->subject_name = p.subject_name;
    msg->segment_name = p.segment_name;
    msg->frame_number = p.frame_number;
    msg->translation_type = p.translation_type;
    position_publisher_->publish(*msg);

    if(_pub_odom)
    {
        nav_msgs::msg::Odometry odom_msg;

        //uto timestamp = rclcpp::Node->now();
        //odom_msg.header.stamp = timestamp;
        odom_msg.header.frame_id = "odom";
        //odom_msg.header.seq = msg->frame_number;
        odom_msg.child_frame_id = msg->segment_name;

        odom_msg.pose.pose.orientation.w = msg->w;
        odom_msg.pose.pose.orientation.x = msg->x_rot;
        odom_msg.pose.pose.orientation.y = msg->y_rot;
        odom_msg.pose.pose.orientation.z = msg->z_rot;

        odom_msg.pose.pose.position.x = msg->x_trans;
        odom_msg.pose.pose.position.y = msg->x_trans;
        odom_msg.pose.pose.position.z = msg->x_trans;

        odom_publisher_->publish(odom_msg);
    }
}
