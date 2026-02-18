# FPGA Accelerator

This directory contains the hardware-accelerated design of the CNN inference engine. By offloading compute-intensive operations—specifically convolution, activation, and pooling—to the FPGA programmable logic, the system avoids the sequential limitations of standard CPU execution.

## Design and Implementation

The accelerator is developed using a High-Level Synthesis (HLS) workflow, enabling the transformation of algorithmic descriptions into optimized hardware architectures. This folder represents the hardware core of the project, focusing on parallel execution of data-intensive tasks to achieve high throughput.

## Key Components

### HLS Source Files
C/C++ source code describing the hardware kernels along with optimization directives such as pipelining, loop unrolling, and array partitioning.

### Synthesis Reports
Performance estimates generated during synthesis, including achievable clock frequency, latency, and initiation interval.

### Resource Utilization
Reports detailing the consumption of FPGA resources, including BRAM, DSP slices, Flip-Flops (FF), and Look-Up Tables (LUT).

## Objective

The primary objective of this module is to maximize computational efficiency in hardware. By leveraging dedicated DSP resources available in the Xilinx Zynq SoC, the design delivers high-performance arithmetic processing while maintaining a balanced power profile and hardware footprint.
