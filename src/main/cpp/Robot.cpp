// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

    m_diffDrive.SetDeadband(.1);
    		/* factory default values */
	  m_rightFront.ConfigFactoryDefault();
	  m_leftFront.ConfigFactoryDefault();
		
		/* set up followers */
		//_rghtFollower.Follow(_rghtFront);
		//_leftFollower.Follow(_leftFront);

		/* [3] flip values so robot moves forward when stick-forward/LEDs-green */
	  m_rightFront.SetInverted(TalonFXInvertType::Clockwise);
		//_rghtFollower.SetInverted(TalonFXInvertType::FollowMaster);
	  m_leftFront.SetInverted(TalonFXInvertType::Clockwise);
		//_leftFollower.SetInverted(TalonFXInvertType::FollowMaster);
  

}

void Robot::RobotPeriodic() {

  frc::SmartDashboard::PutBoolean("Left Bumper:", leftBump);
  frc::SmartDashboard::PutBoolean("Right Bumper", rightBump);
  frc::SmartDashboard::PutBoolean("Button A: ", buttonA);
  frc::SmartDashboard::PutBoolean("Button B: ",buttonB);
  frc::SmartDashboard::PutBoolean("Button X; ",buttonX);
  frc::SmartDashboard::PutBoolean("Button Y: ",buttonY);
  frc::SmartDashboard::PutNumber("Left X:",leftX);
  frc::SmartDashboard::PutNumber("Left Y:",leftY);
  frc::SmartDashboard::PutNumber("Right X:",rightX);
  frc::SmartDashboard::PutNumber("Right Y:",rightY);
  frc::SmartDashboard::PutNumber("Position",leftPos);
  frc::SmartDashboard::PutNumber("Velocity",leftVel);
}

void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {

}

void Robot::TeleopPeriodic() {
  
  leftBump = xbox.frc::XboxController::GetLeftBumper();
  rightBump = xbox.frc::XboxController::GetRightBumper();
  buttonA = xbox.GetAButton();
  buttonB = xbox.GetBButton();
  buttonX = xbox.GetXButton();
  buttonY = xbox.GetYButton();

  leftX = xbox.frc::XboxController::GetLeftX();  
  leftY = xbox.frc::XboxController::GetLeftY();
  rightX = xbox.frc::XboxController::GetRightX();
  rightY = xbox.frc::XboxController::GetRightY();

  m_diffDrive.ArcadeDrive(leftX,rightY,true);

		leftPos = m_leftFront.GetSelectedSensorPosition(0);
		//double rghtPos = _rghtFront.GetSelectedSensorPosition(0);
		leftVel = m_leftFront.GetSelectedSensorVelocity(0);
		//double rghtVelUnitsPer100ms = _rghtFront.GetSelectedSensorVelocity(0);
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif