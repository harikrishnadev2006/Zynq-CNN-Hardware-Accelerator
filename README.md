# Hardware-Accelerated CNN Inference on Xilinx Zynq SoC

## Overview
This repository presents a high-performance implementation of a Convolutional Neural Network (CNN) leveraging the Xilinx Zynq System-on-Chip (SoC). By adopting a Hardware/Software (HW/SW) co-design methodology, workloads are distributed across the ARM Processing System (PS) and the FPGA Programmable Logic (PL) to maximize computational efficiency.

## Objective
The primary goal is to achieve real-time image classification by offloading computationally intensive operations—specifically convolution and pooling—from the CPU to the FPGA fabric. This project serves as a quantitative proof-of-concept demonstrating performance improvements over a CPU-only implementation.

## Platform & Tools

**Target Hardware:** Xilinx Zynq-7000 series development board  
**Processing Core:** Dual-core ARM Cortex-A9 (PS)  
**Acceleration Fabric:** FPGA Programmable Logic (PL)  

**Design Tools:**
- Xilinx Vitis HLS (High-Level Synthesis)
- Vivado Design Suite

## System Partitioning (HW/SW Split)

To optimize system performance, functionality is divided as follows:

### Processing System (PS) — ARM Core
- Image acquisition  
- Preprocessing  
- System control and configuration  
- Post-processing of inference results  

### Programmable Logic (PL) — FPGA
- Parallel computation of convolution layers  
- Activation functions  
- Pooling operations  
- High-throughput arithmetic processing  

## Key Features

- Lightweight CNN architecture optimized for embedded deployment  
- Hardware/software co-design implementation  
- AXI4-based high-speed communication between PS and PL  
- Efficient utilization of DSP slices and BRAM resources  
- Support for benchmarking against CPU-only execution  

## Performance Benchmarks

The system targets improvements across four primary metrics:

- **Latency Reduction:** Lower inference time per frame  
- **Throughput Enhancement:** Higher frames per second (FPS)  
- **Power Optimization:** Reduced energy consumption per inference  
- **Hardware Utilization:** Balanced use of FPGA resources for optimal performance  

## Outcome

This project demonstrates the effectiveness of heterogeneous computing for edge AI applications. By offloading intensive workloads to specialized hardware, the system achieves significantly higher efficiency than traditional CPU-only architectures while maintaining real-time capability.
