#include <QtGui>
#include "key_controller_san/key_control_san.h"
 
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "key_controller_san");
    ros::NodeHandle nh;
    QApplication a(argc, argv);
    KeyControl w(nh);
    w.show();
    
    ros::Rate rate(15);
    while(ros::ok() && w.isVisible())
    {
        a.processEvents();
        ros::spinOnce();
        rate.sleep();
        
    }
 
    
}
