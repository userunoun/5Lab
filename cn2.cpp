#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h> 
using namespace std;

class Timer {
private:
    unsigned long begTime;

public:
    void start() {
        begTime = clock();
    }

    unsigned long elapsedTime() {
        return ((unsigned long)clock() - begTime) / CLOCKS_PER_SEC;
    }

    bool isTimeout(unsigned long seconds) {
        return elapsedTime() >= seconds;
    }
};

int main() {
    int frames[] = {1, 2, 3, 4};
    const unsigned long timeoutSeconds = 5;
    srand(time(NULL));

    Timer t;
    cout << "Sender has to send frames: ";
    for (int frame : frames) {
        cout << frame << " ";
    }
    cout << endl;

    int count = 0;
    bool delay = false;

    cout << endl
         << "Sender\t\t\t\tReceiver" << endl;

    while (count < 4) {
        bool timeout = false;
        cout << "Sending Frame: " << frames[count];
        cout.flush();

        t.start();
        usleep(rand() % 2000000 + 500000); 

        if (!t.isTimeout(timeoutSeconds)) {
            cout << "\t\tReceived Frame: " << frames[count];
            if (delay) {
                cout << " (Duplicate)";
                delay = false;
            }
            cout << endl;
            count++;
        } else {
            cout << "\t\t---" << endl;
            cout << "Timeout" << endl;
            timeout = true;
        }

        t.start();
        if (rand() % 2 || !timeout) {
            usleep(rand() % 2000000 + 500000); 

            if (t.isTimeout(timeoutSeconds)) {
                cout << "Delayed Ack" << endl;
                delay = true;
                count--;
            } else if (!timeout) {
                cout << "Acknowledgement: " << frames[count - 1] << endl;
            }
        }
    }
    return 0;
}
