This folder contains the heart of our software-side work. Before we pushed the limits with FPGA hardware, we built this software-only version of the CNN to run on the ARM processor.

In any serious engineering project, you need a "Ground Truth." This implementation isn't just a backup; it’s our benchmark. It allows us to see exactly how much faster—and more efficient—our final FPGA design is compared to a standard processor.

We’ve kept things modular and clean:

The Inference Logic: This is the core engine that handles the neural network's heavy lifting.

Preprocessing Routines: All the "prep work" (like resizing or normalizing data) happens here before the model takes over.

Performance Tracking: We have implemented  timing scripts to measure latency and throughput. This gives us the hard numbers we need to prove our hardware acceleration actually works.
