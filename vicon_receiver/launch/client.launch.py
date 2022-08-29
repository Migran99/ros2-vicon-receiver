from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument('hostname', default_value='192.168.2.221:801'),
        DeclareLaunchArgument('buffer_size', default_value=4096),
        DeclareLaunchArgument('namespace', default_value='vicon'),
        Node(
            package='vicon_receiver', executable='vicon_client', output='screen',
            parameters=[{
            'hostname': LaunchConfiguration('hostname'),
            'buffer_size': LaunchConfiguration('buffer_size'), 
            'namespace': LaunchConfiguration('namespace')
            }]
        )])
