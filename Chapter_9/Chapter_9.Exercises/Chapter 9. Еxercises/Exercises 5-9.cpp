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

bool Library::handleTransaction(const Book& book, const Patron& patron)
{
    bool isPatronMember = false;
    if (!patron.hasPaidMemberships()) 
    {
        cout << "������: ���������� �� ������� �������� ������.\n";
        return false;
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
        return false;
    }

    auto it = find(books.begin(), books.end(), book);
    if (it == books.end())
    {
        cout << "������: ����� �� ������� � ����������." << endl;
        return false;
    }

    if (it->isOnHand())
    {
        cout << "������: ����� ��� ������." << endl;
        return false;
    }

    it->giveBook(); 
    transactions.push_back(Transaction(*it, patron, Date5_9(2024, 8, 02)));
    cout << "����� ������� ������ ���������." << endl;
    return true;
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

bool Book::checkISBN(string isbn)
{
    istringstream iss(isbn);
    int n1, n2, n3;
    char c1, c2, c3, c4;
    string rem;

    iss >> n1 >> c1 >> n2 >> c2 >> n3 >> c3 >> c4 >> rem;
    if (rem.size() != 0) return false;
    if (c1 != '-' || c2 != '-' || c3 != '-') return false;
    if (n1 <= 0 || n2 <= 0 || n3 <= 0) return false;
    if (!isalnum(c4)) return false;
    return true;
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

