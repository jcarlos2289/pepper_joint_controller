#include "MoveGenerator.h"
#include <boost/thread/thread.hpp>
#include <math.h>

namespace var
{
  //Constructor
  MoveGenerator::MoveGenerator(ros::NodeHandle& nh) : jointMsgGenerator()
  {
      //Inicializar el publicador de la base
      this->basePublisher = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
      //Inicializar el publicador de la cabeza
      this->jointPublisher = nh.advertise<naoqi_bridge_msgs::JointAnglesWithSpeed>("/joint_angles", 1);
  }
    
  //Destructor
  MoveGenerator::~MoveGenerator()
  {

  }
  
  //Convertir de grados a radianes
  double MoveGenerator::degreesToRadians(const double& degrees)
  {
      return degrees*M_PI/180.0;
  }
  
  //Girar articulación determinada x grados
  bool MoveGenerator::moveJoint(const PepperJoint& joint, const double &degrees, const int &millis, const double &speed, const bool& relative)
  {
      //Generar mensaje de movimiento de joint
      MoveJointMessageInfo info(joint,degreesToRadians(degrees));
      this->jointMsgGenerator.createMessageSingle(jointMsg, info, speed, relative);
      //Establecer espera
      this->millis = millis;
      //Enviar mensaje de articulación
      return this->sendJointMsg();
  }
  
  //Girar articulaciones determinadas x grados
  bool MoveGenerator::moveJoints(const std::vector<PepperJoint> &joints, const std::vector<double> &degrees, 
      const int &millis, const double &speed, const bool& relative)
  {
      //Crear información de movimiento para cada joint
      std::vector<MoveJointMessageInfo> infos;
      for(unsigned int i=0; i<joints.size(); ++i)
      {
         infos.push_back(MoveJointMessageInfo(joints[i], degrees[i]));
      }
      
      //Generar mensaje de movimiento de joint
      this->jointMsgGenerator.createMessageMultiple(jointMsg, infos, speed, relative);
      //Establecer espera
      this->millis = millis;
      //Enviar mensaje de articulación
      return this->sendJointMsg();
  }
    
  //Mover la base
  bool MoveGenerator::moveBase(const MoveBaseType& moveType, const double &speed, const int &millis)
  {
      //Generar mensaje de movimiento de base
      MoveBaseMessageInfo info(moveType, speed);
      this->baseMsgGenerator.createMessageSingle(baseMsg, info);
      //Establecer espera
      this->millis = millis;
      //Enviar mensaje de articulación
      return this->sendBaseMsg();
  }
    
  //Parar el movimiento de la base
  bool MoveGenerator::stop(const int &millis)
  {
      //Construir mensaje de parada
      this->baseMsgGenerator.createStopMessage(baseMsg);
      this->millis = millis;
      
      //Enviar mensaje
      return this->sendBaseMsg();
  }
   
  //Enviar mensaje de movimiento de la base
  bool MoveGenerator::sendBaseMsg()
  {
     //Enviar mensaje de twist
     this->basePublisher.publish(this->baseMsg);
     //Esperar tiempo de movimiento
     boost::this_thread::sleep(boost::posix_time::milliseconds(this->millis));     
     return true;
  }
  
   //Enviar mensaje de movimiento de cabeza
   bool MoveGenerator::sendJointMsg()
   {
     //Enviar mensaje de twist
     this->jointPublisher.publish(this->jointMsg);
     //Esperar tiempo de movimiento
     boost::this_thread::sleep(boost::posix_time::milliseconds(this->millis));     
     return true;
   }
}
