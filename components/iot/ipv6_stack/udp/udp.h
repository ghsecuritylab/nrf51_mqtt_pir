/* Copyright (c)  2014 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */

 /** @cond */
 /** @file udp.h
 *
 * @defgroup iot_udp UDP Module Header.
 * @ingroup iot_sdk
 * @{
 * @brief User Datagram Protocol module header defining interface between
 *        udp and other IP stack layers which are not exposed to the application.
 *
 */

#ifndef UDP_H__
#define UDP_H__

#include "sdk_config.h"
#include "sdk_common.h"
#include "ipv6_api.h"

/**
 * @brief  Module initialization function called from ipv6_init(). This shall not be called by the
 *         application explicitly.
 *
 * @retval NRF_SUCCESS on successful execution of procedure, else an error code indicating reason
 *                     for failure.
 */
uint32_t udp_init(void);


/**
 * @brief  Function to feed incoming UDP packets to the module. To be called by the IPv6
 *         stack only and never by the application.
 *
 * @param[in] p_interface Identifies network interface on which the packet is received.
 * @param[in] p_ip_header IP Header of the UDP packet being fed to the module.
 * @param[in] p_packet    UDP packet being notified to the module. p_packet->p_payload points the
 *                        IPv6 payload and p_packet->length indicates total length of the payload.
 *
 * @note This routine is called by the stack with next header field value is set to  UDP protocol
 *       value of 17.
 *
 * @retval NRF_SUCCESS on successful handling of the packet, else an error code indicating reason
 *                     for failure.
 */
uint32_t udp_input(const iot_interface_t  * p_interface,
                   const ipv6_header_t    * p_ip_header,
                   iot_pbuffer_t          * p_packet);

#endif //UDP_H__

/**@} */

/** @endcond */
