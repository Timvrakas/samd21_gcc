/**
 * \file
 *
 * \brief User Interface
 *
 * Copyright (c) 2014-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include <asf.h>
#include "ui.h"
#include "ieee11073_skeleton.h"

void ui_init(void)
{
	LED_Off(LED0_GPIO);
	LED_Off(LED1_GPIO);
}

void ui_powerdown(void)
{
	LED_Off(LED0_GPIO);
	LED_Off(LED1_GPIO);
	LED_Off(LED2_GPIO);
}

void ui_wakeup(void)
{
	LED_On(LED0_GPIO);
}

void ui_association(bool state)
{
	if (state) {
		LED_On(LED2_GPIO);
	} else {
		LED_Off(LED2_GPIO);
	}
}

void ui_process(uint16_t framenumber)
{
	static uint8_t cpt_sof = 0;
	bool b_btn_state;
	static bool btn0_last_state = false;
	static bool btn1_last_state = false;

	if ((framenumber % 1000) == 0) {
		LED_On(LED1_GPIO);
	}

	if ((framenumber % 1000) == 500) {
		LED_Off(LED1_GPIO);
	}

	/* Scan process running each 20ms */
	cpt_sof++;
	if (20 > cpt_sof) {
		return;
	}

	cpt_sof = 0;

	/* Scan buttons on switch 0 (left), 1 (middle), 2 (right) */
	b_btn_state = gpio_pin_is_low(GPIO_PUSH_BUTTON_0);
	if (b_btn_state != btn0_last_state) {
		btn0_last_state = b_btn_state;
		if (b_btn_state) {
			ieee11073_skeleton_send_measure_1();
		}
	}

	b_btn_state = gpio_pin_is_low(GPIO_PUSH_BUTTON_1);
	if (b_btn_state != btn1_last_state) {
		btn1_last_state = b_btn_state;
		if (b_btn_state) {
			ieee11073_skeleton_send_measure_2();
		}
	}
}

/**
 * \defgroup UI User Interface
 *
 * Human interface on XMEGA-A3BU Xplained:
 * - Led green (close to USB connector) is on at power on
 * - Led 0 is on when USB line is in IDLE mode, and off in SUSPEND mode
 * - Led 1 blinks when USB host has checked and enabled PHDC interface
 * - Led 2 is on when PHDC has validated association
 * - SW0 and SW1 Push Button can be used to send a measure
 */
