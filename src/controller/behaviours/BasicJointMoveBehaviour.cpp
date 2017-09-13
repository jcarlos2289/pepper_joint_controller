#include "BasicJointMoveBehaviour.h"
#include <cmath>
#include <algorithm>

#define DEBUG

namespace var
{
    //Constructor
    BasicJointMoveBehaviour::BasicJointMoveBehaviour(MoveGenerator* moveGenerator, const PepperJoint& joint, 
    const double& posInicial, const double& posObjetivo, const double& maxStep, 
    const double& speed, const double &millis, const bool &reconocerObjeto) :
      BasicMoveBehaviour(moveGenerator, posInicial, posObjetivo, 0.001, reconocerObjeto), 
      joint(joint), speed(speed), maxStep(maxStep), millis(millis)
    {
    }
    
    //Destructor
    BasicJointMoveBehaviour::~BasicJointMoveBehaviour()
    {
    }
    
    //Realizar movimiento
    bool BasicJointMoveBehaviour::move()
    {
      //Calcular el giro necesario
      double degreesNeeded = (posObjetivo-posActual);
      //Calcular el movimiento unitario a realizar
      double degreesUnit = degreesNeeded/fabs(degreesNeeded);
      //Calcular el valor de giro a realizar
      double degrees = std::min(fabs(degreesNeeded), maxStep) * degreesUnit;
      
      #ifdef DEBUG
      std::cerr<<"Degrees to move: "<<degrees<<std::endl;
      #endif
      
      //Realizar movimiento
      if(this->moveGenerator->moveJoint(joint, degrees, this->millis ,this->speed, true))
      {
         this->updatePosition(degrees);
         return true;
      }
      else
         return false;
         
    }
}
