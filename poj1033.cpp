#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAX_CLUSTER_NUM 10005

int cluster_num, file_num;
int link[MAX_CLUSTER_NUM];
bool is_free[MAX_CLUSTER_NUM];
int total_length;
bool optimized;

void input()
{
    memset(link, -1, sizeof(link));
    scanf("%d%d", &cluster_num, &file_num);
    for (int i = 0; i < cluster_num; i++)
        is_free[i] = true;
    int target_pos = 0;
    total_length = 0;
    for (int i = 0; i < file_num; i++)
    {
        int file_part_num;
        scanf("%d", &file_part_num);
        total_length += file_part_num;
        for (int j = 0; j < file_part_num; j++)
        {
            int original_pos;
            scanf("%d", &original_pos);
            original_pos--;
            link[target_pos] = original_pos;
            target_pos++;
            is_free[original_pos] = false;
        }
    }
}

int drag(int start_point, int end_pos)
{
    optimized = true;
    int next_point;
    while (link[start_point] != end_pos)
    {
        next_point = link[start_point];
        printf("%d %d\n", next_point + 1, start_point + 1);
        link[start_point] = -1;
        is_free[start_point] = false;
        is_free[next_point] = true;
        start_point = next_point;
    }
    return start_point;
}

void work()
{
    optimized = false;
    for (int i = 0; i < total_length; i++)
        if (is_free[i])
            drag(i, -1);
    for (int i = 0; i < total_length; i++)
    {
        if (link[i] != -1 && link[i] != i)
        {
            printf("%d %d\n", i + 1, total_length + 1);
            is_free[i] = true;
            is_free[total_length - 1] = false;
            int last_pos = drag(i, i);
            link[last_pos] = -1;
            printf("%d %d\n", total_length + 1, last_pos + 1);
            is_free[last_pos] = false;
            is_free[total_length - 1] = true;
        }
    }
    if (!optimized)
        printf("No optimization needed\n");
}

int main()
{
    input();
    work();
    return 0;
}