#include <iostream>
using namespace std;

struct node {
    unsigned dist[6];
    unsigned from[6];
} DVR[10];

int main() {
    cout << "\n\n----- Distance Vector Routing Algorithm -----";
    int costmat[6][6], nodes, i, j, k;

    cout << "\n\n Enter the number of nodes: ";
    cin >> nodes; 

    cout << "\n Enter the cost matrix (use 999 for infinity): \n";
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            cin >> costmat[i][j];
            
            DVR[i].dist[j] = costmat[i][j];
            DVR[i].from[j] = j;
        }
    }
    
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            for (k = 0; k < nodes; k++) {
                if (DVR[i].dist[j] > costmat[i][k] + DVR[k].dist[j]) {
                    DVR[i].dist[j] = costmat[i][k] + DVR[k].dist[j];
                    DVR[i].from[j] = k;
                }
            }
        }
    }

    for (i = 0; i < nodes; i++) {
        cout << "\n\n For router: " << i + 1;
        for (j = 0; j < nodes; j++) {
            cout << "\n   Node " << j + 1 << " via " << DVR[i].from[j] + 1
                 << " Distance " << DVR[i].dist[j];
        }
    }
    cout << "\n\n";
    return 0;
}
