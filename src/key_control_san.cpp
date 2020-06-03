#include "key_controller_san/key_control_san.h"
 
#include <QApplication>
#include <QKeyEvent>
 
KeyControl::KeyControl(ros::NodeHandle _nh,QWidget *parent) :
    QWidget(parent), nh(_nh)
{
    pub = nh.advertise<hammerhead_control::MoveCmd>("/move_cmd",100);

    pub1 = nh.advertise<std_msgs::UInt8>("set_mode",10, true);

    t.data = 1;

    pub1.publish(t);
    
    ros::spinOnce();
    
    myLabel = new QLabel("LABEL");
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(myLabel);
    setLayout(mainLayout);

    a.surge_speed = 0;
    a.surge_time = 0;
    a.surge = 0;

    a.sway_speed = 0;
    a.sway_time = 0;
    a.sway = 0;
    
    a.yaw = 0;
    a.yaw_speed = 0;
    a.yaw_time = 0;
    
    a.depth = 0;
    a.depth_speed = 0;
    a.depth_time = 0;
    
    a.isAbsolute = 1;
    a.mode_after_last_cmd = 1;
    a.wait_for_max_timer_to_timeout = 1;
    ros::Rate loop_rate(15);

}
 
void KeyControl::keyPressEvent(QKeyEvent *event)
{
    t.data = 2;
    if(t.data == 0)
    pub1.publish(t);

    //hammerhead_control::MoveCmd a;
    //surge adjustment
    if(event->key() == Qt::Key_W)
    {
        a.is_surge = 1;
        a.is_depth = 0;
        a.is_sway = 0;
        a.is_yaw = 0;

        a.surge_speed = 5;
        a.surge_time = 1;
        a.surge = 5;

        a.sway_speed = 0;
        a.sway_time = 0;
        a.sway = 0;
        
        a.yaw = 0;
        a.yaw_speed = 0;
        a.yaw_time = 0;
        
        a.depth = 0;
        a.depth_speed = 0;
        a.depth_time = 0;
        
        a.isAbsolute = 0;
      
        pub.publish(a);
    }
    
    if(event->key() == Qt::Key_S)
    {

        a.is_surge = 1;
        a.is_depth = 0;
        a.is_sway = 0;
        a.is_yaw = 0;
        a.surge_speed = -5;
        a.surge_time = 1;
        a.surge = -5;

        a.sway_speed = 0;
        a.sway_time = 0;
        a.sway = 0;
        
        a.yaw = 0;
        a.yaw_speed = 0;
        a.yaw_time = 0;
        
        a.depth = 0;
        a.depth_speed = 0;
        a.depth_time = 0;
        
        a.isAbsolute = 0;
      
        pub.publish(a);
    }


    // sway adjustment
    if(event->key() == Qt::Key_D)
    {

        a.is_surge = 0;
        a.is_depth = 0;
        a.is_sway = 1;
        a.is_yaw = 0;

        a.surge_speed = 0;
        a.surge_time = 0;
        a.surge = 0;

        a.sway_speed = 5;
        a.sway_time = 1;
        a.sway = 5;
        
        a.yaw = 0;
        a.yaw_speed = 0;
        a.yaw_time = 0;
        
        a.depth = 0;
        a.depth_speed = 0;
        a.depth_time = 0;
        
        a.isAbsolute = 0;
      
        pub.publish(a);
    }
    if(event->key() == Qt::Key_A)
    {

        a.is_surge = 0;
        a.is_depth = 0;
        a.is_sway = 1;
        a.is_yaw = 0;

        a.surge_speed = 0;
        a.surge_time = 0;
        a.surge = 0;

        a.sway_speed = -5;
        a.sway_time = 1;
        a.sway = -5;
        
        a.yaw = 0;
        a.yaw_speed = 0;
        a.yaw_time = 0;
        
        a.depth = 0;
        a.depth_speed = 0;
        a.depth_time = 0;
        
        a.isAbsolute = 0;
      
        pub.publish(a);
    }

    //heave adjustmnet
    if(event->key() == Qt::Key_Z)
    {

        a.is_surge = 0;
        a.is_depth = 1;
        a.is_sway = 0;
        a.is_yaw = 0;

        a.surge_speed = 0;
        a.surge_time = 0;
        a.surge = 0;

        a.sway_speed = 0;
        a.sway_time = 0;
        a.sway = 0;
        
        a.yaw = 0;
        a.yaw_speed = 0;
        a.yaw_time = 0;
        
        a.depth = 0.1;
		a.depth_speed = 0.025;
        a.depth_time = 3;
        
        a.isAbsolute = 0;

        pub.publish(a);
	
    }
    if(event->key() == Qt::Key_Space)
    {

        a.is_surge = 0;
        a.is_depth = 1;
        a.is_sway = 0;
        a.is_yaw = 0;

		a.surge_speed = 0;
        a.surge_time = 0;
        a.surge = 0;

        a.sway_speed = 0;
        a.sway_time = 0;
        a.sway = 0;
        
        a.yaw = 0;
        a.yaw_speed = 0;
        a.yaw_time = 0;
        
        a.depth = -0.1;
        a.depth_speed = -0.025;
        a.depth_time = 3;
        
        a.isAbsolute = 0;
      
        pub.publish(a);
	
    }

 // yaw adjustment
    if(event->key() == Qt::Key_E)
    {

        a.is_surge = 0;
        a.is_depth = 0;
        a.is_sway = 0;
        a.is_yaw = 1;

		a.surge_speed = 0;
        a.surge_time = 0;
        a.surge = 0;

        a.sway_speed = 0;
        a.sway_time = 0;
        a.sway = 0;
        
        a.yaw = 0.1;
        a.yaw_speed = 0.1;
        a.yaw_time = 1;
        
        a.depth = 0;
        a.depth_speed = 0;
        a.depth_time = 0;
        
        a.isAbsolute = 0;
      
        pub.publish(a);
	
    }
    if(event->key() == Qt::Key_Q)
    {

        a.is_surge = 0;
        a.is_depth = 0;
        a.is_sway = 0;
        a.is_yaw = 1;

		a.surge_speed = 0;
        a.surge_time = 0;
        a.surge = 0;

        a.sway_speed = 0;
        a.sway_time = 0;
        a.sway = 0;
        
        a.yaw = -0.1;
        a.yaw_speed = -0.1;
        a.yaw_time = 1;
        
        a.depth = 0;
        a.depth_speed = 0;
        a.depth_time = 0;
        
        a.isAbsolute = 0;
      
        pub.publish(a);
    }

    if(event->key() == Qt::Key_H){
        t.data = 1;
        pub1.publish(t);

        //pub.publish(a);
    }

    if(event->key() == Qt::Key_J)
    {
        t.data = 0;
        pub1.publish(t);
    }

}
