// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace OperatorConstants {
  constexpr int kDriverControllerPort = 0;

  constexpr bool kArmInvertTilt   = false;
  constexpr bool kArmInvertRotate = false;
  constexpr bool kArmInvertExtend = false;
  constexpr double kArmRampTilt   = 0.04;
  constexpr double kArmRampRotate = 0.04;
  constexpr double kArmRampExtend = 0.04;

  constexpr bool kDriveInvertL = false;
  constexpr bool kDriveInvertR = true;
  constexpr double kDriveRampX = 0.04;
  constexpr double kDriveRampR = 0.04;
}

namespace CanIds {
  constexpr int kDriveL1 = 1;
  constexpr int kDriveL2 = 2;
  constexpr int kDriveR1 = 3;
  constexpr int kDriveR2 = 4;

  constexpr int kArmTilt   = 6;
  constexpr int kArmRotate = 7;
  constexpr int kArmExtend = 8;
}
