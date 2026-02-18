# CPU Implementation

This directory contains the software-only implementation of the CNN executed on the ARM processor. It serves as the baseline reference for evaluating the performance gains achieved through FPGA acceleration.

In any hardware acceleration project, a reliable ground-truth implementation is essential. This version provides a standard CPU execution profile against which improvements in speed, efficiency, and resource utilization can be measured.

## Components

### Inference Logic
Implements the core neural network computation, including forward propagation through convolutional, activation, and pooling layers.

### Preprocessing Routines
Handles input preparation tasks such as resizing, normalization, and formatting of image data prior to inference.

### Performance Tracking
Includes timing mechanisms used to measure key metrics such as inference latency and throughput. These measurements establish the baseline required for quantitative comparison with the hardware-accelerated system.

## Purpose

The primary purpose of this module is benchmarking. It enables direct comparison between CPU-only execution and the FPGA-accelerated implementation, thereby demonstrating the effectiveness of the hardware/software co-design approach.
