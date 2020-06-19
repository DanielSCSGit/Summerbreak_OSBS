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


