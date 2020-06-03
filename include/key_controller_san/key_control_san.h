#ifndef KEY_CONTROL_SAN_H
#define KEY_CONTROL_SAN_H
 
#include <QWidget>
#include <QtGui>
#include <fstream>
#include <iostream>

#include <hammerhead/hammerhead.h>
#include <hammerhead_control/MoveCmd.h>
#include <hammerhead_control/MoveCmds.h>

#include <ros/ros.h>
#include <ros/package.h>
#include <std_msgs/Int16.h>
#include<std_msgs/UInt8.h>

 
class KeyControl : public QWidget
{
    Q_OBJECT
public:
   explicit KeyControl(ros::NodeHandle _nh,QWidget *parent = 0);
   void publish_sp(void);
protected:
    void keyPressEvent(QKeyEvent *);
    
private:
    QLabel *myLabel;
    QVBoxLayout *mainLayout;
    ros::NodeHandle nh;
    hammerhead_control::MoveCmd spMsg;
    ros::Publisher pub,pub1;
    int count;
    std_msgs::UInt8 t;
hammerhead_control::MoveCmd a;
};
 
#endif // KEY_CONTROL_SAN_H
