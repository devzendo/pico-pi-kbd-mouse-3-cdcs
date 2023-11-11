#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "bsp/board.h"
#include "tusb.h"

void blink_led_task(void)
{
	const uint32_t interval_ms = 500;
	static uint32_t start_ms = 0;
	static bool led_state = false;
	if (board_millis() - start_ms < interval_ms) {
		return;
	}
	start_ms += interval_ms;

	board_led_write(led_state);
	led_state = !led_state;
}

static void cdc_task(void);

int main(void)
{
	board_init();

	printf("Keyboard and Mouse HID Example\r\n");

	tusb_init();
	tud_init(BOARD_TUD_RHPORT);
//	tuh_init(BOARD_TUH_RHPORT);

	while (1) {
		blink_led_task();
		tud_task(); // tinyusb device task
//		tuh_task();
		cdc_task();
	}
}

// echo to either Serial0 or Serial1
// with Serial0 as all lower case, Serial1 as all upper case
static void echo_serial_port(uint8_t itf, uint8_t buf[], uint32_t count)
{
	uint8_t const case_diff = 'a' - 'A';

	for (uint32_t i=0; i<count; i++) {
    		if (itf == 0) {
			// echo back 1st port as lower case
			if (isupper(buf[i])) buf[i] += case_diff;
		} else {
			// echo back 2nd port as upper case
			if (islower(buf[i])) buf[i] -= case_diff;
		}

		tud_cdc_n_write_char(itf, buf[i]);
	}
	tud_cdc_n_write_flush(itf);
}

//--------------------------------------------------------------------+
// USB CDC
//--------------------------------------------------------------------+
static void cdc_task(void)
{
	uint8_t itf;

	for (itf = 0; itf < CFG_TUD_CDC; itf++) {
		// connected() check for DTR bit
		// Most but not all terminal client set this when making connection
		// if ( tud_cdc_n_connected(itf) )
		{
			if (tud_cdc_n_available(itf)) {
				uint8_t buf[64];

				uint32_t count = tud_cdc_n_read(itf, buf, sizeof(buf));

				// echo back to both serial ports
				echo_serial_port(0, buf, count);
				echo_serial_port(1, buf, count);
			}
		}
	}
}

