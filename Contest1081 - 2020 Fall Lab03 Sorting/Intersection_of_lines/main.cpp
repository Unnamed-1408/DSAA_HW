#include <iostream>
#include <algorithm>

using namespace std;

struct points{
    long long y1;
    long long y2;
};


bool compare(points s1, points s2);
void Merge(long long lista[] , long long listb[] , long long left ,long long Center ,long long right);
void Mergesort(long long list[]  ,long long temp[], long long left ,long long right);
long long* Start(long long list[],long long num);

points* Start_struct(points list[],long long num);
void Mergesort_struct(points list[]  ,points temp[], long long left ,long long right);
void Merge_struct(points lista[] , points listb[] , long long left ,long long Center ,long long right);

int main()
{
    int count = 0;
    long long x1 , x2;
    cin >> count >> x1 >> x2;
    int temp = 0;

    long long list[count][2];

    while(temp != count){
        cin >> list[temp][0];
        cin >> list[temp][1];
        temp++;
    }

    temp = 0;

    points output[count];

    while(temp != count){
        output[temp].y1 = list[temp][0]*x1+list[temp][1];
        output[temp].y2 = list[temp][0]*x2+list[temp][1];
        temp++;
    }

    sort(output , output+count , compare);

    long long to_compare[count];
    temp = 0;

    while(temp != count){
        to_compare[temp] = output[temp].y2;
        temp++;
    }
//    sort(to_compare , to_compare+count);
    Start(to_compare , count);
    temp = 0;

    while(temp != count){
        if(output[temp].y2 != to_compare[temp]){
            cout << "YES" << endl;
            return 0;
        }
        temp++;
    }

    cout << "NO" << endl;
}
bool compare(points s1, points s2){
    if(s1.y1 != s2.y1){
        return s1.y1 < s2.y1;
    }
    else{
        return s1.y2 < s2.y2;
    }

}



long long* Start(long long list[],long long num){
    long long temp[num];
    Mergesort(list,temp,0,num-1);
    return list;
}

void Mergesort(long long list[] , long long temp[],long long left ,long long right){

     long long Center = (left+right)/2;

     if(left < right){

        Mergesort(list ,temp, left ,Center);
        Mergesort(list ,temp, Center+1 ,right);
        Merge(list , temp ,left ,Center ,right);

     }

}

void Merge(long long list[] , long long temp[] , long long left ,long long Center ,long long right){
    long long Aptr = left;
    long long Bptr = Center+1;
    long long Cptr = left;
    while(Cptr != right+1){
        if(Aptr != Center+1 && Bptr != right +1){
            if(list[Aptr] < list[Bptr]){
                temp[Cptr] = list[Aptr];
                Cptr ++;
                Aptr ++;
            }
            else{
                temp[Cptr] = list[Bptr];
                Cptr ++;
                Bptr ++;
            }
       }

        else if(Aptr == Center +1){
            temp[Cptr] = list[Bptr];
            Cptr ++;
            Bptr ++;
        }
        else if(Bptr == right+1){
            temp[Cptr] = list[Aptr];
            Cptr ++;
            Aptr ++;
        }
    }
        long long tempnum = left;
        while(tempnum != right+1){
            list[tempnum] = temp[tempnum];
            tempnum++;
        }
}


points* Start_struct(points list[],long long num){
    points temp[num];
    Mergesort_struct(list,temp,0,num-1);
    return list;
}

void Mergesort_struct(points list[] , points temp[],long long left ,long long right){

     long long Center = (left+right)/2;

     if(left < right){

        Mergesort_struct(list ,temp, left ,Center);
        Mergesort_struct(list ,temp, Center+1 ,right);
        Merge_struct(list , temp ,left ,Center ,right);

     }

}

void Merge_struct(points list[] , points temp[] , long long left ,long long Center ,long long right){
    long long Aptr = left;
    long long Bptr = Center+1;
    long long Cptr = left;
    while(Cptr != right+1){
        if(Aptr != Center+1 && Bptr != right +1){
            if(compare(list[Aptr] , list[Bptr])){
                temp[Cptr] = list[Aptr];
                Cptr ++;
                Aptr ++;
            }
            else{
                temp[Cptr] = list[Bptr];
                Cptr ++;
                Bptr ++;
            }
       }

        else if(Aptr == Center +1){
            temp[Cptr] = list[Bptr];
            Cptr ++;
            Bptr ++;
        }
        else if(Bptr == right+1){
            temp[Cptr] = list[Aptr];
            Cptr ++;
            Aptr ++;
        }
    }
        long long tempnum = left;
        while(tempnum != right+1){
            list[tempnum] = temp[tempnum];
            tempnum++;
        }
}

