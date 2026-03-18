#include<iostream>
using namespace std;

class Ibook{
    public:
    virtual int getNubmerofWords(string& s) = 0;
};


class Book: public Ibook{
    private:
    string book;
    public:
    Book(const string& s)
    {
        this->book = s;
    }
    int getNubmerofWords(string& book) override
    {
        return book.size();
    }
};

class bookProxy:public Ibook{
    string book = "";
    Book* bk = nullptr;
    public:
    bookProxy(string& s)
    {
        this->book = s;
    }

    
    int getNubmerofWords(string& s) override
    {
        if(bk == nullptr)
        bk = new Book(book);  // expensive operation and using proxy we are controlling it.

        return bk->getNubmerofWords(book);
    }
};

int main()
{
    string book = "wertyuuhgfdsdfghjnbvcxzxcvghj";

    bookProxy* bp = new bookProxy(book);

    cout << bp->getNubmerofWords(book) << endl; 
}