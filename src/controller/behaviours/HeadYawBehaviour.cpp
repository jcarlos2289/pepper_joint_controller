#include "HeadYawBehaviour.h"
#include "PepperJoint.h"

#define DEBUG

namespace var
{
    //Constructor
    HeadYawBehaviour::HeadYawBehaviour(MoveGenerator* moveGenerator, const double& posInicial, const double& posObjetivo, const double& maxStep,
      const double& speed, const double &millis, const bool &reconocerObjetos) :
      BasicJointMoveBehaviour(moveGenerator, HEAD_YAW, posInicial, posObjetivo, maxStep, speed, millis, reconocerObjetos)
    {
    }
    
    //Destructor
    HeadYawBehaviour::~HeadYawBehaviour()
    {
    }
}
