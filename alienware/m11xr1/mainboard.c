/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2012 secunet Security Networks AG
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <arch/io.h>
#include <device/device.h>
#include <console/console.h>
#include <drivers/intel/gma/int15.h>
#include <ec/acpi/ec.h>
//#include <ec/compal/ene932/ec.h>
#include <smbios.h>
#include "ec.h"

static u8 mainboard_fill_ec_version(char *buf, u8 buf_len)
{
	u8 i, c;
	char str[16 + 1]; /* 16 ASCII chars + \0 */

	/* Build ID */
	for (i = 0; i < 8; i++) {
		c = ec_mm_read(0xf0 + i);
		if (c < 0x20 || c > 0x7f) {
			i = snprintf(str, sizeof(str), "*INVALID");
			break;
		}
		str[i] = c;
	}

	i = MIN(buf_len, i);
	memcpy(buf, str, i);

	return i;
}

static void mainboard_smbios_strings(
	struct device *dev, struct smbios_type11 *t)
{
	char tpec[] = "IBM ThinkPad Embedded Controller -[                 ]-";
	u16 fwvh, fwvl;

	mainboard_fill_ec_version(tpec + 35, 17);
	t->count = smbios_add_string(t->eos, tpec);

	/* Apparently byteswapped compared to H8 */
	fwvh = ec_mm_read(0xe8);
	fwvl = ec_mm_read(0xe9);

	printk(BIOS_INFO, "EC Firmware ID %.54s, Version %d.%d%d%c\n", tpec,
	       fwvh >> 4, fwvh & 0x0f, fwvl >> 4, 0x41 + (fwvl & 0xf));
}

static void mainboard_enable(device_t dev)
{

    //dev->ops->init = mainboard_init;
    dev->ops->get_smbios_strings = mainboard_smbios_strings;

	install_intel_vga_int15_handler(GMA_INT15_ACTIVE_LFP_INT_LVDS,
					GMA_INT15_PANEL_FIT_CENTERING,
					GMA_INT15_BOOT_DISPLAY_DEFAULT, 2);

    if (!acpi_is_wakeup_s3())
		alienware_m11xr1_ec_init();

//	dev->ops->acpi_fill_ssdt_generator = fill_ssdt;
}

struct chip_operations mainboard_ops = {
	.enable_dev = mainboard_enable,
;
