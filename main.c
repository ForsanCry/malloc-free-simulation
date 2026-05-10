#include <stdio.h>
#include <stdbool.h>

#define SIZE 50
#define OCCUPIED 4 

//GLOBAL VARIABLES
int arr[SIZE] = {0};
int top = 0;

int find_gap(int requested_size);
int my_alloc(int requested_size);
void my_free (int index);

int main()
{
    
    int mem_alloc = 0;
    int free_target = 0;

while (true)
{
    printf("Write memory you want to allocate: ");
    scanf("%d", &mem_alloc);

    if (mem_alloc == -1)
    {
        printf("\nWrite Header for free: ");
        scanf("%d", &free_target);

        my_free(free_target);
    }
    else if (mem_alloc == 0)
    {
        break;
    }
    else
    {
        int key = my_alloc(mem_alloc);
        
        if (key != -1) 
        {
            printf("Block starts at index: %d\n", key);
        }
        else
        {
            break;
        }
    }
        
    for (int j = 0; j < top; j++) 
    {
        printf("[%d]", arr[j]);
    }
    printf("\n\n");
        
}

}

//------------------------------------------------------------------------------------FUNCTIONS------------------------------------------------------------------------------------

int find_gap(int requested_size)
{
    int ct = 0;
    int needed = requested_size + 1; //+1 for header cell

    for (int i = 0; i < top; i++)
    {
        if (arr[i] == 0)
        {
            ct++;

            if (ct == needed) 
            {
                return i - requested_size;
            }
        }
        else
        {
            ct = 0;
        }
        
    }
    
    return -1;
}


int my_alloc(int requested_size)
{
    int gap_index = find_gap(requested_size);  


    if (gap_index != -1)
    {
        arr[gap_index] = requested_size;
        for (int i = gap_index + 1; i <= gap_index + requested_size; i++)
        {
            arr[i] = OCCUPIED;
        }
    
        return gap_index;
    }
    else 
    {

        if (top + requested_size > SIZE -1)
        {
            printf("Out of memory!\n");
            return -1;
        }  
        else
        {
            arr[top] = requested_size;
            for (int j = top + 1; j <= top + requested_size; j++)
            {
                arr[j] = OCCUPIED;
            }
            top += requested_size + 1;
            
            return top - requested_size - 1;
        }     
    }
    
    return -1;
}


void my_free (int index)
{
    if (index < 0 || index >= SIZE) 
    {
        printf("Index is not in range.\n");
        return;
    }

    int header = arr[index];

    for (int i = index; i <= index + header; i++)
    {
        arr[i] = 0;
    }

    int check = index + header + 1;

    if (check == top)
    {
        top = index;
    }
        
    
}