/* This files provides address values that exist in the system */

#define BOARD                 "DE1-SoC"

/* Memory */
#define DDR_BASE              0x00000000
#define DDR_END               0x3FFFFFFF
#define A9_ONCHIP_BASE        0xFFFF0000
#define A9_ONCHIP_END         0xFFFFFFFF
#define SDRAM_BASE            0xC0000000
#define SDRAM_END             0xC3FFFFFF
#define FPGA_ONCHIP_BASE      0xC8000000
#define FPGA_ONCHIP_END       0xC803FFFF
#define FPGA_CHAR_BASE        0xC9000000
#define FPGA_CHAR_END         0xC9001FFF

/* Cyclone V FPGA devices */
#define LEDR_BASE             0xFF200000
#define HEX3_HEX0_BASE        0xFF200020
#define HEX5_HEX4_BASE        0xFF200030
#define SW_BASE               0xFF200040
#define KEY_BASE              0xFF200050
#define JP1_BASE              0xFF200060
#define JP2_BASE              0xFF200070
#define PS2_BASE              0xFF200100
#define PS2_DUAL_BASE         0xFF200108
#define JTAG_UART_BASE        0xFF201000
#define JTAG_UART_2_BASE      0xFF201008
#define IrDA_BASE             0xFF201020
#define TIMER_BASE            0xFF202000
#define TIMER_2_BASE          0xFF202020
#define AV_CONFIG_BASE        0xFF203000
#define PIXEL_BUF_CTRL_BASE   0xFF203020
#define CHAR_BUF_CTRL_BASE    0xFF203030
#define AUDIO_BASE            0xFF203040
#define VIDEO_IN_BASE         0xFF203060
#define ADC_BASE              0xFF204000

/* Cyclone V HPS devices */
#define HPS_GPIO1_BASE        0xFF709000
#define HPS_TIMER0_BASE       0xFFC08000
#define HPS_TIMER1_BASE       0xFFC09000
#define HPS_TIMER2_BASE       0xFFD00000
#define HPS_TIMER3_BASE       0xFFD01000
#define FPGA_BRIDGE           0xFFD0501C

/* ARM A9 MPCORE devices */
#define   PERIPH_BASE         0xFFFEC000    // base address of peripheral devices
#define   MPCORE_PRIV_TIMER   0xFFFEC600    // PERIPH_BASE + 0x0600

/* Interrupt controller (GIC) CPU interface(s) */
#define MPCORE_GIC_CPUIF      0xFFFEC100    // PERIPH_BASE + 0x100
#define ICCICR                0x00          // offset to CPU interface control reg
#define ICCPMR                0x04          // offset to interrupt priority mask reg
#define ICCIAR                0x0C          // offset to interrupt acknowledge reg
#define ICCEOIR               0x10          // offset to end of interrupt reg
/* Interrupt controller (GIC) distributor interface(s) */
#define MPCORE_GIC_DIST       0xFFFED000    // PERIPH_BASE + 0x1000
#define ICDDCR                0x00          // offset to distributor control reg
#define ICDISER               0x100         // offset to interrupt set-enable regs
#define ICDICER               0x180         // offset to interrupt clear-enable regs
#define ICDIPTR               0x800         // offset to interrupt processor targets regs
#define ICDICFR               0xC00         // offset to interrupt configuration regs

#define CPU0			0x01
#define PRIV_TIMER_ID	29
#define PST_ID			79

#define RES_X	320
#define RES_Y	240
#define BLACK	0x0000
#define GREEN	0x07E0
#define RED		0xF800
#define WHITE	0xFFFF

#define ser_offset(N) ((N >> 5) << 2)
#define ser_value(N) (1 << (N & 0b11111))
#define ptr_offset(N) ((N >> 2) << 2)
#define ptr_index(N) (N & 0b11)

#define USER_L			15
#define L_ENEMY_L		12
#define M_ENEMY_L		11
#define S_ENEMY_L		8
#define OBJECT_L		16
#define OBJECT_W		8
#define BULLET_W		4

#define L_ENEMY_SCORE	1
#define M_ENEMY_SCORE	2
#define S_ENEMY_SCORE	5

#define BASE_TIME		150000000

#define BULLET_NUM		5

volatile int* gic_cpuif = 		(int*)MPCORE_GIC_CPUIF; 
volatile int* gic_dist = 		(int*)MPCORE_GIC_DIST; 
volatile int* iccpmr_addr = 	(int*)(MPCORE_GIC_CPUIF + ICCPMR); 
volatile int* pix_buf_ctrl = 	(int*)PIXEL_BUF_CTRL_BASE; 
volatile int  pix_buf_start; 
volatile int* ps2_data = 		(int*)PS2_BASE; 
volatile int* ledr_data = 		(int*)LEDR_BASE; 
volatile int* priv_timer_load = (int*)MPCORE_PRIV_TIMER; 			// f = 200MHz
volatile int* icciar_addr = 	(int*)(MPCORE_GIC_CPUIF + ICCIAR); 
volatile int* icceoir_addr = 	(int*)(MPCORE_GIC_CPUIF + ICCEOIR); 

// for pixel letters & numbers
volatile int Text_Pixel[37][7][7] = {
	{
		// A
		{0, 0, 1, 1, 1, 1, 1}, 
		{0, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 0, 1, 0, 0, 0}, 
		{1, 1, 0, 1, 0, 0, 0}, 
		{0, 1, 1, 1, 1, 1, 1}, 
		{0, 0, 1, 1, 1, 1, 1}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// B
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 0, 0, 1, 0, 0, 1}, 
		{1, 0, 0, 1, 0, 0, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{0, 1, 1, 0, 1, 1, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// C
		{0, 1, 1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 0, 1, 1},
		{0, 1, 0, 0, 0, 1, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// D
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 0, 0, 0, 0, 0, 1}, 
		{1, 1, 0, 0, 0, 1, 1}, 
		{0, 1, 1, 1, 1, 1, 0}, 
		{0, 0, 1, 1, 1, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// E
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 0, 0, 1, 0, 0, 1}, 
		{1, 0, 0, 1, 0, 0, 1}, 
		{1, 0, 0, 1, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 1}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// F
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 0, 0, 1, 0, 0, 0}, 
		{1, 0, 0, 1, 0, 0, 0}, 
		{1, 0, 0, 1, 0, 0, 0}, 
		{1, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// G
		{0, 1, 1, 1, 1, 1, 0}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 1, 1, 0, 1}, 
		{1, 1, 0, 1, 0, 0, 1}, 
		{0, 1, 0, 1, 1, 1, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// H
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{0, 0, 0, 1, 0, 0, 0}, 
		{0, 0, 0, 1, 0, 0, 0}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// I
		{0, 0, 0, 0, 0, 0, 0}, 
		{1, 0, 0, 0, 0, 0, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 0, 0, 0, 0, 0, 1}, 
		{0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// J
		{0, 0, 0, 0, 0, 1, 0}, 
		{0, 0, 0, 0, 0, 1, 1}, 
		{1, 0, 0, 0, 0, 0, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 0}, 
		{1, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// K
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{0, 0, 1, 1, 1, 0, 0}, 
		{0, 1, 1, 0, 1, 1, 0}, 
		{1, 1, 0, 0, 0, 1, 1}, 
		{1, 0, 0, 0, 0, 0, 1}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// L
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{0, 0, 0, 0, 0, 0, 1}, 
		{0, 0, 0, 0, 0, 0, 1}, 
		{0, 0, 0, 0, 0, 0, 1}, 
		{0, 0, 0, 0, 0, 0, 1}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// M
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{0, 1, 1, 0, 0, 0, 0}, 
		{0, 0, 1, 1, 0, 0, 0}, 
		{0, 1, 1, 0, 0, 0, 0}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}
	}, 
	{
		// N
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{0, 1, 1, 1, 0, 0, 0}, 
		{0, 0, 1, 1, 1, 0, 0}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// O
		{0, 1, 1, 1, 1, 1, 0}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{0, 1, 1, 1, 1, 1, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// P
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 0, 0, 1, 0, 0, 0}, 
		{1, 0, 0, 1, 0, 0, 0}, 
		{1, 1, 1, 1, 0, 0, 0}, 
		{0, 1, 1, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// Q
		{0, 1, 1, 1, 1, 1, 0}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 1, 0, 1}, 
		{1, 1, 1, 0, 0, 1, 1}, 
		{0, 1, 1, 1, 1, 1, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// R
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 0, 0, 1, 1, 0, 0}, 
		{1, 0, 0, 1, 1, 1, 0}, 
		{1, 1, 1, 1, 0, 1, 1}, 
		{0, 1, 1, 0, 0, 0, 1}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// S
		{0, 1, 1, 0, 0, 1, 0}, 
		{1, 1, 1, 1, 0, 1, 1}, 
		{1, 0, 0, 1, 0, 0, 1}, 
		{1, 0, 0, 1, 0, 0, 1}, 
		{1, 1, 0, 1, 1, 1, 1}, 
		{0, 1, 0, 0, 1, 1, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// T
		{1, 0, 0, 0, 0, 0, 0}, 
		{1, 0, 0, 0, 0, 0, 0}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 0, 0, 0, 0, 0, 0}, 
		{1, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// U
		{1, 1, 1, 1, 1, 1, 0}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{0, 0, 0, 0, 0, 1, 1}, 
		{0, 0, 0, 0, 0, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// V
		{1, 1, 1, 1, 1, 0, 0}, 
		{1, 1, 1, 1, 1, 1, 0}, 
		{0, 0, 0, 0, 0, 1, 1}, 
		{0, 0, 0, 0, 0, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 0}, 
		{1, 1, 1, 1, 1, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// W
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{0, 0, 0, 0, 1, 1, 0}, 
		{0, 0, 0, 1, 1, 0, 0}, 
		{0, 0, 0, 0, 1, 1, 0}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}
	}, 
	{
		// X
		{1, 1, 0, 0, 0, 1, 1}, 
		{1, 1, 1, 0, 1, 1, 1}, 
		{0, 0, 1, 1, 1, 0, 0}, 
		{0, 0, 1, 1, 1, 0, 0}, 
		{1, 1, 1, 0, 1, 1, 1}, 
		{1, 1, 0, 0, 0, 1, 1}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// Y
		{1, 1, 1, 0, 0, 0, 0}, 
		{1, 1, 1, 1, 0, 0, 0}, 
		{0, 0, 1, 1, 1, 1, 1}, 
		{0, 0, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 0, 0, 0}, 
		{1, 1, 1, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// Z
		{1, 0, 0, 0, 0, 1, 1}, 
		{1, 0, 0, 0, 1, 1, 1}, 
		{1, 0, 0, 1, 1, 0, 1}, 
		{1, 0, 1, 1, 0, 0, 1}, 
		{1, 1, 1, 0, 0, 0, 1}, 
		{1, 1, 0, 0, 0, 0, 1}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// 0
		{0, 1, 1, 1, 1, 1, 0}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 0, 0, 1, 0, 0, 1}, 
		{1, 0, 1, 0, 0, 0, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{0, 1, 1, 1, 1, 1, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// 1
		{0, 0, 0, 0, 0, 0, 0}, 
		{0, 1, 0, 0, 0, 0, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{0, 0, 0, 0, 0, 0, 1}, 
		{0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// 2
		{0, 1, 0, 0, 0, 1, 1}, 
		{1, 1, 0, 0, 1, 1, 1}, 
		{1, 0, 0, 1, 1, 0, 1}, 
		{1, 0, 0, 1, 0, 0, 1}, 
		{1, 1, 1, 1, 0, 0, 1}, 
		{0, 1, 1, 0, 0, 0, 1}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// 3
		{0, 1, 0, 0, 0, 1, 0}, 
		{1, 1, 0, 0, 0, 1, 1}, 
		{1, 0, 0, 1, 0, 0, 1}, 
		{1, 0, 0, 1, 0, 0, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{0, 1, 1, 0, 1, 1, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// 4
		{0, 0, 0, 1, 1, 0, 0}, 
		{0, 0, 1, 1, 1, 0, 0}, 
		{0, 1, 1, 0, 1, 0, 0}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{0, 0, 0, 0, 1, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// 5
		{1, 1, 1, 0, 0, 1, 0}, 
		{1, 1, 1, 0, 0, 1, 1}, 
		{1, 0, 1, 0, 0, 0, 1}, 
		{1, 0, 1, 0, 0, 0, 1}, 
		{1, 0, 1, 1, 1, 1, 1}, 
		{1, 0, 0, 1, 1, 1, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// 6
		{0, 1, 1, 1, 1, 1, 0}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 0, 0, 1, 0, 0, 1}, 
		{1, 0, 0, 1, 0, 0, 1}, 
		{1, 1, 0, 1, 1, 1, 1}, 
		{0, 1, 0, 0, 1, 1, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// 7
		{1, 0, 0, 0, 0, 0, 0}, 
		{1, 0, 0, 0, 0, 0, 0}, 
		{1, 0, 0, 1, 1, 1, 1}, 
		{1, 0, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 0, 0, 0, 0}, 
		{1, 1, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// 8
		{0, 1, 1, 0, 1, 1, 0}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{1, 0, 0, 1, 0, 0, 1}, 
		{1, 0, 0, 1, 0, 0, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{0, 1, 1, 0, 1, 1, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// 9
		{0, 1, 1, 0, 0, 1, 0}, 
		{1, 1, 1, 1, 0, 1, 1}, 
		{1, 0, 0, 1, 0, 0, 1}, 
		{1, 0, 0, 1, 0, 0, 1}, 
		{1, 1, 1, 1, 1, 1, 1}, 
		{0, 1, 1, 1, 1, 1, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}, 
	{
		// NULL
		{0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0}
	}
}; 

// for object collision box
volatile int User_Pixel[OBJECT_L][OBJECT_W] = {
	{0, 0, 0, 0, 1, 1, 1, 1}, 
	{0, 0, 0, 1, 1, 1, 1, 1}, 
	{0, 0, 0, 1, 1, 1, 1, 1}, 
	{0, 0, 0, 1, 1, 1, 1, 1}, 
	{0, 0, 0, 1, 1, 1, 1, 1}, 
	{0, 0, 0, 1, 1, 1, 1, 1}, 
	{0, 1, 1, 1, 1, 1, 1, 1}, 
	{1, 1, 1, 1, 1, 1, 1, 1}, 
	{0, 1, 1, 1, 1, 1, 1, 1}, 
	{0, 0, 0, 1, 1, 1, 1, 1}, 
	{0, 0, 0, 1, 1, 1, 1, 1}, 
	{0, 0, 0, 1, 1, 1, 1, 1}, 
	{0, 0, 0, 1, 1, 1, 1, 1}, 
	{0, 0, 0, 1, 1, 1, 1, 1}, 
	{0, 0, 0, 0, 1, 1, 1, 1}, 
	{0, 0, 0, 0, 0, 0, 0, 0}
}; 

// for enemy collision box
volatile int Enemy_Pixel[5][2][OBJECT_L][OBJECT_W] = {
	{
		{
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 1, 1, 0 ,0, 1}, 
			{0, 0, 1, 1, 1, 0, 1, 0}, 
			{0, 1, 1, 0, 1, 1, 0, 1}, 
			{1, 1, 1, 1, 1, 0, 1, 0}, 
			{1, 1, 1, 1, 1, 0, 1, 0}, 
			{0, 1, 1, 0, 1, 1, 0, 1}, 
			{0, 0, 1, 1, 1, 0, 1, 0}, 
			{0, 0, 0, 1, 1, 0 ,0, 1}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}
			
		}, 
		{
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 1, 1, 0, 1, 0}, 
			{0, 0, 1, 1, 1, 1, 0, 1}, 
			{0, 1, 1, 0, 1, 0, 0, 0}, 
			{1, 1, 1, 1, 1, 1, 0, 0}, 
			{1, 1, 1, 1, 1, 1, 0, 0}, 
			{0, 1, 1, 0, 1, 0, 0, 0}, 
			{0, 0, 1, 1, 1, 1, 0, 1}, 
			{0, 0, 0, 1, 1, 0, 1, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}
		}
	}, 
	{
		{
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 1, 1, 1, 1, 0, 0, 0}, 
			{0, 0, 0, 1, 1, 1, 0, 1}, 
			{1, 0, 1, 1, 1, 1, 1, 0}, 
			{0, 1, 1, 0, 1, 1, 0, 0}, 
			{0, 0, 1, 1, 1, 1, 0, 0}, 
			{0, 0, 1, 1, 1, 1, 0, 0}, 
			{0, 0, 1, 1, 1, 1, 0, 0}, 
			{0, 1, 1, 0, 1, 1, 0, 0}, 
			{1, 0, 1, 1, 1, 1, 1, 0}, 
			{0, 0, 0, 1, 1, 1, 0, 1}, 
			{0, 1, 1, 1, 1, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}
		}, 
		{
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 1, 1, 1, 0}, 
			{0, 0, 0, 1, 1, 0, 0, 0}, 
			{1, 0, 1, 1, 1, 1, 1, 0}, 
			{0, 1, 1, 0, 1, 1, 0, 1}, 
			{0, 0, 1, 1, 1, 1, 0, 1}, 
			{0, 0, 1, 1, 1, 1, 0, 0}, 
			{0, 0, 1, 1, 1, 1, 0, 1}, 
			{0, 1, 1, 0, 1, 1, 0, 1}, 
			{1, 0, 1, 1, 1, 1, 1, 0}, 
			{0, 0, 0, 1, 1, 0, 0, 0}, 
			{0, 0, 0, 0, 1, 1, 1, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}
		}
	}, 
	{
		{
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 1, 1, 1, 1, 0, 0, 0}, 
			{0, 0, 0, 1, 1, 1, 0, 1}, 
			{1, 0, 1, 1, 1, 1, 1, 0}, 
			{0, 1, 1, 0, 1, 1, 0, 0}, 
			{0, 0, 1, 1, 1, 1, 0, 0}, 
			{0, 0, 1, 1, 1, 1, 0, 0}, 
			{0, 0, 1, 1, 1, 1, 0, 0}, 
			{0, 1, 1, 0, 1, 1, 0, 0}, 
			{1, 0, 1, 1, 1, 1, 1, 0}, 
			{0, 0, 0, 1, 1, 1, 0, 1}, 
			{0, 1, 1, 1, 1, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}
		}, 
		{
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 1, 1, 1, 0}, 
			{0, 0, 0, 1, 1, 0, 0, 0}, 
			{1, 0, 1, 1, 1, 1, 1, 0}, 
			{0, 1, 1, 0, 1, 1, 0, 1}, 
			{0, 0, 1, 1, 1, 1, 0, 1}, 
			{0, 0, 1, 1, 1, 1, 0, 0}, 
			{0, 0, 1, 1, 1, 1, 0, 1}, 
			{0, 1, 1, 0, 1, 1, 0, 1}, 
			{1, 0, 1, 1, 1, 1, 1, 0}, 
			{0, 0, 0, 1, 1, 0, 0, 0}, 
			{0, 0, 0, 0, 1, 1, 1, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}
		}
	}, 
	{
		{
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 1, 1, 1, 0, 0, 1}, 
			{0, 1, 1, 1, 1, 0, 0, 1}, 
			{0, 1, 1, 1, 1, 0, 1, 0}, 
			{0, 1, 1, 0, 1, 1, 1, 0}, 
			{1, 1, 1, 0, 1, 1, 0, 0}, 
			{1, 1, 1, 1, 1, 0, 1, 0}, 
			{1, 1, 1, 1, 1, 0, 1, 0}, 
			{1, 1, 1, 0, 1, 1, 0, 0}, 
			{0, 1, 1, 0, 1, 1, 1, 0}, 
			{0, 1, 1, 1, 1, 0, 1, 0}, 
			{0, 1, 1, 1, 1, 0, 0, 1}, 
			{0, 0, 1, 1, 1, 0, 0, 1}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}
		}, 
		{
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 1, 1, 1, 0, 0, 0}, 
			{0, 1, 1, 1, 1, 0, 1, 0}, 
			{0, 1, 1, 1, 1, 1, 1, 1}, 
			{0, 1, 1, 0, 1, 1, 0, 1}, 
			{1, 1, 1, 0, 1, 1, 0, 0}, 
			{1, 1, 1, 1, 1, 0, 1, 0}, 
			{1, 1, 1, 1, 1, 0, 1, 0}, 
			{1, 1, 1, 0, 1, 1, 0, 0}, 
			{0, 1, 1, 0, 1, 1, 0, 1}, 
			{0, 1, 1, 1, 1, 1, 1, 1}, 
			{0, 1, 1, 1, 1, 0, 1, 0}, 
			{0, 0, 1, 1, 1, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}
		}
	}, 
	{
		{
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 1, 1, 1, 0, 0, 1}, 
			{0, 1, 1, 1, 1, 0, 0, 1}, 
			{0, 1, 1, 1, 1, 0, 1, 0}, 
			{0, 1, 1, 0, 1, 1, 1, 0}, 
			{1, 1, 1, 0, 1, 1, 0, 0}, 
			{1, 1, 1, 1, 1, 0, 1, 0}, 
			{1, 1, 1, 1, 1, 0, 1, 0}, 
			{1, 1, 1, 0, 1, 1, 0, 0}, 
			{0, 1, 1, 0, 1, 1, 1, 0}, 
			{0, 1, 1, 1, 1, 0, 1, 0}, 
			{0, 1, 1, 1, 1, 0, 0, 1}, 
			{0, 0, 1, 1, 1, 0, 0, 1}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}
		}, 
		{
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 1, 1, 1, 0, 0, 0}, 
			{0, 1, 1, 1, 1, 0, 1, 0}, 
			{0, 1, 1, 1, 1, 1, 1, 1}, 
			{0, 1, 1, 0, 1, 1, 0, 1}, 
			{1, 1, 1, 0, 1, 1, 0, 0}, 
			{1, 1, 1, 1, 1, 0, 1, 0}, 
			{1, 1, 1, 1, 1, 0, 1, 0}, 
			{1, 1, 1, 0, 1, 1, 0, 0}, 
			{0, 1, 1, 0, 1, 1, 0, 1}, 
			{0, 1, 1, 1, 1, 1, 1, 1}, 
			{0, 1, 1, 1, 1, 0, 1, 0}, 
			{0, 0, 1, 1, 1, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}, 
			{0, 0, 0, 0, 0, 0, 0, 0}
		}
	}
}; 

// for destroyed enemy
volatile int Enemy_Destroy_Pixel[OBJECT_L][OBJECT_W] = {
	{0, 0, 0, 0, 0, 0, 0, 0}, 
	{0, 0, 0, 0, 0, 0, 0, 0}, 
	{0, 0, 0, 1, 0, 0, 1, 0}, 
	{1, 0, 0, 1, 0, 1, 0, 0}, 
	{0, 1, 0, 0, 0, 0, 0, 0}, 
	{0, 0, 1, 0, 0, 0, 1, 1}, 
	{0, 0, 0, 0, 0, 1, 0, 0}, 
	{1, 1, 0, 0, 0, 0, 0, 0}, 
	{0, 0, 0, 0, 0, 0, 1, 1}, 
	{0, 0, 1, 0, 0, 0, 0, 0}, 
	{1, 1, 0, 0, 0, 1, 0, 0}, 
	{0, 0, 0, 0, 0, 0, 1, 0}, 
	{0, 0, 1, 0, 1, 0, 0, 1}, 
	{0, 1, 0, 0, 1, 0, 0, 0}, 
	{0, 0, 0, 0, 0, 0, 0, 0}, 
	{0, 0, 0, 0, 0, 0, 0, 0}
}; 

// for start check
volatile int Start_Status; 

// for game win / lose
volatile int Game_Win, Game_Lose; 

// for game score
volatile int Game_Score; 
volatile int Game_Score_Status; 

// for user invincible after hit & life
volatile int User_Invincible; 
volatile int User_Life_Status; 
volatile int User_Life; 

/* for PS/2 keyboard
 * Move_Status: -1 - left, 0 - stop, 1 - right
 * Shoot_Status: 0 - stop, 1 - fire
 * Curr_Move_Key: the latest move key being pressed
 */
volatile int Move_Status, Move_Status_Buffer, Shoot_Status, Curr_Move_Key; 

/* for timer count
 * Game_Time: enable
 */ 
volatile int Game_Time; 
volatile int User_Start, Enemy_Start; 
volatile int User_Stop, Enemy_Stop; 

// for PS/2 byte
volatile int Byte1, Byte2, Byte3; 

// for player status
volatile int User_Pos; 

// for enemy status
volatile int Enemy_Status; 
volatile int Enemy_Direction; 
volatile int Enemy_Vert_Move; 
volatile int Enemy_List[50]; 
volatile int Enemy_Topleft_Pos[2]; 
volatile int Enemy_Shape; 

// for user bullet
volatile int User_Bullet_Status; 
volatile int User_Bullet_Start; 
volatile int User_Bullet_Remove; 
volatile int User_Bullet_Pos[2]; 

// for enemy bullets
volatile int Bullet_Status[BULLET_NUM]; 
volatile int Bullet_Start[BULLET_NUM]; 
volatile int Bullet_Remove[BULLET_NUM]; 
volatile int Bullet_Pos[BULLET_NUM][2]; 

// for swap status
volatile int Swap_Status; 

void initStack(){
	int stack = A9_ONCHIP_END - 7; 
	int mode = 0b11010010; 
	__asm__("msr cpsr, %[ps]" : : [ps] "r" (mode)); 
	__asm__("mov sp, %[ps]" : : [ps] "r" (stack)); 
	mode = 0b11010011; 
	__asm__("msr cpsr, %[ps]" : : [ps] "r" (mode)); 
}

void initGIC(){
	*((int*)0xFFFED100) = 0x20000000; 	// private timer, ser
	*((int*)0xFFFED81C) = 0x00000100; 	// private timer, ptr
	*((int*)0xFFFED108) = 0x00008000; 	// PS/2, ser
	*((int*)0xFFFED84C) = 0x01000000; 	// PS/2, ptr
	
	*iccpmr_addr = 0xFFFF; 
	*gic_cpuif = 1; 
	*gic_dist = 1; 
}

void plotPixel(int x, int y, short int color){
    *(short int *)(pix_buf_start + (y << 10) + (x << 1)) = color; 
}

void waitVsync(){
	*pix_buf_ctrl = 1; 
	volatile int status = *(pix_buf_ctrl + 3); 
	while(status & 1)
		status = *(pix_buf_ctrl + 3);	
}

void clearScreen(){
	for(int x = 0; x < RES_X; x++)
		for(int y = 0; y < RES_Y; y++)
			plotPixel(x, y, BLACK); 
}

void initDevice(){
	// pixel buffer
	*(pix_buf_ctrl + 1) = FPGA_ONCHIP_BASE; 
	waitVsync(); 
	pix_buf_start = *pix_buf_ctrl; 
	clearScreen(); 
	*(pix_buf_ctrl + 1) = SDRAM_BASE; 
	pix_buf_start = *(pix_buf_ctrl + 1); 
	clearScreen(); 
	
	// for game process - 0.75s
	*(priv_timer_load) = BASE_TIME; 
	*(priv_timer_load + 2) = 0b110; 
	
	// PS/2
	*(ps2_data + 1) = 1; 
}

void enableStack(){
	int mode = 0b01010011; 
	__asm__("msr cpsr, %[ps]" : : [ps] "r" (mode)); 
}

void updatePS2Status(){
	
	/* only A, D, Left arrow, Right arrow, Space are considered
	 * A		1C		F01C
	 * D		23		F023
	 * Left		E06B	E0F06B
	 * Right	E074	E0F074
	 * Space	29		F029
	 */
	if((*ps2_data) & 0x8000){
		Byte1 = Byte2; 
		Byte2 = Byte3; 
		Byte3 = (*ps2_data) & 0xFF; 
		
		if(Byte3 == (char)0x1C){
			Curr_Move_Key = Byte1; 
			Move_Status = -1; 
			Move_Status_Buffer = Move_Status; 
		}
		else if(Byte3 == (char)0x23){
			Curr_Move_Key = Byte1; 
			Move_Status = 1; 
			Move_Status_Buffer = Move_Status; 
		}
		else if(Byte2 == (char)0xE0 && Byte3 == (char)0x6B){
			Curr_Move_Key = Byte2; 
			Move_Status = -1; 
			Move_Status_Buffer = Move_Status; 
		}
		else if(Byte2 == (char)0xE0 && Byte3 == (char)0x74){
			Curr_Move_Key = Byte2; 
			Move_Status = 1; 
			Move_Status_Buffer = Move_Status; 
		}
		else if(Byte1 == (char)0xE0 && Byte2 == (char)0xF0 && Byte3 == Curr_Move_Key){
			Curr_Move_Key = 0; 
			Move_Status = 0; 
		}
		else if(Byte3 == (char)0x29){
			Start_Status = 1; 
			Shoot_Status = 1; 
		}
		else if(Byte2 == (char)0xF0 && Byte3 == (char)0x29){
			Shoot_Status = 0; 
		}
		else if(Byte2 == (char)0xF0 && Byte3 == Curr_Move_Key){
			Curr_Move_Key = 0; 
			Move_Status = 0; 
		}
	}
}

void updateTimerStatus(){
	Game_Time = 1; 
	if(User_Invincible) User_Invincible--; 
	*(priv_timer_load + 3) = 1; 
}

void __attribute__((interrupt)) __cs3_isr_irq(){
	volatile int device_id = *icciar_addr; 
	if(device_id == PRIV_TIMER_ID)
		updateTimerStatus(); 
	else if(device_id == PST_ID)
		updatePS2Status(); 
	else while(1); 
	
	*icceoir_addr = device_id; 
}

void __attribute__((interrupt)) __cs3_reset(){
	while(1); 
}

void __attribute__((interrupt)) __cs3_isr_undef(){
	while(1); 
}

void __attribute__((interrupt)) __cs3_isr_swi(){
	while(1); 
}

void __attribute__((interrupt)) __cs3_isr_pabort(){
	while(1); 
}

void __attribute__((interrupt)) __cs3_isr_dabort(){
	while(1); 
}

void __attribute__((interrupt)) __cs3_isr_fiq(){
	while(1); 
}

void swapBuffer(){
	Swap_Status = 0; 
	waitVsync(); 
	pix_buf_start = *(pix_buf_ctrl + 1); 
}

void initStartScreen(){
	clearScreen(); 
	
	for(int s = 75; s < 250; s += 35){
		volatile int letter; 
		if(s == 75) letter = 18; 
		else if(s == 110) letter = 15; 
		else if(s == 145) letter = 0; 
		else if(s == 180) letter = 2; 
		else letter = 4; 
		for(int a = 0; a < 7; a++)
			for(int b = 0; b < 7; b++)
				if(Text_Pixel[letter][a][b])
					for(int x = 0; x < 5; x++)
						for(int y = 0; y < 5; y++)
							plotPixel(s + a * 5 + x, 30 + b * 5 + y, WHITE); 
	}
	
	for(int s = 22; s < 302; s += 35){
		volatile int letter; 
		if(s == 22) letter = 8; 
		else if(s == 57) letter = 13; 
		else if(s == 92) letter = 21; 
		else if(s == 127) letter = 0; 
		else if(s == 162) letter = 3; 
		else if(s == 197) letter = 4; 
		else if(s == 232) letter = 17; 
		else letter = 18; 
		for(int a = 0; a < 7; a++)
			for(int b = 0; b < 7; b++)
				if(Text_Pixel[letter][a][b])
					for(int x = 0; x < 5; x++)
						for(int y = 0; y < 5; y++)
							plotPixel(s + a * 5 + x, 75 + b * 5 + y, WHITE); 
	}
}

void initStartScreenWithPress(){
	initStartScreen(); 
	
	for(int s = 21; s < 301; s += 14){
		volatile int letter; 
		if(s == 21) letter = 15; 
		else if(s == 35) letter = 17; 
		else if(s == 49) letter = 4; 
		else if(s == 63) letter = 18; 
		else if(s == 77) letter = 18; 
		else if(s == 91) letter = 36; 
		else if(s == 105) letter = 18; 
		else if(s == 119) letter = 15; 
		else if(s == 133) letter = 0; 
		else if(s == 147) letter = 2; 
		else if(s == 161) letter = 4; 
		else if(s == 175) letter = 36; 
		else if(s == 189) letter = 19; 
		else if(s == 203) letter = 14; 
		else if(s == 217) letter = 36; 
		else if(s == 231) letter = 18; 
		else if(s == 245) letter = 19; 
		else if(s == 259) letter = 0; 
		else if(s == 273) letter = 17; 
		else letter = 19; 
		for(int a = 0; a < 7; a++)
			for(int b = 0; b < 7; b++)
				if(Text_Pixel[letter][a][b])
					for(int x = 0; x < 2; x++)
						for(int y = 0; y < 2; y++)
							plotPixel(s + a * 2 + x, 173 + b * 2 + y, WHITE); 
	}
}

void initEndScreen(){
	clearScreen(); 
	
	if(Game_Win){
		for(int s = 55; s < 275; s += 70){
			volatile int letter; 
			if(s == 55) letter = 22; 
			else if(s == 125){
				s += 10; 
				letter = 8; 
			}
			else letter = 13; 
			for(int a = 0; a < 7; a++)
				for(int b = 0; b < 7; b++)
					if(Text_Pixel[letter][a][b])
						for(int x = 0; x < 10; x++)
							for(int y = 0; y < 10; y++)
								plotPixel(s + a * 10 + x, 40 + b * 10 + y, WHITE); 
		}
	}
	else if(Game_Lose){
		for(int s = 25; s < 305; s += 70){
			volatile int letter; 
			if(s == 25) letter = 11; 
			else if(s == 95) letter = 14; 
			else if(s == 165) letter = 18; 
			else letter = 4; 
			for(int a = 0; a < 7; a++)
				for(int b = 0; b < 7; b++)
					if(Text_Pixel[letter][a][b])
						for(int x = 0; x < 10; x++)
							for(int y = 0; y < 10; y++)
								plotPixel(s + a * 10 + x, 40 + b * 10 + y, WHITE); 
		}
	}
}

void initEndScreenWithPress(){
	initEndScreen(); 
	
	for(int s = 84; s < 238; s += 14){
		volatile int letter; 
		if(s == 84) letter = 15; 
		else if(s == 98) letter = 17; 
		else if(s == 112) letter = 4; 
		else if(s == 126) letter = 18; 
		else if(s == 140) letter = 18; 
		else if(s == 154) letter = 36; 
		else if(s == 168) letter = 18; 
		else if(s == 182) letter = 15; 
		else if(s == 196) letter = 0; 
		else if(s == 210) letter = 2; 
		else letter = 4; 
		for(int a = 0; a < 7; a++)
			for(int b = 0; b < 7; b++)
				if(Text_Pixel[letter][a][b])
					for(int x = 0; x < 2; x++)
						for(int y = 0; y < 2; y++)
							plotPixel(s + a * 2 + x, 164 + b * 2 + y, WHITE); 
	}
	
	if(Game_Win){
		for(int s = 84; s < 238; s += 14){
			volatile int letter; 
			if(s == 84) letter = 19; 
			else if(s == 98) letter = 14; 
			else if(s == 112) letter = 36; 
			else if(s == 126) letter = 2; 
			else if(s == 140) letter = 14; 
			else if(s == 154) letter = 13; 
			else if(s == 168) letter = 19; 
			else if(s == 182) letter = 8; 
			else if(s == 196) letter = 13; 
			else if(s == 210) letter = 20; 
			else letter = 4; 
			for(int a = 0; a < 7; a++)
				for(int b = 0; b < 7; b++)
					if(Text_Pixel[letter][a][b])
						for(int x = 0; x < 2; x++)
							for(int y = 0; y < 2; y++)
								plotPixel(s + a * 2 + x, 182 + b * 2 + y, WHITE); 
		}
	}
	else if(Game_Lose){
		for(int s = 91; s < 231; s += 14){
			volatile int letter; 
			if(s == 91) letter = 19; 
			else if(s == 105) letter = 14; 
			else if(s == 119) letter = 36; 
			else if(s == 133) letter = 17; 
			else if(s == 147) letter = 4; 
			else if(s == 161) letter = 18; 
			else if(s == 175) letter = 19; 
			else if(s == 189) letter = 0; 
			else if(s == 203) letter = 17; 
			else letter = 19; 
			for(int a = 0; a < 7; a++)
				for(int b = 0; b < 7; b++)
					if(Text_Pixel[letter][a][b])
						for(int x = 0; x < 2; x++)
							for(int y = 0; y < 2; y++)
								plotPixel(s + a * 2 + x, 182 + b * 2 + y, WHITE); 
		}
	}
}

void startTimer(){
	*(priv_timer_load + 2) = 0b111; 
}

void stopTimer(){
	*(priv_timer_load + 2) = 0b110; 
	*(priv_timer_load) = BASE_TIME; 
}

void initScreen(){
	// bottom bar
	User_Life = 3; 
	for(int x = 0; x < RES_X; x++)
		plotPixel(x, 219, WHITE); 
	for(int x = 0; x < OBJECT_L; x++)
		for(int y = 0; y < OBJECT_W; y++)
			if(User_Pixel[x][y])
				for(int n = 0; n < User_Life; n++)
					plotPixel(20 + 22 * n + x, 226 + y, WHITE); 
	
	// user
	User_Pos = (RES_X - OBJECT_L) / 2; 
	for(int x = 0; x < OBJECT_L; x++)
		for(int y = 0; y < OBJECT_W; y++)
			if(User_Pixel[x][y])
				plotPixel(User_Pos + x, 205 + y, WHITE); 
	
	// enemy
	Enemy_Status = 50; 
	Enemy_Shape = 0; 
	Enemy_Topleft_Pos[0] = 20;
	Enemy_Topleft_Pos[1] = 27; 
	for(int n = 0; n < 50; n++){
		Enemy_List[n] = 1; // exist
		for(int x = 0; x < OBJECT_L; x++)
			for(int y = 0; y < OBJECT_W; y++)
				if(Enemy_List[n] && Enemy_Pixel[n / 10][Enemy_Shape][x][y])
					plotPixel(Enemy_Topleft_Pos[0] + OBJECT_L * (n % 10) + x, Enemy_Topleft_Pos[1] + 14 * (n / 10) + y, WHITE); 
	}
	
	// topbar
	for(int x = 0; x < RES_X; x++)
		plotPixel(x, 20, WHITE); 
	for(int s = 20; s < 90; s += 7){
		volatile int letter; 
		if(s == 20) letter = 18; 
		else if(s == 27) letter = 2; 
		else if(s == 34) letter = 14; 
		else if(s == 41) letter = 17; 
		else if(s == 48) letter = 4; 
		else if(s == 55) letter = 36; 
		else if(s == 62) letter = Game_Score / 100 + 26; 
		else if(s == 69) letter = (Game_Score % 100) / 10 + 26; 
		else if(s == 76) letter = Game_Score % 10 + 26; 
		else letter = 26; 
		for(int a = 0; a < 7; a++)
			for(int b = 0; b < 7; b++)
				if(Text_Pixel[letter][a][b])
					plotPixel(s + a, 7 + b, WHITE); 
	}
}

void initMove(){
	User_Start = 1; 
	Enemy_Start = 1; 
	Enemy_Direction = 1; 
	
	Move_Status = 0; 
	Shoot_Status = 0; 
	
	for(int n = 0; n < BULLET_NUM; n++)
		Bullet_Status[n] = 0; 
	
	if(Game_Lose) Game_Score = 0; 
	Game_Win = 0; 
	Game_Lose = 0; 
	
	Swap_Status = 0; 
}

void drawUser(int offset, short int color){
	for(int x = 0; x < OBJECT_L; x++)
		for(int y = 0; y < OBJECT_W; y++)
			if(User_Pixel[x][y])
				plotPixel(User_Pos + x + 2 * offset * Move_Status_Buffer, 205 + y, color); 
}

void updateUserStart(){
	Swap_Status = 1; 
	User_Start = 0; 
	User_Stop = 1; 
	
	Move_Status = 0; 
	
	drawUser(0, BLACK); 
	drawUser(1, WHITE); 
	
	User_Pos += 2 * Move_Status_Buffer; 
}

void updateUserMove(){
	Swap_Status = 1; 
	
	Move_Status = 0; 
	
	drawUser(-1, BLACK); 
	drawUser(1, WHITE); 
	
	User_Pos += 2 * Move_Status_Buffer; 
}

void updateUserStop(){
	Swap_Status = 1; 
	User_Stop = 0; 
	User_Start = 1; 
	
	Move_Status = 0; 
	
	drawUser(-1, BLACK); 
	drawUser(0, WHITE); 
}

void drawEnemy(int offset_x, int offset_y, int offset_shape, short int color){
	for(int n = 0; n < 50; n++){
		if(Enemy_List[n] < 0 && color == BLACK){
			Enemy_List[n]++; 
			for(int x = 0; x < OBJECT_L; x++)
				for(int y = 0; y < OBJECT_W; y++)
					plotPixel(Enemy_Topleft_Pos[0] + OBJECT_L * (n % 10) + x + 4 * offset_x * Enemy_Direction,
							  Enemy_Topleft_Pos[1] + 14 * (n / 10) + y + 14 * offset_y, color); 
		}
		for(int x = 0; x < OBJECT_L; x++)
			for(int y = 0; y < OBJECT_W; y++)
				if(Enemy_List[n] == 1 && Enemy_Pixel[n / 10][Enemy_Shape ^ offset_shape][x][y])
					plotPixel(Enemy_Topleft_Pos[0] + OBJECT_L * (n % 10) + x + 4 * offset_x * Enemy_Direction,
							  Enemy_Topleft_Pos[1] + 14 * (n / 10) + y + 14 * offset_y, color); 
	}
}

void updateEnemyStart(){
	Swap_Status = 1; 
	Enemy_Start = 0; 
	Enemy_Stop = 1; 
	
	Game_Time = 0; 
	
	// horizontal
	if(Enemy_Topleft_Pos[0] + 4 * Enemy_Direction >= 20 && Enemy_Topleft_Pos[0] + 4 * Enemy_Direction <= 140){
		drawEnemy(0, 0, 0, BLACK); 
		drawEnemy(1, 0, 1, WHITE); 
		Enemy_Topleft_Pos[0] += 4 * Enemy_Direction; 
	}
	// vertical
	else{
		drawEnemy(0, 0, 0, BLACK); 
		drawEnemy(0, 1, 1, WHITE); 
		Enemy_Vert_Move = 1; 
		Enemy_Direction = -Enemy_Direction; 
		Enemy_Topleft_Pos[1] += 14; 
	}
	
	Enemy_Shape ^= 1; 
}

void updateEnemyMove(){
	Swap_Status = 1; 
	
	Game_Time = 0; 
	
	// horizontal
	if(Enemy_Topleft_Pos[0] + 4 * Enemy_Direction >= 20 && Enemy_Topleft_Pos[0] + 4 * Enemy_Direction <= 140){
		if(Enemy_Vert_Move){
			drawEnemy(0, -1, 1, BLACK); 
			Enemy_Vert_Move = 0; 
		}
		else drawEnemy(-1, 0, 1, BLACK); 
		drawEnemy(1, 0, 1, WHITE); 
		Enemy_Topleft_Pos[0] += 4 * Enemy_Direction; 
	}
	// vertical
	else{
		drawEnemy(-1, 0, 1, BLACK); 
		drawEnemy(0, 1, 1, WHITE); 
		Enemy_Vert_Move = 1; 
		Enemy_Direction = -Enemy_Direction; 
		Enemy_Topleft_Pos[1] += 14; 
	}
	
	Enemy_Shape ^= 1; 
}

void updateEnemyStop(){
	Swap_Status = 1; 
	Enemy_Stop = 0; 
	Enemy_Start = 1; 
	
	Game_Time = 0; 
	
	if(Enemy_Vert_Move){
		drawEnemy(0, -1, 1, BLACK); 
		Enemy_Vert_Move = 0; 
	}
	else drawEnemy(-1, 0, 1, BLACK); 
	drawEnemy(0, 0, 0, WHITE); 
}

void drawBullet(int n, int offset, short int color){
	for(int y = 0; y < BULLET_W; y++)
		plotPixel(Bullet_Pos[n][0], Bullet_Pos[n][1] + y + 2 * offset, color); 
}

void removeBullet(int n){
	Swap_Status = 1; 
	Bullet_Remove[n] = 0; 
	Bullet_Status[n] = 0; 
	
	drawBullet(n, 0, BLACK); 
}

void updateBulletStart(int n){
	Swap_Status = 1; 
	Bullet_Start[n] = 0; 
	
	drawBullet(n, 1, WHITE); 
	
	Bullet_Pos[n][1] += 2; 
}

void updateBulletMove(int n){
	Swap_Status = 1; 
	
	// destroy
	if(Bullet_Pos[n][1] >= 212){
		Bullet_Remove[n] = 1; 
		
		drawBullet(n, -1, BLACK); 
		return; 
	}
	
	// move
	drawBullet(n, -1, BLACK); 
	drawBullet(n, 1, WHITE); 
	
	Bullet_Pos[n][1] += 2; 
}

void initBullet(int n){
	// create new bullet - 0.5% chance per while loop
	if(rand() % 200) return; 
	
	Swap_Status = 1; 
	Bullet_Start[n] = 1; 
	Bullet_Status[n] = 1; 
	
	volatile int count = rand() % 10; 
	Bullet_Pos[n][0] = Enemy_Topleft_Pos[0] + OBJECT_L * count + OBJECT_L / 2 - 1; 
	for(int j = 5; j; j--)
		if(Enemy_List[count + 10 * (j - 1)] == 1){
			Bullet_Pos[n][1] = Enemy_Topleft_Pos[1] + 14 * (j - 1) + OBJECT_W + 1; 
			break; 
		}
	
	drawBullet(n, 0, WHITE); 
}

void checkBullet(int n){
	if(Bullet_Status[n] && 
	   Bullet_Pos[n][0] >= User_Pos && 
	   Bullet_Pos[n][0] < User_Pos + OBJECT_L - 1 && 
	   (Bullet_Pos[n][1] + BULLET_W - 1) >= 205 && 
	   Bullet_Pos[n][1] < 205 + OBJECT_W){
		// bullet
		Swap_Status = 1; 
		Bullet_Remove[n] = 1; 
		
		drawBullet(n, 0, BLACK); 
		
		if(!Bullet_Start[n]) Bullet_Pos[n][1] -= 2; 
		else if(Bullet_Start[n]) Bullet_Start[n] = 0; 
		
		// user
		User_Invincible = 6; 
		
		// life
		User_Life_Status = 2; 
		User_Life--; 
		if(User_Life < 0) Game_Lose = 1; 
	}
}

void clearUser(){
	if(!(User_Invincible % 2))
		drawUser(0, BLACK); 
}

void updateLife(){
	User_Life_Status--; 
	for(int x = 0; x < OBJECT_L; x++)
		for(int y = 0; y < OBJECT_W; y++)
			if(User_Pixel[x][y])
				plotPixel(20 + 22 * User_Life + x, 226 + y, BLACK); 
}

void checkGameLose(){
	for(int n = 0; n < 50; n++)
		if(Enemy_List[n] == 1 && ((Enemy_Topleft_Pos[1] - 27) / 14 + n / 10) == 13)
			Game_Lose = 1; 
}

void drawUserBullet(int offset, short int color){
	for(int y = 0; y < BULLET_W; y++)
		plotPixel(User_Bullet_Pos[0], User_Bullet_Pos[1] + y + 2 * offset, color); 
}

void removeUserBullet(){
	Swap_Status = 1; 
	User_Bullet_Remove = 0; 
	User_Bullet_Status = 0; 
	
	drawUserBullet(0, BLACK); 
}

void updateUserBulletStart(){
	Swap_Status = 1; 
	Shoot_Status = 0; 
	User_Bullet_Start = 0; 
	
	drawUserBullet(-1, WHITE); 
	
	User_Bullet_Pos[1] -= 2; 
}

void updateUserBulletMove(){
	Swap_Status = 1; 
	Shoot_Status = 0; 
	
	// destroy
	if(User_Bullet_Pos[1] == 21){
		User_Bullet_Remove = 1; 
		
		drawUserBullet(1, BLACK); 
		return; 
	}
	
	// move
	drawUserBullet(1, BLACK); 
	drawUserBullet(-1, WHITE); 
	
	User_Bullet_Pos[1] -= 2; 
}

void initUserBullet(){
	Swap_Status = 1; 
	Shoot_Status = 0; 
	User_Bullet_Start = 1; 
	User_Bullet_Status = 1; 
	User_Bullet_Pos[0] = User_Pos + 7; 
	User_Bullet_Pos[1] = 201; 
	
	drawUserBullet(0, WHITE); 
}

void clearEnemy(){
	for(int n = 0; n < 50; n++){
		if(Enemy_List[n] < 0)
			for(int x = 0; x < OBJECT_L; x++)
				for(int y = 0; y < OBJECT_W; y++)
					plotPixel(Enemy_Topleft_Pos[0] + OBJECT_L * (n % 10) + x, Enemy_Topleft_Pos[1] + 14 * (n / 10) + y, BLACK); 
		if(Enemy_List[n] < -1)
			for(int x = 0; x < OBJECT_L; x++)
				for(int y = 0; y < OBJECT_W; y++)
					if(Enemy_Destroy_Pixel[x][y])
						plotPixel(Enemy_Topleft_Pos[0] + OBJECT_L * (n % 10) + x, Enemy_Topleft_Pos[1] + 14 * (n / 10) + y, WHITE); 
	}
}

void checkUserBullet(){
	int space; 
	for(int n = 0; n < 50; n++){
		if(n / 10 == 0) space = 4; 
		else space = 2; 
		
		if(Enemy_List[n] == 1 &&
		   User_Bullet_Pos[0] >= (Enemy_Topleft_Pos[0] + OBJECT_L * (n % 10) + space) && 
		   User_Bullet_Pos[0] < (Enemy_Topleft_Pos[0] + OBJECT_L * (n % 10) + OBJECT_L - space) &&
		   (User_Bullet_Pos[1] + BULLET_W - 1) >= (Enemy_Topleft_Pos[1] + 14 * (n / 10)) && 
		   User_Bullet_Pos[1] < (Enemy_Topleft_Pos[1] + 14 * (n / 10) + OBJECT_W)){
			// bullet
			Swap_Status = 1; 
			User_Bullet_Remove = 1; 
			
			drawUserBullet(0, BLACK); 
			
			if(!User_Bullet_Start) User_Bullet_Pos[1] += 2; 
			else if(User_Bullet_Start) User_Bullet_Start = 0; 
			
			// enemy
			Enemy_Status--; 
			if(!Enemy_Status) Game_Win = 1; 
			Enemy_List[n] = -2; 
			
			// score
			Game_Score_Status = 2; 
			if(n / 10 == 0) Game_Score += S_ENEMY_SCORE; 
			else if(n / 10 >= 1 && n / 10 <= 2) Game_Score += M_ENEMY_SCORE; 
			else Game_Score += L_ENEMY_SCORE; 
			
			break; 
		}
	}
}

void updateScore(){
	Game_Score_Status--; 
	for(int s = 62; s < 83; s += 7){
		volatile int letter; 
		if(s == 62) letter = Game_Score / 100 + 26; 
		else if(s == 69) letter = (Game_Score % 100) / 10 + 26; 
		else letter = Game_Score % 10 + 26; 
		for(int a = 0; a < 7; a++)
			for(int b = 0; b < 7; b++){
				plotPixel(s + a, 7 + b, BLACK); 
				if(Text_Pixel[letter][a][b])
					plotPixel(s + a, 7 + b, WHITE); 
			}
	}
}

int main(){
	initStack(); 
	initGIC(); 
	initDevice(); 
	enableStack(); 
	
	initStartScreenWithPress(); 
	swapBuffer(); 
	initStartScreen(); 
	startTimer(); 
	while(!Start_Status)
		if(Game_Time){
			Game_Time = 0; 
			swapBuffer(); 
		}
	
	mainGameProcess: {
		stopTimer(); 
		clearScreen(); 
		initScreen(); 
		swapBuffer(); 
		clearScreen(); 
		initScreen(); 
		startTimer(); 
		
		initMove(); 
		while(1){
			// user
			if(User_Pos + 2 * Move_Status_Buffer >= 20 && User_Pos + 2 * Move_Status_Buffer <= 284 && User_Start && Move_Status != 0) updateUserStart(); 
			else if(User_Pos + 2 * Move_Status_Buffer >= 20 && User_Pos + 2 * Move_Status_Buffer <= 284 && !User_Start && Move_Status != 0) updateUserMove(); 
			else if((Move_Status == 0 && User_Stop) || User_Pos + 2 * Move_Status_Buffer < 20 || User_Pos + 2 * Move_Status_Buffer > 284) updateUserStop(); 
			
			// enemy
			if(Enemy_Start && Game_Time) updateEnemyStart(); 
			else if(!Enemy_Start && Game_Time) updateEnemyMove(); 
			else if(!Game_Time && Enemy_Stop) updateEnemyStop(); 
			
			// enemy bullet
			for(int n = 0; n < BULLET_NUM; n++){
				if(Bullet_Remove[n]) removeBullet(n); 
				if(Bullet_Start[n] && Bullet_Status[n]) updateBulletStart(n); 
				else if(!Bullet_Start[n] && Bullet_Status[n]) updateBulletMove(n); 
				else if(!Bullet_Status[n]) initBullet(n); 
			}
			
			// enemy bullet collision
			for(int n = 0; n < BULLET_NUM; n++)
				if(!User_Invincible)
					checkBullet(n); 
			if(User_Invincible) clearUser(); 
			
			// life
			if(User_Life_Status) updateLife(); 
			
			// lose
			checkGameLose(); 
			if(Game_Lose) break; 
			
			// user bullet
			if(User_Bullet_Remove) removeUserBullet(); 
			if(User_Bullet_Start && User_Bullet_Status) updateUserBulletStart(); 
			else if(!User_Bullet_Start && User_Bullet_Status) updateUserBulletMove(); 
			else if(Shoot_Status && !User_Bullet_Status) initUserBullet(); 
			
			// user bullet collision
			checkUserBullet(); 
			clearEnemy(); 
			
			// score
			if(Game_Score_Status) updateScore(); 
			
			// win
			if(Game_Win) break; 
			
			if(Swap_Status) swapBuffer(); 
		}
	}
	
	Start_Status = 0; 
	stopTimer(); 
	initEndScreenWithPress(); 
	swapBuffer(); 
	initEndScreen(); 
	startTimer(); 
	while(!Start_Status)
		if(Game_Time){
			Game_Time = 0; 
			swapBuffer(); 
		}
	goto mainGameProcess; 
}
