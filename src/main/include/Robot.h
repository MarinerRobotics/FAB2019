// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef _ROBOT_H
#define _ROBOT_H

#include "frc/WPILib.h"
#include "frc/commands/Command.h"
#include "frc/livewindow/LiveWindow.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/AutonomousCommand.h"
#include "Subsystems/ArmExtender.h"
#include "Subsystems/BallPuncher.h"
#include "Subsystems/Boomer.h"
#include "Subsystems/CameraServ.h"
#include "Subsystems/Claw.h"
#include "Subsystems/ClawPivotor.h"
#include "Subsystems/DriveBase.h"
#include "Subsystems/JackedUpDrive.h"
#include "Subsystems/Shifter.h"
#include "Subsystems/TheJacks.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "OI.h"

class Robot : public frc::TimedRobot {
public:
	frc::Command* autonomousCommand = nullptr;
	static std::unique_ptr<OI> oi;
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	frc::SendableChooser<frc::Command*> chooser;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static std::shared_ptr<DriveBase> driveBase;
	static std::shared_ptr<Boomer> boomer;
	static std::shared_ptr<Claw> claw;
	static std::shared_ptr<ClawPivotor> clawPivotor;
	static std::shared_ptr<JackedUpDrive> jackedUpDrive;
	static std::shared_ptr<Shifter> shifter;
	static std::shared_ptr<BallPuncher> ballPuncher;
	static std::shared_ptr<ArmExtender> armExtender;
	static std::shared_ptr<CameraServ> cameraServ;
	static std::shared_ptr<TheJacks> theJacks;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
};
#endif
