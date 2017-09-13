#include "BaseTurnBehaviour.h"
#include "MoveBaseType.h"

#define DEBUG

namespace var
{
    //Constructor
    BaseTurnBehaviour::BaseTurnBehaviour(MoveGenerator* moveGenerator, const double& posInicial, const double& posObjetivo, 
      const double& maxStep, const double& speed, const int& millis, const bool &reconocerObjetos) :
      BasicBaseMoveBehaviour(moveGenerator, MOVE_BASE_TURN, posInicial, posObjetivo, maxStep, speed, millis, reconocerObjetos)
    {
    }
    
    //Destructor
    BaseTurnBehaviour::~BaseTurnBehaviour()
    {
    }
}
