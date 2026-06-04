#include<iostream>
#include<vector>
using namespace std;

class Book
{
    private:
    int id;
    string name, author;
    bool isIssued;

    public:
    void details()
    {
        cout<<"Book Name: "<<name<<endl
            <<"Book Id: "<<id<<endl
            <<"Author: "<<author<<endl
            <<"Status: "<<(isIssued ? "Issued" : "Available")<<endl;
    }

    Book(int i, string n, string a): id(i), name(n), author(a), isIssued(false){}

    int getId()
    {
        return id;
    }

    string getBookName()
    {
        return name;
    }

    string getAuthorName()
    {
        return author;
    }

    bool issueBook()
    {
        if (isIssued) 
        {
            return false;
        } // book already issued

        isIssued = true;
        return true;    
    }

    bool returnBook()
    {
        if(!isIssued) 
        {   
            return false;
        }

        isIssued = false;
        return true;
    }

};

class Library
{
    private:
    vector<Book> books;

    public:

    void addBook(const Book& b)
    {
        books.push_back(b);
    }

    int bookNameSearch(string n)
    {
        for(int i = 0; i< books.size(); i++)
        {
            if(books[i].getBookName().find(n) != string::npos)
            {    
                return i;
            }    
        }
        return -1;
    }

    int bookAuthorSearch(string a)
    {
        for(int i = 0; i< books.size(); i++)
        {
            if(books[i].getAuthorName().find(a) != string::npos)
            {    
                return i;
            }    
        }
        return -1;
    }

    int idSearch(int id)
    {
        for(int i = 0; i < books.size(); i++)
        {
            if(books[i].getId() == id)
            {
                return i;
            }
        }
        return -1;
    }

    void showBooks()
    {
        if(books.size()==0)
        {
            cout<<"library is empty"<<endl;
            return;
        }
        for(Book& b: books)
        {   
            b.details();
            cout<<"\n";
        }    
    }

    void issueBook(int bookId)
    {
        int result = idSearch(bookId);

        if(result == -1){cout<<"Book not found "; return; }

        cout<<(books[result].issueBook()? "Your Book is Issued successfully. ": "Book is already issued." )<<endl;
        return;   
    }

    void returnBook(int bookId)
    {
        int result = idSearch(bookId);

        if(result == -1) {cout<<"Book not found "; return;}

        cout<<(books[result].returnBook()? "Book return successful.": "Book was not issued.")<<endl;
        return;
    }

    void searchBook()
    {
        cout<<"Enter your choice"<<endl            
            <<"Search by: "<<endl
            <<"1: Book Id"<<endl         
            <<"2: Book name"<<endl
            <<"3: Book author"<<endl
            <<"4: Exit"<<endl;

        int choice;
        int bookId;
        string authorName, bookName;
        cin>>choice;
                        
        switch(choice)
        {
            case 1: {
                        cout<<"enter book id"<<endl;
                        cin>>bookId;

                        int result = idSearch(bookId);
                        if(result==-1){cout<<"Book not found"<<endl; break; }
                        books[result].details();
                        break;
                    }

            case 2: {
                        cout<<"enter book name"<<endl;
                        cin.ignore();
                        getline(cin, bookName);
                        int result = bookNameSearch(bookName);
                        if(result==-1){cout<<"Book not found"<<endl; break; }
                        books[result].details();
                        break;
                    }

            case 3: {
                        cout<<"enter book author name"<<endl;
                        cin.ignore();
                        getline(cin, authorName);
                        int result = bookAuthorSearch(authorName);
                        if(result==-1){cout<<"Book not found"<<endl; break; }
                        books[result].details();
                        break;
                    }

            case 4: cout<<"exiting"<<endl;
                    return;

            default : cout << "Invalid choice" << endl;
                      return;        
        }
        }
    };

int main()
{
    int choice;
    int bookId; 
    string bookName, author;
    Library lib;

    while(true)
    {
        cout<<"enter your choice:"
        <<"\n1. Add Book"
        <<"\n2. Show Books"
        <<"\n3. Issue Book"
        <<"\n4. Return Book"
        <<"\n5. Search Book"
        <<"\n6. Exit"<<endl;

        cin>>choice;

        switch(choice)    
        {
            case 1: {
                        cout<<"enter book details"<<endl;
                        cout<<"\nenter book id: ";
                        cin>>bookId;
                    
                        while(lib.idSearch(bookId)!= -1)
                        {
                            cout<<"book already exist"<<endl;
                            cout<<"enter another book id"<<endl;
                            cin>>bookId;
                        }

                        cin.ignore(); 
                        cout<<"\nenter book name: ";
                        getline(cin, bookName);
                        cout<<"\nenter book's author name: ";
                        getline(cin, author);
                        Book b(bookId, bookName, author);
                        lib.addBook(b);
                        cout<<"\nBook added successfully"<<endl;
                        break;
                    }
            
            case 2: cout<<"all the books in the library are:"<<endl;
                    lib.showBooks();
                    break;

            case 3: cout<<"enter book id"<<endl;
                    cin>>bookId;

                    lib.issueBook(bookId);
                    break;
             
            case 4: cout<<"enter book id"<<endl;
                    cin>>bookId;
                    
                    lib.returnBook(bookId);
                    break;

            case 5: lib.searchBook();
                    break;

            case 6: cout<<"Exiting "<<endl;
                    return 0;

            default: cout<<"Invalid choice"<<endl
                         <<"Try again"<<endl;
                     return 0;    
        }
    }
    return 0;
}