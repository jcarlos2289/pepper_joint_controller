#include "HeadPitchHomePosition.h"

namespace var
{
   //Constructor
   HeadPitchHomePosition::HeadPitchHomePosition(MoveGenerator* moveGenerator, const double& speed, 
      const double &millis, const bool& reconocerObjetos) : 
      AbsoluteJointPosition(moveGenerator,HEAD_PITCH,0,speed, millis, reconocerObjetos)
   {
   }
   
   //Destructor
   HeadPitchHomePosition::~HeadPitchHomePosition()
   {
   }
}
