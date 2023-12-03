#include "task.h"

int front_left_pwm, front_right_pwm, back_left_pwm, back_right_pwm, left_state, right_state;
ros::NodeHandle nh;
void pwm_command(const haruto_msgs::PWM& data);
bool state=false;

ros::Subscriber<haruto_msgs::PWM> pwm_sub("/diff_pwm", &pwm_command);

Task::Task()
{
 Serial.begin(9600);
 pinMode(Sleep1,OUTPUT);
 pinMode(Dir1,OUTPUT);
 pinMode(pwm1,OUTPUT);
 pinMode(pwm2,OUTPUT);
 pinMode(Dir2,OUTPUT);
 pinMode(Sleep2,OUTPUT);
 
 pinMode(Sleep3,OUTPUT);
 pinMode(Dir3,OUTPUT);
 pinMode(pwm3,OUTPUT);
 pinMode(pwm4,OUTPUT);
 pinMode(Dir4,OUTPUT);
 pinMode(Sleep4,OUTPUT);

  nh.initNode();  
  nh.subscribe(pwm_sub);
}

void Task::execute_command()
{
  if(state)
  {
    analogWrite(pwm1, front_left_pwm);
    analogWrite(pwm2, front_right_pwm);
    analogWrite(pwm3, back_left_pwm);
    analogWrite(pwm4, back_right_pwm);
  
    if(left_state1 == 1)
    {
      nh.loginfo("left wheels1 moving in forward direction");         
      digitalWrite(Sleep1, LOW);
      digitalWrite(Dir1, LOW);
    }
    else if(left_state1 == 2)
    {
      nh.loginfo("left wheels1 moving in backward direction");
      digitalWrite(Sleep1, LOW);
      digitalWrite(Dir1, HIGH);
    }
    else
    {
      nh.loginfo("left wheels1 brake applied");
      digitalWrite(Sleep1, HIGH);}
    
    if(left_state2 == 1)
    {
      nh.loginfo("left wheels2 moving in forward direction");         
      digitalWrite(Sleep2, LOW);
      digitalWrite(Dir2, LOW);
    }
    else if(left_state2 == 2)
    {
      nh.loginfo("left wheels2 moving in backward direction");         
      digitalWrite(Sleep2, LOW);
      digitalWrite(Dir2, HIGH); 
    }
    else
    {
      nh.loginfo("left wheels2 brake applied");
      digitalWrite(Sleep2, HIGH);}
    }  
    
    if(right_state1 == 1)
    {
      nh.loginfo("right wheels1 moving in forward direction");         
      digitalWrite(Sleep3, LOW);
      digitalWrite(Dir3, LOW);
    }
    else if(right_state1 == 2)
    {
      nh.loginfo("right wheels1 moving in backward direction");
      digitalWrite(Sleep3, LOW);
      digitalWrite(Dir3, HIGH);
    }
    else
    {
      nh.loginfo("right wheels1 brake applied");
      digitalWrite(Sleep3, HIGH);}
    
    if(right_state2 == 1)
    {
      nh.loginfo("right wheels2 moving in forward direction");         
      digitalWrite(Sleep4, LOW);
      digitalWrite(Dir4, LOW);
    }
    else if(right_state2 == 2)
    {
      nh.loginfo("right wheels2 moving in backward direction");         
      digitalWrite(Sleep4, LOW);
      digitalWrite(Dir4, HIGH); 
    }
    else
    {
      nh.loginfo("right wheels1 brake applied");
      digitalWrite(Sleep4, HIGH);}
    }      
    state = false;
  }
}

void Task::activate_ros_spin()
{
  nh.spinOnce();
  delay(1);
}

void pwm_command(const haruto_msgs::PWM& data)
{
  front_left_pwm = data.front_left_pwm;
  front_right_pwm = data.front_right_pwm;
  back_left_pwm = data.back_left_pwm;
  back_right_pwm = data.back_right_pwm;
  left_state = data.left_state;
  right_state = data.right_state;
  state = true;
}
