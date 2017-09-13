#include "BasicBaseMoveBehaviour.h"
#include <cmath>
#include <algorithm>
#include <boost/thread/thread.hpp>

#define DEBUG

namespace var
{
    //Constructor
    BasicBaseMoveBehaviour::BasicBaseMoveBehaviour(MoveGenerator* moveGenerator, const MoveBaseType& moveType, 
      const double& posInicial, const double& posObjetivo, const double& maxStep, const double& speed, 
      const int &millis, const bool &reconocerObjeto) :
      BasicMoveBehaviour(moveGenerator, posInicial, posObjetivo, 0.001, reconocerObjeto), 
         moveType(moveType), speed(speed), maxStep(maxStep), millis(millis)
    {
    }
    
    //Destructor
    BasicBaseMoveBehaviour::~BasicBaseMoveBehaviour()
    {
    }
    
    //Realizar movimiento
    bool BasicBaseMoveBehaviour::move()
    {
      //Calcular el giro necesario
      double degreesNeeded = (posObjetivo-posActual);
      //Calcular el movimiento unitario a realizar
      double degreesUnit = degreesNeeded/fabs(degreesNeeded);
      //Calcular el valor de giro a realizar
      double degrees = std::min(fabs(degreesNeeded), maxStep) * degreesUnit;
      
      #ifdef DEBUG
      std::cerr<<"Degrees to turn: "<<degrees<<std::endl;
      #endif
      	  
	  //Calcular los milisegundos de acción del movimiento
	  int millisMovimiento = (degrees/speed)*1000;
	  //Resultado del movimiento
	  bool res = false;
      
      //Realizar movimiento
      if(this->moveGenerator->moveBase(moveType, this->speed, millisMovimiento))
      {
         this->updatePosition(degrees);
         res = true;
      }

      //Parar la base
      this->moveGenerator->stop(this->millis);
         
      return res;
         
    }
}
