from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument('hostname', default_value='192.168.2.221:801'),
        DeclareLaunchArgument('buffer_size', default_value='4096'),
        DeclareLaunchArgument('namespace', default_value='vicon'),
        DeclareLaunchArgument('remap', default_value='vicon'),
        DeclareLaunchArgument('scale', default_value='1000.0'),
        Node(
            package='vicon_receiver', executable='vicon_client', output='screen',
            parameters=[{
            'hostname': LaunchConfiguration('hostname'),
            'buffer_size': LaunchConfiguration('buffer_size'), 
            'namespace': LaunchConfiguration('namespace'),
            'scale': LaunchConfiguration('scale'),
            }],
            #remappings=[('/vicon/cf_upm/cf_upm/pose',LaunchConfiguration('remap'))]
        )])
