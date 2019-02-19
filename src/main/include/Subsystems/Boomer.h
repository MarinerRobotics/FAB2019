// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef BOOMER_H
#define BOOMER_H
#include "frc/commands/Subsystem.h"
#include "frc/WPILib.h"
#include "rev/CanSparkMax.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Boomer: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<rev::CANSparkMax> cANSparkBoom;
	std::shared_ptr<frc::DigitalInput> boomLimit;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	Boomer();
	void InitDefaultCommand() override;
	void Periodic() override;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	void BoomUp();
	void BoomDown();
	void Stop();
	void JoyBoom();
	double boomControl;
	rev::CANPIDController boom_pidController = cANSparkBoom->GetPIDController();
	double kP = 0.1, kI = 1e-4, kD = 1, kIz = 0, kFF = 0, kMaxOutput = 1, kMinOutput = -1;
	rev::CANEncoder boom_encoder = cANSparkBoom->GetEncoder();
	double DB(double axisVal);
	double LIMS(double limitVal, bool goingUp);
	double GetBoomPos();
};

#endif
