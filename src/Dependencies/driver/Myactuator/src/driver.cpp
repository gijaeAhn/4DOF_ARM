#include "myactuator_rmd/driver.hpp"

#include <chrono>
#include <cstdint>
#include <string>

#include "myactuator_rmd/actuator_state/control_mode.hpp"
#include "myactuator_rmd/actuator_state/feedback.hpp"
#include "myactuator_rmd/actuator_state/gains.hpp"
#include "myactuator_rmd/actuator_state/motor_status_1.hpp"
#include "myactuator_rmd/actuator_state/motor_status_2.hpp"
#include "myactuator_rmd/actuator_state/motor_status_3.hpp"
#include "myactuator_rmd/protocol/node.hpp"
#include "myactuator_rmd/protocol/requests.hpp"
#include "myactuator_rmd/protocol/responses.hpp"
#include "myactuator_rmd/exceptions.hpp"


namespace myactuator_rmd {

  Driver::Driver(std::string const& ifname)
  : Node{ifname} {
    return;
  }
  
  void Driver::addMotor(std::uint32_t actuator_id){
    updateIds(actuator_id);
  }

  void Driver::MotorRunning(std::uint32_t actuator_id){
    MotorRunningRequest const request {};
    [[maybe_unused]] auto const response {sendRecv<MotorRunningResponse>(actuator_id,request)};
    return;
  }
  std::int32_t Driver::getAcceleration(std::uint32_t actuator_id) {
    GetAccelerationRequest const request {};
    auto const response {sendRecv<GetAccelerationResponse>(actuator_id,request)};
    return response.getAcceleration();
  }

  Gains Driver::getControllerGains(std::uint32_t actuator_id) {
    GetControllerGainsRequest const request {};
    auto const response {sendRecv<GetControllerGainsResponse>(actuator_id,request)};
    return response.getGains();
  }

  ControlMode Driver::getControlMode(std::uint32_t actuator_id) {
    GetControlModeRequest const request {};
    auto const response {sendRecv<GetControlModeResponse>(actuator_id,request)};
    return response.getMode();
  }

  std::string Driver::getMotorModel(std::uint32_t actuator_id) {
    GetMotorModelRequest const request {};
    auto const response {sendRecv<GetMotorModelResponse>(actuator_id,request)};
    return response.getModel();
  }

  float Driver::getMotorPower(std::uint32_t actuator_id) {
    GetMotorPowerRequest const request {};
    auto const response {sendRecv<GetMotorPowerResponse>(actuator_id,request)};
    return response.getPower();
  }

  MotorStatus1 Driver::getMotorStatus1(std::uint32_t actuator_id) {
    GetMotorStatus1Request const request {};
    auto const response {sendRecv<GetMotorStatus1Response>(actuator_id,request)};
    return response.getStatus();
  }

  MotorStatus2 Driver::getMotorStatus2(std::uint32_t actuator_id) {
    GetMotorStatus2Request const request {};
    auto const response {sendRecv<GetMotorStatus2Response>(actuator_id,request)};
    return response.getStatus();
  }

  MotorStatus3 Driver::getMotorStatus3(std::uint32_t actuator_id) {
    GetMotorStatus3Request const request {};
    auto const response {sendRecv<GetMotorStatus3Response>(actuator_id,request)};
    return response.getStatus();
  }

  float Driver::getMultiTurnAngle(std::uint32_t actuator_id) {
    GetMultiTurnAngleRequest const request {};
    auto const response {sendRecv<GetMultiTurnAngleResponse>(actuator_id,request)};
    return response.getAngle();
  }

  std::int32_t Driver::getMultiTurnEncoderPosition(std::uint32_t actuator_id) {
    GetMultiTurnEncoderPositionRequest const request {};
    auto const response {sendRecv<GetMultiTurnEncoderPositionResponse>(actuator_id,request)};
    return response.getPosition();
  }

  std::int32_t Driver::getMultiTurnEncoderOriginalPosition(std::uint32_t actuator_id) {
    GetMultiTurnEncoderOriginalPositionRequest const request {};
    auto const response {sendRecv<GetMultiTurnEncoderOriginalPositionResponse>(actuator_id,request)};
    return response.getPosition();
  }

  std::int32_t Driver::getMultiTurnEncoderZeroOffset(std::uint32_t actuator_id) {
    GetMultiTurnEncoderZeroOffsetRequest const request {};
    auto const response {sendRecv<GetMultiTurnEncoderZeroOffsetResponse>(actuator_id,request)};
    return response.getPosition();
  }

  std::chrono::milliseconds Driver::getRuntime(std::uint32_t actuator_id) {
    GetSystemRuntimeRequest const request {};
    auto const response {sendRecv<GetSystemRuntimeResponse>(actuator_id,request)};
    return response.getRuntime();
  }

  float Driver::getSingleTurnAngle(std::uint32_t actuator_id) {
    GetSingleTurnAngleRequest const request {};
    auto const response {sendRecv<GetSingleTurnAngleResponse>(actuator_id,request)};
    return response.getAngle();
  }

  std::int16_t Driver::getSingleTurnEncoderPosition(std::uint32_t actuator_id) {
    GetSingleTurnEncoderPositionRequest const request {};
    auto const response {sendRecv<GetSingleTurnEncoderPositionResponse>(actuator_id,request)};
    return response.getPosition();
  }

  std::uint32_t Driver::getVersionDate(std::uint32_t actuator_id) {
    GetVersionDateRequest const request {};
    auto const response {sendRecv<GetVersionDateResponse>(actuator_id,request)};
    return response.getVersion();
  }

  void Driver::lockBrake(std::uint32_t actuator_id) {
    LockBrakeRequest const request {};
    [[maybe_unused]] auto const response {sendRecv<LockBrakeResponse>(actuator_id,request)};
    return;
  }

  void Driver::releaseBrake(std::uint32_t actuator_id) {
    ReleaseBrakeRequest const request {};
    [[maybe_unused]] auto const response {sendRecv<ReleaseBrakeResponse>(actuator_id,request)};
    return;
  }

  void Driver::reset(std::uint32_t actuator_id) {
    ResetRequest const request {};
    send(actuator_id,request);
    return;
  }

  Feedback Driver::sendPositionAbsoluteSetpoint(std::uint32_t actuator_id,float const position, float const max_speed) {
    SetPositionAbsoluteRequest const request {position, max_speed};
    auto const response {sendRecv<SetPositionAbsoluteResponse>(actuator_id,request)};
    return response.getStatus();
  }

  Feedback Driver::sendTorqueSetpoint(std::uint32_t actuator_id,float const current) {
    SetTorqueRequest const request {current};
    auto const response {sendRecv<SetTorqueResponse>(actuator_id,request)};
    
    return response.getStatus();
  }

  Feedback Driver::sendVelocitySetpoint(std::uint32_t actuator_id, float const speed) {
    SetVelocityRequest const request {speed};
    auto const response {sendRecv<SetVelocityResponse>(actuator_id,request)};
    return response.getStatus();
  }

  Gains Driver::setControllerGains(std::uint32_t actuator_id, Gains const& gains, bool const is_persistent) {
    if (is_persistent) {
      SetControllerGainsPersistentlyRequest const request {gains};
      auto const response {sendRecv<SetControllerGainsPersistentlyResponse>(actuator_id,request)};
      return response.getGains();
    } else {
      SetControllerGainsRequest const request {gains};
      auto const response {sendRecv<SetControllerGainsResponse>(actuator_id,request)};
      return response.getGains();
    }
  }

  void Driver::shutdownMotor(std::uint32_t actuator_id) {
    ShutdownMotorRequest const request {};
    [[maybe_unused]] auto const response {sendRecv<ShutdownMotorResponse>(actuator_id,request)};
    return;
  }

  void Driver::stopMotor(std::uint32_t actuator_id) {
    StopMotorRequest const request {};
    [[maybe_unused]] auto const response {sendRecv<StopMotorResponse>(actuator_id,request)};
    return;
  }

}
