#include "SCL_SDA_Splitter.h"


TCA9548::TCA9548(const uint8_t deviceAddress, TwoWire *wire)
{
  _address  = deviceAddress;
  _wire     = wire;
  _mask     = 0x00;
  _resetPin = -1;
  _forced   = false;
  _error    = TCA9548_OK;
}


bool TCA9548::begin(uint8_t mask)
{
  _wire->begin();
  if (! isConnected()) return false;
  setChannelMask(mask);
  return true;
}


bool TCA9548::isConnected()
{
  _wire->beginTransmission(_address);
  return ( _wire->endTransmission() == 0);
}


bool TCA9548::isConnected(uint8_t address)
{
  _wire->beginTransmission(address);
  return ( _wire->endTransmission() == 0);
}



bool TCA9548::enableChannel(uint8_t channel)
{
  if (channel > 7) return false;
  if (!isEnabled(channel))
  {
    setChannelMask(_mask | (0x01 << channel));
  }
  return true;
}


bool TCA9548::disableChannel(uint8_t channel)
{
  if (channel > 7) return false;
  if (!isEnabled(channel))
  {
    setChannelMask(_mask & ~(0x01 << channel));
  }
  return true;
}


bool TCA9548::selectChannel(uint8_t channel)
{
  if (channel > 7) return false;
  setChannelMask(0x01 << channel);
  return true;
}


bool TCA9548::isEnabled(uint8_t channel)
{
  if (channel > 7) return false;
  return (_mask & (0x01 << channel));
}


bool TCA9548::disableAllChannels()
{
  return setChannelMask(0x00);
}


bool TCA9548::setChannelMask(uint8_t mask)
{
  if ((_mask == mask) && (! _forced)) return true;
  _mask = mask;
  _wire->beginTransmission(_address);
  _wire->write(_mask);
  _error = _wire->endTransmission();
  return (_error == 0);
}


uint8_t TCA9548::getChannelMask()
{
  if (_forced)
  {
    _wire->requestFrom(_address, (uint8_t)1);
    _mask = _wire->read();
  }
  return _mask;
}


void TCA9548::setResetPin(uint8_t resetPin)
{
  _resetPin = resetPin;
  pinMode(_resetPin, OUTPUT);
  digitalWrite(_resetPin, HIGH);
}


void TCA9548::reset()
{
  digitalWrite(_resetPin, LOW);
  delayMicroseconds(1);        
  digitalWrite(_resetPin, HIGH);
}


