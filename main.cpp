#include <iostream>
#include <stdlib.h>
#include "Header.h"

using namespace std;

int main()
{
    int control;
    printf("1)  版本一\n"
        "2)  版本二\n"
        "3)  版本三\n"
        "4)  版本四\n"
        "5)  程式結束\n");
    cin >> control;
    while (control != 5) {
        switch (control)
        {
        case 1:
            ver1();
            break;
        case 2:
            ver2();
            break;
        case 3:
            ver3();
            break;
        case 4:
            struct_template();
            break;
        }
        printf("1)  版本一\n"
            "2)  版本二\n"
            "3)  版本三\n"
            "4)  版本四\n"
            "5)  程式結束\n");
        cin >> control;
    }

    printf("End of run.\n");
    return 0;
}