#include "HeadYawRightPosition.h"
#include "HeadYawHomePosition.h"
#include "HeadYawBehaviour.h"

namespace var
{
   //Constructor
   HeadYawRightPosition::HeadYawRightPosition(MoveGenerator* moveGenerator, const double& speed, 
      const double &millis, const bool& reconocerObjetos) : 
      SuccessionMoveBehaviour(moveGenerator)
   {
      this->addBehaviour(new HeadYawHomePosition(moveGenerator, speed, millis, reconocerObjetos));
      this->addBehaviour(new HeadYawBehaviour(moveGenerator, 0, -90, 90, speed, millis, reconocerObjetos));
   }
   
   //Destructor
   HeadYawRightPosition::~HeadYawRightPosition()
   {
   }
}
