#include "NaiveMotionController.h"

namespace var
{
  //Constructor
  NaiveMotionController::NaiveMotionController(ros::NodeHandle& nh) : MotionController(nh)
  {
  }
  
  //Realizar movimiento
  bool NaiveMotionController::move()
  {
      return true;
  }
  
  //Parar el robot
  bool NaiveMotionController::stop()
  {
      //No se mueve el robot, por lo que no hace falta pararlo
      return true;
  }
         
  //Destructor
  NaiveMotionController::~NaiveMotionController()
  {
  }
}
