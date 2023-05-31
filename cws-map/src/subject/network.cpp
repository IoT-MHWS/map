#include "cws/subject/network.hpp"

namespace Subject {

void NetworkDevice::transmitPackets(
    std::list<std::unique_ptr<Network::Packet>> && packetList) {

  for (auto && packet : packetList) {
    transmitBuffer_.push_back(std::move(packet));
  }
}

// just copy
std::list<std::unique_ptr<Network::Packet>>
NetworkDevice::collectNetworkPackets(Network::Type type) const {
  std::list<std::unique_ptr<Network::Packet>> result;

  if (type == networkType_) {
    for (const auto & packet : transmitBuffer_) {
      result.push_back(std::unique_ptr<Network::Packet>(packet->clone()));
    }
  }

  return result;
}

void NetworkDevice::clearTransmitBuffer() { transmitBuffer_.clear(); }

const std::list<std::unique_ptr<Network::Packet>> &
NetworkDevice::getReceivedPackets() const {
  return receiveBuffer_;
}

// just copy
void NetworkDevice::placeNetworkPackets(
    const std::list<std::unique_ptr<Network::Packet>> & packetList,
    Network::Type type) {

  if (type == networkType_) {
    for (const auto & packet : packetList) {
      receiveBuffer_.push_back(std::unique_ptr<Network::Packet>(packet->clone()));
    }
  }
}

void NetworkDevice::clearReceiveBuffer() { receiveBuffer_.clear(); }

};// namespace Subject