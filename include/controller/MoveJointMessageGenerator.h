#ifndef MOVE_JOINT_MESSAGE_GENERATOR
#define MOVE_JOINT_MESSAGE_GENERATOR

#include <naoqi_bridge_msgs/JointAnglesWithSpeed.h>
#include <vector>
#include "PepperJoint.h"

namespace var
{   
   //Información del mensaje de joint
   class MoveJointMessageInfo
   {
      public:
      
      //Constructor
      MoveJointMessageInfo(const PepperJoint& joint, const double &radians);
      //Destructor
      virtual ~MoveJointMessageInfo();
      //Información del mensaje
      //Articulación
      PepperJoint joint;
      //Radianes
      double radians;
      
   };
   
   //Clase para la generación de mensajes
   class MoveJointMessageGenerator
   {
      public:
         //Constructor
         MoveJointMessageGenerator();
         //Destructor
         ~MoveJointMessageGenerator();
         
         //Creador de mensajes únicos
         void createMessageSingle(naoqi_bridge_msgs::JointAnglesWithSpeed &jointMsg, const MoveJointMessageInfo &info, 
         const double &speed, const bool &relative);
         //Creador de mensajes múltiples
         void createMessageMultiple(naoqi_bridge_msgs::JointAnglesWithSpeed &jointMsg, const std::vector<MoveJointMessageInfo>& info, 
         const double &speed, const bool &relative);
         
         //Colección de nombres de joints
         static const int NUM_JOINTS;
         static const std::string jointNames[];
   };
}

#endif
