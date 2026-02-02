# Task-4 Evidence

## UART Output Screenshot

The screenshot below shows the UART output while the program is running on the VSDSquadron Mini board.

It confirms:
- Sampling starts and stops using the push button
- GPIO input values are sampled periodically
- Data is transmitted correctly over UART

[UART Output](task4_monitor_output.png)

## Hardware Video Evidence

A short video is provided showing real hardware execution.

The video demonstrates:
- LED blinking when sampling is enabled
- LED turning OFF when sampling is stopped
- Push button controlling the sampling process

Video file: `task4_evidence_video.mp4`

## Verification Notes

- GPIO, Timer, and UART drivers work together correctly
- Sampling interval is controlled by the timer
- Output behavior matches expected functionality
