#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> booked_number;
vector<int> seat_number;

class threatre{
    private:
        int seat[50];
        string time_slot[5] = {"9 AM-11AM","12 PM-2 PM","3 PM-5 PM","6 PM-8 PM","9 PM-11 PM"};
        int price[5] = {150 , 200 , 180 , 300 , 120};
        string movies[5]= {"PATHAAN " , "shivam " , "suprit" , "utkarsh" , "sachin"};
        string booked_movies[100];
        int option ;
		int check;
        
		
		
    public:
       
        void start();
        void bookTicket();
        void cancelTicket();
        void changePrice();
        void bookingRecords();
        void showSeat();
		void assign_seat_number();
        void vec_check(){
            for(int i = 0 ; i < booked_number.size() ; i++){
                cout << booked_number[i] << endl;
                cout << seat_number[i]; 
            }
        }
};

void threatre::cancelTicket(){
    for(int i = 0 ; i<booked_number.size() ; i++ ){
        int now = booked_number[i];
        cout << "["<<i+1 << "] " << movies[now -1] << " | " << seat_number[i] << endl;
    }
    cout << "Enter the ticket number you wnat to cancel ";
    cin >>option ;
    booked_number.erase(booked_number.begin()+option-1);
    seat_number.erase(seat_number.begin()+option-1);

    cout << "Would u like to cancel more tickets " << endl;
    cout << "PRESS 1 FOR YES " << endl;
    cout << "PRESS any key FOR MAIN MENU " << endl;

    cin >> option ;

    if(option == 1){
        cancelTicket();
    }
    else{start();}
}


void threatre::changePrice(){
    for(int i = 0 ; i < 5 ; i++){
        cout << "["<<i+1 << "] - " << movies[i] << endl;
    }

    cout << "Enter the movie number whose prize u want to change "; cin >>option;
    cout << "Current Price = " << price[option-1] <<endl;
    cout << "Enter the  new price " << endl;
    int pricea;
    cin >> pricea;
    price[option-1] = pricea ;

    start();
}


void threatre::bookingRecords(){
    for(int i = 0 ; i < booked_number.size() ; i++){
        int now = booked_number[i];
        cout << movies[now-1] << " | " << time_slot[now -1] <<  " | "<< seat_number[i]<< endl;
    }
}


void threatre::assign_seat_number(){
	for(int i = 0 ; i < 50 ; i++){
		seat[i] = i+1;
	}
}


void threatre::showSeat(){
	cout << "AVAILABLE SEATS ARE " <<endl;
	cout << endl;
	for(int i = 0 ; i< 50 ; i++){
		cout << seat[i] << " " ;
	}
}



void threatre::bookTicket(){
    system("clear");
    for(int i = 0 ; i <46 ; i++){
        cout << "-" ;
    }
    cout << endl;
    cout << "The list of movies and their pricing is listed below " << endl;
    for(int i = 0 ; i< 46 ; i++){
        cout << "-";
    }
    cout << endl;
    cout << "MOVIE NAME " << " | " << " PRICINGS "  << " | " << " TIMINGS " << endl;
    
    cout << endl;
    for(int i  = 0 ; i <5; i++ ){
        cout <<"[" << i+1 << "] " << movies[i] << " | " << price[i] << " | " << time_slot[i]<< endl;;

    };
	for(int i= 0 ; i < 46 ; i++){
		cout << "-";
	}
	cout << endl;
	cout << "ENTER YOUR CHOICE " << endl;
	cin >> option;
    booked_number.push_back(option);

	check = option -1 ;
	booked_movies[check] = movies[check];
	showSeat();
	cout << endl;
	cout << "ENTER THE SEAT NUMBER YOU WANT TO BOOK " <<endl;
	cin >> option ;
	for(int i = 0 ; i < 50 ; i++){
		if(seat[i] == option){
			seat[i] = 0;
		}
	};
    seat_number.push_back(option);
	showSeat();
	cout << endl;
	cout << "Press any key  to return to main menu" << endl;
	cin >> option;
	if(option == 1){
		start();
	}
	else{
		start();
	}
}

void threatre::start(){

    cout << "\t WELCOME TO THE TICKET BOOKING SYSTEM " <<endl;
    cout << "\t";
    for(int i = 0 ; i < 46 ; i++){
        cout << "-" ;
    }
    cout << "\n";

    cout << "[1] BOOK TICKET" << endl << "[2] CANCEL TICKET " << endl << "[3] Change ticket price" << endl << "[4] Booking records" << endl;
    
    for(int i = 0 ; i < 36 ; i++){
        cout << "-" ;
    }
    cout << endl;
    cout << "Enter the appropriate choice " <<endl;
    cout << ">> " ; cin >> option;
    if(option > 5){
        cout << "INVALID INPUT " << endl;
        start();
    }
    else if(option == 1){
        bookTicket();
    }
    else if(option == 4){
        bookingRecords();
    }
    else if(option == 5){
        vec_check();
    }
    else if(option == 3){
        changePrice();
    }
    else if(option == 2){
        cancelTicket();
    }

}



int main(){
    threatre a;
	a.assign_seat_number();
    a.start();
   
    return 0;
}