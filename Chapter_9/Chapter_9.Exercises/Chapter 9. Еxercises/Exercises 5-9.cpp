#include  "Header_ex5_9.h"

bool operator==(const Book& lhs, const Book& rhs) 
{
    return lhs.getISBN() == rhs.getISBN();
}

bool operator!=(const Book& lhs, const Book& rhs) 
{
    return !(lhs == rhs);
}

ostream& operator<<(ostream& os, const Book& book) 
{
    os << "Title: " << book.getTitle() << "\n"
        << "Author: " << book.getAuthor() << "\n"
        << "ISBN: " << book.getISBN();
    return os;
}

void Library::handleTransaction(const Book& book, const Patron& patron)
{
    bool isPatronMember = false;
    if (!patron.hasPaidMemberships()) 
    {
        cout << "������: ���������� �� ������� �������� ������.\n";
        return;
    }

    for (const auto& p : patrons) 
    {
        if (p.getCardNumber() == patron.getCardNumber()) 
        {
            isPatronMember = true;
            break;
        }
    }

    if (!isPatronMember) 
    {
        cout << "������: ���������� �� �������� ������ ����������." << endl;
        return;
    }

    auto it = find(books.begin(), books.end(), book);
    if (it == books.end())
    {
        cout << "������: ����� �� ������� � ����������." << endl;
        return;
    }

    if (it->isOnHand())
    {
        cout << "������: ����� ��� ������." << endl;
        return;
    }

    it->giveBook(); 
    transactions.push_back(Transaction(*it, patron, Date(2024, 8, 02)));
    cout << "����� ������� ������ ���������." << endl;
}

vector<string> Library::getDebtors() const
{
    vector<string> debtors;
    for (const auto& patron : patrons) 
    {
        if (!patron.hasPaidMemberships()) 
        {
            debtors.push_back(patron.getName());
        }
    }
    return debtors;
}

void print_ex5_6() 
{
    Book book("123-456-789-X", "����� � ���", "��� �������", "1869", Genre::Prose);

    // ����� ���������� � �����
    cout << book << "\n";

    // ������ �����
    book.giveBook();

    // �������� ������� ������ �����
    if (book.isOnHand())
    {
        cout << "����� ������.\n";
    }
    else 
    {
        cout << "����� �� ������.\n";
    }
}

void print_ex7()
{
    Book book1("123-456-789-X", "����� � ���", "��� �������", "1869", Genre::Prose);
    Book book2("987-654-321-Y", "���� ��������", "��� �������", "1878", Genre::Prose);

    // ��������� ���� �� ISBN
    if (book1 == book2) 
    {
        cout << "����� ����� ���������� ISBN.\n";
    }
    else 
    {
        cout << "ISBN ���� �����������.\n";
    }

    // ����� ���������� � ����� � �������������� ��������� <<
    cout << book1;
}

void print_ex8()
{
    // �������� ������� ������ Patron
    Patron patron("���� ������", 12345, 100.0);

    // ��������� ������� ������ ��������
    patron.setHasPaidMembership(true);

    // �������� ������� ������ ��������
    if (patron.hasPaidMemberships())
    {
        cout << "�������� ������ ��������.\n";
    }
    else 
    {
        cout << "�������� ������ �� ��������.\n";
    }
}

void print_ex9()
{
    Library library;

    // ���������� ����� � ����������
    Book book("123-456-789-X", "����� � ���", "��� �������", "1869", Genre::Prose);
    library.addBook(book);

    // ���������� ������������ � ����������
    Patron patron("���� ������", 12345, 100.0);
    library.addPatron(patron);

    // ��������� ���������� ������ ����� ������������
    library.handleTransaction(book, patron);
}