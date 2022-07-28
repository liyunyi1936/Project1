#include <stdio.h>
#include <stddef.h>
typedef unsigned char      uint8_t;
typedef signed char         int8_t;
typedef unsigned int       uint32_t;
int a[5] = {5,2,2,2,1};
uint32_t  p_data;
int8_t g_status;
int8_t dichotomous_search(int * arr, uint32_t size, float target, uint32_t* num);
int main()
{
    g_status = dichotomous_search(a, 5 ,2, &p_data);
    printf("p_data:%d\n", p_data);
    printf("g_status:%d\n", g_status);
}

int8_t dichotomous_search(int* arr, uint32_t size, float target, uint32_t* num)
{

    uint32_t left = 0;
    uint32_t right = size - 1;
    uint32_t mid = 0;
    uint8_t  status = 1;

    if (arr == NULL) {                //judge the array is NULL or not

        return -1;
    }
    if (target > arr[0]) {

        return -2;

    }
    while (left <= right) {         //avoid the array has only 1 data

        mid = (left + right) / 2;

        if (target > arr[mid]) {

            right = mid - 1;

        }
        else if (target < arr[mid]) {

            left = mid + 1;

        }
        else {

            *num = mid;
            break;
        }
    }

    if (target != arr[mid])
    {
        *num = left;
    }

    return status;

}
