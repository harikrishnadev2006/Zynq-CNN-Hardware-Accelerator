# Experimental Results and Evaluation

This directory contains the performance analysis and experimental data collected to evaluate the system. The results quantify the improvements achieved by transitioning from a software-only implementation to a hardware-accelerated design on the Xilinx Zynq SoC.

## Performance Benchmarks

The evaluation focuses on key metrics relevant to embedded inference performance:

### Inference Latency
Comparative measurements showing the reduction in execution time per frame when using the FPGA accelerator.

[`CPU-only latency`](https://github.com/harikrishnadev2006/Zynq-CNN-Hardware-Accelerator/blob/main/Results/ARM_CPU_latency.png)
FPGA    - 

### System Throughput
Performance expressed in frames per second (FPS), demonstrating the increase in processing rate compared to CPU-only execution.

### Power Utilization
Assessment of performance per watt, highlighting the energy advantages of hardware acceleration on a heterogeneous platform.

[`fpga_power_utilization`](https://github.com/harikrishnadev2006/Zynq-CNN-Hardware-Accelerator/blob/main/Results/FPGA_power_consumption.jpeg)

### Resource Utilization
Assessment of resources used such as LUT, Flip Flops and BRAM.

[`FPGA_resouce_utilization`](https://github.com/harikrishnadev2006/Zynq-CNN-Hardware-Accelerator/blob/main/Results/FPGA_resource_utilization.jpeg)

## Conclusion

The collected results demonstrate that offloading computationally intensive operations to FPGA programmable logic significantly improves real-time processing capability for edge AI workloads.
