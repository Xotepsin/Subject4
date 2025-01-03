#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std; // namespace std ���

class Book {
public:
    string title;
    string author;
    Book() : title(""), author("") {}
    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};

class BookManager {
private:
    vector<Book> books; // å ��� ����

public:
    // å �߰� �޼���
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    }

    // ��� å ��� �޼���
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }
    Book searchByTitle(const string& title){
        for (size_t i = 0; i < books.size(); i++) {     // �Ϲ����� for�� ���
            if (books[i].title == title) {              // ������ i���� �ε����� å�� ������ �Է¹��� title�� ���ٸ�  
                cout << books[i].title << " by " << books[i].author << endl;       // å�� �����, ���ڸ� ���
                return Book(books[i]);                       // å ������ ������ ���� ���ٰ� �����߱� ������ ã���� �ٷ� return���� �ݺ����� ����
            }
        }
        cout << "���� �������� " << title << "�̶�� ������ å�� �������� �ʽ��ϴ�!" << endl;
        return Book();
    }
    void searchByAuthor(const string& author) {
        bool isbook = false;
        int count = 0;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].author == author) {
                cout << books[i].title << " by " << books[i].author << endl;
                count++;
            }
        }
        if (count > 0) {
            isbook = true;
        }
        if (isbook == true)
            cout << author << "���� �� å�� ���� �������� " << count << "�� �ֽ��ϴ�.";
        if (isbook == false)
            cout << "���� �������� " << author << "���� �� å�� �������� �ʽ��ϴ�!" << endl;
    }
    Book getBookByTitle(const string& title) {
        return searchByTitle(title);
    }
};
class BorrowManager {
private:
    unordered_map<string, int>stock;
    unordered_map<string, bool>lend;    // å�� �뿩���θ� �����ϴ� ��
public:
    void initializeStock(Book book, int quantity = 3) {
        stock[book.title] = quantity;
        lend[book.title] = false;       // �ʱ⿡ å�� �����Ҷ� false�� �ʱ�ȭ��Ų��.
    }
    void borrowBook(const string& title) {
        auto it = stock.find(title);
        auto rent = lend.find(title);
        if (it->second > 0 && rent->second == false) {
            it->second -= 1;
            rent->second = true;
            cout << "������ �� ���: " << it->second << endl;
        }
        else if(rent->second == true) {     // �뿩 ����� ������ 
            cout << "�뿩 ���θ� ��ȸ�غ��� �뿩�� �Ͻ� ����� �־� �뿩 �Ұ����մϴ�" << endl;
        }
        else                                // �뿩 ��Ͼ��� å�� �������
            cout << "���� ��� �����ϴ�." << endl;
    }
    void returnBook(const string& title) {
        auto it = stock.find(title);
        auto rent = lend.find(title);
        if (rent->second == true) {
            it->second += 1;
            cout << "�ݳ��Ͻ� �� ���: " << it->second << endl;
        }
        else
            cout << "�뿩 ���θ� ��ȸ�غ��� �뿩�� �Ͻ� ����� ���� �ݳ� �Ұ����մϴ�" << endl;    
    }
    void displayStock() {
        for (auto i = stock.begin(); i != stock.end(); ++i) {
            cout << "å ����: " << i->first << " ���� ���" << i->second << "��" << endl;
        }
    }

};

int main() {
    BookManager manager;
    BorrowManager borrow;

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. å �˻�(����)" << endl; // å �������� �˻�
        cout << "4. å �˻�(����)" << endl; // å �����̸����� �˻�
        cout << "5. å ������" << endl;     // å ������
        cout << "6. å �ݳ��ϱ�" << endl;   // å �ݳ��ϱ�
        cout << "7. å ���Ȯ��" << endl;   // å ���Ȯ��
        cout << "8. ����" << endl; // ���α׷� ����
        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;

        if (choice == 1) {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            string title, author;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            manager.addBook(title, author); // �Է¹��� å ������ �߰�
            borrow.initializeStock(manager.getBookByTitle(title));   // �ʱ� å ��� 3�ǰ���
        }
        else if (choice == 2) {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            // 3�� ����: å �˻�(����)
            // �Է¹��� ������ ���� �������� å�� �ִ��� �˻��մϴ�.
            string title;
            cout << "�˻��� å �̸��� �Է��ϼ���: ";
            cin >> title;
            manager.searchByTitle(title);
        }
        else if (choice == 4) {
            // 4�� ����: å �˻�(����)
            // �Է¹��� ���� �̸��� ���� �������� å�� �ִ��� �˻��մϴ�.
            string author;
            cout << "�˻��� å �̸��� �Է��ϼ���: ";
            cin >> author;
            manager.searchByAuthor(author);
        }
        else if (choice == 5) {
            // 5�� ����: å ������
            // �Է¹��� �̸��� ���� ���������� å�� �����ϴ� 0���̸� �������ϴ�.
            string title;
            cout << "���� å �̸��� �Է��ϼ���: ";
            cin >> title;
            Book book = manager.searchByTitle(title);
            if (book.title != "") {
                borrow.borrowBook(title);
            }
            
        }
        else if (choice == 6) {
            // 6�� ����: å �ݳ��ϱ�
            // �Է¹��� �̸��� å�� �������� �ݳ��մϴ�.
            string title;
            cout << "�ݳ� �Ͻ� å �̸��� �Է��ϼ���: ";
            cin >> title;
            Book book = manager.searchByTitle(title);
            if (book.title != "") {
                borrow.returnBook(title);
            }
        }
        else if (choice == 7) {
            // 9�� ����: å ���Ȯ��
            // ���� å ��� Ȯ���մϴ�.
            borrow.displayStock();
        }
        else if (choice == 8) {
            // 8�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}