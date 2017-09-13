#ifndef MOTION_CONTROLLER_FACTORY_H
#define MOTION_CONTROLLER_FACTORY_H

#include "MotionController.h"

namespace var
{
   //Clase para generar un controlador
   class MotionControllerFactory
   {
      public:
         //Constructor
         MotionControllerFactory();
         //Destructor
         virtual ~MotionControllerFactory();
         
         //Generar controlador
         MotionController* generate(const std::string& type, ros::NodeHandle &nh) const;         
   };
}

#endif
