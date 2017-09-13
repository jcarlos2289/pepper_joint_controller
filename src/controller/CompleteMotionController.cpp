#include "CompleteMotionController.h"
#include "RobotInspectionBehaviour.h"

#define DEBUG

namespace var
{
  //Constructor
  CompleteMotionController::CompleteMotionController(ros::NodeHandle& nh) : NoPlanifiedMotionController(nh)
  {
      //Definición del comportamiento
      this->constructMoveBehaviour();
  }
           
  //Destructor
  CompleteMotionController::~CompleteMotionController()
  {
  }
  
  //Construir el comportamiento del movimiento
  void CompleteMotionController::constructMoveBehaviour()
  {
      //Definición del comportamiento
      this->moveBehaviour = new RobotInspectionBehaviour(&moveGenerator);
  }
}
