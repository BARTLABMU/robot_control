#include <string>
#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/String.h>
//--------------------------define & initial Parameters------------//
//----platform posture default------//
bool forward = false;
bool backward = false;
bool right =false;
bool left = false;
bool stop = false;
bool FR = false;
bool FL = false;
bool BR = false;
bool BL = false;
bool joint = false;
bool up45down45 = false;
bool superman = false;
bool cup = false;
bool up45down0 = false;
//----manipulator posture-----------//
int J1_angle = 0;
int J2_angle = 0;
int J3_angle = 0;
int J4_angle = 0;
int J5_angle = 0;
int J6_angle = 0;
int FR_angle = -90;
int FL_angle = -90;
int BR_angle = -90;
int BL_angle = -90;
int Max_angle = 180;
int min_angle = -180;
int j1_min = -90;
int j1_max = 90;
int j2_min = 0;
int j2_max = 100;
int j3_min = 0;
int j3_max = 170;
int j4_min = 0;
int j4_max = 20;
int j5_min = -180;
int j5_max = 180;
int j6_min = -180;
int j6_max = 180;
int step_angle = 10;
int step_joint_angle = 1;
//------------------------//
ros::Publisher tele_pub;
ros::Publisher victim_pub;
std_msgs::String sent;


void joy_callback(const sensor_msgs::JoyConstPtr& joy)
{
  //  ROS_INFO("joy_callback");

   //--------------------Forward-------------------------/
    if(joy->axes[3]==0 && joy->axes[0] == 0 && joy->axes[1]==0&&joy->axes[2] == 0&&joy->axes[4]==0&&joy->axes[5]==1 && joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0
            &&joy->buttons[3]==0&& joy->buttons[4]==0&&joy->buttons[5]==0&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        ROS_INFO("Forward");
        forward = true;             // Go forward true
        backward = false;
        left = false;
        right = false;
        stop = false;
        FL = false;
        up45down45 = false;
        up45down0 = false;
        superman = false;
        cup = false;
        joint = false;
        sent.data = "forward";
        tele_pub.publish(sent);
    }
   //--------------------Backward------------------------/
    else if(joy->axes[3]==0 && joy->axes[0] == 0 && joy->axes[1]==0&&joy->axes[2] == 0&&joy->axes[4]==0&&joy->axes[5]==-1 && joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0
            &&joy->buttons[3]==0&& joy->buttons[4]==0&&joy->buttons[5]==0&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        ROS_INFO("Backward");
        backward=true;          // go backward
        forward = false;
        left = false;
        right = false;
        stop = false;
        FL = false;
        up45down45 = false;
        up45down0 = false;
        superman = false;
        cup = false;
        joint = false;
        sent.data = "backward";
        tele_pub.publish(sent);

    }
    //-------------------Left----------------------------/
    else if(joy->axes[3]==0 && joy->axes[0] ==0 && joy->axes[1]==0&&joy->axes[2] == 0&&joy->axes[4]==1 && joy->axes[5]==0 && joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0
            &&joy->buttons[3]==0&& joy->buttons[4]==0&&joy->buttons[5]==0&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        ROS_INFO("left");
        left=true;
        forward = false;
        backward = false;
        right = false;
        stop = false;
        FL = false;
        up45down45 = false;
        up45down0 = false;
        superman = false;
        cup = false;
        joint = false;
        sent.data = "left";
        tele_pub.publish(sent);
    }
    //------------------Right----------------------------/
    else if(joy->axes[3]==0 && joy->axes[0] == 0 && joy->axes[1]==0&&joy->axes[2] == 0&&joy->axes[4]==-1 && joy->axes[5]==0 && joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0
            &&joy->buttons[3]==0&& joy->buttons[4]==0&&joy->buttons[5]==0&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        ROS_INFO("right");
        right=true;
        left = false;
        forward =false;
        backward=false;
        stop =false;
        FL = false;
        up45down45 = false;
        up45down0 = false;
        superman = false;
        cup = false;
        joint = false;
        sent.data = "right";
        tele_pub.publish(sent);
    }
    //------------------Stop-----------------------------/
    else if(joy->axes[3]==0 && joy->axes[0] == 0 && joy->axes[1]==0&&joy->axes[2] == 0&&joy->axes[4]==0 &&joy->axes[5]==0 && joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0
            &&joy->buttons[3]==0&& joy->buttons[4]==0&&joy->buttons[5]==0&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        ROS_INFO("stop");
        stop = true;
        right=false;
        left = false;
        forward =false;
        backward=false;
        FL = false;
        up45down45 = false;
        up45down0 = false;
        superman = false;
        cup = false;
        joint = false;
        sent.data = "stop";
        tele_pub.publish(sent);
        sent.data = "stop";
        tele_pub.publish(sent);
        sent.data = "stop";
        tele_pub.publish(sent);

    }
    //-----------------Sensor Read to Sensor_read Node---/
    else if(joy->axes[3]== 0 &&joy->axes[0] == 0 && joy->axes[1] == 0&&joy->axes[2] == 0&&joy->axes[4]==0 &&joy->axes[5]==0  && joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0
            &&joy->buttons[3]==0&& joy->buttons[4]==0&&joy->buttons[5]==0&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==1)
    {
        //request
        ROS_INFO("request");
        sent.data="request";
        tele_pub.publish(sent);
    }
    //-------------------FL up---------------------------/
    else if(joy->axes[3]== 0 &&joy->axes[0] == 0 && joy->axes[1] == 0&&joy->axes[2] == 0&&joy->axes[4]==0 &&joy->axes[5]!=0  && joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0
            &&joy->buttons[3]==0&& joy->buttons[4]==1&&joy->buttons[5]==0&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        if(joy->axes[5]== 1)
        {
        ROS_INFO("FL_move up");
        stop = false;
        right=false;
        left = false;
        forward =false;
        backward=false;
        FL = true;
        FR = false;
        BR = false;
        BL =false;
        up45down45 = false;
        up45down0 = false;
        superman = false;
        cup = false;
        joint = false;
            FL_angle = FL_angle +step_angle;
            sent.data = "FLup";
            tele_pub.publish(sent);
        }
        else if(joy->axes[5]==-1)
        {
            ROS_INFO("FL_move down");
            stop = false;
            right=false;
            left = false;
            forward =false;
            backward=false;
            FL = true;
            BR = false;
            BL = false;
            FR = false;
            up45down45 = false;
            up45down0 = false;
            superman = false;
            cup = false;
            joint = false;
        FL_angle = FL_angle -step_angle;
        sent.data = "FLdown";
        tele_pub.publish(sent);
        }
    }
    //-------------------FR ip---------------------------/
    else if(joy->axes[3]== 0 &&joy->axes[0] == 0 && joy->axes[1] == 0&&joy->axes[2] == 0&&joy->axes[4]==0 &&joy->axes[5]!=0  && joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0
            &&joy->buttons[3]==0&& joy->buttons[4]==0&&joy->buttons[5]==1&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        if(joy->axes[5]==1)
        {
        ROS_INFO("FR_move up");
        stop = false;
        right=false;
        left = false;
        forward =false;
        backward=false;
        FL = false;
        FR = true;
        BR = false;
        BL = false;
        up45down45 = false;
        up45down0 = false;
        superman = false;
        cup = false;
        joint = false;
        FR_angle = FR_angle +step_angle;
        sent.data = "FRup";
        tele_pub.publish(sent);
        }
        else if(joy->axes[5]==-1)
        {
            ROS_INFO("FR_move down");
            stop = false;
            right=false;
            left = false;
            forward =false;
            backward=false;
            FR = true;
            FL = false;
            BR = false;
            BL = false;
            up45down45 = false;
            up45down0 = false;
            superman = false;
            cup = false;
            joint = false;
            FR_angle = FR_angle -step_angle;
            sent.data = "FRdown";
            tele_pub.publish(sent);
        }
    }
    else if(joy->axes[3]== 0 &&joy->axes[0] == 0 && joy->axes[1] == 0&&joy->axes[2] == 0&&joy->axes[4]==0 &&joy->axes[5]!=0  && joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0
            &&joy->buttons[3]==0&& joy->buttons[4]==0&&joy->buttons[5]==0&& joy->buttons[6]==1&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        if(joy->axes[5]==1)
        {
        ROS_INFO("BL_move up");
        stop = false;
        right=false;
        left = false;
        forward =false;
        backward=false;
        FL = false;
        FR = false;
        BL =true;
        BR =false;
        up45down45 = false;
        up45down0 = false;
        superman = false;
        cup = false;
        joint = false;
        BL_angle = BL_angle +step_angle;
        sent.data = "BLup";
        tele_pub.publish(sent);
        }
        else if(joy->axes[5]==-1)
        {
            ROS_INFO("BL_move down");
            stop = false;
            right=false;
            left = false;
            forward =false;
            backward=false;
            FR = false;
            FL = false;
            BL = true;
            BR = false;
            up45down45 = false;
            up45down0 = false;
            superman = false;
            cup = false;
            joint = false;
            BL_angle = BL_angle -step_angle;
            sent.data = "BLdown";
            tele_pub.publish(sent);
        }
    }
    else if(joy->axes[3]== 0 &&joy->axes[0] == 0 && joy->axes[1] == 0&&joy->axes[2] == 0&&joy->axes[4]==0 &&joy->axes[5]!=0  && joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0
            &&joy->buttons[3]==0&& joy->buttons[4]==0&&joy->buttons[5]==0&& joy->buttons[6]==0&& joy->buttons[7]==1&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        if(joy->axes[5]==1)
        {
        ROS_INFO("BR_move up");
        stop = false;
        right=false;
        left = false;
        forward =false;
        backward=false;
        FL = false;
        FR = false;
        BL =false;
        BR = true;
        up45down45 = false;
        up45down0 = false;
        superman = false;
        cup = false;
        joint = false;
        BR_angle = BR_angle +step_angle;
        sent.data = "BRup";
        tele_pub.publish(sent);
        }
        else if(joy->axes[5]== -1)
        {
            ROS_INFO("BR_move down");
            stop = false;
            right=false;
            left = false;
            forward =false;
            backward=false;
            FR = false;
            FL = false;
            BR = true;
            BL = false;
            up45down45 = false;
            up45down0 = false;
            superman = false;
            cup = false;
            joint = false;
            BR_angle = BR_angle -step_angle;
            sent.data = "BRdown";
            tele_pub.publish(sent);
        }
    }
    else if(joy->axes[3]== 0 &&joy->axes[0] == 0 && joy->axes[1] == 0&&joy->axes[2] == 0&&joy->axes[4]==0 &&joy->axes[5]!=0  && joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0
            &&joy->buttons[3]==0&& joy->buttons[4]==1&&joy->buttons[5]==1&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        if(joy->axes[5] ==1)
        {
            ROS_INFO("FL_FR move up");
            stop = false;
            right=false;
            left = false;
            forward =false;
            backward=false;
            FL = true;
            FR = true;
            BR = false;
            BL =false;
            up45down45 = false;
            up45down0 = false;
            superman = false;
            cup = false;
            joint = false;
            FL_angle = FL_angle +step_angle;
            FR_angle = FR_angle +step_angle;
            sent.data = "FLup";
            tele_pub.publish(sent);
               ros::Duration(0.02).sleep();
            sent.data = "FRup";
            tele_pub.publish(sent);
        }
        else if(joy->axes[5]==-1)
        {
            ROS_INFO("FL_FR move down");
            stop = false;
            right=false;
            left = false;
            forward =false;
            backward=false;
            FL = true;
            FR = true;
            BR = false;
            BL =false;
            up45down45 = false;
            up45down0 = false;
            superman = false;
            cup = false;
            joint = false;
            FL_angle = FL_angle-step_angle;
             FR_angle = FR_angle -step_angle;
             sent.data = "FLdown";
             tele_pub.publish(sent);
                ros::Duration(0.02).sleep();
             sent.data = "FRdown";
             tele_pub.publish(sent);
        }
    }
    else if(joy->axes[3]== 0 &&joy->axes[0] == 0 && joy->axes[1] == 0&&joy->axes[2] == 0&&joy->axes[4]==0 &&joy->axes[5]!=0  && joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0
            &&joy->buttons[3]==0&& joy->buttons[4]==0&&joy->buttons[5]==0&& joy->buttons[6]==1&& joy->buttons[7]==1&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        if(joy->axes[5]==1)
        {
            ROS_INFO("BL_BR move up");
            stop = false;
            right=false;
            left = false;
            forward =false;
            backward=false;
            FL = false;
            FR = false;
            BR = true;
            BL =true;
            up45down45 = false;
            up45down0 = false;
            superman = false;
            cup = false;
            joint = false;
            BL_angle = BL_angle +step_angle;
            BR_angle = BR_angle +step_angle;
            sent.data = "BLup";
            tele_pub.publish(sent);
               ros::Duration(0.02).sleep();
            sent.data = "BRup";
            tele_pub.publish(sent);
        }
        else if(joy->axes[5]==-1)
        {
            ROS_INFO("BL_BR move down");
            stop = false;
            right=false;
            left = false;
            forward =false;
            backward=false;
            FL = false;
            FR = false;
            BR = true;
            BL =true;
            up45down45 = false;
            up45down0 = false;
            superman = false;
            cup = false;
            joint = false;
            BL_angle = BL_angle-step_angle;
             BR_angle = BR_angle -step_angle;
             sent.data = "BLdown";
             tele_pub.publish(sent);
                ros::Duration(0.02).sleep();
             sent.data = "BRdown";
             tele_pub.publish(sent);
        }
    }
    else if(joy->axes[3]== 0 &&joy->axes[0] == 0 && joy->axes[1] == 0&&joy->axes[2] == 0&&joy->axes[4]==0 &&joy->axes[5]!=0  && joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0
            &&joy->buttons[3]==0&& joy->buttons[4]==1&&joy->buttons[5]==1&& joy->buttons[6]==1&& joy->buttons[7]==1&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        if(joy->axes[5] ==1)
        {
            ROS_INFO("all move up");
            stop = false;
            right=false;
            left = false;
            forward =false;
            backward=false;
            FL = true;
            FR = true;
            BR = true;
            BL =true;
            up45down45 = false;
            up45down0 = false;
            superman = false;
            cup = false;
            joint = false;
            BL_angle = BL_angle +step_angle;
            BR_angle = BR_angle +step_angle;

            FL_angle = FL_angle+step_angle;
             FR_angle = FR_angle +step_angle;

             sent.data = "FLup";
             tele_pub.publish(sent);
             ros::Duration(0.02).sleep();
             sent.data = "FRup";
             tele_pub.publish(sent);
             ros::Duration(0.02).sleep();
             sent.data = "BLup";
             tele_pub.publish(sent);
             ros::Duration(0.02).sleep();
             sent.data = "BRup";
             tele_pub.publish(sent);
        }
        else if(joy->axes[5]==-1)
        {
            ROS_INFO("all move down");
            stop = false;
            right=false;
            left = false;
            forward =false;
            backward=false;
            FL = true;
            FR = true;
            BR = true;
            BL =true;
            up45down45 = false;
            up45down0 = false;
            superman = false;
            cup = false;
            joint = false;
            BL_angle = BL_angle-step_angle;
             BR_angle = BR_angle -step_angle;

             FL_angle = FL_angle-step_angle;
              FR_angle = FR_angle -step_angle;
              sent.data = "FLdown";
              tele_pub.publish(sent);
              ros::Duration(0.02).sleep();
              sent.data = "FRdown";
              tele_pub.publish(sent);
              ros::Duration(0.02).sleep();
              sent.data = "BLdown";
              tele_pub.publish(sent);
              ros::Duration(0.02).sleep();
              sent.data = "BRdown";
              tele_pub.publish(sent);

        }
    }
    else if( joy->axes[3]==0&& (joy->axes[4] != 0 || joy->axes[5]!=0 )&&joy->axes[2] == 0&&joy->axes[1]==0 &&
             joy->buttons[0]==0&& (joy->buttons[1]==1|| joy->buttons[2]==1 ||joy->buttons[3]==1)&& joy->buttons[4]==0&&joy->buttons[5]==0&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {

        stop = false;
        right=false;
        left = false;
        forward =false;
        backward=false;
        FL = false;
        FR = false;
        BR = false;
        BL =false;
        joint = true;
        up45down45 = false;
        up45down0 = false;
        superman = false;
        cup = false;

        if(joy->axes[4]>0 && joy->buttons[1]==1)
        {
            // j1 rotate left
            sent.data ="j1up";
            tele_pub.publish(sent);
            J1_angle = J1_angle + step_joint_angle;

        }
        else if(joy->axes[4]<0 && joy->buttons[1]==1)
        {
               // j1 rotate right
            sent.data ="j1down";
              tele_pub.publish(sent);
           J1_angle = J1_angle - step_joint_angle;
        }
        else if(joy->axes[5]>0 && joy->buttons[1]==1)
        {
            // j2 rotate left
            sent.data ="j2up";
            tele_pub.publish(sent);
            J2_angle = J2_angle + step_joint_angle;

        }
        else if(joy->axes[5]<0 && joy->buttons[1]==1)
        {
               // j2 rotate right
            sent.data ="j2down";
            tele_pub.publish(sent);
           J2_angle = J2_angle - step_joint_angle;
        }
        else if(joy->axes[5]>0 && joy->buttons[2]==1)
        {
            // j3 rotate left
            sent.data ="j3up";
            tele_pub.publish(sent);
            J3_angle = J3_angle + step_joint_angle;

        }
        else if(joy->axes[5]<0 && joy->buttons[2]==1)
        {
               // j3 rotate right
            sent.data ="j3down";
            tele_pub.publish(sent);
           J3_angle = J3_angle - step_joint_angle;
        }
        else if(joy->axes[4]>0 && joy->buttons[2]==1)
        {
            // j4 rotate left
            sent.data ="j4up";
            tele_pub.publish(sent);
            J4_angle = J4_angle + step_joint_angle;

        }
        else if(joy->axes[4]<0 && joy->buttons[2]==1)
        {
               // j4 rotate right
            sent.data ="j4down";
            tele_pub.publish(sent);
           J4_angle = J4_angle - step_joint_angle;
        }
        else if(joy->axes[4]>0 && joy->buttons[3]==1)
        {
            // j5 rotate left
            sent.data ="j5up";
            tele_pub.publish(sent);
            J5_angle = J5_angle + step_joint_angle;

        }
        else if(joy->axes[4]<0 && joy->buttons[3]==1)
        {
               // j5 rotate right
            sent.data ="j5down";
            tele_pub.publish(sent);
           J5_angle = J5_angle - step_joint_angle;
        }
        else if(joy->axes[5]>0 && joy->buttons[3]==1)
        {
            // j6 rotate left
            sent.data ="j6down";
            tele_pub.publish(sent);
            J6_angle = J6_angle + step_joint_angle;

        }
        else if(joy->axes[5]<0 && joy->buttons[3]==1)
        {
               // j6 rotate right
            sent.data ="j6up";
            tele_pub.publish(sent);
           J6_angle = J6_angle - step_joint_angle;
        }

    }
    else if( joy->axes[3]==0&& joy->axes[0] == 0 && joy->axes[1]==0 &&joy->axes[2] == 0&&joy->axes[4]==0 &&
             joy->buttons[0]==1&& joy->buttons[1]==0&& joy->buttons[2]==0 && joy->buttons[3]==0 && joy->buttons[4]==0&&joy->buttons[5]==0&& joy->buttons[6]==1&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        sent.data = "VL";
                victim_pub.publish(sent);
                ROS_INFO("Left victim");
    }
    else if( joy->axes[3]==0&& joy->axes[0] == 0 && joy->axes[1]==0 &&joy->axes[2] == 0&&joy->axes[4]==0 &&
             joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==1 && joy->buttons[3]==0 && joy->buttons[4]==0&&joy->buttons[5]==0&& joy->buttons[6]==1&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        ROS_INFO("Right Victim");
        sent.data ="VR";
        victim_pub.publish(sent);
    }
    else if( joy->axes[3]==0&& joy->axes[0] == 0 && joy->axes[1]==0 &&joy->axes[2] == 0&&joy->axes[4]==0 &&
             joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0 && joy->buttons[3]==1 && joy->buttons[4]==0&&joy->buttons[5]==0&& joy->buttons[6]==1&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        ROS_INFO("Center Victim");
        sent.data ="VC";
        victim_pub.publish(sent);
    }
    else if( joy->axes[3]==0&& joy->axes[0] == 0 && joy->axes[1]==0 &&joy->axes[2] == 0&&joy->axes[4]==0 &&
             joy->buttons[0]==0&& joy->buttons[1]==1&& joy->buttons[2]==0 && joy->buttons[3]==0 && joy->buttons[4]==1&&joy->buttons[5]==0&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {

        ROS_INFO("down45down0");
               //  /-----   down 45 down 0
                FL_angle = -45;
                FR_angle = -45;
                BL_angle = 0;
                BR_angle = 0;
                sent.data = "down45down0";
                tele_pub.publish(sent);

    }
    else if( joy->axes[3]==0&& joy->axes[0] == 0 && joy->axes[1]==0 &&joy->axes[2] == 0&&joy->axes[4]==0 &&
             joy->buttons[0]==1&& joy->buttons[1]==0&& joy->buttons[2]==0 && joy->buttons[3]==0 && joy->buttons[4]==1&&joy->buttons[5]==0&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {

        ROS_INFO("down45down45");
               //  /---\   down 45 down 45
                FL_angle = 45;
                FR_angle = 45;
                BL_angle = -45;
                BR_angle = -45;
                sent.data = "down45down45";
                tele_pub.publish(sent);

    }
    else if( joy->axes[3]==0&& joy->axes[0] == 0 && joy->axes[1]==0 &&joy->axes[2] == 0&&joy->axes[4]==0 &&
             joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==1 && joy->buttons[3]==0 && joy->buttons[4]==1&&joy->buttons[5]==0&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {

        ROS_INFO("up0down45");
               //  --\   up 0 down 45
                FL_angle = 0;
                FR_angle = 0;
                BL_angle = -45;
                BR_angle = -45;
                sent.data = "up0down45";
                tele_pub.publish(sent);

    }
    else if( joy->axes[3]==0&& joy->axes[0] == 0 && joy->axes[1]==0 &&joy->axes[2] == 0&&joy->axes[4]==0 &&
             joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0 && joy->buttons[3]==1 && joy->buttons[4]==1&&joy->buttons[5]==0&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {

        ROS_INFO("up0up45");
               //  ___/   up 0 up 45
                FL_angle = 0;
                FR_angle = 0;
                BL_angle = 45;
                BR_angle = 45;
                sent.data = "up0up45";
                tele_pub.publish(sent);

    }
    else if( joy->axes[3]==0&& joy->axes[0] == 0 && joy->axes[1]==0 &&joy->axes[2] == 0&&joy->axes[4]==0 &&
             joy->buttons[0]==1&& joy->buttons[1]==0&& joy->buttons[2]==0 && joy->buttons[3]==0 && joy->buttons[4]==0&&joy->buttons[5]==1&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        stop = false;
        right=false;
        left = false;
        forward =false;
        backward=false;
        FL = false;
        FR = false;
        BR = false;
        BL =false;
        joint = false;
        up45down45 = true;
        up45down0 = false;
        superman = false;
        cup = false;
        ROS_INFO("up45down45");
               //  \-\   up 45 down 45
                FL_angle = -45;
                FR_angle = -45;
                BL_angle = -45;
                BR_angle = -45;
                sent.data = "up45down45";
                tele_pub.publish(sent);

    }
    else if( joy->axes[3]==0&& joy->axes[0] == 0 && joy->axes[1]==0 &&joy->axes[2] == 0&&joy->axes[4]==0 &&
             joy->buttons[0]==0&& joy->buttons[1]==1&& joy->buttons[2]==0 && joy->buttons[3]==0 && joy->buttons[4]==0&&joy->buttons[5]==1&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        stop = false;
        right=false;
        left = false;
        forward =false;
        backward=false;
        FL = false;
        FR = false;
        BR = false;
        BL =false;
        joint = false;
        up45down45 = false;
        up45down0 = false;
        superman = true;
        cup = false;
        ROS_INFO("superman");
               //  -- - --  superman
                FL_angle = 0;
                FR_angle = 0;
                BL_angle = 0;
                BR_angle = 0;
                sent.data = "superman";
                tele_pub.publish(sent);

    }
    else if( joy->axes[3]==0&& joy->axes[0] == 0 && joy->axes[1]==0 &&joy->axes[2] == 0&&joy->axes[4]==0 &&
             joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==1 && joy->buttons[3]==0 && joy->buttons[4]==0&&joy->buttons[5]==1&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
        ROS_INFO("cup");
        stop = false;
        right=false;
        left = false;
        forward =false;
        backward=false;
        FL = false;
        FR = false;
        BR = false;
        BL =false;
        joint = false;
        up45down45 = false;
        up45down0 = false;
        superman = false;
        cup = true;
        //  \___/   cup
                FL_angle = -45;
                FR_angle = -45;
                BL_angle = 45;
                BR_angle = 45;
                sent.data = "cup";
                tele_pub.publish(sent);

    }
    else if( joy->axes[3]==0&& joy->axes[0] == 0 && joy->axes[1]==0 &&joy->axes[2] == 0&&joy->axes[4]==0 &&
             joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0 && joy->buttons[3]==1 && joy->buttons[4]==0&&joy->buttons[5]==1&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==0&& joy->buttons[9]==0)
    {
               //  \____ _   up 45 down 0
        ROS_INFO("up45donw0");
        stop = false;
        right=false;
        left = false;
        forward =false;
        backward=false;
        FL = false;
        FR = false;
        BR = false;
        BL =false;
        joint = false;
        up45down45 = false;
        up45down0 = true;
        superman = false;
        cup = false;
        FL_angle = -45;
                FR_angle = -45;
                BL_angle = 0;
                BR_angle = 0;
                sent.data = "up45down0";
                tele_pub.publish(sent);

    }
    else if( joy->axes[3]==0&& joy->axes[0] == 0 && joy->axes[1]==0 &&joy->axes[2] == 0&&joy->axes[4]==0 &&
             joy->buttons[0]==0&& joy->buttons[1]==1&& joy->buttons[2]==0 && joy->buttons[3]==0 && joy->buttons[4]==0&&joy->buttons[5]==0&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==1&& joy->buttons[9]==0)
    {
        //Manipulator reset
        stop = false;
        right=false;
        left = false;
        forward =false;
        backward=false;
        FL = false;
        FR = false;
        BR = false;
        BL =false;
        joint = true;
        up45down45 = false;
        up45down0 = false;
        superman = false;
        cup = false;
        ROS_INFO("manireset");

        J1_angle = 0;
        J2_angle = j2_min;
        J3_angle = j3_min;
        J4_angle = j4_min;
        J5_angle = 0;
        J6_angle = 0;
        sent.data = "manireset";
        tele_pub.publish(sent);

    }
    else if( joy->axes[3]==0&& joy->axes[0] == 0 && joy->axes[1]==0 &&joy->axes[2] == 0&&joy->axes[4]==0 &&
             joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0 && joy->buttons[3]==0 && joy->buttons[4]==1&&joy->buttons[5]==1&& joy->buttons[6]==1&& joy->buttons[7]==1&& joy->buttons[8]==1&& joy->buttons[9]==0)
    {
        // leg reset
        ROS_INFO("legreset");
        stop = false;
        right=false;
        left = false;
        forward =false;
        backward=false;
        FL = true;
        FR = true;
        BR = true;
        BL =true;
        joint = false;
        up45down45 = false;
        up45down0 = false;
        superman = false;
        cup = false;

        FL_angle = -90;
        FR_angle = -90;
        BL_angle = 90;
        BR_angle = 90;
        sent.data = "legreset";
        tele_pub.publish(sent);

    }
    else if( joy->axes[3]==0&& joy->axes[0] == 0 && joy->axes[1]==0 &&joy->axes[2] == 0&&joy->axes[4]==0 &&
             joy->buttons[0]==0&& joy->buttons[1]==0&& joy->buttons[2]==0 && joy->buttons[3]==0 && joy->buttons[4]==1&&joy->buttons[5]==0&& joy->buttons[6]==0&& joy->buttons[7]==0&& joy->buttons[8]==1&& joy->buttons[9]==0)
    {
        // leg reset
        ROS_INFO("camreset");


        sent.data = "legreset";
        tele_pub.publish(sent);

    }

}
int main(int argc, char** argv)

{
    ros::init(argc, argv, "robot_control");     // start robot_control node
    ros::NodeHandle n;
  //  ros::Publisher joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 100);
    victim_pub = n.advertise<std_msgs::String>("syscommand",10);    //send victim_pub to system which using name syscommand
    tele_pub = n.advertise<std_msgs::String>("teleop_control",10);
    ros::Subscriber joy_sub = n.subscribe("joy",10,joy_callback);
  //  tf::TransformBroadcaster broadcaster;
   ros::Rate loop_rate(30);
   while(ros::ok)
   {
       if(forward==true&&backward==false&&left==false&&right==false&&stop==false)
       {
           sent.data = "forward";
           tele_pub.publish(sent);
       }
       else if(forward==false&&backward==true&&left==false&&right==false&&stop==false)
       {
           sent.data = "backward";
           tele_pub.publish(sent);
       }
       else if(forward==false&&backward==false&&left==false&&right==true&&stop==false)
       {
           sent.data = "right";
           tele_pub.publish(sent);
       }
       else if(forward==false&&backward==false&&left==true&&right==false&&stop==false)
       {
           sent.data = "left";
           tele_pub.publish(sent);
       }

        ros::spinOnce();
        loop_rate.sleep();
   }




    return 0;
}
