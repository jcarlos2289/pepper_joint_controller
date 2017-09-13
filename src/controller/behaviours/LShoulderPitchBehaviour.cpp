#include "LShoulderPitchBehaviour.h"
#include "PepperJoint.h"

#define DEBUG

namespace var
{
    //Constructor
     LShoulderPitchBehaviour:: LShoulderPitchBehaviour(MoveGenerator* moveGenerator, const double& posInicial, const double& posObjetivo, const double& maxStep,
      const double& speed, const double &millis, const bool &reconocerObjetos) :
      BasicJointMoveBehaviour(moveGenerator, L_SHOULDER_PITCH, posInicial, posObjetivo, maxStep, speed, millis, reconocerObjetos)
    {
    }
    
    //Destructor
    LShoulderPitchBehaviour::~LShoulderPitchBehaviour()
    {
    }
}
