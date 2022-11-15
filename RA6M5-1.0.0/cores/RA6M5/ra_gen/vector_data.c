/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = ether_eint_isr, /* EDMAC0 EINT (EDMAC 0 interrupt) */
            [1] = sci_uart_rxi_isr, /* SCI7 RXI (Received data full) */
            [2] = sci_uart_txi_isr, /* SCI7 TXI (Transmit data empty) */
            [3] = sci_uart_tei_isr, /* SCI7 TEI (Transmit end) */
            [4] = sci_uart_eri_isr, /* SCI7 ERI (Receive error) */
            [5] = gpt_counter_overflow_isr, /* GPT0 COUNTER OVERFLOW (Overflow) */
            [6] = iic_master_rxi_isr, /* IIC1 RXI (Receive data full) */
            [7] = iic_master_txi_isr, /* IIC1 TXI (Transmit data empty) */
            [8] = iic_master_tei_isr, /* IIC1 TEI (Transmit end) */
            [9] = iic_master_eri_isr, /* IIC1 ERI (Transfer error) */
            [10] = sci_spi_rxi_isr, /* SCI5 RXI (Received data full) */
            [11] = sci_spi_txi_isr, /* SCI5 TXI (Transmit data empty) */
            [12] = sci_spi_tei_isr, /* SCI5 TEI (Transmit end) */
            [13] = sci_spi_eri_isr, /* SCI5 ERI (Receive error) */
            [14] = sci_spi_rxi_isr, /* SCI9 RXI (Received data full) */
            [15] = sci_spi_txi_isr, /* SCI9 TXI (Transmit data empty) */
            [16] = sci_spi_tei_isr, /* SCI9 TEI (Transmit end) */
            [17] = sci_spi_eri_isr, /* SCI9 ERI (Receive error) */
            [18] = fcu_frdyi_isr, /* FCU FRDYI (Flash ready interrupt) */
            [19] = fcu_fiferr_isr, /* FCU FIFERR (Flash access error interrupt) */
            [20] = r_icu_isr, /* ICU IRQ11 (External pin interrupt 11) */
            [21] = r_icu_isr, /* ICU IRQ14 (External pin interrupt 14) */
            [22] = r_icu_isr, /* ICU IRQ4 (External pin interrupt 4) */
            [23] = r_icu_isr, /* ICU IRQ5 (External pin interrupt 5) */
            [24] = usbfs_interrupt_handler, /* USBFS INT (USBFS interrupt) */
            [25] = usbfs_resume_handler, /* USBFS RESUME (USBFS resume interrupt) */
            [26] = usbfs_d0fifo_handler, /* USBFS FIFO 0 (DMA transfer request 0) */
            [27] = usbfs_d1fifo_handler, /* USBFS FIFO 1 (DMA transfer request 1) */
            [28] = usbhs_interrupt_handler, /* USBHS USB INT RESUME (USBHS interrupt) */
            [29] = usbhs_d0fifo_handler, /* USBHS FIFO 0 (DMA transfer request 0) */
            [30] = usbhs_d1fifo_handler, /* USBHS FIFO 1 (DMA transfer request 1) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_IELS_ENUM(EVENT_EDMAC0_EINT), /* EDMAC0 EINT (EDMAC 0 interrupt) */
            [1] = BSP_PRV_IELS_ENUM(EVENT_SCI7_RXI), /* SCI7 RXI (Received data full) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_SCI7_TXI), /* SCI7 TXI (Transmit data empty) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_SCI7_TEI), /* SCI7 TEI (Transmit end) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_SCI7_ERI), /* SCI7 ERI (Receive error) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_GPT0_COUNTER_OVERFLOW), /* GPT0 COUNTER OVERFLOW (Overflow) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_IIC1_RXI), /* IIC1 RXI (Receive data full) */
            [7] = BSP_PRV_IELS_ENUM(EVENT_IIC1_TXI), /* IIC1 TXI (Transmit data empty) */
            [8] = BSP_PRV_IELS_ENUM(EVENT_IIC1_TEI), /* IIC1 TEI (Transmit end) */
            [9] = BSP_PRV_IELS_ENUM(EVENT_IIC1_ERI), /* IIC1 ERI (Transfer error) */
            [10] = BSP_PRV_IELS_ENUM(EVENT_SCI5_RXI), /* SCI5 RXI (Received data full) */
            [11] = BSP_PRV_IELS_ENUM(EVENT_SCI5_TXI), /* SCI5 TXI (Transmit data empty) */
            [12] = BSP_PRV_IELS_ENUM(EVENT_SCI5_TEI), /* SCI5 TEI (Transmit end) */
            [13] = BSP_PRV_IELS_ENUM(EVENT_SCI5_ERI), /* SCI5 ERI (Receive error) */
            [14] = BSP_PRV_IELS_ENUM(EVENT_SCI9_RXI), /* SCI9 RXI (Received data full) */
            [15] = BSP_PRV_IELS_ENUM(EVENT_SCI9_TXI), /* SCI9 TXI (Transmit data empty) */
            [16] = BSP_PRV_IELS_ENUM(EVENT_SCI9_TEI), /* SCI9 TEI (Transmit end) */
            [17] = BSP_PRV_IELS_ENUM(EVENT_SCI9_ERI), /* SCI9 ERI (Receive error) */
            [18] = BSP_PRV_IELS_ENUM(EVENT_FCU_FRDYI), /* FCU FRDYI (Flash ready interrupt) */
            [19] = BSP_PRV_IELS_ENUM(EVENT_FCU_FIFERR), /* FCU FIFERR (Flash access error interrupt) */
            [20] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ11), /* ICU IRQ11 (External pin interrupt 11) */
            [21] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ14), /* ICU IRQ14 (External pin interrupt 14) */
            [22] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ4), /* ICU IRQ4 (External pin interrupt 4) */
            [23] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ5), /* ICU IRQ5 (External pin interrupt 5) */
            [24] = BSP_PRV_IELS_ENUM(EVENT_USBFS_INT), /* USBFS INT (USBFS interrupt) */
            [25] = BSP_PRV_IELS_ENUM(EVENT_USBFS_RESUME), /* USBFS RESUME (USBFS resume interrupt) */
            [26] = BSP_PRV_IELS_ENUM(EVENT_USBFS_FIFO_0), /* USBFS FIFO 0 (DMA transfer request 0) */
            [27] = BSP_PRV_IELS_ENUM(EVENT_USBFS_FIFO_1), /* USBFS FIFO 1 (DMA transfer request 1) */
            [28] = BSP_PRV_IELS_ENUM(EVENT_USBHS_USB_INT_RESUME), /* USBHS USB INT RESUME (USBHS interrupt) */
            [29] = BSP_PRV_IELS_ENUM(EVENT_USBHS_FIFO_0), /* USBHS FIFO 0 (DMA transfer request 0) */
            [30] = BSP_PRV_IELS_ENUM(EVENT_USBHS_FIFO_1), /* USBHS FIFO 1 (DMA transfer request 1) */
        };
        #endif
