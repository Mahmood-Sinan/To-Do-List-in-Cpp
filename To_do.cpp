#include <iostream>
#include <vector>
using namespace std;

class page{
   private:
      string heading;
      vector<string> tasks;
   public:
      page(){
         cout<<"Enter a heading: ";
         std::getline(std::cin, heading);
         this->heading = heading;
         cout<<"Page successfully created\n";
      }
      void add_task(){
         string task;
         cout<<"Enter the task: ";
         std::getline(std::cin, task);
         tasks.emplace_back(task);
         cout<<"Task successfully added\n";
      }
      void remove_task(){
         int n=0;
         cout<<"Enter the task number to be removed: ";
         cin>>n;
         if(n<1||n>tasks.size()){
            cout<<"Task not found\n";
         }
         else{
            tasks.erase(tasks.begin()+n-1);
            cout<<"Task successfully removed\n";
         }
      }
      void display(){
         cout<<"********************\n";
         cout<<heading<<'\n';
         for(int i=0;i<tasks.size();i++){
            cout<<i+1<<": "<<tasks[i]<<'\n';
         }
         cout<<"********************\n";
      }
};

int main(){
   page page_1;
   page_1.display();
   page_1.add_task();
   page_1.add_task();
   page_1.add_task();
   page_1.display();
   page_1.remove_task();
   page_1.display();
   return 0;
}