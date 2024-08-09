#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

enum class Genre { Fantasy, Prose, Periodicals, Biography, Children };

class Date5_9
{
private:
    int y, m, d;
public:
    Date5_9(int y, int m, int d) : y(y), m(m), d(d) {}
    int day() const { return d; }
    int month() const { return m; }
    int year() const { return y; }
};

class Book 
{
private:
    string isbn;
    string title;
    string author;
    string copyrightDate;
    Genre genre;
    bool isOnHands;
public:
    Book(const string& isbn, const string& title, const string& author, const string& copyrightDate, Genre genre)
        : isbn(isbn), title(title), author(author), copyrightDate(copyrightDate), genre(genre), isOnHands(false) 
    {
        if (!checkISBN(isbn)) throw invalid_argument("Неверный формат ISBN");
    }

    string getISBN() const { return isbn; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getCopyrightDate() const { return copyrightDate; }
    bool isOnHand() const { return isOnHands; }
    static bool checkISBN(string isbn);
    Genre getGenre() const { return genre; }
    void giveBook() { isOnHands = true; }
};

class Patron 
{
private:
    string name;
    int cardNumber;
    double membershipFee;
    bool hasPaidMembership;
public:
    Patron(const string& name, int cardNumber, double membershipFee)
        : name(name), cardNumber(cardNumber), membershipFee(membershipFee), hasPaidMembership(false) {}
   
    string getName() const { return name; }
    int getCardNumber() const { return cardNumber; }
    double getMembershipFee() const { return membershipFee; }
    bool hasPaidMemberships() const { return hasPaidMembership; }
    void setHasPaidMembership(bool status) { hasPaidMembership = status; }
};

struct Transaction 
{
    Book book;
    Patron patron;
    Date5_9 date;

    Transaction(const Book& b, const Patron& p, const Date5_9& d)
        : book(b), patron(p), date(d) {}
};

class Library 
{
private:
    vector<Book> books;
    vector<Patron> patrons;
    vector<Transaction> transactions;
    
public:
    void addBook(const Book& book)  { books.push_back(book); }
    void addPatron(const Patron& patron) { patrons.push_back(patron); }
    vector<string> getDebtors() const;
    bool handleTransaction(const Book& book, const Patron& patron);
};

void print_ex5_6();
void print_ex7();
void print_ex8();
void print_ex9();
