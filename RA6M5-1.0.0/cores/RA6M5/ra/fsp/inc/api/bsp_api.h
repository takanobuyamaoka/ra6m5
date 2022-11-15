/***********************************************************************************************************************
 * Copyright [2020-2021] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics America Inc. and may only be used with products
 * of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.  Renesas products are
 * sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for the selection and use
 * of Renesas products and Renesas assumes no liability.  No license, express or implied, to any intellectual property
 * right is granted by Renesas. This software is protected under all applicable laws, including copyright laws. Renesas
 * reserves the right to change or discontinue this software and/or this documentation. THE SOFTWARE AND DOCUMENTATION
 * IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND TO THE FULLEST EXTENT
 * PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY, INCLUDING WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE SOFTWARE OR
 * DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.  TO THE MAXIMUM
 * EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR DOCUMENTATION
 * (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER, INCLUDING,
 * WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY LOST PROFITS,
 * OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE POSSIBILITY
 * OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

#ifndef BSP_API_H
#define BSP_API_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/* FSP Common Includes. */
#include "fsp_common_api.h"

/* Gets MCU configuration information. */
#include "bsp_cfg.h"

#if defined(__GNUC__) && !defined(__ARMCC_VERSION)

/* CMSIS-CORE currently generates 2 warnings when compiling with GCC. One in core_cmInstr.h and one in core_cm4_simd.h.
 * We are not modifying these files so we will ignore these warnings temporarily. */
 #pragma GCC diagnostic ignored "-Wconversion"
 #pragma GCC diagnostic ignored "-Wsign-conversion"
#endif

/* Vector information for this project. This is generated by the tooling. */
#include "vector_data.h"

/* CMSIS-CORE Renesas Device Files. Must come after bsp_feature.h, which is included in bsp_cfg.h. */
#include "../../src/bsp/cmsis/Device/RENESAS/Include/renesas.h"
#include "../../src/bsp/cmsis/Device/RENESAS/Include/system.h"

#if defined(__GNUC__) && !defined(__ARMCC_VERSION)

/* Restore warning settings for 'conversion' and 'sign-conversion' to as specified on command line. */
 #pragma GCC diagnostic pop
#endif

/* BSP Common Includes. */
#include "../../src/bsp/mcu/all/bsp_common.h"

/* BSP MCU Specific Includes. */
#include "../../src/bsp/mcu/all/bsp_register_protection.h"
#include "../../src/bsp/mcu/all/bsp_irq.h"
#include "../../src/bsp/mcu/all/bsp_io.h"
#include "../../src/bsp/mcu/all/bsp_group_irq.h"
#include "../../src/bsp/mcu/all/bsp_clocks.h"
#include "../../src/bsp/mcu/all/bsp_module_stop.h"
#include "../../src/bsp/mcu/all/bsp_security.h"

/* Factory MCU information. */
#include "../../inc/fsp_features.h"

/* BSP Common Includes (Other than bsp_common.h) */
#include "../../src/bsp/mcu/all/bsp_delay.h"
#include "../../src/bsp/mcu/all/bsp_mcu_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

fsp_err_t R_FSP_VersionGet(fsp_pack_version_t * const p_version);

/** @} (end addtogroup BSP_MCU) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
