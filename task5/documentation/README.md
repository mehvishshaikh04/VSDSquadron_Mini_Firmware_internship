# UART-Based GPIO Sampling Application

## Overview
This project implements a UART-based GPIO sampling application on the VSDSquadron Mini board. A push button is used to start and stop periodic sampling of a digital GPIO input, and sampled values are transmitted over UART as line-based serial output.

## Hardware
- VSDSquadron Mini board
- PD0: Push button (start/stop)
- PD1: Digital signal input

## Supported Drivers
- GPIO
- UART
- Timer

## Quick Start
1. Build and flash the firmware.
2. Open a UART terminal at 9600 baud.
3. Press the button to start or stop sampling.
