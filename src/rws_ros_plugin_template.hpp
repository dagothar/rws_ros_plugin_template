#pragma once

#include <rws/RobWorkStudioPlugin.hpp>
#include "ui_rws_ros_plugin_template.h"
#include <rw/models/WorkCell.hpp>
#include <rw/models/Device.hpp>
#include <rw/kinematics/Frame.hpp>
#include <ros/ros.h>
#include <std_msgs/Int32.h>

/*//////////////////////////////////////////////////////////////////////
 * 
 * ADD OTHER INCLUDES HERE
 * 
 /////////////////////////////////////////////////////////////////////*/

/*//////////////////////////////////////////////////////////////////////
 * 
 * Define plugin class.
 * CHANGE CLASS NAME, CTOR AND DTOR NAMES AS REQUIRED
 * 
 /////////////////////////////////////////////////////////////////////*/
class RwsRosPluginTemplate:
  public rws::RobWorkStudioPlugin
{
    
Q_OBJECT
Q_PLUGIN_METADATA(IID "dk.sdu.mip.Robwork.RobWorkStudioPlugin/0.1" FILE "plugin.json")
Q_INTERFACES(rws::RobWorkStudioPlugin)

public:
  RwsRosPluginTemplate();
  
  virtual ~RwsRosPluginTemplate();
  
  // Called when the plugin is loaded in RWS
  virtual void initialize() override;

  // Called when a workcell is opened in RWS
  virtual void open(rw::models::WorkCell* workcell) override;

  // Called when a workcell is closed in RWS
  virtual void close() override;
  
  /*////////////////////////////////////////////////////////////////////
   * 
   * DEFINE YOUR PUBLIC METHODS HERE
   * 
   ///////////////////////////////////////////////////////////////////*/
  
  /*
   * Example: listens to a '/level' topic of std_msgs::Int32 type and updates a Label.
   */
  void level_cb(const std_msgs::Int32::ConstPtr& msg);

// Define methods for Qt GUI callbacks below
private slots:
  void onTestButtonClicked();
  
  // Example: publishes value from QSpinBox to a '/measured' topic.
  void onMeasuredBoxValueChanged(int i);

private:
  // Stores a pointer to the GUI
  Ui::PluginWidget* _ui;
  
  // Stores ROS node handle
  ros::NodeHandle* _nh;
  
  // Stores ROS spinner thread
  ros::AsyncSpinner* _spinner;
  
  // Stores the pointer to the currently loaded workcell
  rw::models::WorkCell* _wc;
  
  /*////////////////////////////////////////////////////////////////////
   * 
   * DEFINE YOUR PRIVATE PROPERTIES HERE
   * 
   ///////////////////////////////////////////////////////////////////*/
   
   // Example: ROS subscriber
   ros::Subscriber _level_subscriber;
   
   // Example: ROS publisher
   ros::Publisher _measured_publisher;
};
