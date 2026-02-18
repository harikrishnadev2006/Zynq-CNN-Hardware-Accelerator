#include <stdio.h>
#include <stdlib.h>
#include <xtime_l.h> // Required for timing on Zynq
#include "dataset.h" // Your Python-generated image data

/* --- CNN Configuration --- */
#define IMG_H 32
#define IMG_W 32
#define INPUT_CHANNELS 1
#define CONV1_FILTERS 8
#define CONV1_KERNEL 3
#define CONV2_FILTERS 16
#define CONV2_KERNEL 3

/* --- Convolution Layer --- */
void conv2d(int in_ch, int in_h, int in_w, int out_ch, int k_size,
            float input[in_ch][in_h][in_w],
            float weights[out_ch][in_ch][k_size][k_size],
            float bias[out_ch],
            float output[out_ch][in_h - k_size + 1][in_w - k_size + 1]) {
    for (int f = 0; f < out_ch; f++) {
        for (int i = 0; i < (in_h - k_size + 1); i++) {
            for (int j = 0; j < (in_w - k_size + 1); j++) {
                float sum = bias[f];
                for (int c = 0; c < in_ch; c++) {
                    for (int ki = 0; ki < k_size; ki++) {
                        for (int kj = 0; kj < k_size; kj++) {
                            sum += input[c][i + ki][j + kj] * weights[f][c][ki][kj];
                        }
                    }
                }
                output[f][i][j] = (sum > 0) ? sum : 0; // ReLU
            }
        }
    }
}

/* --- Max Pooling Layer --- */
void maxpool(int ch, int in_h, int in_w, float input[ch][in_h][in_w], float output[ch][in_h/2][in_w/2]) {
    for (int c = 0; c < ch; c++) {
        for (int i = 0; i < in_h / 2; i++) {
            for (int j = 0; j < in_w / 2; j++) {
                float max_v = -1e9;
                for (int pi = 0; pi < 2; pi++)
                    for (int pj = 0; pj < 2; pj++)
                        if (input[c][i*2+pi][j*2+pj] > max_v) max_v = input[c][i*2+pi][j*2+pj];
                output[c][i][j] = max_v;
            }
        }
    }
}

/* --- Buffers --- */
static float conv1_out[8][30][30], pool1_out[8][15][15];
static float conv2_out[16][13][13], pool2_out[16][6][6];
static float w1[8][1][3][3], b1[8], w2[16][8][3][3], b2[16];

int main() {
    printf("--- Zynq CNN Software Baseline Started ---\n\r");
    printf("Dataset Size: %d images\n\r", NUM_TEST_IMAGES);

    XTime tStart, tEnd;
    for(int i=0; i<NUM_TEST_IMAGES; i++) {
        float (*img)[32][32] = (float (*)[32][32])test_dataset[i];

        XTime_GetTime(&tStart);
        conv2d(1, 32, 32, 8, 3, img, w1, b1, conv1_out);
        maxpool(8, 30, 30, conv1_out, pool1_out);
        conv2d(8, 15, 15, 16, 3, pool1_out, w2, b2, conv2_out);
        maxpool(16, 13, 13, conv2_out, pool2_out);
        XTime_GetTime(&tEnd);

        double us = (double)(tEnd - tStart) / (COUNTS_PER_SECOND / 1000000);
        printf("Image %d: %.2f us\n\r", i, us);
    }
    return 0;
}