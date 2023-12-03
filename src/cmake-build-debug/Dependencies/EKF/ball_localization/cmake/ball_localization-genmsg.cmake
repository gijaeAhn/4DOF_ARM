# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "ball_localization: 0 messages, 7 services")

set(MSG_I_FLAGS "-Igeographic_msgs:/opt/ros/noetic/share/geographic_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/noetic/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg;-Iuuid_msgs:/opt/ros/noetic/share/uuid_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(ball_localization_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/GetState.srv" NAME_WE)
add_custom_target(_ball_localization_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ball_localization" "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/GetState.srv" ""
)

get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetDatum.srv" NAME_WE)
add_custom_target(_ball_localization_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ball_localization" "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetDatum.srv" "geometry_msgs/Quaternion:geographic_msgs/GeoPoint:geographic_msgs/GeoPose"
)

get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetPose.srv" NAME_WE)
add_custom_target(_ball_localization_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ball_localization" "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetPose.srv" "geometry_msgs/PoseWithCovariance:std_msgs/Header:geometry_msgs/Pose:geometry_msgs/Quaternion:geometry_msgs/PoseWithCovarianceStamped:geometry_msgs/Point"
)

get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetUTMZone.srv" NAME_WE)
add_custom_target(_ball_localization_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ball_localization" "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetUTMZone.srv" ""
)

get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToggleFilterProcessing.srv" NAME_WE)
add_custom_target(_ball_localization_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ball_localization" "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToggleFilterProcessing.srv" ""
)

get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/FromLL.srv" NAME_WE)
add_custom_target(_ball_localization_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ball_localization" "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/FromLL.srv" "geographic_msgs/GeoPoint:geometry_msgs/Point"
)

get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToLL.srv" NAME_WE)
add_custom_target(_ball_localization_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ball_localization" "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToLL.srv" "geographic_msgs/GeoPoint:geometry_msgs/Point"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/GetState.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ball_localization
)
_generate_srv_cpp(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetDatum.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPoint.msg;/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ball_localization
)
_generate_srv_cpp(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetPose.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovarianceStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ball_localization
)
_generate_srv_cpp(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetUTMZone.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ball_localization
)
_generate_srv_cpp(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToggleFilterProcessing.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ball_localization
)
_generate_srv_cpp(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/FromLL.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ball_localization
)
_generate_srv_cpp(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToLL.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ball_localization
)

### Generating Module File
_generate_module_cpp(ball_localization
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ball_localization
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(ball_localization_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(ball_localization_generate_messages ball_localization_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/GetState.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_cpp _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetDatum.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_cpp _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetPose.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_cpp _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetUTMZone.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_cpp _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToggleFilterProcessing.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_cpp _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/FromLL.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_cpp _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToLL.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_cpp _ball_localization_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ball_localization_gencpp)
add_dependencies(ball_localization_gencpp ball_localization_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ball_localization_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/GetState.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ball_localization
)
_generate_srv_eus(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetDatum.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPoint.msg;/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ball_localization
)
_generate_srv_eus(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetPose.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovarianceStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ball_localization
)
_generate_srv_eus(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetUTMZone.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ball_localization
)
_generate_srv_eus(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToggleFilterProcessing.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ball_localization
)
_generate_srv_eus(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/FromLL.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ball_localization
)
_generate_srv_eus(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToLL.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ball_localization
)

### Generating Module File
_generate_module_eus(ball_localization
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ball_localization
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(ball_localization_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(ball_localization_generate_messages ball_localization_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/GetState.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_eus _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetDatum.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_eus _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetPose.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_eus _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetUTMZone.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_eus _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToggleFilterProcessing.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_eus _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/FromLL.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_eus _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToLL.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_eus _ball_localization_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ball_localization_geneus)
add_dependencies(ball_localization_geneus ball_localization_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ball_localization_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/GetState.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ball_localization
)
_generate_srv_lisp(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetDatum.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPoint.msg;/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ball_localization
)
_generate_srv_lisp(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetPose.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovarianceStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ball_localization
)
_generate_srv_lisp(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetUTMZone.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ball_localization
)
_generate_srv_lisp(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToggleFilterProcessing.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ball_localization
)
_generate_srv_lisp(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/FromLL.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ball_localization
)
_generate_srv_lisp(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToLL.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ball_localization
)

### Generating Module File
_generate_module_lisp(ball_localization
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ball_localization
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(ball_localization_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(ball_localization_generate_messages ball_localization_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/GetState.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_lisp _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetDatum.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_lisp _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetPose.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_lisp _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetUTMZone.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_lisp _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToggleFilterProcessing.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_lisp _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/FromLL.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_lisp _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToLL.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_lisp _ball_localization_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ball_localization_genlisp)
add_dependencies(ball_localization_genlisp ball_localization_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ball_localization_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/GetState.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ball_localization
)
_generate_srv_nodejs(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetDatum.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPoint.msg;/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ball_localization
)
_generate_srv_nodejs(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetPose.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovarianceStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ball_localization
)
_generate_srv_nodejs(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetUTMZone.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ball_localization
)
_generate_srv_nodejs(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToggleFilterProcessing.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ball_localization
)
_generate_srv_nodejs(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/FromLL.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ball_localization
)
_generate_srv_nodejs(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToLL.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ball_localization
)

### Generating Module File
_generate_module_nodejs(ball_localization
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ball_localization
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(ball_localization_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(ball_localization_generate_messages ball_localization_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/GetState.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_nodejs _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetDatum.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_nodejs _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetPose.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_nodejs _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetUTMZone.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_nodejs _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToggleFilterProcessing.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_nodejs _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/FromLL.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_nodejs _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToLL.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_nodejs _ball_localization_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ball_localization_gennodejs)
add_dependencies(ball_localization_gennodejs ball_localization_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ball_localization_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/GetState.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ball_localization
)
_generate_srv_py(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetDatum.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPoint.msg;/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ball_localization
)
_generate_srv_py(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetPose.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovarianceStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ball_localization
)
_generate_srv_py(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetUTMZone.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ball_localization
)
_generate_srv_py(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToggleFilterProcessing.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ball_localization
)
_generate_srv_py(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/FromLL.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ball_localization
)
_generate_srv_py(ball_localization
  "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToLL.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geographic_msgs/cmake/../msg/GeoPoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ball_localization
)

### Generating Module File
_generate_module_py(ball_localization
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ball_localization
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(ball_localization_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(ball_localization_generate_messages ball_localization_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/GetState.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_py _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetDatum.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_py _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetPose.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_py _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/SetUTMZone.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_py _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToggleFilterProcessing.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_py _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/FromLL.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_py _ball_localization_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/sj/Desktop/4DOF_ARM/src/Dependencies/EKF/ball_localization/srv/ToLL.srv" NAME_WE)
add_dependencies(ball_localization_generate_messages_py _ball_localization_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ball_localization_genpy)
add_dependencies(ball_localization_genpy ball_localization_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ball_localization_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ball_localization)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ball_localization
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geographic_msgs_generate_messages_cpp)
  add_dependencies(ball_localization_generate_messages_cpp geographic_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(ball_localization_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(ball_localization_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ball_localization)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ball_localization
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET geographic_msgs_generate_messages_eus)
  add_dependencies(ball_localization_generate_messages_eus geographic_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(ball_localization_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(ball_localization_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ball_localization)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ball_localization
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geographic_msgs_generate_messages_lisp)
  add_dependencies(ball_localization_generate_messages_lisp geographic_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(ball_localization_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(ball_localization_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ball_localization)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ball_localization
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET geographic_msgs_generate_messages_nodejs)
  add_dependencies(ball_localization_generate_messages_nodejs geographic_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(ball_localization_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(ball_localization_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ball_localization)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ball_localization\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ball_localization
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geographic_msgs_generate_messages_py)
  add_dependencies(ball_localization_generate_messages_py geographic_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(ball_localization_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(ball_localization_generate_messages_py std_msgs_generate_messages_py)
endif()
