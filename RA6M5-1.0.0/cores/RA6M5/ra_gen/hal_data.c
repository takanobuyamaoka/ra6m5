/* generated HAL source file - do not edit */
#include "hal_data.h"

/* Macros to tie dynamic ELC links to ADC_TRIGGER_SYNC_ELC option in adc_trigger_t. */
#define ADC_TRIGGER_ADC0        ADC_TRIGGER_SYNC_ELC
#define ADC_TRIGGER_ADC0_B      ADC_TRIGGER_SYNC_ELC
#define ADC_TRIGGER_ADC1        ADC_TRIGGER_SYNC_ELC
#define ADC_TRIGGER_ADC1_B      ADC_TRIGGER_SYNC_ELC
icu_instance_ctrl_t g_external_irq5_ctrl;
const external_irq_cfg_t g_external_irq5_cfg = { .channel = 5, .trigger =
		EXTERNAL_IRQ_TRIG_RISING, .filter_enable = true, .pclk_div =
		EXTERNAL_IRQ_PCLK_DIV_BY_64, .p_callback = isr_irq5, .p_context = NULL,
		.p_extend = NULL, .ipl = (12),
#if defined(VECTOR_NUMBER_ICU_IRQ5)
    .irq                 = VECTOR_NUMBER_ICU_IRQ5,
#else
		.irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq5 = { .p_ctrl =
		&g_external_irq5_ctrl, .p_cfg = &g_external_irq5_cfg, .p_api =
		&g_external_irq_on_icu };
icu_instance_ctrl_t g_external_irq4_ctrl;
const external_irq_cfg_t g_external_irq4_cfg = { .channel = 4, .trigger =
		EXTERNAL_IRQ_TRIG_RISING, .filter_enable = true, .pclk_div =
		EXTERNAL_IRQ_PCLK_DIV_BY_64, .p_callback = isr_irq4, .p_context = NULL,
		.p_extend = NULL, .ipl = (12),
#if defined(VECTOR_NUMBER_ICU_IRQ4)
    .irq                 = VECTOR_NUMBER_ICU_IRQ4,
#else
		.irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq4 = { .p_ctrl =
		&g_external_irq4_ctrl, .p_cfg = &g_external_irq4_cfg, .p_api =
		&g_external_irq_on_icu };
icu_instance_ctrl_t g_external_irq14_ctrl;
const external_irq_cfg_t g_external_irq14_cfg = { .channel = 14, .trigger =
		EXTERNAL_IRQ_TRIG_RISING, .filter_enable = true, .pclk_div =
		EXTERNAL_IRQ_PCLK_DIV_BY_64, .p_callback = isr_irq14, .p_context = NULL,
		.p_extend = NULL, .ipl = (12),
#if defined(VECTOR_NUMBER_ICU_IRQ14)
    .irq                 = VECTOR_NUMBER_ICU_IRQ14,
#else
		.irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq14 = { .p_ctrl =
		&g_external_irq14_ctrl, .p_cfg = &g_external_irq14_cfg, .p_api =
		&g_external_irq_on_icu };
icu_instance_ctrl_t g_external_irq11_ctrl;
const external_irq_cfg_t g_external_irq11_cfg = { .channel = 11, .trigger =
		EXTERNAL_IRQ_TRIG_RISING, .filter_enable = true, .pclk_div =
		EXTERNAL_IRQ_PCLK_DIV_BY_64, .p_callback = isr_irq11, .p_context = NULL,
		.p_extend = NULL, .ipl = (12),
#if defined(VECTOR_NUMBER_ICU_IRQ11)
    .irq                 = VECTOR_NUMBER_ICU_IRQ11,
#else
		.irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq11 = { .p_ctrl =
		&g_external_irq11_ctrl, .p_cfg = &g_external_irq11_cfg, .p_api =
		&g_external_irq_on_icu };
flash_hp_instance_ctrl_t g_flash0_ctrl;
const flash_cfg_t g_flash0_cfg = { .data_flash_bgo = false, .p_callback =
		isr_flash, .p_context = NULL,
#if defined(VECTOR_NUMBER_FCU_FRDYI)
    .irq                 = VECTOR_NUMBER_FCU_FRDYI,
#else
		.irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_FCU_FIFERR)
    .err_irq             = VECTOR_NUMBER_FCU_FIFERR,
#else
		.err_irq = FSP_INVALID_VECTOR,
#endif
		.err_ipl = (15), .ipl = (15), };
/* Instance structure to use this module. */
const flash_instance_t g_flash0 = { .p_ctrl = &g_flash0_ctrl, .p_cfg =
		&g_flash0_cfg, .p_api = &g_flash_on_flash_hp };
sci_spi_instance_ctrl_t g_spi9_ctrl;

/** SPI extended configuration */
const sci_spi_extended_cfg_t g_spi9_cfg_extend = { .clk_div = {
/* Actual calculated bitrate: 3571429. */.cks = 0, .brr = 6, .mddr = 0, } };

const spi_cfg_t g_spi9_cfg = { .channel = 9, .operating_mode = SPI_MODE_MASTER,
		.clk_phase = SPI_CLK_PHASE_EDGE_ODD, .clk_polarity =
				SPI_CLK_POLARITY_LOW,
		.mode_fault = SPI_MODE_FAULT_ERROR_DISABLE, .bit_order =
				SPI_BIT_ORDER_MSB_FIRST,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
		.p_transfer_tx = NULL,
#else
    .p_transfer_tx   = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
		.p_transfer_rx = NULL,
#else
    .p_transfer_rx   = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
		.p_callback = sci_spi_callback, .p_context = NULL, .rxi_irq =
				VECTOR_NUMBER_SCI9_RXI, .txi_irq = VECTOR_NUMBER_SCI9_TXI,
		.tei_irq = VECTOR_NUMBER_SCI9_TEI, .eri_irq = VECTOR_NUMBER_SCI9_ERI,
		.rxi_ipl = (12), .txi_ipl = (12), .tei_ipl = (12), .eri_ipl = (12),
		.p_extend = &g_spi9_cfg_extend, };
/* Instance structure to use this module. */
const spi_instance_t g_spi9 = { .p_ctrl = &g_spi9_ctrl, .p_cfg = &g_spi9_cfg,
		.p_api = &g_spi_on_sci };
sci_spi_instance_ctrl_t g_spi5_ctrl;

/** SPI extended configuration */
const sci_spi_extended_cfg_t g_spi5_cfg_extend = { .clk_div = {
/* Actual calculated bitrate: 3571429. */.cks = 0, .brr = 6, .mddr = 0, } };

const spi_cfg_t g_spi5_cfg = { .channel = 5, .operating_mode = SPI_MODE_MASTER,
		.clk_phase = SPI_CLK_PHASE_EDGE_ODD, .clk_polarity =
				SPI_CLK_POLARITY_LOW,
		.mode_fault = SPI_MODE_FAULT_ERROR_DISABLE, .bit_order =
				SPI_BIT_ORDER_MSB_FIRST,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
		.p_transfer_tx = NULL,
#else
    .p_transfer_tx   = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
		.p_transfer_rx = NULL,
#else
    .p_transfer_rx   = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
		.p_callback = sci_spi_callback, .p_context = NULL, .rxi_irq =
				VECTOR_NUMBER_SCI5_RXI, .txi_irq = VECTOR_NUMBER_SCI5_TXI,
		.tei_irq = VECTOR_NUMBER_SCI5_TEI, .eri_irq = VECTOR_NUMBER_SCI5_ERI,
		.rxi_ipl = (12), .txi_ipl = (12), .tei_ipl = (12), .eri_ipl = (12),
		.p_extend = &g_spi5_cfg_extend, };
/* Instance structure to use this module. */
const spi_instance_t g_spi5 = { .p_ctrl = &g_spi5_ctrl, .p_cfg = &g_spi5_cfg,
		.p_api = &g_spi_on_sci };
iic_master_instance_ctrl_t g_i2c_master1_ctrl;
const iic_master_extended_cfg_t g_i2c_master1_extend =
		{ .timeout_mode = IIC_MASTER_TIMEOUT_MODE_SHORT,
				/* Actual calculated bitrate: 98425. Actual calculated duty cycle: 50%. */.clock_settings.brl_value =
						28, .clock_settings.brh_value = 28,
				.clock_settings.cks_value = 3, };
const i2c_master_cfg_t g_i2c_master1_cfg = { .channel = 1, .rate =
		I2C_MASTER_RATE_STANDARD, .slave = 0x00, .addr_mode =
		I2C_MASTER_ADDR_MODE_7BIT,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
		.p_transfer_tx = NULL,
#else
                .p_transfer_tx       = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
		.p_transfer_rx = NULL,
#else
                .p_transfer_rx       = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
		.p_callback = isr_riic1, .p_context = NULL,
#if defined(VECTOR_NUMBER_IIC1_RXI)
    .rxi_irq             = VECTOR_NUMBER_IIC1_RXI,
#else
		.rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC1_TXI)
    .txi_irq             = VECTOR_NUMBER_IIC1_TXI,
#else
		.txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC1_TEI)
    .tei_irq             = VECTOR_NUMBER_IIC1_TEI,
#else
		.tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC1_ERI)
    .eri_irq             = VECTOR_NUMBER_IIC1_ERI,
#else
		.eri_irq = FSP_INVALID_VECTOR,
#endif
		.ipl = (12), .p_extend = &g_i2c_master1_extend, };
/* Instance structure to use this module. */
const i2c_master_instance_t g_i2c_master1 = { .p_ctrl = &g_i2c_master1_ctrl,
		.p_cfg = &g_i2c_master1_cfg, .p_api = &g_i2c_master_on_iic };
gpt_instance_ctrl_t g_timer8_ctrl;
#if 0
const gpt_extended_pwm_cfg_t g_timer8_pwm_extend =
{
    .trough_ipl          = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT8_COUNTER_UNDERFLOW)
    .trough_irq          = VECTOR_NUMBER_GPT8_COUNTER_UNDERFLOW,
#else
    .trough_irq          = FSP_INVALID_VECTOR,
#endif
    .poeg_link           = GPT_POEG_LINK_POEG0,
    .output_disable      =  GPT_OUTPUT_DISABLE_NONE,
    .adc_trigger         =  GPT_ADC_TRIGGER_NONE,
    .dead_time_count_up  = 0,
    .dead_time_count_down = 0,
    .adc_a_compare_match = 0,
    .adc_b_compare_match = 0,
    .interrupt_skip_source = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count  = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc    = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t g_timer8_extend =
		{ .gtioca = { .output_enabled = true, .stop_level = GPT_PIN_LEVEL_LOW },
				.gtiocb = { .output_enabled = false, .stop_level =
						GPT_PIN_LEVEL_LOW }, .start_source = (gpt_source_t)(
						GPT_SOURCE_NONE), .stop_source = (gpt_source_t)(
						GPT_SOURCE_NONE), .clear_source = (gpt_source_t)(
						GPT_SOURCE_NONE), .count_up_source = (gpt_source_t)(
						GPT_SOURCE_NONE), .count_down_source = (gpt_source_t)(
						GPT_SOURCE_NONE), .capture_a_source = (gpt_source_t)(
						GPT_SOURCE_NONE), .capture_b_source = (gpt_source_t)(
						GPT_SOURCE_NONE), .capture_a_ipl = (BSP_IRQ_DISABLED),
				.capture_b_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT8_CAPTURE_COMPARE_A)
    .capture_a_irq       = VECTOR_NUMBER_GPT8_CAPTURE_COMPARE_A,
#else
				.capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT8_CAPTURE_COMPARE_B)
    .capture_b_irq       = VECTOR_NUMBER_GPT8_CAPTURE_COMPARE_B,
#else
				.capture_b_irq = FSP_INVALID_VECTOR,
#endif
				.capture_filter_gtioca = GPT_CAPTURE_FILTER_NONE,
				.capture_filter_gtiocb = GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg                   = &g_timer8_pwm_extend,
#else
				.p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) true,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) false,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
				.gtior_setting.gtior = 0U,
#endif
		};
const timer_cfg_t g_timer8_cfg = { .mode = TIMER_MODE_PWM,
/* Actual period: 0.0010204 seconds. Actual duty: 50%. */.period_counts =
		(uint32_t) 0x63a6, .duty_cycle_counts = 0x31d3, .source_div =
		(timer_source_div_t) 2, .channel = 8, .p_callback = NULL,
/** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
		.p_context = &NULL,
#endif
		.p_extend = &g_timer8_extend, .cycle_end_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT8_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT8_COUNTER_OVERFLOW,
#else
		.cycle_end_irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const timer_instance_t g_timer8 = { .p_ctrl = &g_timer8_ctrl, .p_cfg =
		&g_timer8_cfg, .p_api = &g_timer_on_gpt };
gpt_instance_ctrl_t g_timer7_ctrl;
#if 0
const gpt_extended_pwm_cfg_t g_timer7_pwm_extend =
{
    .trough_ipl          = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT7_COUNTER_UNDERFLOW)
    .trough_irq          = VECTOR_NUMBER_GPT7_COUNTER_UNDERFLOW,
#else
    .trough_irq          = FSP_INVALID_VECTOR,
#endif
    .poeg_link           = GPT_POEG_LINK_POEG0,
    .output_disable      =  GPT_OUTPUT_DISABLE_NONE,
    .adc_trigger         =  GPT_ADC_TRIGGER_NONE,
    .dead_time_count_up  = 0,
    .dead_time_count_down = 0,
    .adc_a_compare_match = 0,
    .adc_b_compare_match = 0,
    .interrupt_skip_source = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count  = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc    = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t g_timer7_extend =
		{
				.gtioca = { .output_enabled = false, .stop_level =
						GPT_PIN_LEVEL_LOW }, .gtiocb = { .output_enabled = true,
						.stop_level = GPT_PIN_LEVEL_LOW }, .start_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .stop_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .clear_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .count_up_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .count_down_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_a_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_b_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_a_ipl =
						(BSP_IRQ_DISABLED), .capture_b_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT7_CAPTURE_COMPARE_A)
    .capture_a_irq       = VECTOR_NUMBER_GPT7_CAPTURE_COMPARE_A,
#else
				.capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT7_CAPTURE_COMPARE_B)
    .capture_b_irq       = VECTOR_NUMBER_GPT7_CAPTURE_COMPARE_B,
#else
				.capture_b_irq = FSP_INVALID_VECTOR,
#endif
				.capture_filter_gtioca = GPT_CAPTURE_FILTER_NONE,
				.capture_filter_gtiocb = GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg                   = &g_timer7_pwm_extend,
#else
				.p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) false,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) true,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
				.gtior_setting.gtior = 0U,
#endif
		};
const timer_cfg_t g_timer7_cfg = { .mode = TIMER_MODE_PWM,
/* Actual period: 0.0000049 seconds. Actual duty: 50%. */.period_counts =
		(uint32_t) 0x1ea, .duty_cycle_counts = 0xf5, .source_div =
		(timer_source_div_t) 0, .channel = 7, .p_callback = NULL,
/** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
		.p_context = &NULL,
#endif
		.p_extend = &g_timer7_extend, .cycle_end_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT7_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT7_COUNTER_OVERFLOW,
#else
		.cycle_end_irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const timer_instance_t g_timer7 = { .p_ctrl = &g_timer7_ctrl, .p_cfg =
		&g_timer7_cfg, .p_api = &g_timer_on_gpt };
gpt_instance_ctrl_t g_timer4_ctrl;
#if 0
const gpt_extended_pwm_cfg_t g_timer4_pwm_extend =
{
    .trough_ipl          = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT4_COUNTER_UNDERFLOW)
    .trough_irq          = VECTOR_NUMBER_GPT4_COUNTER_UNDERFLOW,
#else
    .trough_irq          = FSP_INVALID_VECTOR,
#endif
    .poeg_link           = GPT_POEG_LINK_POEG0,
    .output_disable      =  GPT_OUTPUT_DISABLE_NONE,
    .adc_trigger         =  GPT_ADC_TRIGGER_NONE,
    .dead_time_count_up  = 0,
    .dead_time_count_down = 0,
    .adc_a_compare_match = 0,
    .adc_b_compare_match = 0,
    .interrupt_skip_source = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count  = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc    = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t g_timer4_extend =
		{
				.gtioca = { .output_enabled = false, .stop_level =
						GPT_PIN_LEVEL_LOW }, .gtiocb = { .output_enabled = true,
						.stop_level = GPT_PIN_LEVEL_LOW }, .start_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .stop_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .clear_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .count_up_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .count_down_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_a_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_b_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_a_ipl =
						(BSP_IRQ_DISABLED), .capture_b_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT4_CAPTURE_COMPARE_A)
    .capture_a_irq       = VECTOR_NUMBER_GPT4_CAPTURE_COMPARE_A,
#else
				.capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT4_CAPTURE_COMPARE_B)
    .capture_b_irq       = VECTOR_NUMBER_GPT4_CAPTURE_COMPARE_B,
#else
				.capture_b_irq = FSP_INVALID_VECTOR,
#endif
				.capture_filter_gtioca = GPT_CAPTURE_FILTER_NONE,
				.capture_filter_gtiocb = GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg                   = &g_timer4_pwm_extend,
#else
				.p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) false,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) true,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
				.gtior_setting.gtior = 0U,
#endif
		};
const timer_cfg_t g_timer4_cfg = { .mode = TIMER_MODE_PWM,
/* Actual period: 0.0020408 seconds. Actual duty: 50%. */.period_counts =
		(uint32_t) 0xc74c, .duty_cycle_counts = 0x63a6, .source_div =
		(timer_source_div_t) 2, .channel = 4, .p_callback = NULL,
/** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
		.p_context = &NULL,
#endif
		.p_extend = &g_timer4_extend, .cycle_end_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT4_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT4_COUNTER_OVERFLOW,
#else
		.cycle_end_irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const timer_instance_t g_timer4 = { .p_ctrl = &g_timer4_ctrl, .p_cfg =
		&g_timer4_cfg, .p_api = &g_timer_on_gpt };
gpt_instance_ctrl_t g_timer3_ctrl;
#if 0
const gpt_extended_pwm_cfg_t g_timer3_pwm_extend =
{
    .trough_ipl          = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT3_COUNTER_UNDERFLOW)
    .trough_irq          = VECTOR_NUMBER_GPT3_COUNTER_UNDERFLOW,
#else
    .trough_irq          = FSP_INVALID_VECTOR,
#endif
    .poeg_link           = GPT_POEG_LINK_POEG0,
    .output_disable      =  GPT_OUTPUT_DISABLE_NONE,
    .adc_trigger         =  GPT_ADC_TRIGGER_NONE,
    .dead_time_count_up  = 0,
    .dead_time_count_down = 0,
    .adc_a_compare_match = 0,
    .adc_b_compare_match = 0,
    .interrupt_skip_source = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count  = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc    = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t g_timer3_extend =
		{ .gtioca = { .output_enabled = true, .stop_level = GPT_PIN_LEVEL_LOW },
				.gtiocb = { .output_enabled = false, .stop_level =
						GPT_PIN_LEVEL_LOW }, .start_source = (gpt_source_t)(
						GPT_SOURCE_NONE), .stop_source = (gpt_source_t)(
						GPT_SOURCE_NONE), .clear_source = (gpt_source_t)(
						GPT_SOURCE_NONE), .count_up_source = (gpt_source_t)(
						GPT_SOURCE_NONE), .count_down_source = (gpt_source_t)(
						GPT_SOURCE_NONE), .capture_a_source = (gpt_source_t)(
						GPT_SOURCE_NONE), .capture_b_source = (gpt_source_t)(
						GPT_SOURCE_NONE), .capture_a_ipl = (BSP_IRQ_DISABLED),
				.capture_b_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT3_CAPTURE_COMPARE_A)
    .capture_a_irq       = VECTOR_NUMBER_GPT3_CAPTURE_COMPARE_A,
#else
				.capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT3_CAPTURE_COMPARE_B)
    .capture_b_irq       = VECTOR_NUMBER_GPT3_CAPTURE_COMPARE_B,
#else
				.capture_b_irq = FSP_INVALID_VECTOR,
#endif
				.capture_filter_gtioca = GPT_CAPTURE_FILTER_NONE,
				.capture_filter_gtiocb = GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg                   = &g_timer3_pwm_extend,
#else
				.p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) true,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) false,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
				.gtior_setting.gtior = 0U,
#endif
		};
const timer_cfg_t g_timer3_cfg =
		{ .mode = TIMER_MODE_PWM,
				/* Actual period: 0.00204081 seconds. Actual duty: 49.999754999240494%. */.period_counts =
						(uint32_t) 0x31d31, .duty_cycle_counts = 0x18e98,
				.source_div = (timer_source_div_t) 0, .channel = 3,
				.p_callback = NULL,
				/** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
				.p_context = &NULL,
#endif
				.p_extend = &g_timer3_extend, .cycle_end_ipl =
						(BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT3_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT3_COUNTER_OVERFLOW,
#else
				.cycle_end_irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const timer_instance_t g_timer3 = { .p_ctrl = &g_timer3_ctrl, .p_cfg =
		&g_timer3_cfg, .p_api = &g_timer_on_gpt };
gpt_instance_ctrl_t g_timer2_ctrl;
#if 0
const gpt_extended_pwm_cfg_t g_timer2_pwm_extend =
{
    .trough_ipl          = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT2_COUNTER_UNDERFLOW)
    .trough_irq          = VECTOR_NUMBER_GPT2_COUNTER_UNDERFLOW,
#else
    .trough_irq          = FSP_INVALID_VECTOR,
#endif
    .poeg_link           = GPT_POEG_LINK_POEG0,
    .output_disable      =  GPT_OUTPUT_DISABLE_NONE,
    .adc_trigger         =  GPT_ADC_TRIGGER_NONE,
    .dead_time_count_up  = 0,
    .dead_time_count_down = 0,
    .adc_a_compare_match = 0,
    .adc_b_compare_match = 0,
    .interrupt_skip_source = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count  = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc    = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t g_timer2_extend =
		{
				.gtioca = { .output_enabled = false, .stop_level =
						GPT_PIN_LEVEL_LOW }, .gtiocb = { .output_enabled = true,
						.stop_level = GPT_PIN_LEVEL_LOW }, .start_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .stop_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .clear_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .count_up_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .count_down_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_a_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_b_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_a_ipl =
						(BSP_IRQ_DISABLED), .capture_b_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT2_CAPTURE_COMPARE_A)
    .capture_a_irq       = VECTOR_NUMBER_GPT2_CAPTURE_COMPARE_A,
#else
				.capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT2_CAPTURE_COMPARE_B)
    .capture_b_irq       = VECTOR_NUMBER_GPT2_CAPTURE_COMPARE_B,
#else
				.capture_b_irq = FSP_INVALID_VECTOR,
#endif
				.capture_filter_gtioca = GPT_CAPTURE_FILTER_NONE,
				.capture_filter_gtiocb = GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg                   = &g_timer2_pwm_extend,
#else
				.p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) false,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) true,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
				.gtior_setting.gtior = 0U,
#endif
		};
const timer_cfg_t g_timer2_cfg =
		{ .mode = TIMER_MODE_PWM,
				/* Actual period: 0.00204081 seconds. Actual duty: 49.999754999240494%. */.period_counts =
						(uint32_t) 0x31d31, .duty_cycle_counts = 0x18e98,
				.source_div = (timer_source_div_t) 0, .channel = 2,
				.p_callback = NULL,
				/** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
				.p_context = &NULL,
#endif
				.p_extend = &g_timer2_extend, .cycle_end_ipl =
						(BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT2_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT2_COUNTER_OVERFLOW,
#else
				.cycle_end_irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const timer_instance_t g_timer2 = { .p_ctrl = &g_timer2_ctrl, .p_cfg =
		&g_timer2_cfg, .p_api = &g_timer_on_gpt };
gpt_instance_ctrl_t g_timer1_ctrl;
#if 0
const gpt_extended_pwm_cfg_t g_timer1_pwm_extend =
{
    .trough_ipl          = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT1_COUNTER_UNDERFLOW)
    .trough_irq          = VECTOR_NUMBER_GPT1_COUNTER_UNDERFLOW,
#else
    .trough_irq          = FSP_INVALID_VECTOR,
#endif
    .poeg_link           = GPT_POEG_LINK_POEG0,
    .output_disable      =  GPT_OUTPUT_DISABLE_NONE,
    .adc_trigger         =  GPT_ADC_TRIGGER_NONE,
    .dead_time_count_up  = 0,
    .dead_time_count_down = 0,
    .adc_a_compare_match = 0,
    .adc_b_compare_match = 0,
    .interrupt_skip_source = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count  = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc    = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t g_timer1_extend =
		{
				.gtioca = { .output_enabled = false, .stop_level =
						GPT_PIN_LEVEL_LOW }, .gtiocb = { .output_enabled = true,
						.stop_level = GPT_PIN_LEVEL_LOW }, .start_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .stop_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .clear_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .count_up_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .count_down_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_a_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_b_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_a_ipl =
						(BSP_IRQ_DISABLED), .capture_b_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT1_CAPTURE_COMPARE_A)
    .capture_a_irq       = VECTOR_NUMBER_GPT1_CAPTURE_COMPARE_A,
#else
				.capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT1_CAPTURE_COMPARE_B)
    .capture_b_irq       = VECTOR_NUMBER_GPT1_CAPTURE_COMPARE_B,
#else
				.capture_b_irq = FSP_INVALID_VECTOR,
#endif
				.capture_filter_gtioca = GPT_CAPTURE_FILTER_NONE,
				.capture_filter_gtiocb = GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg                   = &g_timer1_pwm_extend,
#else
				.p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) false,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) true,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
				.gtior_setting.gtior = 0U,
#endif
		};
const timer_cfg_t g_timer1_cfg = { .mode = TIMER_MODE_PWM,
/* Actual period: 0.0010204 seconds. Actual duty: 50%. */.period_counts =
		(uint32_t) 0x18e98, .duty_cycle_counts = 0xc74c, .source_div =
		(timer_source_div_t) 0, .channel = 1, .p_callback = NULL,
/** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
		.p_context = &NULL,
#endif
		.p_extend = &g_timer1_extend, .cycle_end_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT1_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT1_COUNTER_OVERFLOW,
#else
		.cycle_end_irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const timer_instance_t g_timer1 = { .p_ctrl = &g_timer1_ctrl, .p_cfg =
		&g_timer1_cfg, .p_api = &g_timer_on_gpt };
gpt_instance_ctrl_t g_timer0_ctrl;
#if 0
const gpt_extended_pwm_cfg_t g_timer0_pwm_extend =
{
    .trough_ipl          = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT0_COUNTER_UNDERFLOW)
    .trough_irq          = VECTOR_NUMBER_GPT0_COUNTER_UNDERFLOW,
#else
    .trough_irq          = FSP_INVALID_VECTOR,
#endif
    .poeg_link           = GPT_POEG_LINK_POEG0,
    .output_disable      =  GPT_OUTPUT_DISABLE_NONE,
    .adc_trigger         =  GPT_ADC_TRIGGER_NONE,
    .dead_time_count_up  = 0,
    .dead_time_count_down = 0,
    .adc_a_compare_match = 0,
    .adc_b_compare_match = 0,
    .interrupt_skip_source = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count  = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc    = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t g_timer0_extend =
		{
				.gtioca = { .output_enabled = false, .stop_level =
						GPT_PIN_LEVEL_LOW }, .gtiocb =
						{ .output_enabled = false, .stop_level =
								GPT_PIN_LEVEL_LOW }, .start_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .stop_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .clear_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .count_up_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .count_down_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_a_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_b_source =
						(gpt_source_t)(GPT_SOURCE_NONE), .capture_a_ipl =
						(BSP_IRQ_DISABLED), .capture_b_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT0_CAPTURE_COMPARE_A)
    .capture_a_irq       = VECTOR_NUMBER_GPT0_CAPTURE_COMPARE_A,
#else
				.capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT0_CAPTURE_COMPARE_B)
    .capture_b_irq       = VECTOR_NUMBER_GPT0_CAPTURE_COMPARE_B,
#else
				.capture_b_irq = FSP_INVALID_VECTOR,
#endif
				.capture_filter_gtioca = GPT_CAPTURE_FILTER_NONE,
				.capture_filter_gtiocb = GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg                   = &g_timer0_pwm_extend,
#else
				.p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) false,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) false,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
				.gtior_setting.gtior = 0U,
#endif
		};
const timer_cfg_t g_timer0_cfg = { .mode = TIMER_MODE_PERIODIC,
/* Actual period: 0.001 seconds. Actual duty: 50%. */.period_counts =
		(uint32_t) 0x186a0, .duty_cycle_counts = 0xc350, .source_div =
		(timer_source_div_t) 0, .channel = 0, .p_callback = isr_gpt0,
/** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
		.p_context = &NULL,
#endif
		.p_extend = &g_timer0_extend, .cycle_end_ipl = (15),
#if defined(VECTOR_NUMBER_GPT0_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT0_COUNTER_OVERFLOW,
#else
		.cycle_end_irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const timer_instance_t g_timer0 = { .p_ctrl = &g_timer0_ctrl, .p_cfg =
		&g_timer0_cfg, .p_api = &g_timer_on_gpt };
dtc_instance_ctrl_t g_transfer0_ctrl;

transfer_info_t g_transfer0_info = { .dest_addr_mode =
		TRANSFER_ADDR_MODE_INCREMENTED, .repeat_area =
		TRANSFER_REPEAT_AREA_DESTINATION, .irq = TRANSFER_IRQ_END, .chain_mode =
		TRANSFER_CHAIN_MODE_DISABLED, .src_addr_mode = TRANSFER_ADDR_MODE_FIXED,
		.size = TRANSFER_SIZE_1_BYTE, .mode = TRANSFER_MODE_NORMAL, .p_dest =
				(void*) NULL, .p_src = (void const*) NULL, .num_blocks = 0,
		.length = 0, };
const dtc_extended_cfg_t g_transfer0_cfg_extend = { .activation_source =
		VECTOR_NUMBER_SCI7_RXI, };
const transfer_cfg_t g_transfer0_cfg = { .p_info = &g_transfer0_info,
		.p_extend = &g_transfer0_cfg_extend, };

/* Instance structure to use this module. */
const transfer_instance_t g_transfer0 = { .p_ctrl = &g_transfer0_ctrl, .p_cfg =
		&g_transfer0_cfg, .p_api = &g_transfer_on_dtc };
sci_uart_instance_ctrl_t g_uart7_ctrl;

baud_setting_t g_uart7_baud_setting = {
/* Baud rate calculated with 0.014% error. */.abcse = 0, .abcs = 0, .bgdm = 1,
		.cks = 0, .brr = 38, .mddr = (uint8_t) 184, .brme = true };

/** UART extended configuration for UARTonSCI HAL driver */
const sci_uart_extended_cfg_t g_uart7_cfg_extend = {
		.clock = SCI_UART_CLOCK_INT, .rx_edge_start =
				SCI_UART_START_BIT_FALLING_EDGE, .noise_cancel =
				SCI_UART_NOISE_CANCELLATION_DISABLE, .rx_fifo_trigger =
				SCI_UART_RX_FIFO_TRIGGER_MAX, .p_baud_setting =
				&g_uart7_baud_setting,
		.flow_control = SCI_UART_FLOW_CONTROL_RTS,
#if 0xFF != 0xFF
                .flow_control_pin       = BSP_IO_PORT_FF_PIN_0xFF,
                #else
		.flow_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
#endif
		};

/** UART interface configuration */
const uart_cfg_t g_uart7_cfg = { .channel = 7, .data_bits = UART_DATA_BITS_8,
		.parity = UART_PARITY_OFF, .stop_bits = UART_STOP_BITS_1, .p_callback =
				user_uart_callback, .p_context = NULL, .p_extend =
				&g_uart7_cfg_extend,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
		.p_transfer_tx = NULL,
#else
                .p_transfer_tx       = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == g_transfer0)
                .p_transfer_rx       = NULL,
#else
		.p_transfer_rx = &g_transfer0,
#endif
#undef RA_NOT_DEFINED
		.rxi_ipl = (12), .txi_ipl = (12), .tei_ipl = (12), .eri_ipl = (12),
#if defined(VECTOR_NUMBER_SCI7_RXI)
                .rxi_irq             = VECTOR_NUMBER_SCI7_RXI,
#else
		.rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI7_TXI)
                .txi_irq             = VECTOR_NUMBER_SCI7_TXI,
#else
		.txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI7_TEI)
                .tei_irq             = VECTOR_NUMBER_SCI7_TEI,
#else
		.tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI7_ERI)
                .eri_irq             = VECTOR_NUMBER_SCI7_ERI,
#else
		.eri_irq = FSP_INVALID_VECTOR,
#endif
		};

/* Instance structure to use this module. */
const uart_instance_t g_uart7 = { .p_ctrl = &g_uart7_ctrl,
		.p_cfg = &g_uart7_cfg, .p_api = &g_uart_on_sci };
adc_instance_ctrl_t g_adc0_ctrl;
const adc_extended_cfg_t g_adc0_cfg_extend = { .add_average_count = ADC_ADD_OFF,
		.clearing = ADC_CLEAR_AFTER_READ_ON, .trigger_group_b =
				ADC_TRIGGER_SYNC_ELC, .double_trigger_mode =
				ADC_DOUBLE_TRIGGER_DISABLED, .adc_vref_control =
				ADC_VREF_CONTROL_VREFH, .enable_adbuf = 0, };
const adc_cfg_t g_adc0_cfg = { .unit = 0, .mode = ADC_MODE_SINGLE_SCAN,
		.resolution = ADC_RESOLUTION_12_BIT, .alignment =
				(adc_alignment_t) ADC_ALIGNMENT_RIGHT, .trigger =
				ADC_TRIGGER_SOFTWARE, .p_callback = NULL, .p_context = NULL,
		.p_extend = &g_adc0_cfg_extend,
#if defined(VECTOR_NUMBER_ADC0_SCAN_END)
    .scan_end_irq        = VECTOR_NUMBER_ADC0_SCAN_END,
#else
		.scan_end_irq = FSP_INVALID_VECTOR,
#endif
		.scan_end_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_ADC0_SCAN_END_B)
    .scan_end_b_irq      = VECTOR_NUMBER_ADC0_SCAN_END_B,
#else
		.scan_end_b_irq = FSP_INVALID_VECTOR,
#endif
		.scan_end_b_ipl = (BSP_IRQ_DISABLED), };
const adc_channel_cfg_t g_adc0_channel_cfg = { .scan_mask = ADC_MASK_CHANNEL_0
		| ADC_MASK_CHANNEL_1 | ADC_MASK_CHANNEL_2 | ADC_MASK_CHANNEL_3
		| ADC_MASK_CHANNEL_12 | ADC_MASK_CHANNEL_13 | 0, .scan_mask_group_b = 0,
		.priority_group_a = ADC_GROUP_A_PRIORITY_OFF, .add_mask = 0,
		.sample_hold_mask = 0, .sample_hold_states = 24, };
/* Instance structure to use this module. */
const adc_instance_t g_adc0 = { .p_ctrl = &g_adc0_ctrl, .p_cfg = &g_adc0_cfg,
		.p_channel_cfg = &g_adc0_channel_cfg, .p_api = &g_adc_on_adc };
void g_hal_init(void) {
	g_common_init();
}
