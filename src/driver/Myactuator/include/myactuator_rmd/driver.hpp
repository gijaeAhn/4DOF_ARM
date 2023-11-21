/**
 * \file driver.hpp
 * \mainpage
 *    Contains the main driver
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__DRIVER
#define MYACTUATOR_RMD__DRIVER
#pragma once

#include <chrono>
#include <cstdint>
#include <string>

#include "myactuator_rmd/actuator_state/control_mode.hpp"
#include "myactuator_rmd/actuator_state/feedback.hpp"
#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/actuator_state/motor_status_1.hpp"
#include "myactuator_rmd/actuator_state/motor_status_2.hpp"
#include "myactuator_rmd/actuator_state/motor_status_3.hpp"
#include "myactuator_rmd/protocol/address_offset.hpp"
#include "myactuator_rmd/protocol/node.hpp"


namespace myactuator_rmd {

  /**\class Driver
   * \brief
   *    Driver for commanding the MyActuator RMD actuator series
  */
  class Driver: protected Node<AddressOffset::request,AddressOffset::response> {
    public:
      /**\fn Driver
       * \brief
       *    Class constructor
       * 
       * \param[in] ifname
       *    The name of the network interface that should communicated over
       * \param[in] actuator_id
       *    The actuator id [1, 32]
      */
      Driver(std::string const& ifname);
      Driver() = delete;
      Driver(Driver const&) = delete;
      Driver& operator = (Driver const&) = default;
      Driver(Driver&&) = default;
      Driver& operator = (Driver&&) = default;


      void addMotor(std::uint32_t actuator_id);

      void MotorRunning(std::uint32_t actuator_id);
      /**\fn getAcceleration
       * \brief
       *    Reads the current acceleration
       * 
       * \return
       *    The current acceleration in dps with a resolution of 1 dps
      */
      [[nodiscard]]
      std::int32_t getAcceleration(std::uint32_t actuator_id);

      /**\fn getControllerGains
       * \brief
       *    Reads the currently used controller gains
       * 
       * \return
       *    The currently used controller gains for current, speed and position as unsigned 8-bit integers
      */
      [[nodiscard]]
      Gains getControllerGains(std::uint32_t actuator_id);

      /**\fn getControlMode
       * \brief
       *    Reads the currently used control mode
       * 
       * \return
       *    The currently used control mode
      */
      [[nodiscard]]
      ControlMode getControlMode(std::uint32_t actuator_id);

      /**\fn getMotorModel
       * \brief
       *    Reads the motor model currently in use by the actuator
       * 
       * \return
       *    The motor model string currently in use by the actuator, e.g. 'X8S2V10'
      */
      [[nodiscard]]
      std::string getMotorModel(std::uint32_t actuator_id);

      /**\fn getMotorPower
       * \brief
       *    Reads the current motor power consumption in Watt
       * 
       * \return
       *    The current motor power consumption in Watt with a resolution of 0.1
      */
      [[nodiscard]]
      float getMotorPower(std::uint32_t actuator_id);

      /**\fn getMotorStatus1
       * \brief
       *    Reads the motor status 1
       * 
       * \return
       *    The motor status 1 containing temperature, voltage and error codes
      */
      [[nodiscard]]
      MotorStatus1 getMotorStatus1(std::uint32_t actuator_id);

      /**\fn getMotorStatus2
       * \brief
       *    Reads the motor status 2
       * 
       * \return
       *    The motor status 2 containing current, speed and position
      */
      [[nodiscard]]
      MotorStatus2 getMotorStatus2(std::uint32_t actuator_id);

      /**\fn getMotorStatus3
       * \brief
       *    Reads the motor status 3
       * 
       * \return
       *    The motor status 3 containing detailed current information
      */
      [[nodiscard]]
      MotorStatus3 getMotorStatus3(std::uint32_t actuator_id);

      /**\fn getMultiTurnAngle
       * \brief
       *    Read the multi-turn angle
       * 
       * \return
       *    The current multi-turn angle with a resolution of 0.01 deg
      */
      [[nodiscard]]
      float getMultiTurnAngle(std::uint32_t actuator_id);

      /**\fn getMultiTurnEncoderPosition
       * \brief
       *    Read the multi-turn encoder position subtracted by the encoder multi-turn zero offset
       * 
       * \return
       *    The multi-turn encoder position
      */
      [[nodiscard]]
      std::int32_t getMultiTurnEncoderPosition(std::uint32_t actuator_id);

      /**\fn getMultiTurnEncoderOriginalPosition
       * \brief
       *    Read the raw multi-turn encoder position without taking into consideration the multi-turn zero offset
       * 
       * \return
       *    The multi-turn encoder position
      */
      [[nodiscard]]
      std::int32_t getMultiTurnEncoderOriginalPosition(std::uint32_t actuator_id);

      /**\fn getMultiTurnEncoderZeroOffset
       * \brief
       *    Read the multi-turn encoder zero offset
       * 
       * \return
       *    The multi-turn encoder zero offset
      */
      [[nodiscard]]
      std::int32_t getMultiTurnEncoderZeroOffset(std::uint32_t actuator_id);

      /**\fn getRuntime
       * \brief
       *    Reads the uptime of the actuator in milliseconds
       * 
       * \return
       *    The uptime of the actuator in milliseconds
      */
      [[nodiscard]]
      std::chrono::milliseconds getRuntime(std::uint32_t actuator_id);

      /**\fn getSingleTurnAngle
       * \brief
       *    Read the single-turn angle
       * 
       * \return
       *    The current single-turn angle with a resolution of 0.01 deg
      */
      [[nodiscard]]
      float getSingleTurnAngle(std::uint32_t actuator_id);

      /**\fn getSingleTurnEncoderPosition
       * \brief
       *    Read the single-turn encoder position
       * 
       * \return
       *    The single-turn encoder position
      */
      [[nodiscard]]
      std::int16_t getSingleTurnEncoderPosition(std::uint32_t actuator_id);

      /**\fn getVersionDate
       * \brief
       *    Reads the version date of the actuator firmware
       * 
       * \return
       *    The version date of the firmware on the actuator, e.g. '20220206'
      */
      [[nodiscard]]
      std::uint32_t getVersionDate(std::uint32_t actuator_id);

      /**\fn lockBrake
       * \brief
       *    Close the holding brake. The motor won't be able to turn anymore.
      */
      void lockBrake(std::uint32_t actuator_id);

      /**\fn releaseBrake
       * \brief
       *    Open the holding brake leaving the motor in a movable state
      */
      void releaseBrake(std::uint32_t actuator_id);

      /**\fn reset
       * \brief
       *    Reset the actuator
      */
      void reset(std::uint32_t actuator_id);

      /**\fn sendPositionAbsoluteSetpoint
       * \brief
       *    Send an absolute position set-point to the actuator additionally specifying a maximum velocity
       *
       * \param[in] position
       *    The position set-point in degree [-360.00, 360.00]
       * \param[in] max_speed
       *    The maximum speed for the motion in degree per second [-1320.0, 1320.0]
       * \return
       *    Feedback control message containing actuator position, velocity, torque and temperature
      */
      Feedback sendPositionAbsoluteSetpoint(std::uint32_t actuator_id,float const position, float const max_speed = 500.0);

      /**\fn sendTorqueSetpoint
       * \brief
       *    Send a torque set-point to the actuator by specifying the current
       *
       * \param[in] current
       *    The current set-point in Ampere [-20.00, 20.00]
       * \return
       *    Feedback control message containing actuator position, velocity, torque and temperature
      */
      Feedback sendTorqueSetpoint(std::uint32_t actuator_id,float const current);

      /**\fn sendVelocitySetpoint
       * \brief
       *    Send a velocity set-point to the actuator
       *
       * \param[in] speed
       *    The speed set-point in degree per second [-1320.00, 1320.00]
       * \return
       *    Feedback control message containing actuator position, velocity, torque and temperature
      */
      Feedback sendVelocitySetpoint(std::uint32_t actuator_id,float const speed);

      /**\fn setControllerGains
       * \brief
       *    Write the currently used controller gains either to RAM (not persistent after reboot) or ROM (persistent)
       * 
       * \param[in] gains
       *    The PI-gains for current, speed and position to be set
       * \param[in] is_persistent
       *    Boolean argument signaling whether the controller gains should be persistent after reboot of the actuator or not
       * \return
       *    The currently used controller gains for current, speed and position as unsigned 8-bit integers
      */
      Gains setControllerGains(std::uint32_t actuator_id, Gains const& gains, bool const is_persistent = false);

      /**\fn shutdownMotor
       * \brief
       *    Turn off the motor
      */
      void shutdownMotor(std::uint32_t actuator_id);

      /**\fn stopMotor
       * \brief
       *    Stop the motor if running closed loop command
      */
      void stopMotor(std::uint32_t actuator_id);
  };

}

#endif // MYACTUATOR_RMD__DRIVER
