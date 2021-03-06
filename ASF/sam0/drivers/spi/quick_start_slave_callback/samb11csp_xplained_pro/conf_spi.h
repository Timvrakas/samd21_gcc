/**
 * \file
 *
 * \brief SAM B11 CSP Xplained Pro Xplained SPI configuration
 *
 * Copyright (c) 2016-2018 Microchip Technology Inc. and its subsidiaries.
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


#ifndef CONF_SPI_H_INCLUDED
#  define CONF_SPI_H_INCLUDED

#  define CONF_SPI_MASTER_ENABLE     false
#  define CONF_SPI_SLAVE_ENABLE      true

#  define CONF_SPI_TRANSFER_MODE     SPI_TRANSFER_MODE_0

#  define CONF_SPI                   SPI0

#  define CONF_SPI_PIN_SCK           PIN_LP_GPIO_10
#  define CONF_SPI_PIN_MOSI          PIN_LP_GPIO_11
#  define CONF_SPI_PIN_SSN           PIN_LP_GPIO_12
#  define CONF_SPI_PIN_MISO          PIN_LP_GPIO_13

#  define CONF_SPI_MUX_SCK           MUX_LP_GPIO_10_MUX4
#  define CONF_SPI_MUX_MOSI          MUX_LP_GPIO_11_MUX4
#  define CONF_SPI_MUX_SSN           MUX_LP_GPIO_12_MUX4
#  define CONF_SPI_MUX_MISO          MUX_LP_GPIO_13_MUX4

#endif /* CONF_SPI_H_INCLUDED */

