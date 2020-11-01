RobWorkStudio ROS plugin template
=============================

1. Introduction
---------------
This is a sample RWS plugin that uses ROS build system.
The example plugin features:
* listening to a /level [std_msgs/Int32] topic and updating a label in GUI,
* publishing values from a SpinBox widget to a /measured [std_msgs/Int32] topic.

You can extend the plugin as desired. 

2. Installation
---------------

After installing the RobWork suite, you need to set the environment variables
pointing to the RobWork modules root directories. Add the following lines to your
.bashrc:

    export RW_ROOT=${HOME}/robwork/RobWork
    export RWS_ROOT=${HOME}/robwork/RobWorkStudio
    export RWSIM_ROOT=${HOME}/robwork/RobWorkSim

(Change the path as required.)

Place the package in your catkin workspace /src subdirectory.
It is recommended to just soft link it:

    cd <catkin workspace>/src
    ln -s <path to the package>

3. Building
-----------

    cd <catkin workspace>
    catkin build rws_ros_plugin_template

or

    catkin_make rws_ros_plugin_template

4. Using
--------

Make sure that roscore is running.

    roscore

You can add the plugin using Plugins -> Load plugin menu action.
The better way is to add an entry to your '[Plugins]' section of the RobWorkStudio.ini file as below:

    RWSROSPluginTemplate\DockArea=2
    RWSROSPluginTemplate\Filename=librws_ros_plugin_template.so
    RWSROSPluginTemplate\Path=<plugin path>/libs
    RWSROSPluginTemplate\Visible=true

Change the RWSPluginTemplate in the snippet above to an unique name!

If you should like to have a specific workcell loaded whenever you launch RobWorkStudio,
add the following section to your RobWorkStudio.ini file:

    [Settings]
    Workcell\Path=<workcell path>/scene.wc.xml
