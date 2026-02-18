# Hardware-Accelerated CNN Inference on Xilinx Zynq SoC

## Overview
This project implements a hardware-accelerated convolutional neural network (CNN) inference system on a Xilinx Zynq System-on-Chip using a hardware/software co-design approach. The ARM processing system performs image acquisition, preprocessing, and control, while the FPGA programmable logic accelerates computationally intensive CNN operations.

## Objective
To achieve real-time or near real-time image classification by offloading convolution and pooling operations to FPGA fabric and to quantitatively demonstrate performance improvements over a CPU-only implementation.

## Platform
- Xilinx Zynq-based development board
- ARM Cortex-A9 Processing System (PS)
- FPGA Programmable Logic (PL)
- Vitis HLS and Vivado Design Suite

## System Partitioning
- **PS (ARM Core):** Image handling, preprocessing, control, and post-processing  
- **PL (FPGA):** Convolution, activation, pooling, and parallel arithmetic operations  

## Key Features
- Lightweight CNN implementation
- Hardware/software co-design
- AXI-based PS–PL communication
- Performance comparison with CPU-only execution
- Resource-efficient FPGA implementation

## Performance Goals
- Reduced inference latency
- Improved throughput
- Lower power consumption
- Efficient utilization of FPGA resources

## Repository Structure
- CPU-only software implementation
- FPGA accelerator design files
- Hardware/software integration components
- Experimental results
- Final project documentation

## Outcome
The project demonstrates the effectiveness of heterogeneous computing on embedded platforms for accelerating edge AI workloads.
