# Hardware-Accelerated CNN on Xilinx Zynq-7000 SoC

## Overview

This project implements a Convolutional Neural Network (CNN) inference pipeline on a Xilinx Zynq-7000 SoC using a hardware/software co-design approach. The work evaluates the performance benefits of redesigning the convolution layer as a hardware accelerator using Vivado HLS, while maintaining system control on the ARM Cortex-A9 Processing System (PS).

The project is organized into two stages:

* Stage 1: CPU-only CNN inference on ARM (baseline)
* Stage 2: HLS-based accelerator architecture for convolution (evaluated via synthesis and implementation reports)

## Target Platform

* SoC: Xilinx Zynq-7000
* Processor: ARM Cortex-A9 (PS)
* Accelerator Design: FPGA Programmable Logic (PL-oriented architecture)
* Tools: Vivado, Vitis, Vivado HLS

## Repository Structure

```
CPU_Implementation/      -> Processor-based CNN inference (Stage 1)
FPGA_Accelerator/        -> HLS accelerator design and integration
Results/                 -> Latency, throughput, power, and resource reports
Project_Documentation.pdf -> Full project report
main.c                   -> Application entry and benchmarking
 dataset.h               -> Dataset and input definitions
 design_1_wrapper.xsa    -> Exported hardware platform
```

## System Architecture

### Processing System (PS)

* Image loading and memory management
* Accelerator configuration via AXI-Lite
* Execution control and latency measurement

### Accelerator Architecture (HLS-Based)

* Convolution computation engine
* DDR memory access via AXI Master interface
* Parallel arithmetic operations for reduced latency

## Design Flow

1. Implement baseline CNN on ARM processor
2. Design convolution accelerator using Vivado HLS
3. Integrate accelerator into Zynq hardware design
4. Develop Vitis application for control and benchmarking
5. Compare CPU execution vs accelerator-oriented design

## Performance Summary

* Stage 1 (CPU): ~27 ms latency, ~36 FPS
* Stage 2 (Accelerator Estimate): ~161 µs latency
* Estimated Speedup: ~169×
* FPGA Utilization: < 4% LUT/FF, < 1% BRAM

Performance metrics for Stage 2 are obtained from Vivado HLS synthesis and post-implementation analysis within the Zynq architecture.

## Key Features

* Hardware/Software co-design on Zynq SoC
* HLS-based CNN convolution accelerator
* AXI-based PS–PL communication model
* Low resource and power footprint
* Comparative benchmarking framework

## Results

The accelerator-oriented architecture significantly reduces inference latency and improves throughput potential compared to processor-only execution, while maintaining efficient FPGA resource utilization and moderate power consumption.

## Future Work

* Full PL runtime deployment with DMA
* Multi-layer CNN acceleration
* AXI-Stream based dataflow optimization
* Real-time camera input integration


## Outcome

This project demonstrates the effectiveness of heterogeneous computing for edge AI applications. By offloading intensive workloads to specialized hardware, the system achieves significantly higher efficiency than traditional CPU-only architectures, while maintaining real-time capability.
