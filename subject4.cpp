#include <iostream>
#include <vector>
#include <string>

using namespace std; // namespace std ���

class Book {
public:
    string title;
    string author;

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
    void searchByTitle(const string& title) {
        bool isbook = false;               // å�� ���翩�θ� ��Ÿ���� boolŸ���� ���� isbook
        for (size_t i = 0; i < books.size(); i++) {     // �Ϲ����� for�� ���
            if (books[i].title == title) {              // ������ i���� �ε����� å�� ������ �Է¹��� title�� ���ٸ�  
                cout << books[i].title << " by " << books[i].author << endl;       // å�� �����, ���ڸ� ���
                isbook = true;
                break;                                  // å ������ ������ ���� ���ٰ� �����߱� ������ ã���� �ٷ� break�� �ݺ���������
            }
        }
        if (isbook == false)
            cout << "���� �������� " << title << "�̶�� ������ å�� �������� �ʽ��ϴ�!" << endl;
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
};

int main() {
    BookManager manager;

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. å �˻�(����)" << endl; // å �������� �˻�
        cout << "4. å �˻�(����)" << endl; // å �����̸����� �˻�
        cout << "5. ����" << endl; // ���α׷� ����
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
            // 5�� ����: ����
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