#ifndef PATIENT_H
#define PATIENT_H

//Singleton Class
class Patient
{
    static Patient* instance;
    Patient(){};
public:
    static Patient* getInstance();

};

#endif // PATIENT_H
