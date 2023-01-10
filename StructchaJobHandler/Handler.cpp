#include <iostream>
#include <exception>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

using namespace std;

/*
    This main file starts all the other services when required which are:
    - Check if request for job status is called
    - Checking if there is a job to run/pause/stop/finished
    - Passing data too and retrieving data from the database

*/ 

int main() {
    cout << "Starting StructchaHandler\n";
    cout << "...\n";
    //initilisation phase

    cout << "StructchaHandler Started and running with no errors\n";
    cout << "Looking for tasks\n";

    int i = 0;
    while(i < 1'000'000'000) {
        if(i % 100'000'000 == 0) {
            cout << i << "\n";
        }        
        i++;
    }

    
    

    cout << "\nStructchaHandler has exited\n";
    return 0;
}