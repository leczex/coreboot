/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef _AMD_FAM15TN_PCI_DEVS_H_
#define _AMD_FAM15TN_PCI_DEVS_H_

#include <device/pci_def.h>

#define BUS0 0

/* GNB Root Complex */
#define GNB_DEV			0x0
#define GNB_FUNC		0
#define GNB_DEVFN		PCI_DEVFN(GNB_DEV, GNB_FUNC)

/* IOMMU */
#define IOMMU_DEV		0x0
#define IOMMU_FUNC		2
#define IOMMU_DEVFN		PCI_DEVFN(IOMMU_DEV, IOMMU_FUNC)

/* Graphics and Display */
#define GFX_DEV 0x1
#define GFX_FUNC 0
#define GFX_DEVFN PCI_DEVFN(GFX_DEV, GFX_FUNC)

/* Integrated GPU Internal HDMI Audio Controller */
#define ACTL_FUNC	1
#define ACTL_DEVFN	PCI_DEVFN(GFX_DEV, ACTL_FUNC)

/* PCIe Ports */
#define NB_PCIE_PORT1_DEV 0x2
#define NB_PCIE_PORT2_DEV 0x3
#define NB_PCIE_PORT3_DEV 0x4
#define NB_PCIE_PORT4_DEV 0x5
#define NB_PCIE_PORT5_DEV 0x6
#define NB_PCIE_PORT6_DEV 0x7
#define NB_PCIE_PORT7_DEV 0x8
#define NB_PCIE_FUNC 0
#define NB_PCIE_PORT1_DEVID 0x1412
#define NB_PCIE_PORT2_DEVID 0x1413
#define NB_PCIE_PORT3_DEVID 0x1414
#define NB_PCIE_PORT4_DEVID 0x1415
#define NB_PCIE_PORT5_DEVID 0x1416
#define NB_PCIE_PORT6_DEVID 0x1417
#define NB_PCIE_PORT7_DEVID 0x1418
#define NB_PCIE_PORT1_DEVFN PCI_DEVFN(NB_PCIE_PORT1_DEV, NB_PCIE_FUNC)
#define NB_PCIE_PORT2_DEVFN PCI_DEVFN(NB_PCIE_PORT2_DEV, NB_PCIE_FUNC)
#define NB_PCIE_PORT3_DEVFN PCI_DEVFN(NB_PCIE_PORT3_DEV, NB_PCIE_FUNC)
#define NB_PCIE_PORT4_DEVFN PCI_DEVFN(NB_PCIE_PORT4_DEV, NB_PCIE_FUNC)
#define NB_PCIE_PORT5_DEVFN PCI_DEVFN(NB_PCIE_PORT5_DEV, NB_PCIE_FUNC)
#define NB_PCIE_PORT6_DEVFN PCI_DEVFN(NB_PCIE_PORT6_DEV, NB_PCIE_FUNC)
#define NB_PCIE_PORT7_DEVFN PCI_DEVFN(NB_PCIE_PORT7_DEV, NB_PCIE_FUNC)

#endif /* _AMD_FAM15TN_PCI_DEVS_H_ */