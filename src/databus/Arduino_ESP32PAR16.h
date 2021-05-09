/*
 * start rewrite from:
 * https://github.com/daumemo/IPS_LCD_R61529_FT6236_Arduino_eSPI_Test
 */
#ifdef ESP32
#ifndef _ARDUINO_ESP32PAR16_H_
#define _ARDUINO_ESP32PAR16_H_

#include "Arduino_DataBus.h"

class Arduino_ESP32PAR16 : public Arduino_DataBus
{
public:
  Arduino_ESP32PAR16(
      int8_t dc, int8_t cs, int8_t wr, int8_t rd,
      int8_t d0, int8_t d1, int8_t d2, int8_t d3, int8_t d4, int8_t d5, int8_t d6, int8_t d7,
      int8_t d8, int8_t d9, int8_t d10, int8_t d11, int8_t d12, int8_t d13, int8_t d14, int8_t d15); // Constructor

  void begin(int32_t speed = 0, int8_t dataMode = 0) override;
  void beginWrite() override;
  void endWrite() override;
  void writeCommand(uint8_t) override;
  void writeCommand16(uint16_t) override;
  void write(uint8_t) override;
  void write16(uint16_t) override;
  void writeRepeat(uint16_t p, uint32_t len) override;
  void writePixels(uint16_t *data, uint32_t len) override;

  void writeC8D8(uint8_t c, uint8_t d) override;
  void writeC8D16(uint8_t c, uint16_t d) override;
  void writeC8D16D16(uint8_t c, uint16_t d1, uint16_t d2) override;
  void writeBytes(uint8_t *data, uint32_t len) override;
  void writePattern(uint8_t *data, uint8_t len, uint32_t repeat) override;

  void writeIndexedPixels(uint8_t *data, uint16_t *idx, uint32_t len) override;
  void writeIndexedPixelsDouble(uint8_t *data, uint16_t *idx, uint32_t len) override;

protected:
private:
  INLINE void WRITE(uint8_t d);
  INLINE void WRITE16(uint16_t d);
  INLINE void DC_HIGH(void);
  INLINE void DC_LOW(void);
  INLINE void CS_HIGH(void);
  INLINE void CS_LOW(void);

  int8_t _dc, _cs, _wr, _rd;
  int8_t _d0, _d1, _d2, _d3, _d4, _d5, _d6, _d7;
  int8_t _d8, _d9, _d10, _d11, _d12, _d13, _d14, _d15;

  PORTreg_t _dcPortSet; ///< PORT register SET
  PORTreg_t _dcPortClr; ///< PORT register CLEAR
  uint32_t _dcPinMask;  ///< Bitmask

  PORTreg_t _csPortSet; ///< PORT register SET
  PORTreg_t _csPortClr; ///< PORT register CLEAR
  uint32_t _csPinMask;  ///< Bitmask

  PORTreg_t _wrPortSet; ///< PORT register SET
  PORTreg_t wrPortClr; ///< PORT register CLEAR
  uint32_t _wrPinMask;  ///< Bitmask

  PORTreg_t _rdPortSet; ///< PORT register SET
  PORTreg_t _rdPortClr; ///< PORT register CLEAR
  uint32_t _rdPinMask;  ///< Bitmask

  PORTreg_t _dataPortSet; ///< PORT register SET
  PORTreg_t _dataPortClr; ///< PORT register CLEAR
  uint32_t _dataClrMask;
  // Lookup table for ESP32 parallel bus interface uses 2kbyte RAM,
  uint32_t _xset_mask_lo[256];
  uint32_t _xset_mask_hi[256];
};

#endif // _ARDUINO_ESP32PAR16_H_
#endif // #ifdef ESP32
