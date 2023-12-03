#include "task.h"

extern Task task;

void setup()
{
  Task task;
  Serial.begin(115200);
}

void loop()
{
  task.execute_command();
  task.activate_ros_spin(); 
}
