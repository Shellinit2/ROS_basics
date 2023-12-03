set(_AMENT_PACKAGE_NAME "gazebo_simulation")
set(gazebo_simulation_VERSION "0.0.0")
set(gazebo_simulation_MAINTAINER "robotmania <robotmania@todo.todo>")
set(gazebo_simulation_BUILD_DEPENDS "gazebo_ros_pkgs" "geometry_msgs" "nav_msgs" "rclcpp" "sensor_msgs" "tf2")
set(gazebo_simulation_BUILDTOOL_DEPENDS "ament_cmake")
set(gazebo_simulation_BUILD_EXPORT_DEPENDS "gazebo_ros_pkgs" "geometry_msgs" "nav_msgs" "rclcpp" "sensor_msgs" "tf2")
set(gazebo_simulation_BUILDTOOL_EXPORT_DEPENDS )
set(gazebo_simulation_EXEC_DEPENDS "robot_description" "gazebo_ros_pkgs" "geometry_msgs" "nav_msgs" "rclcpp" "sensor_msgs" "tf2")
set(gazebo_simulation_TEST_DEPENDS )
set(gazebo_simulation_GROUP_DEPENDS )
set(gazebo_simulation_MEMBER_OF_GROUPS )
set(gazebo_simulation_DEPRECATED "")
set(gazebo_simulation_EXPORT_TAGS)
list(APPEND gazebo_simulation_EXPORT_TAGS "<build_type>ament_cmake</build_type>")
list(APPEND gazebo_simulation_EXPORT_TAGS "<gazebo_ros gazebo_model_path=\"models\"/>")