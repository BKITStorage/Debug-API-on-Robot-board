/*
 * button.c
 *
 *  Created on: May 30, 2025
 *      Author: Divu
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // Thêm để sử dụng int8_t
#include "button.h"

// Tạo và khởi tạo ma trận
button *create_button()
{
    button *btn = (button *)malloc(sizeof(button));
    if (!btn)
    {
        return NULL; // Memory allocation failed
    }
    btn->des = 0;
    btn->rows = ROWS;
    btn->cols = COLS;
    // Khởi tạo mảng tĩnh về 0
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            btn->data[i][j] = 0; // Khởi tạo giá trị 0
        }
    }
    return btn;
}

// In mảng button cache
void printButtonCache(button *btn)
{
    if (btn == NULL)
    {
        printf("Button cache is NULL!\n");
        return;
    }

    for (int i = 0; i < btn->rows; i++)
    {
        for (int j = 0; j < btn->cols; j++)
        {
            printf("%d ", btn->data[i][j]);
        }
        printf("\n");
    }
}

void fillButtonCache(uint8_t input, button *btn)
{

    if (btn == NULL)
    {
        return;
    }

    for (int j = 0; j < btn->cols && j < 8; j++)
    {
        btn->data[btn->des][7 - j] = (input >> j) & 1; // Điền bit từ thấp đến cao, đảo ngược
    }
    // Chỉ sử dụng hàng đầu tiên để lưu 8 bit
    btn->des = (btn->des + 1) % btn->rows; // Cập nhật hàng tiếp theo

    printButtonCache(btn); // In kết quả
}

// Lấy giá trị từ button cache
uint8_t getButtonValue(button *btn)
{
    if (btn == NULL)
    {
        return 0b00000000; // Trả về giá trị mặc định nếu btn là NULL
    }
    uint8_t value = 0;
    // Lấy giá trị từ hàng đầu tiên (8 bit)

    for (int i = 0; i < btn->cols; i++)
    {
        int sum = btn->data[0][i] + btn->data[1][i] + btn->data[2][i] + btn->data[3][i] + btn->data[4][i];
        if (sum > 2)
        {
            value |= (1 << (btn->cols - 1 - i)); // Nếu tổng lớn hơn 3, coi là bit 1
        }
        else
        {
            value &= ~(1 << (btn->cols - 1 - i)); // Nếu tổng nhỏ hơn hoặc bằng 3, coi là bit 0
        }
    }
    printf("Button value: %d\n", value);
    return value; // Trả về giá trị đã lấy
}

// Giải phóng bộ nhớ
void freeButtonCache(button *btn)
{
    if (btn == NULL)
        return;
    free(btn); // Chỉ cần giải phóng btn vì data là mảng tĩnh trong struct
}
