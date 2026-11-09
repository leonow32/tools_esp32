#ifndef COMPONENT_TOOLS_ESP32_H_
#define COMPONENT_TOOLS_ESP32_H_

#include "../uCosmos/uCosmos.h"

namespace tools_esp32 {
	void reset_cmd(int argc, char * argv[]);
	void mem_cmd(int argc, char * argv[]);
	void fcpu_cmd(int argc, char * argv[]);
	void serial_number_cmd(int argc, char * argv[]);
}

#endif
