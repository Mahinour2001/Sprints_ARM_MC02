#include "Int_Port.h"
#include "Dio.h"

void PORT_USER(void)
{
    Port_Init(GPIO_ARR_INPUT);
}