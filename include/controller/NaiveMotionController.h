#ifndef NAIVE_MOTION_CONTROLLER_H
#define NAIVE_MOTION_CONTROLLER_H

#include "MotionController.h"

namespace var
{
   //Controlador vacío para movimiento
   class NaiveMotionController : public MotionController
   {
      public:
         //Constructor
         NaiveMotionController(ros::NodeHandle& nh);
         //Destructor
         virtual ~NaiveMotionController();
         //Parar el robot
         virtual bool stop();
	      
	   protected:
	      //Realizar movimiento
	      virtual bool move() override;
   };
}

#endif
