#include "iostream"
using namespace std;
//Stack DSA using Two Queues
//push လုပ်တဲ့အခါမှာ ပုံမှန်ပဲထည့်ပြီးတော့ Pop ပြန်ထုတ်တဲံအချိန်မှာမှ
//Queue ၏ Data Structure အတိုင်း FIFO ထွက်မလာစေရန် နှင့်
//Stack ၏ Structure အတိုင်း LIFO ထွက်လာစေရန် queue နှစ်ခုကို
//element များကို ဟိုဘက်ဒီဘက်swap လုပ်ခြင်းအားဖြင့် ထုတ်သည်။
struct queue1{
    int data1;
    queue1 *next1;
};
struct queue1 *front1,*rear1,*q1,*np1 = NULL;

struct queue2{
    int data2;
    queue2 *next2;
};
struct queue2 *front2,*rear2,*q2,*np2 = NULL;

void enqueue1(int number){
    np1 = new queue1;
    np1->data1 = number;
    np1->next1 = NULL;
    if(front1 == NULL){
        rear1 = np1;
        rear1->next1 = NULL;
        front1=rear1;
    }else{
        rear1->next1 = np1;
        rear1 = np1;
        rear1->next1 = NULL;
    }
}
int dequeue1()
{
    int x;
    if (front1 == NULL)
    {
        cout<<"no elements present in queue\n";
    }
    else
    {
        q1 = front1;
        front1 = front1->next1;
        x = q1->data1;
        delete(q1);
        return x;
    }
}
void enqueue2(int x)
{
    np2 = new queue2;
    np2->data2 = x;
    np2->next2 = NULL;
    if (front2 == NULL)
    {
        rear2 = np2;
        rear2->next2 = NULL;
        front2=rear2;
    }
    else
    {
        rear2->next2 = np2;
        rear2 = np2;
        rear2->next2 = NULL;
    }
}
int dequeue2()
{
    int x;
    if (front2 == NULL)
    {
        cout<<"no elements present in queue\n";
    }
    else
    {
        q2 = front2;
        front2 = front2->next2;
        x = q2->data2;
        delete(q2);
        return x;
    }
}
void pop(){
    while (front1 != NULL || front2 != NULL)
    {
        if (front2 == NULL)
        {
            while (front1->next1 != NULL)
            {
                enqueue2(dequeue1());
            }
            cout<<dequeue1()<<endl;
        }
        else if (front1 == NULL)
        {
            while (front2->next2 != NULL)
            {
                enqueue1(dequeue2());
            }
            cout<<dequeue2()<<endl;
        }
    }
}
int main(){
    int choice,result,element;
    int i,n=0;
    while(1){
        cout << ("1. Push\n");
        cout << ("2. Pop\n");
        cout << ("3. Top\n");
        cout << ("4. Print all elements of the stack\n");
        cout << ("5. isEmpty\n");
        cout << ("5. isFull\n");
        cout << ("6. Quit\n");
        cout << ("Enter your choice: ");
        cin >> choice;

        switch(choice){
            case 1:
                cout << "\nEnter the number of element into stack:\n ";
                cin  >> n;
                while(i<n){
                    cout << "Enter the elements to insert into stack:\n ";
                    cin  >> element;
                    enqueue1(element);
                    i++;
                }
                break;
            case 2:
                cout << "\n\nElements popped\n\n";
                pop();
                break;
            case 6:
                exit(1);
        }
    }
    return 0;
}
