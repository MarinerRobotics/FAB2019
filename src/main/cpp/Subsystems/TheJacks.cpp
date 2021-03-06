// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Subsystems/TheJacks.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

TheJacks::TheJacks() : frc::Subsystem("TheJacks") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    cANSparkMAXJacksBack.reset(new rev::CANSparkMax(7, rev::CANSparkMax::MotorType::kBrushless));
    cANSparkMAXJacksFront.reset(new rev::CANSparkMax(6, rev::CANSparkMax::MotorType::kBrushless));
    frontJacksRaiseLimit.reset(new frc::DigitalInput(3));
    frontJacksLowerLimit.reset(new frc::DigitalInput(4));
    backJacksRaiseLimit.reset(new frc::DigitalInput(5));
    backJacksLowerLimit.reset(new frc::DigitalInput(6));

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    cANSparkMAXJacksBack->SetInverted(true);
    backJack_encoder = cANSparkMAXJacksBack->GetEncoder();
    frontJack_encoder = cANSparkMAXJacksFront->GetEncoder();
    cANSparkMAXJacksBack->SetSmartCurrentLimit(80);
    cANSparkMAXJacksFront->SetSmartCurrentLimit(80);
}

void TheJacks::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void TheJacks::Periodic() {
    // Put code here to be run every loop

}

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS


// Put methods for controlling this subsystem
// here. Call these from Commands.
void TheJacks::RaiseJacksInBack(){
    frc::SmartDashboard::PutNumber("Back Jacks Encoder Pos", backJack_encoder.GetPosition());
    double backJacksPos = backJack_encoder.GetPosition();
    if (!backJacksRaiseLimit->Get()){
        StopBack();
        frc::SmartDashboard::PutNumber("Back Jacks Limit", 4);
    }
    else{
        cANSparkMAXJacksBack->Set(0.5);
        frc::SmartDashboard::PutNumber("Back Jacks Limit", 3);
    }
}


void TheJacks::RaiseJacksInFront(){
    frc::SmartDashboard::PutNumber("Front Jacks Encoder Pos", frontJack_encoder.GetPosition());
    double frontJacksPos = frontJack_encoder.GetPosition();
    if (!frontJacksRaiseLimit->Get()){
        StopFront();
        frc::SmartDashboard::PutNumber("Front Jacks Limit", 4);
    }
    else{
        cANSparkMAXJacksFront->Set(0.5);
        frc::SmartDashboard::PutNumber("Front Jacks Limit", 3);
    }
}

void TheJacks::RaiseBoth(){
    double frontJacksPos = frontJack_encoder.GetPosition();
    double backJacksPos = backJack_encoder.GetPosition();
    double baseSpeed = .5;
    if (frontJacksPos > backJacksPos){
        double dif = frontJacksPos - backJacksPos;
        if (!backJacksRaiseLimit->Get()){
            cANSparkMAXJacksBack->StopMotor();
        }
        else {
            cANSparkMAXJacksBack->Set(baseSpeed + dif*.02/2); //speed up the Back cause it's lower
        }
        if (!frontJacksRaiseLimit->Get()){
            cANSparkMAXJacksFront->StopMotor();
        }
        else{
             cANSparkMAXJacksFront->Set(baseSpeed - dif*.02/2); //slow down the Front cause it's higher
        }
    }
    else if (backJacksPos > frontJacksPos){
         double dif = backJacksPos - frontJacksPos;
         if (!frontJacksRaiseLimit->Get()){
            cANSparkMAXJacksFront->StopMotor();
         }
         else{
            cANSparkMAXJacksFront->Set(baseSpeed + dif*.02/2); //speed up the Front cause it's lower
         }
         if (!backJacksRaiseLimit->Get()){
             cANSparkMAXJacksBack->StopMotor();
         }
         else{
            cANSparkMAXJacksBack->Set(baseSpeed - dif*.02/2); //slow down the back cause it's higher
         }
    }
    else {
        if (!backJacksRaiseLimit->Get()){
            cANSparkMAXJacksBack->StopMotor();
        }
        else{
            cANSparkMAXJacksBack->Set(baseSpeed);
        }
        if (!frontJacksRaiseLimit->Get()){
            cANSparkMAXJacksFront->StopMotor();
        }
        else{
            cANSparkMAXJacksFront->Set(baseSpeed);
        }
    }
}
void TheJacks::LowerBoth(){
    LowerJacksInBack();
    LowerJacksInFront();
}
void TheJacks::LowerJacksInBack(){
    double backJacksPos = backJack_encoder.GetPosition();
    frc::SmartDashboard::PutNumber("Back Jacks Encoder Pos", backJack_encoder.GetPosition());
     if (backJacksLowerLimit->Get()){
         
          //double leftTrigger = Robot::oi->getJoystick2()->GetRawAxis(2);
        cANSparkMAXJacksBack->Set(-0.5);
        frc::SmartDashboard::PutNumber("Back Jacks Limit", 0);
    }
    else {
        
        StopBack();
        frc::SmartDashboard::PutNumber("Back Jacks Limit", 1);
    
    }
}
void TheJacks::LowerJacksInFront(){
    frc::SmartDashboard::PutNumber("Front Jacks Encoder Pos", frontJack_encoder.GetPosition());
    double frontJacksPos = frontJack_encoder.GetPosition();
    if (frontJacksLowerLimit->Get()){
         //double rightTrigger = Robot::oi->getJoystick2()->GetRawAxis(3);
        cANSparkMAXJacksFront->Set(-0.5);
        frc::SmartDashboard::PutNumber("Front Jacks Limit", 0);
    }
    else {
        //cANSparkMAXJacksFront->Set(-0.2);
        StopFront();
        frc::SmartDashboard::PutNumber("Front Jacks Limit", 1);
    }
}

void TheJacks::Stop(){
    cANSparkMAXJacksBack->StopMotor();
    cANSparkMAXJacksFront->StopMotor();
}
void TheJacks::StopBack(){
    cANSparkMAXJacksBack->StopMotor();
}
void TheJacks::StopFront(){
    cANSparkMAXJacksFront->StopMotor();
}
