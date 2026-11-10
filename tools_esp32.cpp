#include "../_config/_config.h"
#if COMPONENT_TOOLS_ESP32
#include "tools_esp32.h"
#include "esp_mac.h"

namespace tools_esp32 {

void reset_cmd(int argc, char * argv[]) {
    print_ok();
	esp_restart();
}

void mem_cmd(int argc, char * argv[]) {
    uint32_t ram_size   = heap_caps_get_total_size(MALLOC_CAP_INTERNAL);
	uint32_t ram_free   = heap_caps_get_free_size(MALLOC_CAP_INTERNAL);
	uint32_t ram_used   = ram_size - ram_free;
    uint32_t ram_min    = heap_caps_get_minimum_free_size(MALLOC_CAP_INTERNAL);

    uint32_t psram_size = heap_caps_get_total_size(MALLOC_CAP_SPIRAM);
    uint32_t psram_free = heap_caps_get_free_size(MALLOC_CAP_SPIRAM);
	uint32_t psram_used = psram_size - psram_free;
    uint32_t psram_min  = heap_caps_get_minimum_free_size(MALLOC_CAP_SPIRAM);

    printf("             RAM      PSRAM\n");
    printf("Size: %10lu %10lu\n", ram_size, psram_size);
    printf("Used: %10lu %10lu\n", ram_used, psram_used);
    printf("Free: %10lu %10lu\n", ram_free, psram_free);
	printf("Min:  %10lu %10lu\n", ram_min,  psram_min);
}

void fcpu_cmd(int argc, char * argv[]) {
	uint32_t fcpu_hz;
	esp_clk_tree_src_get_freq_hz(SOC_MOD_CLK_CPU, ESP_CLK_TREE_SRC_FREQ_PRECISION_CACHED, &fcpu_hz);
	printf("%lu MHz\n", fcpu_hz / 1000000);
}

void serial_number_cmd(int argc, char * argv[]) {
	uint8_t sn[6] = {0};
	esp_read_mac(sn, ESP_MAC_WIFI_STA);
	print_hexstr(sn, sizeof(sn), true), ' ';
}

}

#endif
