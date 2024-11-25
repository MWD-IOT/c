// #include <stdio.h>
// #include <string.h>
// #include <stdint.h>

// #define MAX_PAYLOADS 5
// #define MAX_FRAME_SIZE 256
// #define MAX_PAYLOAD_SIZE 512

// typedef struct {
//     uint8_t data[MAX_FRAME_SIZE];
//     size_t length;
// } Frame;

// // 判断是否为帧头
// int is_frame_header(const uint8_t *data, size_t len) {
//     return len >= 4 && data[0] == 0xD0 && data[1] == 0x35 && data[3] == 0x00;
// }

// // 判断是否是有效载荷开始
// int is_payload_start(const uint8_t *data, size_t len) {
//     return len >= 2 && data[0] == 0x00 && data[1] == 0x64;
// }

// // 判断是否是有效载荷结束
// int is_payload_end(const uint8_t *data, size_t len) {
//     if (len < 1) return 0;
//     return data[len - 1] == 0x11 || data[len - 1] == 0x21;
// }

// // 提取有效载荷
// void extract_payloads(const uint8_t *stream, size_t stream_len, uint8_t payloads[MAX_PAYLOADS][MAX_PAYLOAD_SIZE], size_t payload_sizes[MAX_PAYLOADS]) {
//     size_t payload_count = 0;
//     size_t i = 0, payload_start = 0, payload_end = 0;
//     int in_payload = 0;

//     while (i < stream_len) {
//         // 检查帧头
//         if (is_frame_header(&stream[i], stream_len - i)) {
//             i += 4; // 跳过帧头
//             continue;
//         }

//         // 检查有效载荷起点
//         if (!in_payload && is_payload_start(&stream[i], stream_len - i)) {
//             payload_start = i;
//             in_payload = 1;
//         }

//         // 检查有效载荷终点
//         if (in_payload && is_payload_end(&stream[i], i - payload_start + 1)) {
//             payload_end = i;
//             size_t payload_len = payload_end - payload_start + 1;

//             // 存储到缓冲区
//             if (payload_count < MAX_PAYLOADS) {
//                 memcpy(payloads[payload_count], &stream[payload_start], payload_len);
//                 payload_sizes[payload_count] = payload_len;
//                 payload_count++;
//             }

//             in_payload = 0; // 结束当前载荷提取
//         }

//         i++;
//     }
// }

// int main() {
//     uint8_t stream[] = {
//         0xD0, 0x35, 0x01, 0x00, 0x00, 0x64, 0x10, 0x20, 0x11,
//         0xD0, 0x35, 0x02, 0x00, 0x00, 0x64, 0x10, 0x20, 0x21,
//         0xD0, 0x35, 0x03, 0x00, 0x00, 0x64, 0x10, 0x11
//     };

//     size_t stream_len = sizeof(stream);
//     uint8_t payloads[MAX_PAYLOADS][MAX_PAYLOAD_SIZE] = {0};
//     size_t payload_sizes[MAX_PAYLOADS] = {0};

//     extract_payloads(stream, stream_len, payloads, payload_sizes);

//     for (size_t i = 0; i < MAX_PAYLOADS; i++) {
//         if (payload_sizes[i] > 0) {
//             printf("Payload %zu: ", i + 1);
//             for (size_t j = 0; j < payload_sizes[i]; j++) {
//                 printf("%02X ", payloads[i][j]);
//             }
//             printf("\n");
//         }
//     }

//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_PAYLOADS 5
#define MAX_FRAME_SIZE 256
#define MAX_PAYLOAD_SIZE 512

// Helper function to find frame headers
int find_frame_header(uint8_t *data, int len, int *frame_start) {
    for (int i = 0; i < len - 3; i++) {
        if (data[i] == 0xD0 && data[i + 1] == 0x35 && data[i + 3] == 0x00) {
            *frame_start = i;
            return 1;
        }
    }
    return 0;
}

// Extract payloads from data stream
void extract_payloads(uint8_t *data, int len, uint8_t buf[MAX_PAYLOADS][MAX_PAYLOAD_SIZE], int buf_sizes[MAX_PAYLOADS]) {
    int frame_start = 0;
    int current_payload = 0;
    int payload_idx = 0;
    int inside_payload = 0;

    while (find_frame_header(data + frame_start, len - frame_start, &frame_start)) {
        frame_start += frame_start; // Adjust frame start to global index
        int frame_end = frame_start + MAX_FRAME_SIZE < len ? frame_start + MAX_FRAME_SIZE : len;

        for (int i = frame_start; i < frame_end && current_payload < MAX_PAYLOADS; i++) {
            // Check for payload start
            if (!inside_payload && i + 1 < frame_end && data[i] == 0x00 && data[i + 1] == 0x64) {
                inside_payload = 1;
                payload_idx = 0;
            }

            // Capture payload data
            if (inside_payload) {
                buf[current_payload][payload_idx++] = data[i];
                if (payload_idx >= MAX_PAYLOAD_SIZE) {
                    fprintf(stderr, "Payload size exceeded!\n");
                    return;
                }

                // Check for payload end
                if ((data[i] == 0x11 || data[i] == 0x21) && (i == 0 || data[i - 1] == 0x10 || data[i - 1] == 0x20)) {
                    inside_payload = 0;
                    buf_sizes[current_payload++] = payload_idx;
                }
            }
        }
        frame_start = frame_end;
    }
}

int main() {
    // Example data stream
    uint8_t data_stream[] = {
        0x12, 0x39, 0x88, 0x70, 
        0xD0, 0x35, 0x01, 0x00, 0x00, 0x64, 0x52, 0x02, 0x10, 0x10, 0x10, 0x20, 0x20, 0x10, 0x10, 0x20, 0x10, 0x20, 0x20, 0x10, 0x21, 
        0xD0, 0x35, 0x02, 0x00, 0x00, 0x64, 0x58, 0x21, 0x10, 0x10, 0x10, 0x20, 0x20, 0x10, 0x10, 0x20, 0x10, 0x20, 0x10, 0x20, 0x11, 
        0xD0, 0x35, 0x03, 0x00, 0x00, 0x64, 0x40, 0x36, 0x10, 0x10, 0x10, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x20, 0x10, 0x20, 0x21
    };
    int data_stream_len = sizeof(data_stream);

    // Buffers for extracted payloads
    uint8_t buf[MAX_PAYLOADS][MAX_PAYLOAD_SIZE];
    int buf_sizes[MAX_PAYLOADS] = {0};

    // Extract payloads
    extract_payloads(data_stream, data_stream_len, buf, buf_sizes);

    // Print extracted payloads
    for (int i = 0; i < MAX_PAYLOADS; i++) {
        if (buf_sizes[i] > 0) {
            printf("Payload %d: ", i + 1);
            for (int j = 0; j < buf_sizes[i]; j++) {
                printf("%02X ", buf[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}



