#include <iostream>
#include <vector>
using namespace std;

class Page{
   private:
      string heading;
      vector<string> tasks;
   public:
      Page(){
         cout<<"Enter a heading: ";
         std::getline(std::cin, heading);
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
         cin>>n;cin.ignore();
         if(n<1||n>tasks.size()){
            cout<<"Task not found\n";
         }
         else{
            tasks.erase(tasks.begin()+n-1);
            cout<<"Task successfully removed\n";
         }
      }
      void display(){
         if(tasks.size()==0){
            cout<<"\n********************\n\n";
            cout<<heading<<"\n\n";
            cout<<"There are no tasks\n";
            cout<<"\n********************\n";
            return;
         }
         cout<<"\n********************\n\n";
         cout<<heading<<"\n\n";
         for(int i=0;i<tasks.size();i++){
            cout<<i+1<<": "<<tasks[i]<<'\n';
         }
         cout<<"\n********************\n";
      }
      string getHeading() const{
         return heading;
      }
};

class Book{
   private:
      vector<Page> pages;
   public:
      void add_page(){
         Page newpage;
         pages.emplace_back(newpage);
      }
      void remove_page(){
         int n=0;
         cout<<"Enter the page number to be removed: ";
         cin>>n;cin.ignore();
         if(n<1||n>pages.size()){
            cout<<"Page not found\n";
         }
         else{
            pages.erase(pages.begin()+n-1);
            cout<<"Page successfully removed\n";
         }
      }
      void display_pages(){
         if(pages.size()==0){
            cout<<"There are no pages\n";
            return;
         }
         cout<<'\n';
         for(int i=0;i<pages.size();i++){
            cout<<i+1<<". "<<pages[i].getHeading()<<'\n';
         }
      }
      Page& get_page(int i){
         return pages[i-1];
      }
      int get_number_of_pages(){
         return pages.size();
      }
};

int main(){
   Book book;
   int book_choice = 0, page_choice = 0;
   cout<<"\n\nWELCOME TO MY TODO LIST\n\n";
   do{
      cout<<"\nMenu\n";
      cout<<"1. Add page\n";
      cout<<"2. Remove page\n";
      cout<<"3. View all pages\n";
      cout<<"4. Go to a page\n";
      cout<<"5. Exit\nEnter a choice: ";
      cin>>book_choice;cin.ignore();
      switch(book_choice){
         case 1:
            book.add_page();
            break;
         case 2:
            book.remove_page();
            break;
         case 3:
            book.display_pages();
            break;
         case 4:
            cout<<"Enter the page no that you want to go to: ";
            cin>>page_choice;cin.ignore();
            if(page_choice<1||page_choice>book.get_number_of_pages()){
               cout<<"That page does not exist\n";
            }
            else{
               Page& cur_page = book.get_page(page_choice);
               cur_page.display();
               int task_choice = 0;
               do{
                  cout<<"\n1. Add task\n";
                  cout<<"2. Remove task\n";
                  cout<<"3. View tasks\n";
                  cout<<"4. Go back to Main Menu\n";
                  cout<<"Enter a choice: ";
                  cin>>task_choice;cin.ignore();
                  switch(task_choice){
                     case 1:
                        cur_page.add_task();
                        break;
                     case 2:
                        cur_page.remove_task();
                        break;
                     case 3:
                        cur_page.display();
                        break;
                     case 4: 
                        break;
                     default:cout<<"Enter a valid choice\n";
                  }
               }while(task_choice!=4);
            }
         case 5:
            break;
         default:cout<<"Enter a valid choice\n";
      }
   }while(book_choice!= 5);
   cout<<"Programme exiting\n";
   return 0;
}