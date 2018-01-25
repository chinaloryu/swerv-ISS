#pragma once

#include <stdint.h>


enum WhisperMessageType { Peek, Poke, Step, Until, Change, ChangeCount,
			  Quit, Invalid };

/// Structure used to communicate with the whisper program using
/// sockets.  When a ChangeCount message is returned by whisper (as a
/// reply to a Step or a ChangeCount request), the address is set to
/// the program-counter of the last executed instruction, the resource
/// is set to the opcode of that instruction and the value is set to
/// the number of change records generated by that instruction.
struct WhisperMessage
{
#ifdef __cplusplus
  WhisperMessage(uint32_t hart = 0, WhisperMessageType type = Invalid,
		 uint32_t resource = 0, uint64_t address = 0, 
		 uint64_t value = 0)
  : hart(hart), type(type), resource(resource), address(address),
    value(value)
  { }
#endif

  uint32_t hart;
  uint32_t type;
  uint32_t resource;
  uint32_t pad;
  uint64_t address;
  uint64_t value;
  char buffer[128];
};