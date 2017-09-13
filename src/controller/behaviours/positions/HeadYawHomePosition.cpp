#include "HeadYawHomePosition.h"

namespace var
{
   //Constructor
   HeadYawHomePosition::HeadYawHomePosition(MoveGenerator* moveGenerator, const double& speed, 
      const double &millis, const bool& reconocerObjetos) : 
      AbsoluteJointPosition(moveGenerator,HEAD_YAW,0,speed, millis, reconocerObjetos)
   {
   }
   
   //Destructor
   HeadYawHomePosition::~HeadYawHomePosition()
   {
   }
}
