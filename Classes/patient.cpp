#include "patient.h"



Patient *Patient::getInstance()
{
    if(!instance){
        instance = new Patient;
    }
    return instance;
}

Patient* Patient::instance=0;
