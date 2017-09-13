#include "HeadPitchBehaviour.h"
#include "PepperJoint.h"

#define DEBUG

namespace var
{
    //Constructor
    HeadPitchBehaviour::HeadPitchBehaviour(MoveGenerator* moveGenerator, const double& posInicial, const double& posObjetivo, const double& maxStep,
      const double& speed, const double &millis, const bool &reconocerObjetos) :
      BasicJointMoveBehaviour(moveGenerator, HEAD_PITCH, posInicial, posObjetivo, maxStep, speed, millis, reconocerObjetos)
    {
    }
    
    //Destructor
    HeadPitchBehaviour::~HeadPitchBehaviour()
    {
    }
}
