#include <iostream>

using namespace std;
long long Merge(int list[] , int left , int right , int Center);
long long spilt(int list[] , int left , int right);

int main()
{
    int count = 0;
    cin >> count;
    while(count != 0){
    int num = 0;
    cin >> num;
    int list[num];
    int temp = 0;
    while(temp != num){
        cin >> list[temp];
        temp++;
    }

//    int list[6] = {10,4,1,2,5,3};
    cout << spilt(list , 0 , num-1)<<endl;
    count--;
}
}

long long spilt(int list[] , int left , int right){

    if(left < right){
        int Center = (left+right+1)/2;
        long long a = spilt(list , left , Center-1);
        long long b = spilt(list , Center , right);
        return a+b+Merge(list , left , right , Center);
    }
    else{
        return 0;
    }

}

long long Merge(int list[] , int left , int right , int Center){
    int Aptr = left;
//    cout << "A"<<Aptr << endl;
    int Bptr = Center;
//    cout << "B"<<Bptr << endl;
//    cout << "R" << right << endl;
    long long output = 0;

    while(Aptr != Center){

        Bptr = Center;

        while(Bptr != right+1){
            if(list[Aptr] > list[Bptr]){
                output++;
            }
            Bptr++;
        }

        Aptr++;
    }
//    cout << output << endl;
    return output;
}
