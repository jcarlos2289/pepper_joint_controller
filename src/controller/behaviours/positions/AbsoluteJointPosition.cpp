#include "AbsoluteJointPosition.h"

#define DEBUG

namespace var
{
   //Constructor de una articulación
   AbsoluteJointPosition::AbsoluteJointPosition(MoveGenerator* moveGenerator, const PepperJoint& joint, const double& posObjetivo, 
            const double& speed, const double &millis, const bool& reconocerObjetos)
            : MoveBehaviour(moveGenerator), speed(speed), millis(millis), reconocerObjetos(reconocerObjetos), done(false)
   {
      //Añadir joint
      this->joints.push_back(joint);
      //Añadir posición
      this->posObjetivo.push_back(posObjetivo);
   }
   
   //Constructor de múltiples articulaciones
   AbsoluteJointPosition::AbsoluteJointPosition(MoveGenerator* moveGenerator, const double& speed, const double &millis,
         const bool& reconocerObjetos, const std::vector<PepperJoint> &joints, const std::vector<double> &posObjetivo) 
            : MoveBehaviour(moveGenerator), joints(joints), posObjetivo(posObjetivo), speed(speed), 
               reconocerObjetos(reconocerObjetos), millis(millis), done(false)
   {

   }
   
   //Añadir joint y posición
   void AbsoluteJointPosition::addJoint(const PepperJoint& joint, const double& objetivo)
   {
      //Añadir joint
      this->joints.push_back(joint);
      //Añadir posición
      this->posObjetivo.push_back(objetivo);
   }
   
   //Destructor
   AbsoluteJointPosition::~AbsoluteJointPosition()
   {
   }

   //Gestionar movimiento
   bool AbsoluteJointPosition::move()
   {
      #ifdef DEBUG
      std::cerr<<"Preparando movimiento de joints absoluto"<<std::endl;
      #endif
      //Realizar movimiento absoluto
      if(this->moveAbsoluteOneStep())
         //Marcar como finalizado
         this->done = true;
   }
   
   //Comprobar si debe realizarse el reconocimiento de objetos
   bool AbsoluteJointPosition::checkToRecognize()
   {
      return this->reconocerObjetos;
   }
   
   //Realizar movimiento a posición absoluta de una sola pasada
   bool AbsoluteJointPosition::moveAbsoluteOneStep()
   {          
      //Realizar movimiento
      return this->moveGenerator->moveJoints(joints, posObjetivo, this->millis ,this->speed, false);
   }
      
   //Comprobar si ha terminado el objetivo
   bool AbsoluteJointPosition::checkIfEnded()
   {
      return done;
   }
}
