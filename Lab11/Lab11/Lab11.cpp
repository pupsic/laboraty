#include <iostream>
using namespace std;

void my_strcut(char arr[],int point){
    int size=0;
    int count_p=0;

    for (; arr[size] != '\0'; size++)
        ;
    char* copy_arr = new char(size);
    int g = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == ' ' && arr[i+1]!=' ') {
            count_p++;
            if (count_p == point) {
                
                for (; i < size; i++,g++)
                {
                    copy_arr[g] = arr[i];

                }
                break;
            }
        }
    }
    copy_arr[g + 1] = '\0';
    for (size = 0; copy_arr[size] != '\0'; size++)
        cout<<copy_arr[size];
}

int main()
{
    char my_string[] = "hello my dear friend";
    
    //int size = sizeof(my_string) / sizeof(my_string[0]);
    my_strcut(my_string,2);
    
    
    return 0;
}

