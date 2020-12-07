#include <iostream>

using namespace std;

struct Node{
    long long num;
    long long pow;
    Node *Next = nullptr;
};


int main()
{
    register long long total_count = 0;
    cin >> total_count;
    while(total_count != 0){
    register long long count = 0;
    Node* to_first;
    Node* to_second;
    Node *first;
    Node *last;
    Node *second;
    while(count != 2){
        long long temp = 0;
        cin >> temp;
        long long tempa = temp;
//        if(count == 0){
        while(temp != 0){
            Node *a = new Node;
            cin >> a->num;
            cin >> a->pow;
            if(temp != tempa){
                last->Next = a;
            }
            last = a;
            if(tempa == temp && count == 0){
                first = a;
            }
            if(tempa == temp && count ==1){
                second = a;
            }
            temp--;
        }
//        }
//        else{
            /*
            while(temp != 0){
                Node *temp_ptr = first;
                long long temp_num = 0;
                long long temp_pow = 0;
                cin >> temp_num >> temp_pow;

                if(temp_pow < first->pow){
                    Node *b = new Node;
                    b->Next = first;
                    b->num = temp_num;
                    b->pow = temp_pow;
                    first = b;

                }
                else{
                while(temp_ptr != nullptr){

                     if(temp_ptr->pow == temp_pow){
                         break;
                     }
                     if(temp_ptr->Next != nullptr &&temp_ptr->pow < temp_pow && temp_ptr->Next->pow > temp_pow){
                         break;
                     }
                     if(temp_ptr->Next == nullptr){
                         break;
                     }
                    temp_ptr = temp_ptr->Next;
                }

                if(temp_ptr->pow == temp_pow){
                    temp_ptr->num +=temp_num;
                }
                else if(temp_ptr->pow < temp_pow){
                    Node *a = new Node;
                    a->pow = temp_pow;
                    a->num = temp_num;
                    a->Next = temp_ptr->Next;
                    temp_ptr->Next = a;
                }
                }
//                cout << temp<<endl;
                temp--;
            }*/
//        }

        count++;
    }
    to_first = first;
    to_second = second;
    Node *third;
    Node *last_third;
    int count_temp = 0;
    while(first != nullptr && second != nullptr){
        Node *a = new Node;
        if(count_temp == 0){
            count_temp = 1;
            third = a;
            last_third = a;
        }
        if(first->pow == second->pow){
            a->pow = first->pow;
            a->num = first->num + second->num;
            first = first->Next;
            second = second->Next;
            last_third->Next = a;
            last_third = a;
            continue;
        }
        if(first->pow > second->pow){
            a->pow = second->pow;
            a->num = second->num;
            second = second->Next;
            last_third->Next = a;
            last_third = a;
            continue;
        }
        if(second->pow > first->pow){
            a->pow = first->pow;
            a->num = first->num;
            first = first->Next;
            last_third->Next = a;
            last_third = a;
            continue;
        }

    }

    if(first != nullptr){
        last_third->Next = first;
    }
    if(second != nullptr){
        last_third->Next = second;
    }


    string temp = "";
    Node *ant = third;
    int temp_count = 0;
    while (ant != nullptr)
    {

      if (ant->num < 0)
      {
        if (ant->num == -1)
        {
          temp+="-";
        }
        else
        {
          temp+=to_string(ant->num);
        }

        if (ant->pow == 0)
        {
        }
        if (ant->pow == 1)
        {
          temp+="x";
        }
        else if(ant->pow!=0&ant->pow!=1)
        {
          temp+="x^";
          temp+=to_string(ant->pow);
        }
      }
      if (ant->num > 0)
      {
        if (ant->num != 1)
        {

          if (temp_count != 0)
          {
            temp+="+";
            temp+=to_string(ant->num);

          }
          else
          {
            temp+=to_string(ant->num);

          }
          if (ant->pow == 0)
          {
          }
          if (ant->pow == 1)
          {
            temp+="x";

          }
          else if(ant->pow!=0&ant->pow!=1)
          {
            temp+="x^";
            temp+=to_string(ant->pow);

          }
        }
        else if (ant->num == 1)
        {

          if (temp_count != 0)
          {
            temp+="+";

          }

          if (ant->pow == 0)
          {
           temp+="1";
          }
          if (ant->pow == 1)
          {
            temp+="x";
          }
          else if(ant->pow!=0&ant->pow!=1)
          {
            temp+="x^";
            temp+=to_string(ant->pow);

          }
        }
      }
      ant = ant->Next;
      temp_count++;
    }
    if (temp.length()==0)
    {
       temp+="0";
    }
    if (temp[0]=='+')
    {
      temp=temp.substr(1,temp.length());
    }

/*    while(ant != nullptr){
        if(ant->num == 0){
            ant = ant->Next;
            continue;
        }
        if(ant->num < 0){
            if(ant->num != -1){
                temp+=to_string(ant->num);
            }
            else{
                temp+="-";
            }
        }
        if(ant->num > 0){
            if(ant->num != 1){
                    temp+="+"+to_string(ant->num);
            }
            else{
                if(ant->pow != 0){
                    temp+="+";
                }
                else{
                    temp+="1";
                }
            }

        }

        if(ant->pow == 1){
            temp+="x";
        }
        if(ant->pow == 0){
        }
        if(ant->pow != 1 && ant->pow != 0){
            temp+="x^"+to_string(ant->pow);
        }
//        temp += ant->num + "x^" + ant->pow ;
//        if(ant->Next != nullptr){
//            cout << "+";
//        }
        ant = ant->Next;
    }
//    cout << temp;
    if(temp.length() == 0){
        temp+="0";
    }

    if(temp.at(0) == '+'){
        temp = temp.substr(1);
    }

    if(temp.length() == 0){
        temp+="0";
    }
    */
    cout << temp<<endl;

    while(third != nullptr){
        Node *a_temp;
        a_temp = third->Next;
        delete third;
        third = a_temp;
    }



    total_count--;
    }
}
