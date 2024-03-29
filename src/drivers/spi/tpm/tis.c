/* SPDX-License-Identifier: BSD-3-Clause */

#include <console/console.h>
#include <security/tpm/tis.h>

#include "tpm.h"

static unsigned int tpm_is_open;

static const struct {
	uint16_t vid;
	uint16_t did;
	const char *device_name;
} dev_map[] = {
	{ 0x15d1, 0x001b, "SLB9670" },
	{ 0x1ae0, 0x0028, "CR50" },
	{ 0x104a, 0x0000, "ST33HTPH2E32" },
	{ 0x6666, 0x504a, "TI50" },
};

static const char *tis_get_dev_name(struct tpm2_info *info)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(dev_map); i++)
		if ((dev_map[i].vid == info->vendor_id) &&
		    (dev_map[i].did == info->device_id))
			return dev_map[i].device_name;
	return "Unknown";
}

tpm_result_t tis_open(void)
{
	if (tpm_is_open) {
		printk(BIOS_ERR, "%s() called twice.\n", __func__);
		return TPM_CB_FAIL;
	}
	return TPM_SUCCESS;
}

tpm_result_t tis_init(void)
{
	struct spi_slave spi;
	struct tpm2_info info;
	tpm_result_t rc = TPM_SUCCESS;

	if (spi_setup_slave(CONFIG_DRIVER_TPM_SPI_BUS,
			    CONFIG_DRIVER_TPM_SPI_CHIP, &spi)) {
		printk(BIOS_ERR, "Failed to setup TPM SPI slave\n");
		return TPM_CB_FAIL;
	}

	rc = tpm2_init(&spi);
	if (rc) {
		printk(BIOS_ERR, "Failed to initialize TPM SPI interface\n");
		return rc;
	}

	tpm2_get_info(&info);

	printk(BIOS_INFO, "Initialized TPM device %s revision %d\n",
	       tis_get_dev_name(&info), info.revision);

	return TPM_SUCCESS;
}

tpm_result_t tis_sendrecv(const uint8_t *sendbuf, size_t sbuf_size,
		 uint8_t *recvbuf, size_t *rbuf_len)
{
	int len = tpm2_process_command(sendbuf, sbuf_size, recvbuf, *rbuf_len);

	if (len == 0)
		return TPM_CB_FAIL;

	*rbuf_len = len;

	return TPM_SUCCESS;
}
