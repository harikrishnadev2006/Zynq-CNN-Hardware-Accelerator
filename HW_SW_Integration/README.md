# Hardware–Software Integration

This directory contains the integration framework that connects the ARM Processing System (PS) and the FPGA Programmable Logic (PL). In a heterogeneous SoC environment, this layer enables coordinated operation between software and hardware components, allowing the system to function as a unified platform.

## System Interconnect and Control

Communication between the processor and the accelerator is implemented using the AXI4 interconnect. This architecture supports high-bandwidth data transfer and low-latency control, enabling the CPU to offload computationally intensive tasks to the FPGA efficiently.

## Key Components

### Block Design Configurations
Hardware design files that define the structural connectivity between the processing system and the custom accelerator IP within the programmable logic.

### AXI Interface Setup
Configuration of Memory-Mapped (AXI-Lite) interfaces for control and register access, and Streaming (AXI-Stream) interfaces for high-speed data transfer.

### Application-Level Drivers
C/C++ software components responsible for interfacing with the hardware, including address mapping, DMA management, and execution control of the accelerator.

## Operational Flow

The system partitions tasks across the heterogeneous architecture. Image preprocessing and control operations are executed on the ARM processor, while compute-intensive inference operations run on the FPGA accelerator. This coordinated execution enables the system to meet real-time performance requirements.
