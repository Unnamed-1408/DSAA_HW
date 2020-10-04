#include <iostream>
#include <algorithm>

using namespace std;

struct points{
    long long y1;
    long long y2;
};


bool compare(points s1, points s2);



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
    sort(to_compare , to_compare+count);
    temp = 0;

    while(temp != count){
        if(output[temp].y2 != to_compare[temp]){
//            cout << output[temp].y2 << endl;
//            cout << to_compare[temp] << endl;
            cout << "YES" << endl;
            return 0;
        }
        temp++;
    }

    cout << "NO" << endl;
/*
    int output[2][count];

    int* outptr = output[0];

    while(temp != count){
        output[0][temp] = list[temp][0]*x1+list[temp][1];
        output[1][temp] = list[temp][0]*x2+list[temp][1];
        temp++;
    }

    sort(*(outptr) , *(outptr+count));
    temp = 0;
    int compare[count];

    while(temp != count){
        compare[temp] = output[1][temp];
        temp++;
    }
    sort(compare , compare+count);

    temp = 0;
    while(temp != count){
        if(output[1][temp] != compare[temp]){
            cout << "YES" << endl;
            return 0;
        }
        temp++;
    }
    cout << "NO" << endl;
*/
}
bool compare(points s1, points s2){
    if(s1.y1 != s2.y1){
    return s1.y1 < s2.y1;
    }
    else{
        return s1.y2 < s2.y2;
    }

}
