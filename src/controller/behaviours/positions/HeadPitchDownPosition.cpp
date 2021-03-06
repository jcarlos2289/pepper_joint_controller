#include "HeadPitchDownPosition.h"
#include "HeadPitchHomePosition.h"
#include "HeadPitchBehaviour.h"

namespace var
{
   //Constructor
   HeadPitchDownPosition::HeadPitchDownPosition(MoveGenerator* moveGenerator, const double& speed, 
      const double &millis, const bool& reconocerObjetos) :
      SuccessionMoveBehaviour(moveGenerator) 
   {
      this->addBehaviour(new HeadPitchHomePosition(moveGenerator, speed, millis, reconocerObjetos));
      this->addBehaviour(new HeadPitchBehaviour(moveGenerator, 0, 30, 30, speed, millis, reconocerObjetos));
   }
   
   //Destructor
   HeadPitchDownPosition::~HeadPitchDownPosition()
   {
   }
}
