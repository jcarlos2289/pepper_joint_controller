#include "RShoulderPitchBehaviour.h"
#include "PepperJoint.h"

#define DEBUG

namespace var
{
    //Constructor
     RShoulderPitchBehaviour:: RShoulderPitchBehaviour(MoveGenerator* moveGenerator, const double& posInicial, const double& posObjetivo, const double& maxStep,
      const double& speed, const double &millis, const bool &reconocerObjetos) :
      BasicJointMoveBehaviour(moveGenerator, R_SHOULDER_PITCH, posInicial, posObjetivo, maxStep, speed, millis, reconocerObjetos)
    {
    }
    
    //Destructor
    RShoulderPitchBehaviour::~RShoulderPitchBehaviour()
    {
    }
}
