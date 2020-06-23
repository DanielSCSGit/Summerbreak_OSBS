# forward routine notes

By default, an internal open drain transistor pulls the FLAG pin to ground when at least one
of the following conditions occurs:
- Power-up or standby/reset exit
- Overcurrent detection
- Thermal warning
- Thermal shutdown
- UVLO
- Switch turn-on event
- Wrong command
- Non performable command.
see more @ page 26 L6474 doc

NOTPERF_CMD flag to look for when implementing routine, may indicate some errors

The motor movement is defined by the step clock signal applied to the STCK pin. At each
step clock rising edge, the motor is moved by one microstep in the direction selected by DIR
input (high for forward direction and low for reverse direction) and absolute position is
consequently updated.

#define ABS_POS h01
#define EL_POS  h02
#define MARK    h03
#define TVAL    h09
#define T_FAST  h0E
#define TON_MIN h0F
#define TOFF_MIN h10
#define ADC_OUT h12
#define OCD_TH h13
#define STEP_MODE h16
#define ALARM_EN h17
#define CONFIG h18
#define STATUS h19


