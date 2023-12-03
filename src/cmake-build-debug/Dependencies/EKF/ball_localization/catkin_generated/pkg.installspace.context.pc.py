# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include;/usr/include/eigen3".split(';') if "${prefix}/include;/usr/include/eigen3" != "" else []
PROJECT_CATKIN_DEPENDS = "cmake_modules;diagnostic_msgs;diagnostic_updater;eigen_conversions;geographic_msgs;geometry_msgs;message_filters;message_runtime;nav_msgs;roscpp;sensor_msgs;std_msgs;std_srvs;tf2;tf2_geometry_msgs;tf2_ros".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lball_ekf;-lball_ekf_localization_nodelet;-lball_filter_base;-lball_filter_utilities;-lball_navsat_transform;-lball_navsat_transform_nodelet;-lros_ball_filter;-lros_ball_filter_utilities;-lball_localization_estimator;-lros_ball_localization_listener;-lball_ukf;-lball_ukf_localization_nodelet;-lyaml-cpp".split(';') if "-lball_ekf;-lball_ekf_localization_nodelet;-lball_filter_base;-lball_filter_utilities;-lball_navsat_transform;-lball_navsat_transform_nodelet;-lros_ball_filter;-lros_ball_filter_utilities;-lball_localization_estimator;-lros_ball_localization_listener;-lball_ukf;-lball_ukf_localization_nodelet;-lyaml-cpp" != "" else []
PROJECT_NAME = "ball_localization"
PROJECT_SPACE_DIR = "/usr/local"
PROJECT_VERSION = "2.7.3"
