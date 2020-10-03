#include <iostream>

using namespace std;
void find(int value[] , int left , int right , int energy);

int main()
{
    int problem = 0;
    int labs = 0;
    cin >> problem >> labs;
    int value[problem];
    int temp = 0;

    while(temp != problem){
        cin >> value[temp];
        temp++;
    }

    temp = 0;
    int energy[labs];

    while( temp != labs){
        cin >> energy[temp];
        temp++;
    }

    temp = 0;

    while(temp != labs){
      find(value , 0 , problem-1 ,energy[temp]);
      temp++;
    }

}

void find(int value[] , int left , int right , int energy){

    int Center = (left+right)/2;

    if(left == right){
        if(value[right] > energy){
            cout << energy - value[right-1] <<endl;
            return;
        }
        if(value[right] < energy){
            cout << energy - value[right] <<endl;
            return;
        }
        if(value[right] == energy){
            cout << "Accept" << endl;
            return;
        }
    }

    if(value[Center] > energy){
        find(value , left , Center ,energy);
    }
    if(value[Center] < energy){
        find(value , Center+1 ,right ,energy);
    }
    if(value[Center] == energy){
        cout << "Accept" << endl;
        return;
    }


}
