/**
 * \file node.hpp
 * \mainpage
 *    Contains the base class for the driver as well as the actuator mock
 * \author
 *    Tobit Flatscher (github.com/2b-t)
*/

#ifndef MYACTUATOR_RMD__NODE
#define MYACTUATOR_RMD__NODE
#pragma once

#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <mutex>

#include "myactuator_rmd/can/frame.hpp"
#include "myactuator_rmd/can/node.hpp"
#include "myactuator_rmd/protocol/message.hpp"
#include "myactuator_rmd/exceptions.hpp"
#include "myactuator_rmd/protocol/address_offset.hpp"





namespace myactuator_rmd {

  /**\class Node
   * \brief
   *    Base class for the driver as well as the actuator mock
  */
  template <std::uint32_t SEND_ID_OFFSET, std::uint32_t RECEIVE_ID_OFFSET>
  class Node: protected can::Node {
    protected:
      /**\fn Node
       * \brief
       *    Class constructor
       * 
       * \param[in] ifname
       *    The name of the network interface that should communicated over
       * \param[in] actuator_id
       *    The id of the actuator [0, 32]
      */
      Node(std::string const& ifname);
      Node() = delete;
      Node(Node const&) = delete;
      Node& operator = (Node const&) = default;
      Node(Node&&) = default;
      Node& operator = (Node&&) = default;
      ~Node();

      /**\fn updateIds
       * \brief
       *    Updates the id as well as the send and receive ids in a consistent manner
       * 
       * \param[in] actuator_id
       *    The id of the actuator [0, 32]
      */
      void updateIds(std::uint32_t const actuator_id);

      /**\fn send
       * \brief
       *    Writes a given CAN frame based on the request to the internally saved send_id_
       * 
       * \param[in] msg
       *    The message that should be sent to the corresponding send_id_
      */
      inline void send(std::uint32_t const actuator_id, Message const& msg);

      /**\fn sendRecv
       * \brief
       *    Writes a given CAN frame based on the request to the internally saved send_id_
       *    and waits for a corresponding reply
       * 
       * \tparam RESPONSE_TYPE
       *    Type of the response
       * \param[in] request
       *    Request that should be sent to the corresponding send_id_
       * \return
       *    The parsed response message
      */
      template <typename RESPONSE_TYPE>
      [[nodiscard]]
      inline RESPONSE_TYPE sendRecv(std::uint32_t const actuator_id, Message const& request);

    private:
      // std::uint32_t actuator_id_;
      std::vector<std::uint32_t> actuator_id_;
      std::vector<std::uint32_t> can_send_id_;
      std::vector<std::uint32_t> can_receive_id_;
      std::mutex mtx;


  };

  template <std::uint32_t SEND_ID_OFFSET, std::uint32_t RECEIVE_ID_OFFSET>
  Node<SEND_ID_OFFSET,RECEIVE_ID_OFFSET>::Node(std::string const& ifname)
  : can::Node{ifname} {
    return;
  }

  template <std::uint32_t SEND_ID_OFFSET, std::uint32_t RECEIVE_ID_OFFSET>
  Node<SEND_ID_OFFSET,RECEIVE_ID_OFFSET>::~Node()
  {std::cout << "Deconstruction of node" << std::endl;}



  template <std::uint32_t SEND_ID_OFFSET, std::uint32_t RECEIVE_ID_OFFSET>
  void Node<SEND_ID_OFFSET,RECEIVE_ID_OFFSET>::updateIds(std::uint32_t const actuator_id) {
    if ((actuator_id < 1) || (actuator_id > 32)) {
      throw Exception("Given actuator id '" + std::to_string(actuator_id) + "' out of admittable range [1, 32]!");
    }

    actuator_id_.push_back(actuator_id);
    can_send_id_.push_back(SEND_ID_OFFSET + actuator_id_[actuator_id -1]) ;
    can_receive_id_.push_back(RECEIVE_ID_OFFSET + actuator_id_[actuator_id -1]);
    setRecvFilter(can_receive_id_[actuator_id -1]);
    return;
  }

  template <std::uint32_t SEND_ID_OFFSET, std::uint32_t RECEIVE_ID_OFFSET>
  void Node<SEND_ID_OFFSET,RECEIVE_ID_OFFSET>::send(std::uint32_t const actuator_id, Message const& msg) {
    // mtx.lock();
    write(can_send_id_[actuator_id-1], msg.getData());
    // mtx.unlock();
    return;
  }

  template <std::uint32_t SEND_ID_OFFSET, std::uint32_t RECEIVE_ID_OFFSET>
  template <typename RESPONSE_TYPE>
  RESPONSE_TYPE Node<SEND_ID_OFFSET,RECEIVE_ID_OFFSET>::sendRecv(std::uint32_t const actuator_id, Message const& request) {
    std::cout << "Actuator Number : " << actuator_id << std::endl;
    std::cout << "send recieve id : " << can_send_id_[actuator_id -1] <<" " << can_receive_id_[actuator_id-1]<< std::endl;
    write(can_send_id_[actuator_id -1], request.getData());
    can::Frame const frame {can::Node::read(can_receive_id_[actuator_id-1])};




    RESPONSE_TYPE const response {frame.getData()};
    return response;

  }

}

#endif // MYACTUATOR_RMD__NODE
