#include <iostream>

using namespace std;

void qs(int *data, int left, int right)
{
    if (left > right)
    {
        return;
    }
    int i = left;
    int j = right;
    int key = data[left];
    while(i != j)
    {
        while(data[j] >= key && i < j) // 先要右边，一次相遇的时候，挺的位置才是比key小的位置，后面才能交换
            j --;

        while(data[i] <= key && i < j) // <= 等于千万别忘记
            i ++;

        if (i < j)
        {
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    data[left] = data[i];
    data[i] = key;

    qs(data, left, i-1);
    qs(data, i+1, right);
}
void qsort(int *data, size_t size)
{
    qs(data, 0, size-1);
}


int main()
{
    cout<<"Hello World" << std::endl;
    int test[] = {3,5,2,1,7};
    qsort(test, 5);
    for(int i = 0; i < 5; i++)
    {
        std::cout <<test[i] << std::endl;
    }

    int test2[] = {6,1,2,7,9,10,4,5,11,8};
    qsort(test2, 10);
    for(int i = 0; i < 10; i++)
    {
        std::cout <<test2[i] << std::endl;
    }
    return 0;
}
