/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (31)
#endif
/* ISR prototypes */
void ether_eint_isr(void);
void sci_uart_rxi_isr(void);
void sci_uart_txi_isr(void);
void sci_uart_tei_isr(void);
void sci_uart_eri_isr(void);
void gpt_counter_overflow_isr(void);
void iic_master_rxi_isr(void);
void iic_master_txi_isr(void);
void iic_master_tei_isr(void);
void iic_master_eri_isr(void);
void sci_spi_rxi_isr(void);
void sci_spi_txi_isr(void);
void sci_spi_tei_isr(void);
void sci_spi_eri_isr(void);
void fcu_frdyi_isr(void);
void fcu_fiferr_isr(void);
void r_icu_isr(void);
void usbfs_interrupt_handler(void);
void usbfs_resume_handler(void);
void usbfs_d0fifo_handler(void);
void usbfs_d1fifo_handler(void);
void usbhs_interrupt_handler(void);
void usbhs_d0fifo_handler(void);
void usbhs_d1fifo_handler(void);

/* Vector table allocations */
#define VECTOR_NUMBER_EDMAC0_EINT ((IRQn_Type) 0) /* EDMAC0 EINT (EDMAC 0 interrupt) */
#define VECTOR_NUMBER_SCI7_RXI ((IRQn_Type) 1) /* SCI7 RXI (Received data full) */
#define VECTOR_NUMBER_SCI7_TXI ((IRQn_Type) 2) /* SCI7 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI7_TEI ((IRQn_Type) 3) /* SCI7 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI7_ERI ((IRQn_Type) 4) /* SCI7 ERI (Receive error) */
#define VECTOR_NUMBER_GPT0_COUNTER_OVERFLOW ((IRQn_Type) 5) /* GPT0 COUNTER OVERFLOW (Overflow) */
#define VECTOR_NUMBER_IIC1_RXI ((IRQn_Type) 6) /* IIC1 RXI (Receive data full) */
#define VECTOR_NUMBER_IIC1_TXI ((IRQn_Type) 7) /* IIC1 TXI (Transmit data empty) */
#define VECTOR_NUMBER_IIC1_TEI ((IRQn_Type) 8) /* IIC1 TEI (Transmit end) */
#define VECTOR_NUMBER_IIC1_ERI ((IRQn_Type) 9) /* IIC1 ERI (Transfer error) */
#define VECTOR_NUMBER_SCI5_RXI ((IRQn_Type) 10) /* SCI5 RXI (Received data full) */
#define VECTOR_NUMBER_SCI5_TXI ((IRQn_Type) 11) /* SCI5 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI5_TEI ((IRQn_Type) 12) /* SCI5 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI5_ERI ((IRQn_Type) 13) /* SCI5 ERI (Receive error) */
#define VECTOR_NUMBER_SCI9_RXI ((IRQn_Type) 14) /* SCI9 RXI (Received data full) */
#define VECTOR_NUMBER_SCI9_TXI ((IRQn_Type) 15) /* SCI9 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI9_TEI ((IRQn_Type) 16) /* SCI9 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI9_ERI ((IRQn_Type) 17) /* SCI9 ERI (Receive error) */
#define VECTOR_NUMBER_FCU_FRDYI ((IRQn_Type) 18) /* FCU FRDYI (Flash ready interrupt) */
#define VECTOR_NUMBER_FCU_FIFERR ((IRQn_Type) 19) /* FCU FIFERR (Flash access error interrupt) */
#define VECTOR_NUMBER_ICU_IRQ11 ((IRQn_Type) 20) /* ICU IRQ11 (External pin interrupt 11) */
#define VECTOR_NUMBER_ICU_IRQ14 ((IRQn_Type) 21) /* ICU IRQ14 (External pin interrupt 14) */
#define VECTOR_NUMBER_ICU_IRQ4 ((IRQn_Type) 22) /* ICU IRQ4 (External pin interrupt 4) */
#define VECTOR_NUMBER_ICU_IRQ5 ((IRQn_Type) 23) /* ICU IRQ5 (External pin interrupt 5) */
#define VECTOR_NUMBER_USBFS_INT ((IRQn_Type) 24) /* USBFS INT (USBFS interrupt) */
#define VECTOR_NUMBER_USBFS_RESUME ((IRQn_Type) 25) /* USBFS RESUME (USBFS resume interrupt) */
#define VECTOR_NUMBER_USBFS_FIFO_0 ((IRQn_Type) 26) /* USBFS FIFO 0 (DMA transfer request 0) */
#define VECTOR_NUMBER_USBFS_FIFO_1 ((IRQn_Type) 27) /* USBFS FIFO 1 (DMA transfer request 1) */
#define VECTOR_NUMBER_USBHS_USB_INT_RESUME ((IRQn_Type) 28) /* USBHS USB INT RESUME (USBHS interrupt) */
#define VECTOR_NUMBER_USBHS_FIFO_0 ((IRQn_Type) 29) /* USBHS FIFO 0 (DMA transfer request 0) */
#define VECTOR_NUMBER_USBHS_FIFO_1 ((IRQn_Type) 30) /* USBHS FIFO 1 (DMA transfer request 1) */
typedef enum IRQn {
	Reset_IRQn = -15,
	NonMaskableInt_IRQn = -14,
	HardFault_IRQn = -13,
	MemoryManagement_IRQn = -12,
	BusFault_IRQn = -11,
	UsageFault_IRQn = -10,
	SecureFault_IRQn = -9,
	SVCall_IRQn = -5,
	DebugMonitor_IRQn = -4,
	PendSV_IRQn = -2,
	SysTick_IRQn = -1,
	EDMAC0_EINT_IRQn = 0, /* EDMAC0 EINT (EDMAC 0 interrupt) */
	SCI7_RXI_IRQn = 1, /* SCI7 RXI (Received data full) */
	SCI7_TXI_IRQn = 2, /* SCI7 TXI (Transmit data empty) */
	SCI7_TEI_IRQn = 3, /* SCI7 TEI (Transmit end) */
	SCI7_ERI_IRQn = 4, /* SCI7 ERI (Receive error) */
	GPT0_COUNTER_OVERFLOW_IRQn = 5, /* GPT0 COUNTER OVERFLOW (Overflow) */
	IIC1_RXI_IRQn = 6, /* IIC1 RXI (Receive data full) */
	IIC1_TXI_IRQn = 7, /* IIC1 TXI (Transmit data empty) */
	IIC1_TEI_IRQn = 8, /* IIC1 TEI (Transmit end) */
	IIC1_ERI_IRQn = 9, /* IIC1 ERI (Transfer error) */
	SCI5_RXI_IRQn = 10, /* SCI5 RXI (Received data full) */
	SCI5_TXI_IRQn = 11, /* SCI5 TXI (Transmit data empty) */
	SCI5_TEI_IRQn = 12, /* SCI5 TEI (Transmit end) */
	SCI5_ERI_IRQn = 13, /* SCI5 ERI (Receive error) */
	SCI9_RXI_IRQn = 14, /* SCI9 RXI (Received data full) */
	SCI9_TXI_IRQn = 15, /* SCI9 TXI (Transmit data empty) */
	SCI9_TEI_IRQn = 16, /* SCI9 TEI (Transmit end) */
	SCI9_ERI_IRQn = 17, /* SCI9 ERI (Receive error) */
	FCU_FRDYI_IRQn = 18, /* FCU FRDYI (Flash ready interrupt) */
	FCU_FIFERR_IRQn = 19, /* FCU FIFERR (Flash access error interrupt) */
	ICU_IRQ11_IRQn = 20, /* ICU IRQ11 (External pin interrupt 11) */
	ICU_IRQ14_IRQn = 21, /* ICU IRQ14 (External pin interrupt 14) */
	ICU_IRQ4_IRQn = 22, /* ICU IRQ4 (External pin interrupt 4) */
	ICU_IRQ5_IRQn = 23, /* ICU IRQ5 (External pin interrupt 5) */
	USBFS_INT_IRQn = 24, /* USBFS INT (USBFS interrupt) */
	USBFS_RESUME_IRQn = 25, /* USBFS RESUME (USBFS resume interrupt) */
	USBFS_FIFO_0_IRQn = 26, /* USBFS FIFO 0 (DMA transfer request 0) */
	USBFS_FIFO_1_IRQn = 27, /* USBFS FIFO 1 (DMA transfer request 1) */
	USBHS_USB_INT_RESUME_IRQn = 28, /* USBHS USB INT RESUME (USBHS interrupt) */
	USBHS_FIFO_0_IRQn = 29, /* USBHS FIFO 0 (DMA transfer request 0) */
	USBHS_FIFO_1_IRQn = 30, /* USBHS FIFO 1 (DMA transfer request 1) */
} IRQn_Type;
#endif /* VECTOR_DATA_H */
