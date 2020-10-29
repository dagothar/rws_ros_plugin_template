/*//////////////////////////////////////////////////////////////////////
 * 
 * CHANGE THIS INCLUDE ACCORDING TO HEADER FILENAME
 * 
 /////////////////////////////////////////////////////////////////////*/
#include "rws_ros_plugin_template.hpp"

#include <rws/RobWorkStudio.hpp>

/*//////////////////////////////////////////////////////////////////////
 * 
 * ADD OTHER INCLUDES HERE
 * 
 /////////////////////////////////////////////////////////////////////*/


using namespace std;
using namespace rw::models;
using namespace rw::kinematics;
using namespace rw::math;
using namespace rw::common;
using namespace rw::core;

/*//////////////////////////////////////////////////////////////////////
 * 
 * ADD OTHER NAMESPACES HERE
 * 
 /////////////////////////////////////////////////////////////////////*/


RwsRosPluginTemplate::RwsRosPluginTemplate() :
  RobWorkStudioPlugin("RwsRosPluginTemplate", QIcon(":/picon.png"))
{
  /*
   * Create ROS node handle
   */
  int argc = 0;
  char* argv[] = {""};
  ros::init(argc, argv, "rws_ros_plugin_template");
  _nh = new ros::NodeHandle("~");
  
  /*
   * Launch ROS spinner
   */
  _spinner = new ros::AsyncSpinner(1); // number of threads
  _spinner->start();
  
  /*
   * Set up publishers, subscribers & other ROS stuff.
   */
  _level_subscriber = _nh->subscribe("/level", 100, &RwsRosPluginTemplate::level_cb, this);
  _measured_publisher = _nh->advertise<std_msgs::Int32>("/measured", 100);
  
  /*
   * Create GUI instance
   */
  _ui = new Ui::PluginWidget;
  _ui->setupUi(this);
  
  /*
   * Connect widgets (e.g. buttons) to methods in the class.
   */
  connect(_ui->testButton, SIGNAL(clicked()), this, SLOT(onTestButtonClicked()));
  connect(_ui->measuredBox, SIGNAL(valueChanged(int)), this, SLOT(onMeasuredBoxValueChanged(int)));
}


RwsRosPluginTemplate::~RwsRosPluginTemplate() {
  delete _spinner;
  delete _nh;
  delete _ui;
}


void RwsRosPluginTemplate::initialize() {
}


void RwsRosPluginTemplate::open(rw::models::WorkCell* workcell) {
  /*
   * This method is called when a workcell is loaded in RWS environment.
   * Save the argument as the private property for further use.
   */
  _wc = workcell;
}


void RwsRosPluginTemplate::close() {
  /*
   * Define what happens when the workcell is closed.
   * You will likely want to clear the pointers to objects that
   * no longer exist.
   */
  _wc = nullptr;
}


void RwsRosPluginTemplate::onTestButtonClicked() {
  Log::log().info() << "Test button clicked!" << endl;
}


void RwsRosPluginTemplate::level_cb(const std_msgs::Int32::ConstPtr& msg) {
  _ui->levelLabel->setText(QString::number(msg->data));
}


void RwsRosPluginTemplate::onMeasuredBoxValueChanged(int i) {
  _measured_publisher.publish(i);
}

