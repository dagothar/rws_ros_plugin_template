cmake_minimum_required(VERSION 3.0.2)
project(rws_ros_plugin_template)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)
SET(RW_ROOT "$ENV{RW_ROOT}")
SET(RWS_ROOT "$ENV{RWS_ROOT}")
SET(RWSIM_ROOT "$ENV{RWSIM_ROOT}")
SET(RobWork_DIR ${RW_ROOT}/cmake)
SET(RobWorkStudio_DIR ${RWS_ROOT}/cmake)
#SET(RobWorkSim_DIR ${RWSIM_ROOT}/cmake)
SET(CMAKE_BUILD_TYPE Release)
FIND_PACKAGE(RobWork REQUIRED)
FIND_PACKAGE(RobWorkStudio REQUIRED)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a exec_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a exec_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES rws_ros_plugin_template
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${ROBWORK_INCLUDE_DIRS}
	${ROBWORKSTUDIO_INCLUDE_DIRS}
	# ${ROBWORKSIM_INCLUDE_DIRS}
)

LINK_DIRECTORIES(
	${ROBWORK_LIBRARY_DIRS}
	${ROBWORKSTUDIO_LIBRARY_DIRS}
	# ${ROBWORKSIM_LIBRARY_DIRS}
)

## Add cmake target dependencies of the library
# UI files
SET(
  UisFiles
  src/rws_ros_plugin_template.ui
)

# HPP files
SET(
  MocHeaders
  src/rws_ros_plugin_template.hpp
) 

# CPP files        
SET(
  SrcFiles
  src/rws_ros_plugin_template.cpp
) 

########################################################################
#
# Wrap MOC headers & resources
#
########################################################################
SET(MocSrcFiles)
QT5_WRAP_CPP(MocSrcFiles ${MocHeaders})
SET(RccSrcFiles)
QT5_ADD_RESOURCES(
  RccSrcFiles
  src/resources.qrc
)
QT5_WRAP_UI(UiHeaders ${UisFiles})

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

########################################################################
#
# Add targets
# CHANGE TARGET NAME. THIS WILL BECOME THE LIBRARY NAME ACCORDING
# TO THE FOLLOWING FORMAT: lib<target name>.so
# ADD LIBRARIES AS REQUIRED.
# UNCOMMMENT RobWorkSim IF REQUIRED.
#
########################################################################
add_library(rws_ros_plugin_template MODULE ${SrcFiles} ${MocSrcFiles} ${RccSrcFiles} ${UiHeaders})
target_link_libraries(rws_ros_plugin_template -lGL -lGLU -lglut -lm
  ${ROBWORKSTUDIO_LIBRARIES}
  ${ROBWORK_LIBRARIES}
  #${ROBWORKSIM_LIBRARIES}
  ${catkin_LIBRARIES}
)

