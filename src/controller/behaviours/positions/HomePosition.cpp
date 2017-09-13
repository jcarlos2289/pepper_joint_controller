#include "HomePosition.h"

namespace var
{
   //Constructor
   HomePosition::HomePosition(MoveGenerator* moveGenerator, const double& speed, 
      const double &millis, const bool& reconocerObjetos) : 
      AbsoluteJointPosition(moveGenerator,speed, millis, reconocerObjetos)
   {
      this->addJoint(HEAD_YAW,0);
      this->addJoint(HEAD_PITCH,0);
      this->addJoint(L_SHOULDER_PITCH,0);
      this->addJoint(L_SHOULDER_ROLL,0);
      this->addJoint(L_ELBOW_YAW,0);
      this->addJoint(L_ELBOW_ROLL,0);
      this->addJoint(L_WRIST_YAW,0);
      this->addJoint(L_HAND,0);
      this->addJoint(HIP_ROLL,0);
      this->addJoint(HIP_PITCH,0);
      this->addJoint(KNEE_PITCH,0);
      this->addJoint(R_SHOULDER_PITCH,0);
      this->addJoint(R_SHOULDER_ROLL,0);
      this->addJoint(R_ELBOW_YAW,0);
      this->addJoint(R_ELBOW_ROLL,0);
      this->addJoint(R_WRIST_YAW,0);
      this->addJoint(R_HAND,0);
   }
   
   //Destructor
   HomePosition::~HomePosition()
   {
   }
}
