#include "MoveJointMessageGenerator.h"

namespace var
{
  //Constructor
  MoveJointMessageInfo::MoveJointMessageInfo(const PepperJoint& joint, const double &radians) :
   joint(joint), radians(radians)
  {
  }
  //Destructor
  MoveJointMessageInfo::~MoveJointMessageInfo()
  {
  }
  
  //Colección de nombres de joints
  const int MoveJointMessageGenerator::NUM_JOINTS = 17;
  const std::string MoveJointMessageGenerator::jointNames[NUM_JOINTS] = {"HeadYaw", "HeadPitch", "LShoulderPitch", 
   "LShoulderRoll", "LElbowYaw", "LElbowRoll", "LWristYaw", "LHand", "HipRoll", "HipPitch", "KneePitch", "RShoulderPitch",
   "RShoulderRoll", "RElbowYaw", "RElbowRoll", "RWristYaw", "RHand"};
  
  //Constructor  
  MoveJointMessageGenerator::MoveJointMessageGenerator()
  {
  }
  
  //Destructor
  MoveJointMessageGenerator::~MoveJointMessageGenerator()
  {
  }
  
  //Creador de mensajes únicos
  void MoveJointMessageGenerator::createMessageSingle(naoqi_bridge_msgs::JointAnglesWithSpeed &jointMsg, const MoveJointMessageInfo &info, 
         const double &speed, const bool &relative)
  {
      //Limpiar nombres y ángulos
      jointMsg.joint_names.clear();
      jointMsg.joint_angles.clear();
      
      //Establecer velocidad
      jointMsg.speed = speed;
      jointMsg.relative = relative;
      
      //Añadir nombre y radianes
      jointMsg.joint_names.push_back(MoveJointMessageGenerator::jointNames[info.joint]);
      jointMsg.joint_angles.push_back(info.radians);
  }
         
  //Creador de mensajes
  void MoveJointMessageGenerator::createMessageMultiple(naoqi_bridge_msgs::JointAnglesWithSpeed &jointMsg, 
   const std::vector<MoveJointMessageInfo>& info, const double &speed, const bool &relative)
   {
      //Limpiar nombres y ángulos
      jointMsg.joint_names.clear();
      jointMsg.joint_angles.clear();
      
      //Establecer velocidad
      jointMsg.speed = speed;
      jointMsg.relative = relative;
      
      //Añadir nombres y ángulos
      for(unsigned int i=0; i<info.size(); ++i)
      {
         const MoveJointMessageInfo &jMsg = info[i];
         //Añadir nombre y radianes
         jointMsg.joint_names.push_back(MoveJointMessageGenerator::jointNames[jMsg.joint]);
         jointMsg.joint_angles.push_back(jMsg.radians);
      }
      
   }
}
