#include<iostream>
using namespace std;
struct node{
    int from[20];
    int dist[20];
}route[10];

int main(){
    int dm[10][10],n;
    cout<<"enter the number of nodes : ";
    cin>>n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin>>dm[i][j];

            dm[i][i]=0;
            route[i].dist[j] = dm[i][j];
            route[i].from[j] = j;
        }
    }
    bool flag;
    do{
       flag =0;
       for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                for (int k = 0; k < n; k++){
                    if (( route[i].dist[j] ) > (route[i].dist[k] + route[j].dist[k])){
                        route[i].dist[j] = route[i].dist[k]+route[j].dist[k];
                        route[i].from[j]= k;
                        flag =1;
                    }
                }
            }
       }
    } while (flag);
    
    for (int i = 0; i < n; i++){
        cout << "Router info for router: " << i + 1 << endl;
        cout << "Dest\tNext Hop\tDist" << endl;
        for (int j = 0; j < n; j++){
            cout << i + 1 << "\t" << route[i].from[j] + 1 << "\t\t" << route[i].dist[j] << endl;
        }
    }
    return 0 ;
}

// -------------------------------------------------------------------------------------

// #include <iostream>
// using namespace std;

// struct node
// {
//     int from[20];
//     int dist[20];
// } route[10];

// int main()
// {
//     int dm[20][20], n;

//     cout << "Enter the no of nodes: ";
//     cin >> n;

//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < n; j++){
//             cin >> dm[i][j];

//             dm[i][i] = 0;
//             route[i].dist[j] = dm[i][j];
//             route[i].from[j] = j;
//         }
//     }

//     bool flag;
//     do{
//         flag = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 for (int k = 0; k < n; k++)
//                 {
//                     if ((route[i].dist[j]) > ((route[i].dist[k]) + (route[k].dist[j])))
//                     {
//                         route[i].dist[j] = (route[i].dist[k]) + (route[k].dist[j]);
//                         route[i].from[j] = k;
//                         flag = 1;
//                     }
//                 }
//             }
//         }
//     } while (flag);

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << i + 1 << "\t" << route[i].from[j] + 1 << "\t" << route[i].dist[j] << endl;
//         }
//     }
//     return 0;
// }
