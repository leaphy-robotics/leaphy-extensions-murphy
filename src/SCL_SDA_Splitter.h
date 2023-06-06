#pragma once

#include "Arduino.h"
#include "Wire.h"

#define TCA9548_OK 0

class TCA9548
{
public:
  TCA9548(const uint8_t deviceAddress, TwoWire *wire = &Wire);
  bool    begin(uint8_t mask = 0x00);  
  bool    isConnected();               
  bool    isConnected(uint8_t address);      

  bool    enableChannel(uint8_t channel);  
  bool    disableChannel(uint8_t channel);
  bool    selectChannel(uint8_t channel);  
  bool    isEnabled(uint8_t channel);
  bool    disableAllChannels();

  bool    setChannelMask(uint8_t mask);
  uint8_t getChannelMask();

  void    setResetPin(uint8_t resetPin);
  void    reset();

private:
  uint8_t _otherAddress;
  uint8_t   _address;
  TwoWire*  _wire;
  uint8_t   _mask;          
  uint8_t   _resetPin;
  bool      _forced;
  int       _error;
};
