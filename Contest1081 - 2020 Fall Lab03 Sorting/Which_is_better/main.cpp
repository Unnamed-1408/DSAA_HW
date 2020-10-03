#include <iostream>

using namespace std;
long long insertion_sort(int list[] , int num);
long long Selection_Sort(int list[] , int num);
void outputa(int list[] , int num);


int main()
{
    int count = 0;
    cin >> count;
    while(count != 0){
    int num = 0;
    cin >> num;
    int temp = 0;
    int list[num];

    while(temp != num){
        cin >> list[temp];
        temp++;
    }
//    cout << insertion_sort(list , num) << Selection_Sort(list , num);
    long long a = insertion_sort(list , num);
    long long b = Selection_Sort(list , num);
    if(a > b){
        cout << "Selection Sort wins!" << endl;
    }
    else{
        cout << "Insertion Sort wins!" << endl;
    }
     count--;
}

}

long long insertion_sort(int list[] , int num){
    long long output = 0;
    int temp = 0;
    int count = 0;
    int tempnum = 0;
    while(count != num){

        temp = count;

        while(temp != -1){

            if(list[temp] < list[temp-1]){
                tempnum = list[temp];
                list[temp] = list[temp-1];
                list[temp-1] = tempnum;
                output = output +2;
            }
            else{
                output++;
               break;
            }
            temp--;
        }
        count++;
    }
    return output;
}

long long Selection_Sort(int list[] , int num){
    int Aptr = 0;
    int Bptr = 0;
    int temp = 0;
    long long output = 0;
    while(Aptr != num){
        Bptr = Aptr;

        while(Bptr != num){
            if(list[Bptr] < list[Aptr]){
                temp = list[Aptr];
                list[Aptr] = list[Bptr];
                list[Bptr] = temp;
                output = output+2;
            }
            else{
                output++;
            }
            Bptr++;
        }
        Aptr++;
    }
    outputa(list , num);
    return output;
}


void outputa(int list[] , int num){
    int temp = 0;
    while(temp != num){

        cout<<list[temp]<<" ";

        temp++;

    }
    cout<<endl;
}

