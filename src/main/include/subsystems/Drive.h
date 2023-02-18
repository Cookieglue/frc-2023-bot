// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <functional>
#include <vector>

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/button/CommandXboxController.h>

#include <frc/motorcontrol/MotorController.h>
#include <frc/motorcontrol/MotorControllerGroup.h>

#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>

#include "Constants.h"

using MotorDriver = ctre::phoenix::motorcontrol::can::WPI_TalonFX;
using MotorCollection = std::vector<std::reference_wrapper<frc::MotorController>>;

class Drive : public frc2::SubsystemBase {
public:
  Drive(bool invertL, bool invertR, double rampX, double rampR);

  void AttachController(frc2::CommandXboxController *driverController);

  void SetPower(double x, double r, double k = 1.0);

  void Periodic();

private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc2::CommandXboxController *m_driverController;

  MotorDriver m_motors[4] {
    {CanIds::kDriveL1},
    {CanIds::kDriveL2},
    {CanIds::kDriveR1},
    {CanIds::kDriveR2},
  };

#define MOTOR(n) (*(frc::MotorController *) (m_motors + (n)))
  MotorCollection m_motorsL {MOTOR(0), MOTOR(1)};
  MotorCollection m_motorsR {MOTOR(2), MOTOR(3)};
#undef MOTOR

  frc::MotorControllerGroup m_ctrlL {std::move(m_motorsL)};
  frc::MotorControllerGroup m_ctrlR {std::move(m_motorsR)};

  const double rampX, rampR;

  double curX = 0, curR = 0;
};
