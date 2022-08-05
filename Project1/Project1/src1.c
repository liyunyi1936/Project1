#include "stdint.h"
#include "stdio.h"
#define data_type float
int8_t g_status;
uint32_t p_data;

double arr[5] = {5,4,3,2,1};
double res_value = 2;

int8_t dichotomous_search(void* arr, uint32_t data_type_len, uint32_t data_len, void* target,
    int8_t(*compare_func)(void* member_1, void* member_2), uint32_t* num);
static int8_t float_compare_func(void* m1, void* m2);

int main()
{
    
    g_status = dichotomous_search(arr, sizeof(double), 5, &res_value, float_compare_func ,&p_data);
    printf("p_data:%d\n", p_data);
    printf("g_status:%d\n", g_status);
    return 0;

}

int8_t dichotomous_search(void* arr, uint32_t data_type_len, uint32_t data_len, void* target,
    int8_t(*compare_func)(void* member_1, void* member_2), uint32_t* num)
{

    uint32_t left = 0;
    uint32_t right = data_len - 1;
    uint32_t mid = 0;
    uint8_t  status = 1;
    int8_t cmp_ret = 0;

    char* data_array = arr;

    if (arr == NULL) {                //judge the array is NULL or not

        return -1;
    }
    if (compare_func(target, data_array) > 0) {

        return -2;

    }


    while (left <= right) {      //avoid the array has only 1 data

        mid = (left + right) >> 1;

        cmp_ret = compare_func(data_array + mid * data_type_len, target);  //"compare_func"  big to small :-   small to big:+

        if (cmp_ret < 0) {

            right = mid - 1;

        }
        else if (cmp_ret > 0) {

            left = mid + 1;

        }
        else {

            *num = mid;
            break;
        }
    }

    if (cmp_ret)
    {
        *num = left;
    }

    return status;

}


static int8_t float_compare_func(void* m1, void* m2)
{
    int8_t ret = 0;
    double* a = m1;
    double* b = m2;


    if (*a == *b) {


        ret = 0;
    }
    else if (*a > *b) {


        ret = 1;
    }
    else {



        ret = -1;
    }

    return ret;


}

