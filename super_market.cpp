#include<bits/stdc++.h>
#include<fstream>
#include<string.h>
#include <exception>

using namespace std;
 int static num;	
class supermarket{                
	private :
  
	char P_ID[10] ,  P_ID_R[10], P_Name[25], P_Name_R[25], P_Qnt[6], P_Cost[10];	
	bool id_r ,name_r;
	
	public :
     supermarket();
     ~supermarket();
     void  insert();
	 void display();
	 void update();
	 void search();
	 void Delete();
     char  count();       


};

class bill: public supermarket{
	
private:
char ID[25] ,pro[25];

public:
	
	void ADDBILL();
	void ADDPRO();
	
};
// Constructor  //
 supermarket::supermarket(){
 	
 	for(int i=0 ;i<10 ;i++)
 	 P_ID[i]='0';
 	
 	for(int i=0 ;i<25 ;i++)
 	 P_Name[i]='0';
 	
 	for(int i=0 ;i<6 ;i++)
 	 P_Qnt[i]='0';
 	
 	for(int i=0 ;i<10 ;i++)
 	 P_Cost[i]='0';
 }
// ~destructor  //
supermarket::~supermarket(){
	
}

// to insert data //
void supermarket::insert(){
	  char m;   
	do{
		id_r = false ;
		name_r = false;
		fstream f;
		f.open("super_markets.txt" ,ios::in );
         
		 cin.ignore();
		 
		 cout<<"Enter ID           :";
		 cin.getline(P_ID ,10); 
		  
		  while(!f.eof()){
		f.getline( P_ID_R ,10 ,'|');	
		f.getline(P_Name_R, 25, '|');
		f.getline(P_Qnt, 6, '|');
		f.getline(P_Cost, 10, '\n');	
			  if(strcmp(P_ID ,P_ID_R)==0){
		  	  id_r=true ;
			  break;	
			  }
		    
		  }
		  
		  if(id_r){
		  	cout<<"This ID already exist :( \n";}
		else{
			f.close();
			f.open("super_markets.txt" ,ios::app);
				cout<<"Enter product Name         :";
				cin.getline( P_Name  ,25);
				cout << "Enter Product Cost       : ";
				cin.getline(P_Cost, 10);
				cout << "Enter Product Quantity   : ";
				cin.getline(P_Qnt, 6);
		f<<P_ID<<'|'<<P_Name<<'|'<<P_Cost<<'|'<<P_Qnt<<"\n";
	    num++;
		cout<<"This Product Is Succeded Insert :) \n";
		}	
		
		cout<<"If You Want To Insert More enter < M or m > \n ";
		 cin>>m;
		 f.close();
	} while ( m=='M' or  m=='m' );
	
	
	
}
// to show data //
void supermarket::display(){
	
	char idd[5] ,name[25] , cost[10] , quan[25];
	fstream f;
	f.open("super_markets.txt" , ios::in);
	
	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout  << "pro_ID" <<"\t\t" << " Name" << "\t\t" << " cost" << "\t\t"<< "  Quantity#" << endl;
      cin.ignore();
	   while(!f.eof()){
	  
		  f.getline(idd ,5 ,'|');
		f.getline(name ,25 ,'|');
	  	f.getline(cost ,10 ,'|');
	  	f.getline(quan ,25 );
		cout  << idd <<"\t\t " <<name << "\t\t  " << cost<< "\t\t    "<< quan << endl;
	  	}
	f.close();
	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
}
// to search in data //
void supermarket::search(){
	
	char idd[5] ,name[25] , cost[10] , quan[25];
	char op[2], x[2];
	do{
	 trys:
	
	cout << "#To Search By Name      : 1 \n" 
	     << "#To Search By ID        : 2 \n";
	
	// Exception Handling
	try
	{
	cin>>op[0];
	
	if(op[0]=='1'){
	cout<<"Enter The Name :";
	cin.ignore();
	cin.getline( P_Name , 25 );}
	
	else if( op[0]=='2' ){
	cout<<"Enter The ID :";
	cin.ignore();
	cin.getline(P_ID ,10);}
	
	else
	throw("enter correct 1 or 2 only :) \n");
	
	}
   
    catch(const char* q){
    	cout<<q;
		goto trys;
		}
	
	  fstream f;
	  f.open("super_markets.txt" ,ios::in);
	

	  bool ex=true ;
	   while(!f.eof()){
	   
	   	f.getline( idd ,5 ,'|');
	   	f.getline( name ,25 ,'|');
	   	f.getline( cost ,10 ,'|');
	   	f.getline( quan ,25 );
	   
	   if( strcmp(idd,P_ID)==0 or strcmp(P_Name ,name)==0 ){
	    cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	   cout  << "pro_ID" <<"\t\t" << " Name" << "\t\t" << " cost" << "\t\t"<< "  Quantity#" << endl;
	   cout  << idd <<"\t\t " <<name << "\t\t  " << cost<< "\t\t    "<< quan << endl;  
	    cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        ex=false;
        break;
		}
	   
	   
	   }
	
	   if(ex)
	   cout<<"this product not exist :(\n";

cout<<"If You Want Search More Enter ( m or M )\n";
cin>>x[0];
f.close();
}while(  x[0]=='m' or x[0]=='M'  );
	
	
}

// to delete some rows //
void supermarket::Delete(){
	
	char idd[10] ,name[25] , cost[10] , quan[25] ,x[2] ;
	bool fou;
	int c;
	fstream f, t;
	do{
		fou=false;
		f.open("super_markets.txt" , ios::in);
		t.open( "copy.txt" , ios::app );
		here:
     cout << "#To Delete By ID      : 1 \n" 
	      << "#To Delete By Name    : 2 \n";
        try{
          cin>>c;   	
         if(c==1){
           cin.ignore();
		 	cout<<"Enter ID : ";
         	cin.getline( P_ID , 10 );
        }
		else if(c==2){
			cin.ignore();
			cout<<"Enter Name : ";
			cin.getline( P_Name ,25  );
		}    	
        else
         throw "Choose 1 Or 2 Only :) \n";
        
		}
        
       catch(const char* x){
       	 cout<<x;
       	 goto here;
	   }
  
         while(!f.eof()){
         	
         	f.getline( idd ,10 ,'|'  );
         	f.getline( name ,25 ,'|'   );
         	f.getline( cost ,10 ,'|'   );
         	f.getline( quan , 25  );
         	
         	if( strcmp(idd ,P_ID)==0 or strcmp(name ,P_Name)==0 ){
			 num--;
			 continue;}
         	else
         	t<<idd<<'|'<<name<<'|'<<cost<<'|'<<quan<<"\n";
         
	 }
     t.close();
     f.close();
	 remove("super_markets.txt");
	 rename("super_markets.txt"  , "copy.txt");
     rename( "copy.txt" , "super_markets.txt" );
    
   cout<<"If You Want Delete More Enter ( m or M )\n";
     cin>>x[0];
   
         	}while(x[0]=='m' or x[0]=='M');
     
     

} 
//to update the some rows in the data //
void supermarket::update(){
	
	
	
	
		
	char idd[10] ,name[25] , cost[10] , quan[25] ,x[2] ;
	int c;
	fstream f, t;
	do{
		f.open("super_markets.txt" , ios::in);
		t.open( "copy.txt" , ios::app );
		here:
     cout << "#To update By ID      : 1 \n" 
	      << "#To update By Name    : 2 \n";
        try{
          cin>>c;   	
         if(c==1){
           cin.ignore();
		 	cout<<"Enter ID : ";
         	cin.getline( P_ID , 10 );
        }
		else if(c==2){
			cin.ignore();
			cout<<"Enter Name : ";
			cin.getline( P_Name ,25  );
		}    	
        else
         throw "Choose 1 Or 2 Only :) \n";
        
		}
        
       catch(const char* x){
       	 cout<<x;
       	 goto here;
	   }
  
         while(!f.eof()){
         	f.getline( idd ,10 ,'|'  );
         	f.getline( name ,25 ,'|'   );
         	f.getline( cost ,10 ,'|'   );
         	f.getline( quan , 25  );
         	
         	if( strcmp(idd ,P_ID)==0 or strcmp(name ,P_Name)==0 ){
			  //cin.ignore();
		    // cout<<"hey\n";
			 cout<<"Enter New ID           :";
		     cin.getline(idd ,10); 	
     		 cout<<"Enter product Name         :";
			 cin.getline( name  ,25);
			 cout << "Enter Product Cost       : ";
			 cin.getline(cost, 10);
			 cout << "Enter Product Quantity   : ";
			 cin.getline(quan, 25);	
         	t<<idd<<'|'<<name<<'|'<<cost<<'|'<<quan<<"\n";
			 continue;	
			 
			 }
         	else
         	t<<idd<<'|'<<name<<'|'<<cost<<'|'<<quan<<"\n";
         
	 }
	
     t.close();
     f.close();
	 remove("super_markets.txt");
	 rename("super_markets.txt"  , "copy.txt");
     rename( "copy.txt" , "super_markets.txt" );
    
   cout<<"If You Want Delete More Enter ( m or M )\n";
     cin>>x[0];
   
         	}while(x[0]=='m' or x[0]=='M');	
	
}
// to count the number of record //
char  supermarket::count(){
	char idd[5] ,name[25] , cost[10] , quan[25] ,x[5] ,xx[5];
	
	if(num==0){  // as if you update or delete the date //
	fstream f;
	f.open("super_markets.txt" , ios::in);
	  while(!f.eof()){
	  
		f.getline(idd ,5 ,'|');
		f.getline(name ,25 ,'|');
	  	f.getline(cost ,10 ,'|');
	  	f.getline(quan ,25 );
		
		if(strcmp(idd ,"" )==0 )
		continue;
		else
		num++;
	  	}
	f.close();
cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"# The Number Of Record In The System : "<<num<<endl;
cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	}
	else{
	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"# The Number Of Record In The System : "<<num<<endl;
    cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";}

return ' ';
}



//**************** Bill*********************//

void bill::ADDBILL(){
	char x[25] ,o[1];  bool fla=1;
	do{
	trys:
		fla=1;
	cin.ignore();
	cout<<"Enter ID : ";
	cin>>ID[0];
	fstream b;
	b.open("bills.txt" ,ios::in);
	while(!b.eof()){
		b.getline( x, 25 ,'\n' );
		if( strcmp(ID , x) ==0 ){
			fla=0;
			break;
		}
	}
	b.close();
	if(fla==1)
	{
		b.open("bills.txt" ,ios::app);
	    b<<ID<<"\n";
	cout<<"# Created A Bill complete Successfully :)\n";
	}
	else
	{
		cout<<"# This ID Already Exist, Try Again\n";
		goto trys;
	}


	b.close();

cout<<"If You Want Create More Enter <m or M> : ";
cin>>o[0];

}while(o[0]=='m' or o[0]=='M' );
}

void bill::ADDPRO(){
char idd[25] ,name[25] , cost[10] , quan[25] ,o[1];	
	char x[25] ,IDPro[25];
   
     do{

	 bool f1=0 ,f2=0;
	fstream b,f;
	
    cin.ignore();
	here:
	b.open( "bills.txt" ,ios::in );
	cout<<"# Enter Bill ID : ";
	cin.getline(ID ,25);
	      while(!b.eof()){
	      	b.getline(x,25 ,'\n');
		  	if(strcmp(x,ID)==0){
	      	  f1=1;
				break;	
			  }
		  }
	      if(f1==0){
	      	cout<<"this ID Not Exist :( ,Try Again\n";
		   b.close();
		    goto here;
		  }
	   b.close();
	   pro:
	   f.open( "super_markets.txt" ,ios::in );
	   
	   cout<<"Enter The ID Product : ";
	   cin.getline(IDPro, 25);

             while(!f.eof()){
        f.getline( idd ,25 ,'|');
	   	f.getline( name ,25 ,'|');
	   	f.getline( cost ,10 ,'|');
	   	f.getline( quan ,25 );
			 	if( strcmp(IDPro ,idd)==0 ){
             		f2=1;
             		break;
             		}
			 
			 }
       
	   if(f2==0)
			 {
			 	cout<<"this ID Not Exist :( ,Try Again\n";
			 	goto pro;
			 }

f.close();
    cout<<"It Is A Successful Addition :)\n";
  cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
  cout<<"If You Want Add More Enter <m or M> : ";
  cin>>o[0];

}while(o[0]=='m' or o[0]=='M' );


}


void store (){
	supermarket c;
	 int a;
	 bool fla=1;
	 do{
	
	cout << "###########################\n";
		cout << "#To Insert Enter       : 1 #\n" 
		     << "#To Display Enter      : 2 #\n" 
			 << "#To search Enter       : 3 #\n" 
			 << "#To Delete Enter       : 4 #\n"
			 << "#To update Enter       : 5 #\n" 
			 << "#To Count Record       : 6 #\n"
		     << "#To Return To Main Maun: 7 #\n";
		
		cout << "###########################\n";
		
		cout << "Enter Your Choice : ";
        

         cin>>a;
		switch(a){   
		    
			case 1:
		       c.insert();	
		        break;
		    
			case 2:
		        c.display();
		         break;
		    
		    case 3:
		    	c.search();
		    	 break;
		    case 4:
		    	c.Delete();
		        break;
		    
			case 5:
			   c.update();
			   break;    
			
			case 6:
				c.count();
				break;
			case 7:
				cout<<"Thank You :)\n";
				fla=0;
				break;
			
		     
		    default:
			cout << "\aChoose correct Number \n";	
                      
			}
   }while(fla==1);

	


}


void bills(){
	int z; bool fla = true;
	 bill c1;
	 
	 
	  
	    do{
	    cout << "###########################\n";
       cout<<"#To Create New Bill      : 1 #\n"
           <<"#To Add Product to Bill  : 2 #\n"
           <<"#To Return To Main Maun  : 3 #\n";
	  cout << "###########################\n";
	         cin>>z;
	    	switch(z){
	    		
	    		case 1:
	    			c1.ADDBILL();
	    			break;
	    	   
			   case 2:
			   	c1.ADDPRO();
			   	break;
			
				case 3:
					cout<<"# Think You :)\n";
					fla= false;
					break;
			default:
				cout<<"# Chose Correct Numder\n";
			}
	    	
	    	
		}while( fla == true );
	    
	    
	
}



int main(){
		
	fstream f;
	f.open("super_markets.txt" ,ios::app );
	f.close();
	
	
	
	
	int a;
	bool flage =true ;
	

    
	    
	    do{
	  cout << "###########################\n";
       cout<<"#To Store Enter      : 1 #\n"
           <<"#To Bill Enter       : 2 #\n"
           <<"#To Exit Program     : 3 #\n";
	  cout << "###########################\n";
	   cin>>a;
	    	switch (a){
	    		
	    		case 1:
	    			store();
	    			break;
	    	
				case 2:
	    	      bills();
				  break;
				  		
	    		case 3:
	    			flage=false;
	    			break;
	    		
	    		default:
	    			cout<<"#Enter Correct Numder :)\n";
			}
	    	
	    	
	    	
		}while(flage==true);
	  cout<<"Good By :)\n";
	
}
