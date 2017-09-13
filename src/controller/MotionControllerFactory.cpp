#include "MotionControllerFactory.h"
#include "SimpleMotionController.h"
#include "CompleteMotionController.h"
#include "NaiveMotionController.h"

namespace var
{
   //Constructor
   MotionControllerFactory::MotionControllerFactory()
   {
   }
   
   //Destructor
   MotionControllerFactory::~MotionControllerFactory()
   {
   }
   
   //Generar controlador
   MotionController* MotionControllerFactory::generate(const std::string& type, ros::NodeHandle &nh) const
   {
      //Buscar el tipo
	   if(type=="naive")
	   {
	      return new NaiveMotionController(nh);
	   }
	   else if(type=="simple")
	   {
	      return new var::SimpleMotionController(nh);
	   }
	   else if(type=="complete")
	   {
	      return new var::CompleteMotionController(nh);
	   }
	   else
	   {  
	      return NULL;
	   }
   }
}
