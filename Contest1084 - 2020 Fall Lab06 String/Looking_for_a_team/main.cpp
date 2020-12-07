#include <iostream>
#include <math.h>
#include<algorithm>
using namespace std;

string a = "asdwdas";
string b = "dwasdw";
size_t *str1;
size_t *str2;

void hashing(size_t a_hash[], size_t b_hash[], int length);
bool kmp(int length);
void output(size_t *a, int length);
int binarySearch(int low , int high);

size_t power[100000];

int main()
{

    cin >> a;
    cin >> b;
    int r = (a.length() > b.length()) ? b.length() : a.length();
    power[0] = 1;
    for (int i = 1; i <= r; i++)
    {
        power[i] = power[i - 1] * 139LL;
    }
    str1 = new size_t[a.length()+1]();
    str2 = new size_t[b.length()+1]();
    str1[0] = 0;
    str2[0] = 0;
    for (int i = 0; i < a.length(); i++)
    {
        str1[i + 1] = 139 * str1[i] + a[i];
    }
    for (int i = 0; i < b.length(); i++)
    {
        str2[i + 1] = 139 * str2[i] + b[i];
    }

    cout << binarySearch(0,r) << endl;
}


int binarySearch(int low , int high)
{
    int middle = (low + high+1)/2;
//    cout << "asdasd";
//    cout << low << " " << high << endl;
    if(low >= high){
        return high;
    }
    if(kmp(middle)){
        return binarySearch(middle,high);
    }
    else{
        return binarySearch(low,middle-1);
    }
};


bool kmp(int length){
    size_t *a_hash = new size_t[a.length()-length+1]();
    size_t *b_hash = new size_t[b.length()-length+1]();
    hashing(a_hash, b_hash, length);
//    sort(a_hash,a_hash+a.length()-length+1);
    sort(b_hash,b_hash+b.length()-length+1);
//    output(a_hash,a.length()-length+1);
//    output(b_hash,b.length()-length+1);
    for(int i= 0; i < a.length()-length+1; i++){
        if(binary_search(b_hash,b_hash+b.length()-length+1,a_hash[i])){
            delete a_hash,b_hash;
            return true;
        }
    }
    delete a_hash,b_hash;
    return false;
}

//void hashing(long long a_hash[], long long b_hash[], int length){
//    long long base = 139;
//    long long pow_use = power[length-1];
////    cout << a_hash[1] << endl;
//    for(int i = 0; i < length; i++){
////        a_hash[0] *= base;
////        b_hash[0] *= base;
////        a_hash[0] += a[length-i-1];
////        b_hash[0] += b[length-i-1];
//        a_hash[0] += a[i] * power[length-i-1];
//        b_hash[0] += b[i] * power[length-i-i];
//    }

//    for(int i = length, count = 1; i < a.length(); i++,count++){
//        a_hash[count] = (a_hash[count-1]-a[i-length])/base + a[i]*pow_use;
//        cout <<  (a_hash[count-1]-a[i-length])/base << endl;
//    }
//    for(int i = length, count = 1; i < b.length(); i++,count++){
//        b_hash[count] = (b_hash[count-1]-b[i-length])/base + b[i]*pow_use;
//    }
//}

size_t hashstring(size_t in[], int left, int right)
{
    return in[right] - in[left] * power[right - left];
}

void hashing(size_t a_hash[], size_t b_hash[], int length){
    int count = 0;
    for (int i = length; i <= a.length(); i++,count++)
    {
        a_hash[count] = hashstring(str1, i - length, i);
    }

    count = 0;
    for (int i = length; i <= b.length(); i++,count++)
    {
        b_hash[count] = hashstring(str2, i - length, i);
    }
}

void output(size_t *a, int length){
    for(int i = 0;i < length; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
