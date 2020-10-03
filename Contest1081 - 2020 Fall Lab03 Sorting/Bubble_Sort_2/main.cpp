#include <iostream>

using namespace std;
long long Merge(int lista[] , int listb[] , int left ,int Center ,int right);
long long Mergesort(int list[]  ,int temp[], int left ,int right);
int* Start(int list[],int num);
void output(int list[] , int num);

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
    Start(list , num);
    count--;
}


}

int* Start(int list[],int num){
    int temp[num];
    cout << Mergesort(list,temp,0,num-1) << endl;
    return list;
}

long long Mergesort(int list[] , int temp[],int left ,int right){

     int Center = (left+right)/2;

     if(left < right){

        long long a = Mergesort(list ,temp, left ,Center);
        long long b =Mergesort(list ,temp, Center+1 ,right);
        long long c =Merge(list , temp ,left ,Center ,right);
        return a+b+c;
     }
     else {
         return 0;
     }

}

long long Merge(int list[] , int temp[] , int left ,int Center ,int right){
    int Aptr = Center;
    int Bptr = right;
    int Cptr = right;
    long long count = 0;
    while(Cptr != left-1){
        if(Aptr != left-1 && Bptr != Center){
            if(list[Aptr] > list[Bptr]){
                temp[Cptr] = list[Aptr];
                Cptr --;
                Aptr --;
                count=count+Bptr-Center;
            }
            else{
                temp[Cptr] = list[Bptr];
                Cptr --;
                Bptr --;
            }
       }

        else if(Aptr == left-1 ){
            temp[Cptr] = list[Bptr];
            Cptr --;
            Bptr --;
        }
        else if(Bptr == Center){
            temp[Cptr] = list[Aptr];
            Cptr --;
            Aptr --;
        }
    }
        int tempnum = left;
        while(tempnum != right+1){
            list[tempnum] = temp[tempnum];
//            cout<<list[tempnum]<<endl;
            tempnum++;
        }
//        cout << count;
        return count;
}


void output(int list[] , int num){
    int temp = 0;
    while(temp != num){

        cout<<list[temp]<<" ";

        temp++;

    }
    cout<<endl;
}
