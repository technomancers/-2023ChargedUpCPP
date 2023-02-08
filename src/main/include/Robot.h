#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h> 
#include <frc/XboxController.h>
#include <frc/drive/DifferentialDrive.h>
#include "ctre/Phoenix.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

frc::XboxController xbox{0};
bool leftBump  = false;
bool rightBump =false;
bool buttonA = false;
bool buttonB = false;
bool buttonX = false;
bool buttonY = false;

double leftX = 0.0;
double leftY = 0.0;
double rightX = 0.0;
double rightY =0.0;

double leftPos = 0;
double leftVel = 0;

WPI_TalonFX m_rightFront{3};
WPI_TalonFX m_leftFront{4};
 

frc::DifferentialDrive m_diffDrive{m_leftFront, m_rightFront};


};