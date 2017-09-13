#include "RobotInspectionBehaviour.h"
#include "HomePosition.h"
#include "LShoulderPitchBehaviour.h"
#include "RShoulderPitchBehaviour.h"
#include "RobotLeftInspectionBehaviour.h"
#include "RobotRightInspectionBehaviour.h"
#include "RobotUpDownInspectionBehaviour.h"

namespace var
{
  //Constructor
  RobotInspectionBehaviour::RobotInspectionBehaviour(MoveGenerator* moveGenerator) : SuccessionMoveBehaviour(moveGenerator)
  {
      //Posición home del robot
      this->addBehaviour(new HomePosition(moveGenerator, 0.1, 6000, false));
      //Mover brazo izquierdo abajo
      this->addBehaviour(new LShoulderPitchBehaviour(moveGenerator, 0, 90, 90, 0.1, 5000, false));
      //Mover brazo derecho abajo
      this->addBehaviour(new RShoulderPitchBehaviour(moveGenerator, 0, 90, 90, 0.1, 5000, false));
      
      //Movimiento de inspección a la izquierda
      this->addBehaviour(new RobotLeftInspectionBehaviour(moveGenerator));
      //Movimiento de inspección a la derecha
      this->addBehaviour(new RobotRightInspectionBehaviour(moveGenerator));
      //Movimiento de inspección arriba y abajo
      this->addBehaviour(new RobotUpDownInspectionBehaviour(moveGenerator));
  }
        
  //Destructor
  RobotInspectionBehaviour::~RobotInspectionBehaviour()
  {
  }
   
}
