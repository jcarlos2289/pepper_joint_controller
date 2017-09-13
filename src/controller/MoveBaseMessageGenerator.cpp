#include "MoveBaseMessageGenerator.h"
#include <math.h>

namespace var
{
  //Constructor
  MoveBaseMessageInfo::MoveBaseMessageInfo(const MoveBaseType& moveType, const double &speed) :
   moveType(moveType), speed(speed)
  {
  }
  //Destructor
  MoveBaseMessageInfo::~MoveBaseMessageInfo()
  {
  }
    
  //Constructor  
  MoveBaseMessageGenerator::MoveBaseMessageGenerator()
  {
  }
  
  //Destructor
  MoveBaseMessageGenerator::~MoveBaseMessageGenerator()
  {
  }
  
  //Convertir de grados a radianes
  double MoveBaseMessageGenerator::degreesToRadians(const double& degrees)
  {
      return degrees*M_PI/180.0;
  }
  
  //Creador de mensajes únicos
  void MoveBaseMessageGenerator::createMessageSingle(geometry_msgs::Twist &moveMsg, const MoveBaseMessageInfo &info)
  {
      //Limpiar nombres y ángulos
      this->createStopMessage(moveMsg);
      //Seleccionar tipo de movimiento
      this->processMoveInfo(moveMsg, info);
  }
         
  //Creador de mensajes
  void MoveBaseMessageGenerator::createMessageMultiple(geometry_msgs::Twist &moveMsg, const std::vector<MoveBaseMessageInfo>& info)
   {
      //Limpiar nombres y ángulos
      this->createStopMessage(moveMsg);
      
      //Añadir nombres y ángulos
      for(unsigned int i=0; i<info.size(); ++i)
      {
         //Información de movimiento
         const MoveBaseMessageInfo& inf = info[i];
         //Seleccionar tipo de movimiento
         this->processMoveInfo(moveMsg, inf);
      }
      
   }
   
   //Procesar mensaje de base
   void MoveBaseMessageGenerator::processMoveInfo(geometry_msgs::Twist &moveMsg, const MoveBaseMessageInfo &info)
   {
      //Seleccionar tipo de movimiento
      switch(info.moveType)
      {
         case MOVE_BASE_TURN: setAngularZ(moveMsg, info.speed);
                              break;
         case MOVE_BASE_X:    setLinearX(moveMsg, info.speed);
                              break;
         case MOVE_BASE_Y:    setLinearY(moveMsg, info.speed);
                              break;                    
      }
   }
   
   //Setear velocidad lineal x
   void MoveBaseMessageGenerator::setLinearX(geometry_msgs::Twist &moveMsg, const double &meters)
   {
      moveMsg.linear.x = meters;
   }
   
   //Setear velocidad lineal y
   void MoveBaseMessageGenerator::setLinearY(geometry_msgs::Twist &moveMsg, const double &meters)
   {
      moveMsg.linear.y = meters;
   }
   
   //Setear velocidad angular
   void MoveBaseMessageGenerator::setAngularZ(geometry_msgs::Twist &moveMsg, const double &degrees)
   {
      moveMsg.angular.z = this->degreesToRadians(degrees);
   }
   
   //Crear mensaje de parada
   void MoveBaseMessageGenerator::createStopMessage(geometry_msgs::Twist &moveMsg)
   {
      //Poner a 0 las velocidades
      moveMsg.angular.z = 0;
      moveMsg.linear.x = 0;
      moveMsg.linear.y = 0;
   }
}
